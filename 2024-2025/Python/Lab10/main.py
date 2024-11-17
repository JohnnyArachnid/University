# Python Language, Gr.1, LAB10 exercises implementation author: Daniel Szarek

import tkinter as tk
from tkinter import PhotoImage
import random
import os

# Historia rzutów
historia = []

# Funkcja do losowania i aktualizacji wyników
def losowanie_rzutu_kostką():
    losowanie = random.randint(1, 6)
    historia.append(losowanie)
    
    # Jeżeli lista ma więcej niż 10 elementów, usuwamy najstarszy wynik
    if len(historia) > 10:
        historia.pop(0)
    
    # Aktualizowanie historii w etykiecie
    historia_label.config(text="Historia: " + ', '.join(map(str, historia)))
    
    # Aktualizowanie obrazu wyniku
    result_image.config(image=dice_images[losowanie - 1])
    result_label.config(text="Wynik: {}".format(losowanie))

# Funkcja resetująca stan aplikacji
def reset():
    historia.clear()

    # Resetowanie obrazu i tekstu
    result_image.config(image=logo_image)
    result_label.config(text="Wynik: Brak")
    historia_label.config(text="Historia: Pusta")
    
# Główne okno aplikacji
root = tk.Tk()
root.title("Symulator rzutu sześcienną kostką")
root.configure(width=500, height=500, bg="#FF8C00")
root.resizable(False, False)

# Obrazy kostek
dice_images = [PhotoImage(file=os.path.join('photos', 'dice{}.png').format(i)).subsample(4, 4) for i in range(1, 7)]
logo_image = PhotoImage(file=os.path.join('photos', 'dice.png')).subsample(2, 2)

# Ramka główna
frame = tk.Frame(root, bg="#FF8C00")
frame.grid(row=0, column=0, padx=20, pady=20)

# Tytuł
title_label = tk.Label(frame, text="Symulator rzutu sześcienną kostką", font=("Arial", 16, "bold"), bg="#FF8C00", fg="black")
title_label.grid(row=0, column=0, pady=10)

# Historia
historia_label = tk.Label(frame, text="Historia: Pusta", font=("Arial", 12), bg="#FF8C00", fg="black")
historia_label.grid(row=1, column=0, pady=10)

# Wynik
result_label = tk.Label(frame, text="Wynik: Brak", font=("Arial", 12), bg="#FF8C00", fg="black")
result_label.grid(row=2, column=0, pady=10)

result_image = tk.Label(frame, image=logo_image, bg="#FF8C00")
result_image.grid(row=3, column=0, pady=10)

# Przyciski
buttons_frame = tk.Frame(frame, bg="#FF8C00")
buttons_frame.grid(row=4, column=0, pady=10)

roll_button = tk.Button(buttons_frame, text="Rzuć kostką", font=("Arial", 14), command=losowanie_rzutu_kostką, bg="white", fg="black")
roll_button.grid(row=0, column=0, padx=20)

reset_button = tk.Button(buttons_frame, text="Reset", font=("Arial", 14), command=reset, bg="white", fg="black")
reset_button.grid(row=0, column=1, padx=20)

# Uruchomienie aplikacji
root.mainloop()
