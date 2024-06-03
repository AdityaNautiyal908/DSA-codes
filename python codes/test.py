import cv2
import numpy as np
import mediapipe as mp
import tkinter as tk
from tkinter import Button, Scale, Label, HORIZONTAL

import threading
import time

# Initialize MediaPipe Hand model
mp_hands = mp.solutions.hands
hands = mp_hands.Hands()
mp_drawing = mp.solutions.drawing_utils

# Create a white canvas with increased width
canvas = np.ones((720, 1920, 3), dtype="uint8") * 255

# Initialize a variable to store drawing points
drawing_points = []
mode = "brush"  # Initialize mode as brush
is_running = True  # Flag to control the application loop

# Initialize variables for undo and redo stacks
undo_stack = []  # Stack to store drawing history for undo
redo_stack = []  # Stack to store undone drawing for redo

# Initialize brush color and width
brush_color = (0, 0, 0)  # Default: Black
brush_width = 2  # Default: 2 pixels

# Function to draw on the canvas
def draw_on_canvas(points, canvas, mode):
    global brush_color, brush_width
    for i in range(1, len(points)):
        if points[i - 1] is None or points[i] is None:
            continue
        color = brush_color if mode == "brush" else (255, 255, 255)  # Use brush_color for brush, white for eraser
        thickness = brush_width if mode == "brush" else 20  # Thicker line for eraser
        thickness = int(thickness)  # Ensure thickness is an integer
        cv2.line(canvas, points[i - 1], points[i], color, thickness)

# Function to start the hand gesture drawing application
def start_drawing():
    global drawing_points, canvas, mode, is_running, undo_stack, redo_stack
    cap = cv2.VideoCapture(0)
    pinching = False  # Flag to track pinching gesture
    last_snap_time = 0  # Time of the last snap
    snap_count = 0  # Number of snaps detected
    cursor_pos = (0, 0)  # Initialize cursor position

    while is_running and cap.isOpened():
        ret, frame = cap.read()
        if not ret:
            break
        
        frame = cv2.flip(frame, 1)
        frame_rgb = cv2.cvtColor(frame, cv2.COLOR_BGR2RGB)
        
        results = hands.process(frame_rgb)

        if results.multi_hand_landmarks:
            for hand_landmarks in results.multi_hand_landmarks:
                mp_drawing.draw_landmarks(frame, hand_landmarks, mp_hands.HAND_CONNECTIONS)
                
                index_finger_tip = hand_landmarks.landmark[mp_hands.HandLandmark.INDEX_FINGER_TIP]
                thumb_tip = hand_landmarks.landmark[mp_hands.HandLandmark.THUMB_TIP]
                h, w, _ = frame.shape
                ix, iy = int(index_finger_tip.x * w), int(index_finger_tip.y * h)
                tx, ty = int(thumb_tip.x * w), int(thumb_tip.y * h)

                # Map the hand landmark coordinates to the canvas
                canvas_h, canvas_w, _ = canvas.shape
                mapped_ix = int(index_finger_tip.x * canvas_w)
                mapped_iy = int(index_finger_tip.y * canvas_h)
                mapped_tx = int(thumb_tip.x * canvas_w)
                mapped_ty = int(thumb_tip.y * canvas_h)

                cursor_pos = (mapped_ix, mapped_iy)  # Update cursor position

                # Detect pinch gesture for drawing
                if np.linalg.norm(np.array([mapped_ix, mapped_iy]) - np.array([mapped_tx, mapped_ty])) < 20:
                    pinching = True
                    drawing_points.append((mapped_ix, mapped_iy))
                else:
                    pinching = False
                    drawing_points.append(None)

        else:
            drawing_points.append(None)

        # Draw on canvas
        draw_on_canvas(drawing_points, canvas, mode)

        # Draw the cursor on the canvas
        cv2.circle(canvas, cursor_pos, 5, (0, 0, 255), -1)  # Draw a small red circle to represent the cursor

        # Ensure frame and canvas have the same height for concatenation
        frame_h, frame_w, _ = frame.shape
        canvas_h, canvas_w, _ = canvas.shape
        if frame_h != canvas_h:
            frame = cv2.resize(frame, (frame_w, canvas_h))

        combined_frame = cv2.hconcat([frame, canvas])
        cv2.imshow('Hand Gesture Drawing Assistant', combined_frame)
        
        if cv2.waitKey(1) & 0xFF == 27:  # Press 'Esc' to exit
            break

    cap.release()
    cv2.destroyAllWindows()

