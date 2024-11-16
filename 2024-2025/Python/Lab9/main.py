# Python Language, Gr.1, LAB9 exercises implementation author: Daniel Szarek

import pygame
import os
import sys
import time
from constants import *

# Inicjacja pygame

pygame.init()
screen = pygame.display.set_mode((WIDTH, HEIGHT))
pygame.display.set_caption("Pong")

# Zegar

clock = pygame.time.Clock()

# Czcionki

font = pygame.font.Font(None, 74)
small_font = pygame.font.Font(None, 36)

# Zdjęcia

icon = pygame.image.load(os.path.join('photos', 'icon.png'))
pygame.display.set_icon(icon)

logo = pygame.image.load(os.path.join('photos', 'logo.png'))
scaled_logo = pygame.transform.scale(logo, (750, 250))

# Klasa Piłki

class Ball:
    def __init__(self, x, y):
        self.rect = pygame.Rect(x, y, 15, 15)
        self.vx = BALL_SPEED
        self.vy = BALL_SPEED

    def move(self):
        self.rect.x += self.vx
        self.rect.y += self.vy

        if self.rect.top <= 0 or self.rect.bottom >= HEIGHT:
            self.vy = -self.vy

    def reset(self):
        self.rect.center = (WIDTH // 2, HEIGHT // 2)
        self.vx *= -1

    def draw(self):
        pygame.draw.ellipse(screen, WHITE, self.rect)

# Klasa Wiosła

class Paddle:
    def __init__(self, x, y):
        self.rect = pygame.Rect(x, y, 10, 100)
        self.speed = 0

    def move(self):
        self.rect.y += self.speed
        if self.rect.top < 0:
            self.rect.top = 0
        if self.rect.bottom > HEIGHT:
            self.rect.bottom = HEIGHT

    def draw(self):
        pygame.draw.rect(screen, WHITE, self.rect)

# Wyświetlenie tła

def draw_background():
    screen.fill(BLACK)
    screen.blit(scaled_logo, (WIDTH // 2 - scaled_logo.get_width() // 2, HEIGHT // 2 - scaled_logo.get_height() // 2))

# Pokazanie głównego menu

def show_main_menu():
    while True:
        draw_background()
        
        title_text = font.render("Pong Game", True, WHITE)
        screen.blit(title_text, (WIDTH // 2 - title_text.get_width() // 2, HEIGHT // 4))

        play_multiplayer_text = small_font.render("1. Play with Player", True, WHITE)
        screen.blit(play_multiplayer_text, (WIDTH // 2 - play_multiplayer_text.get_width() // 2, HEIGHT // 2 - 40))

        play_ai_text = small_font.render("2. Play with AI", True, WHITE)
        screen.blit(play_ai_text, (WIDTH // 2 - play_ai_text.get_width() // 2, HEIGHT // 2))

        instructions_text = small_font.render("3. Instructions", True, WHITE)
        screen.blit(instructions_text, (WIDTH // 2 - instructions_text.get_width() // 2, HEIGHT // 2 + 40))

        exit_text = small_font.render("ESC. Quit", True, WHITE)
        screen.blit(exit_text, (WIDTH // 2 - exit_text.get_width() // 2, HEIGHT // 2 + 80))

        pygame.display.flip()

        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                pygame.quit()
                sys.exit(0)
            if event.type == pygame.KEYDOWN:
                if event.key == pygame.K_1:
                    play_game("player")
                elif event.key == pygame.K_2:
                    play_game("ai")
                elif event.key == pygame.K_3:
                    show_instructions()
                elif event.key == pygame.K_ESCAPE:
                    pygame.quit()
                    sys.exit(0)

# Pokazanie instrukcji

def show_instructions():
    while True:
        draw_background()

        instruction_text_first_player = small_font.render("Player 1: W to move up, S to move down", True, WHITE)
        screen.blit(instruction_text_first_player, (WIDTH // 2 - instruction_text_first_player.get_width() // 2, HEIGHT // 2 - 40))

        instruction_text_second_player = small_font.render("Player 2: Up Arrow to move up, Down Arrow to move down", True, WHITE)
        screen.blit(instruction_text_second_player, (WIDTH // 2 - instruction_text_second_player.get_width() // 2, HEIGHT // 2))

        instruction_text_pause = small_font.render("P to pause the game", True, WHITE)
        screen.blit(instruction_text_pause, (WIDTH // 2 - instruction_text_pause.get_width() // 2, HEIGHT // 2 + 40))

        back_text = small_font.render("Press ESC to go back", True, WHITE)
        screen.blit(back_text, (WIDTH // 2 - back_text.get_width() // 2, HEIGHT // 2 + 80))        
        
        pygame.display.flip()

        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                pygame.quit()
                sys.exit(0)
            if event.type == pygame.KEYDOWN:
                if event.key == pygame.K_ESCAPE:
                    return

# Pokazanie ekranu końcowego

def show_end_screen(winner, game_mode):
    draw_background()

    winner_text = font.render("{} Wins!".format(winner), True, WHITE)
    screen.blit(winner_text, (WIDTH // 2 - winner_text.get_width() // 2, HEIGHT // 2 - 50))

    pygame.display.flip()
    time.sleep(3)

    while True:
        draw_background()

        replay_text = small_font.render("1. Play Again", True, WHITE)
        screen.blit(replay_text, (WIDTH // 2 - replay_text.get_width() // 2, HEIGHT // 2 - 40))

        menu_text = small_font.render("2. Return to Menu", True, WHITE)
        screen.blit(menu_text, (WIDTH // 2 - menu_text.get_width() // 2, HEIGHT // 2))

        exit_text = small_font.render("3. Quit", True, WHITE)
        screen.blit(exit_text, (WIDTH // 2 - exit_text.get_width() // 2, HEIGHT // 2 + 40))

        pygame.display.flip()

        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                pygame.quit()
                sys.exit(0)
            if event.type == pygame.KEYDOWN:
                if event.key == pygame.K_1:
                    play_game(game_mode)
                elif event.key == pygame.K_2:
                    show_main_menu()
                elif event.key == pygame.K_3:
                    pygame.quit()
                    sys.exit(0)

# Pokazanie menu pauzy

def show_pause_menu():
    while True:
        draw_background()

        pause_text = font.render("Game Paused", True, WHITE)
        screen.blit(pause_text, (WIDTH // 2 - pause_text.get_width() // 2, HEIGHT // 2 - 50))

        resume_text = small_font.render("Press P to Resume", True, WHITE)
        screen.blit(resume_text, (WIDTH // 2 - resume_text.get_width() // 2, HEIGHT // 2 + 20))

        menu_text = small_font.render("Press ESC to Return to Menu", True, WHITE)
        screen.blit(menu_text, (WIDTH // 2 - menu_text.get_width() // 2, HEIGHT // 2 + 60))

        pygame.display.flip()

        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                pygame.quit()
                sys.exit(0)
            if event.type == pygame.KEYDOWN:
                if event.key == pygame.K_p:
                    countdown()
                    return
                if event.key == pygame.K_ESCAPE:
                    show_main_menu()

# Odliczanie

def countdown():
    for i in range(3, 0, -1):
        draw_background()

        text = font.render(str(i), True, WHITE)
        screen.blit(text, (WIDTH // 2 - text.get_width() // 2, HEIGHT // 2 - text.get_height() // 2))
        
        pygame.display.flip()
        time.sleep(1)

    draw_background()

    pong_text = font.render("PONG!", True, WHITE)
    screen.blit(pong_text, (WIDTH // 2 - pong_text.get_width() // 2, HEIGHT // 2 - pong_text.get_height() // 2))

    pygame.display.flip()
    time.sleep(1)

# Rozgrywka

def play_game(game_mode):
    left_paddle = Paddle(20, HEIGHT // 2 - 50)
    right_paddle = Paddle(WIDTH - 30, HEIGHT // 2 - 50)
    ball = Ball(WIDTH // 2, HEIGHT // 2)

    left_score = 0
    right_score = 0

    countdown()

    while True:
        screen.fill(BLACK)
        for y in range(0, HEIGHT, LINE_HEIGHT * 2):
            pygame.draw.line(screen, WHITE, (WIDTH // 2, y), (WIDTH // 2, y + LINE_HEIGHT))

        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                pygame.quit()
                sys.exit(0)
            if event.type == pygame.KEYDOWN:
                if event.key == pygame.K_p:
                    show_pause_menu()

        keys = pygame.key.get_pressed()

        if keys[pygame.K_w]:
            left_paddle.speed = -PADDLE_SPEED_PLAYER
        elif keys[pygame.K_s]:
            left_paddle.speed = PADDLE_SPEED_PLAYER
        else:
            left_paddle.speed = 0

        if game_mode == "player":
            if keys[pygame.K_UP]:
                right_paddle.speed = -PADDLE_SPEED_PLAYER
            elif keys[pygame.K_DOWN]:
                right_paddle.speed = PADDLE_SPEED_PLAYER
            else:
                right_paddle.speed = 0

        elif game_mode == "ai":
            if right_paddle.rect.centery < ball.rect.centery:
                right_paddle.speed = PADDLE_SPEED_AI
            elif right_paddle.rect.centery > ball.rect.centery:
                right_paddle.speed = -PADDLE_SPEED_AI
            else:
                right_paddle.speed = 0

        left_paddle.move()
        right_paddle.move()
        ball.move()

        if ball.rect.colliderect(left_paddle.rect) or ball.rect.colliderect(right_paddle.rect):
            ball.vx = -ball.vx

        if ball.rect.left <= 0:
            right_score += 1
            ball.reset()

        if ball.rect.right >= WIDTH:
            left_score += 1
            ball.reset()

        left_score_text = small_font.render(str(left_score), True, WHITE)
        right_score_text = small_font.render(str(right_score), True, WHITE)

        screen.blit(left_score_text, (WIDTH // 4 - left_score_text.get_width() // 2, 20))
        screen.blit(right_score_text, (3 * WIDTH // 4 - right_score_text.get_width() // 2, 20))

        left_paddle.draw()
        right_paddle.draw()
        ball.draw()

        pygame.display.flip()

        if left_score == WINNING_SCORE:
            show_end_screen("Player 1", game_mode)
        elif right_score == WINNING_SCORE:
            show_end_screen("Player 2", game_mode)

        clock.tick(FPS)

# Uruchomienie gry

show_main_menu()
