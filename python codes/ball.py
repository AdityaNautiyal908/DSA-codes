import pygame
import random
import sys

# Initialize pygame
pygame.init()

# Screen dimensions
WIDTH, HEIGHT = 800, 600
screen = pygame.display.set_mode((WIDTH, HEIGHT))
pygame.display.set_caption("Bounce the Ball to Hit the Bubble")

# Colors
BLACK = (0, 0, 0)
WHITE = (255, 255, 255)
BLUE = (0, 0, 255)
RED = (255, 0, 0)

# Ball properties
ball_radius = 15
ball_x = WIDTH // 2
ball_y = HEIGHT // 2
ball_speed = 5

# Bubble properties
bubble_radius = 20
bubble_x = random.randint(bubble_radius, WIDTH - bubble_radius)
bubble_y = random.randint(bubble_radius, HEIGHT - bubble_radius)

# Font for score
font = pygame.font.Font(None, 36)
score = 0

# Main game loop
running = True
while running:
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            running = False
    
    # Get key states
    keys = pygame.key.get_pressed()
    
    # Move the ball based on arrow key inputs
    if keys[pygame.K_LEFT]:
        ball_x -= ball_speed
    if keys[pygame.K_RIGHT]:
        ball_x += ball_speed
    if keys[pygame.K_UP]:
        ball_y -= ball_speed
    if keys[pygame.K_DOWN]:
        ball_y += ball_speed

    # Ball collision with walls
    if ball_x - ball_radius <= 0:
        ball_x = ball_radius
    if ball_x + ball_radius >= WIDTH:
        ball_x = WIDTH - ball_radius
    if ball_y - ball_radius <= 0:
        ball_y = ball_radius
    if ball_y + ball_radius >= HEIGHT:
        ball_y = HEIGHT - ball_radius

    # Ball collision with bubble
    if (ball_x - bubble_x) ** 2 + (ball_y - bubble_y) ** 2 <= (ball_radius + bubble_radius) ** 2:
        score += 1
        bubble_x = random.randint(bubble_radius, WIDTH - bubble_radius)
        bubble_y = random.randint(bubble_radius, HEIGHT - bubble_radius)
    
    # Clear screen
    screen.fill(BLACK)
    
    # Draw ball
    pygame.draw.circle(screen, BLUE, (ball_x, ball_y), ball_radius)
    
    # Draw bubble
    pygame.draw.circle(screen, RED, (bubble_x, bubble_y), bubble_radius)
    
    # Draw score
    score_text = font.render(f"Score: {score}", True, WHITE)
    screen.blit(score_text, (10, 10))
    
    # Update display
    pygame.display.flip()
    
    # Frame rate
    pygame.time.Clock().tick(60)

# Quit pygame
pygame.quit()
sys.exit()