# Function to start the drawing in a separate thread
def start_drawing_thread():
    global is_running
    is_running = True
    threading.Thread(target=start_drawing).start()

# Functions to switch between brush and eraser modes
def set_brush_mode():
    global mode
    mode = "brush"

def set_eraser_mode():
    global mode
    mode = "eraser"

# Function to stop the application
def stop_application():
    global is_running
    is_running = False
    root.destroy()

# Function to change brush color
def change_brush_color(new_color):
    global brush_color
    brush_color = new_color

# Function to change brush width
def change_brush_width(new_width):
    global brush_width
    brush_width = int(new_width)  # Ensure brush width is an integer

# Function to clear the canvas
def clear_canvas():
    global canvas, drawing_points, undo_stack
    undo_stack.append(canvas.copy())  # Save current canvas to undo stack before clearing
    canvas = np.ones((720, 1920, 3), dtype="uint8") * 255
    drawing_points = []  # Clear the drawing points

# Function to undo the last action
def undo():
    global canvas, undo_stack, redo_stack
    if undo_stack:
        redo_stack.append(canvas.copy())  # Save current canvas to redo stack
        canvas = undo_stack.pop()  # Restore the last canvas state
        drawing_points.clear()  # Clear drawing points

# Function to redo the undone action
def redo():
    global canvas, undo_stack, redo_stack
    if redo_stack:
        undo_stack.append(canvas.copy())  # Save current canvas to undo stack
        canvas = redo_stack.pop()  # Restore the last undone canvas state
        drawing_points.clear()  # Clear drawing points

# Create the main Tkinter window
root = tk.Tk()
root.title("Hand Gesture Drawing Assistant")

# Create and place a button to start the drawing application
start_button = Button(root, text="Start Drawing", command=start_drawing_thread)
start_button.pack(pady=10)

# Create and place buttons to switch between brush and eraser modes
brush_button = Button(root, text="Brush", command=set_brush_mode)
brush_button.pack(pady=5)

eraser_button = Button(root, text="Eraser", command=set_eraser_mode)
eraser_button.pack(pady=5)

# Create a scale to change brush width
brush_width_label = Label(root, text="Brush Width")
brush_width_label.pack()
brush_width_scale = Scale(root, from_=1, to=20, orient=HORIZONTAL, command=change_brush_width)
brush_width_scale.set(2)  # Initial width: 2 pixels
brush_width_scale.pack()

# Create buttons to change brush color
brush_color_label = Label(root, text="Brush Color")
brush_color_label.pack()
black_button = Button(root, text="Black", command=lambda: change_brush_color((0, 0, 0)))
black_button.pack()
red_button = Button(root, text="Red", command=lambda: change_brush_color((0, 0, 255)))
red_button.pack()
green_button = Button(root, text="Green", command=lambda: change_brush_color((0, 255, 0)))
green_button.pack()
blue_button = Button(root, text="Blue", command=lambda: change_brush_color((255, 0, 0)))
blue_button.pack()

# Create a button to clear the canvas
clear_button = Button(root, text="Clear Canvas", command=clear_canvas)
clear_button.pack(pady=10)

# Create and place a button to switch off the application
switch_off_button = Button(root, text="Switch Off", command=stop_application)
switch_off_button.pack(pady=10)

# Run the Tkinter main loop
root.mainloop()
