# Python Language, Gr.1, LAB3 exercises implementation author: Daniel Szarek

from typing import Tuple, List, Union

def exercise_3_3() -> List[int]:
    return [number for number in range(31) if number % 3 != 0]

def exercise_3_5(number: int) -> str:
    # Dodałem ograniczenie ponieważ miarka liczy od liczb większych od 0, w dodatku przy liczbach więcej niz 4 cyfrowych, liczby by sie już zlewały stąd takie ograniczenie
    if number <= 0 or number >= 10000:
        return "Podaj liczbę naturalną mniejszą od 10000 i większą od 0!"

    result_up = ""
    result_down = ""
    
    for i in range(number + 1):
        result_up += "|...."
        result_down += str(i).rjust(5)

    result_up = result_up[:-4]
    return result_up + '\n' + result_down.strip()

def exercise_3_6(height: int, width: int) -> str:
    # Dodałem ograniczenie na szerokość i dlugość prostokata ponieważ nie istnieje dlugość i szerekość mniejsza od 0 w dodatku w ramach ograniczeń pojemności terminala postanowiłem ustalić maksymalną dlugość i szerokość na maks 100
    if height <= 0 or width <= 0 or height >= 100 or width >= 100:
        return "Podaj wysokość oraz szerokość prostokąta w granicach od 1 do 99"
    
    top_line = "+---" * width + "+" 
    middle_line = "|   " * width + "|"

    rectangle = []
    for _ in range(height):
        rectangle.append(top_line)
        rectangle.append(middle_line)
    rectangle.append(top_line)

    return "\n".join(rectangle)

def exercise_3_8(first: str, second: str) -> Tuple[List[str], List[str]]:
    # Rzutowanie na string dodałem ponieważ możemy też obsługiwać liczby
    set_first = set(str(first))
    set_second = set(str(second))
    
    common_elements = sorted(list(set_first & set_second))
    
    all_elements = sorted(list(set_first | set_second))
    
    return common_elements, all_elements

def exercise_3_9(sequences: List[Union[List[int], Tuple[int, ...]]]) -> List[int]:
    return [sum(seq) for seq in sequences]

# Pierwsze wersja zadania 3_10 tutaj operujemy na odwróconym wariancie liczby rzymskiej następnie dokonujemy porównania z poprzednią wartością i aktualizujemy na jej podstawie wartość końcową
def exercise_3_10_v1(roman_value: str) -> int:
    roman_to_int = {
        'I': 1,
        'V': 5,
        'X': 10,
        'L': 50,
        'C': 100,
        'D': 500,
        'M': 1000
    }
    
    total = 0
    prev_value = 0
    
    for char in reversed(roman_value):
        current_value = roman_to_int[char]        
        if current_value < prev_value:
            total -= current_value
        else:
            total += current_value
        prev_value = current_value
    
    return total

# Druga wersja zadania 3_10 tutaj również dokonujemy porównania tylko bez odwracania liczby, porównanie następuję z liczbą następną i na tej podstawie decydujemy jaką operację wykonać aby otrzymać wynik całkowity
def exercise_3_10_v2(roman_value: str) -> int:
    roman_to_int = {
        'I': 1,
        'V': 5,
        'X': 10,
        'L': 50,
        'C': 100,
        'D': 500,
        'M': 1000
    }
    
    total = 0
    length = len(roman_value)
    
    for i in range(length):
        current_value = roman_to_int[roman_value[i]]
        if i < length - 1 and roman_to_int[roman_value[i]] < roman_to_int[roman_value[i + 1]]:
            total -= current_value
        else:
            total += current_value
    
    return total








