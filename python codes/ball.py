import pygame
import time
import random

# Initialize pygame
pygame.init()

# Set up display
WIDTH, HEIGHT = 600, 400
window = pygame.display.set_mode((WIDTH, HEIGHT))
pygame.display.set_caption("Snake Game")

# Define colors
BLACK = (0, 0, 0)
WHITE = (255, 255, 255)
GREEN = (0, 255, 0)
RED = (255, 0, 0)

# Set up clock
clock = pygame.time.Clock()
SNAKE_SPEED = 15

# Snake and food parameters
SNAKE_SIZE = 10
FOOD_SIZE = 10

font_style = pygame.font.SysFont(None, 35)

def message(msg, color):
    mesg = font_style.render(msg, True, color)
    window.blit(mesg, [WIDTH / 6, HEIGHT / 3])

def draw_snake(snake_list):
    for x in snake_list:
        pygame.draw.circle(window, WHITE, (x[0] + SNAKE_SIZE // 2, x[1] + SNAKE_SIZE // 2), SNAKE_SIZE // 2)

def game_loop():
    game_over = False
    game_close = False

    x1 = WIDTH / 2
    y1 = HEIGHT / 2

    x1_change = 0
    y1_change = 0

    snake_List = []
    Length_of_snake = 1

    foodx = round(random.randrange(0, WIDTH - SNAKE_SIZE) / 10.0) * 10.0
    foody = round(random.randrange(0, HEIGHT - SNAKE_SIZE) / 10.0) * 10.0

    while not game_over:

        while game_close:
            window.fill(BLACK)
            message("You Lost! Press Q-Quit or C-Play Again", RED)
            pygame.display.update()

            for event in pygame.event.get():
                if event.type == pygame.KEYDOWN:
                    if event.key == pygame.K_q:
                        game_over = True
                        game_close = False
                    if event.key == pygame.K_c:
                        game_loop()

        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                game_over = True
            if event.type == pygame.KEYDOWN:
                if event.key == pygame.K_LEFT:
                    x1_change = -SNAKE_SIZE
                    y1_change = 0
                elif event.key == pygame.K_RIGHT:
                    x1_change = SNAKE_SIZE
                    y1_change = 0
                elif event.key == pygame.K_UP:
                    y1_change = -SNAKE_SIZE
                    x1_change = 0
                elif event.key == pygame.K_DOWN:
                    y1_change = SNAKE_SIZE
                    x1_change = 0

        if x1 >= WIDTH or x1 < 0 or y1 >= HEIGHT or y1 < 0:
            game_close = True
        x1 += x1_change
        y1 += y1_change
        window.fill(BLACK)
        pygame.draw.circle(window, GREEN, (int(foodx + FOOD_SIZE / 2), int(foody + FOOD_SIZE / 2)), FOOD_SIZE // 2)
        snake_Head = []
        snake_Head.append(x1)
        snake_Head.append(y1)
        snake_List.append(snake_Head)
        if len(snake_List) > Length_of_snake:
            del snake_List[0]

        for x in snake_List[:-1]:
            if x == snake_Head:
                game_close = True

        draw_snake(snake_List)

        pygame.display.update()

        if x1 == foodx and y1 == foody:
            foodx = round(random.randrange(0, WIDTH - SNAKE_SIZE) / 10.0) * 10.0
            foody = round(random.randrange(0, HEIGHT - SNAKE_SIZE) / 10.0) * 10.0
            Length_of_snake += 1

        clock.tick(SNAKE_SPEED)

    pygame.quit()
    quit()

game_loop()
