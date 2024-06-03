import speech_recognition as sr
import pyttsx3
import os
import webbrowser
import pyaudio
import numpy as np
import tkinter as tk
from tkinter.scrolledtext import ScrolledText
import threading
import cv2
import mediapipe as mp
from collections import deque

# Initialize the recognizer
recognizer = sr.Recognizer()

# Initialize the text-to-speech engine
engine = pyttsx3.init()

# Initialize the flag to indicate whether the assistant is busy or not
is_busy = False

# Function to convert text to speech
def speak(text):
    engine.say(text)
    engine.runAndWait()

# Function to listen to the user's command
def listen():
    global is_busy
    if is_busy:
        return ""  # Return an empty string if the assistant is busy

    with sr.Microphone() as source:
        log("Listening...")
        audio = recognizer.listen(source)
        try:
            command = recognizer.recognize_google(audio)
            log(f"You said: {command}")
            return command.lower()
        except sr.UnknownValueError:
            speak("Sorry, I did not understand that.")
            log("Sorry, I did not understand that.")
            return ""
        except sr.RequestError:
            speak("Sorry, my speech service is down.")
            log("Sorry, my speech service is down.")
            return ""

# Function to execute commands
def execute_command(command):
    global is_busy  # Access the global flag variable
    if is_busy:
        speak("I'm currently busy. Please wait until I finish the current task.")
        log("I'm currently busy. Please wait until I finish the current task.")
        return True  # Return True to stay in the loop

    is_busy = True  # Set the flag to indicate the assistant is busy

    if 'hello' in command:
        speak("What can I do for you, sir?")
        log("What can I do for you, sir?")
    elif 'open google chrome' in command:
        if 'and search for' in command:
            search_query = command.split('search for')[-1].strip()
            if search_query:
                speak(f"Opening Google Chrome and searching for {search_query}")
                log(f"Opening Google Chrome and searching for {search_query}")
                url = f"https://www.google.com/search?q={search_query}"
                webbrowser.open(url)
        else:
            speak("Opening Google Chrome")
            log("Opening Google Chrome")
            os.startfile('C:\\Program Files\\Google\\Chrome\\Application\\chrome.exe')  # Adjust the path if needed
    elif 'open notepad' in command:
        speak("Opening Notepad")
        log("Opening Notepad")
        os.system('notepad.exe')
    elif 'open website' in command:
        speak("Which website would you like to open?")
        log("Which website would you like to open?")
        website = listen()
        if website:  # Ensure a valid response is received
            url = f"https://{website}"
            speak(f"Opening {website}")
            log(f"Opening {website}")
            webbrowser.open(url)
    elif 'open file' in command:
        file_name = command.split('open file')[-1].strip()
        file_path = f"C:\\path\\to\\your\\directory\\{file_name}"
        if os.path.exists(file_path):
            speak(f"Opening {file_name} in VS Code")
            log(f"Opening {file_name} in VS Code")
            os.startfile(f'code "{file_path}"')  # Launch file in VS Code
        else:
            speak("File not found.")
            log("File not found.")
    elif 'off' in command or 'shut down' in command or 'turn off' in command:
        speak("Turning off. Goodbye!")
        log("Turning off. Goodbye!")
        is_busy = False  # Reset the flag before shutting down
        return False  # Return False to exit the loop
    else:
        speak("Sorry, I don't know how to do that yet.")
        log("Sorry, I don't know how to do that yet.")
    
    is_busy = False  # Reset the flag once the task is finished
    return True

# Function to log messages to the GUI
def log(message):
    text_area.insert(tk.END, message + '\n')
    text_area.see(tk.END)
    root.update()

# Function to update the canvas with voice levels
def update_canvas():
    CHUNK = 1024
    RATE = 44100

    p = pyaudio.PyAudio()
    stream = p.open(format=pyaudio.paInt16,
                    channels=1,
                    rate=RATE,
                    input=True,
                    frames_per_buffer=CHUNK)

    while True:
        data = np.frombuffer(stream.read(CHUNK), dtype=np.int16)
        peak = np.abs(data).max()
        draw_waveform(peak)
        root.update_idletasks()
        root.update()

# Function to draw the waveform on the canvas
def draw_waveform(peak):
    canvas.delete("all")
    width = canvas.winfo_width()
    height = canvas.winfo_height()
    x = width / 2
    y = height / 2
    peak_normalized = peak / 32767.0
    radius = peak_normalized * (height / 2)
    canvas.create_oval(x - radius, y - radius, x + radius, y + radius, fill="blue")

# Function to recognize hand gestures using the webcam
def recognize_gestures():
    mp_hands = mp.solutions.hands
    hands = mp_hands.Hands()
    mp_drawing = mp.solutions.drawing_utils
    cap = cv2.VideoCapture(0)
    
    # To store the points for drawing shapes
    points_deque = deque(maxlen=512)
    drawing_canvas = np.ones((720, 1280, 3), dtype="uint8") * 255  # White canvas for drawing

    while cap.isOpened():
        ret, frame = cap.read()
        if not ret:
            break
        frame = cv2.cvtColor(frame, cv2.COLOR_BGR2RGB)
        results = hands.process(frame)

        if results.multi_hand_landmarks:
            for hand_landmarks in results.multi_hand_landmarks:
                mp_drawing.draw_landmarks(frame, hand_landmarks, mp_hands.HAND_CONNECTIONS)
                index_finger_tip = hand_landmarks.landmark[mp_hands.HandLandmark.INDEX_FINGER_TIP]
                
                # Convert normalized coordinates to pixel coordinates
                h, w, _ = frame.shape
                cx, cy = int(index_finger_tip.x * w), int(index_finger_tip.y * h)
                points_deque.appendleft((cx, cy))
                
                for i in range(1, len(points_deque)):
                    if points_deque[i - 1] is None or points_deque[i] is None:
                        continue
                    cv2.line(drawing_canvas, points_deque[i - 1], points_deque[i], (0, 0, 0), 2)
                
                # Check if the user draws a circle
                if len(points_deque) == 512 and is_circle(points_deque):
                    log("Circle gesture detected")
                    speak("Circle gesture detected")
                    cv2.circle(drawing_canvas, (cx, cy), 50, (0, 0, 255), 2)  # Draw circle on canvas

                # Check if the user draws a house (very basic detection)
                if len(points_deque) == 512 and is_house(points_deque):
                    log("House gesture detected")
                    speak("House gesture detected")
                    draw_house(drawing_canvas, (cx, cy))

        frame = cv2.cvtColor(frame, cv2.COLOR_RGB2BGR)
        combined_frame = cv2.hconcat([frame, drawing_canvas])
        cv2.imshow('Hand Gesture Recognition', combined_frame)
        if cv2.waitKey(5) & 0xFF == 27:
            break

    cap.release()
    cv2.destroyAllWindows()

def is_circle(points):
    # Placeholder function to detect a circle shape in points
    return False  # Replace with actual circle detection logic

def is_house(points):
    # Placeholder function to detect a house shape in points
    return False  # Replace with actual house detection logic

def draw_house(canvas, position):
    x, y = position
    cv2.rectangle(canvas, (x - 50, y), (x + 50, y + 100), (0, 255, 0), 2)  # House body
    pts = np.array([[x - 50, y], [x + 50, y], [x, y - 50]], np.int32)  # House roof
    pts = pts.reshape((-1, 1, 2))
    cv2.polylines(canvas, [pts], isClosed=True, color=(0, 255, 0), thickness=2)

# Main function
def main():
    while True:
        command = listen()
        if command:
            if not execute_command(command):
                break

if __name__ == "__main__":
    root = tk.Tk()
    root.title("Voice Assistant")
    
    # Default background and foreground colors for the GUI
    text_area = ScrolledText(root, wrap=tk.WORD, width=50, height=10)
    text_area.pack(padx=10, pady=10)

    canvas = tk.Canvas(root, width=400, height=100)
    canvas.pack(padx=10, pady=10)
    
    main_button = tk.Button(root, text="Start Assistant", command=lambda: threading.Thread(target=main).start())
    main_button.pack(pady=10)
    
    gesture_button = tk.Button(root, text="Start Gesture Recognition", command=lambda: threading.Thread(target=recognize_gestures).start())
    gesture_button.pack(pady=10)

    threading.Thread(target=update_canvas).start()
    
    # Initial greeting outside the main loop
    speak("Hello, I am your voice assistant. How can I help you today?")
    log("Hello, I am your voice assistant. How can I help you today?")
    
    root.mainloop()
