# Python Language, Gr.1, LAB4 exercises implementation author: Daniel Szarek

from typing import Union

def make_ruler(number: int) -> str:
    if not isinstance(number, int):
        raise TypeError("Argument musi być liczbą naturalną.")
    
    if number < 0:
        raise ValueError("Argument nie może być liczbą ujemną.")

    result_up = ""
    result_down = ""
    
    for i in range(number + 1):
        result_up += "|...."
        result_down += str(i).rjust(5)

    result_up = result_up[:-4]
    return result_up + '\n' + result_down.strip()
    

def make_grid(height: int, width: int) -> str:
    if not isinstance(height, int) or not isinstance(width, int):
        raise TypeError("Argumenty muszą być liczbami naturalnymi.")
    
    if height < 0 or width < 0:
        raise ValueError("Argumenty nie mogą być liczbami ujemnymi.")
    
    top_line = "+---" * width 
    if height != 0 or width != 0: top_line += "+"
    middle_line = "|   " * width + "|"

    rectangle = []
    for _ in range(height):
        rectangle.append(top_line)
        rectangle.append(middle_line)
    rectangle.append(top_line)

    return "\n".join(rectangle)

def exercise_4_3(number: int) -> int:
    if not isinstance(number, int):
        raise TypeError("Argument musi być liczbą naturalną.")
    
    if number < 0:
        raise ValueError("Argument nie może być liczbą ujemną.")
    
    result = 1
    for temp in range(1, number + 1):
        result *= temp
        
    return result

def exercise_4_4(number: int) -> int:
    if not isinstance(number, int):
        raise TypeError("Argument musi być liczbą naturalną.")
    
    if number < 0:
        raise ValueError("Argument nie może być liczbą ujemną.")
    
    if number == 0:
        return 0
    
    prev, current = 0, 1
    for _ in range(2, number + 1):
        prev, current = current, prev + current
    return current

def odwracanie_iteracyjne(L: list, left: int, right: int) -> None:
    if not isinstance(L, list) or not isinstance(left, int) or not isinstance(right, int):
        raise TypeError("Argument 'L' musi być listą, natomiast 'left' oraz 'right' muszą być liczbami naturalnymi.")

    if left < 0 or right >= len(L) or left > right:
        raise ValueError("Argument 'left' musi być większy lub równy 0 i mniejszy lub równy 'right', a 'right' musi być mniejszy niż długość listy.")

    while left < right:
        L[left], L[right] = L[right], L[left]
        left += 1
        right -= 1
    
def odwracanie_rekurencyjne(L: list, left: int, right: int) -> None:
    if not isinstance(L, list) or not isinstance(left, int) or not isinstance(right, int):
        raise TypeError("Argument 'L' musi być listą, natomiast 'left' oraz 'right' muszą być liczbami naturalnymi.")

    if left < 0 or right >= len(L) or left > right:
        raise ValueError("Argument 'left' musi być większy lub równy 0 i mniejszy lub równy 'right', a 'right' musi być mniejszy niż długość listy.")

    if left >= right:
        return

    L[left], L[right] = L[right], L[left]

    odwracanie_rekurencyjne(L, left + 1, right - 1)

def sum_seq(sequence: Union[list, tuple]) -> float:
    if not isinstance(sequence, (list, tuple)):
        raise TypeError("Argument musi być sekwencją.")
    
    result = 0

    for item in sequence:
        if isinstance(item, (list, tuple)):
            result += sum_seq(item) 
        else:
            result += item
        
    return result

def flatten(sequence: Union[list, tuple]) -> list:
    if not isinstance(sequence, (list, tuple)):
        raise TypeError("Argument musi być sekwencją.")
    
    result = []

    for item in sequence:
        if isinstance(item, (list, tuple)):
            result.extend(flatten(item))
        else:
            result.append(item)
        
    return result







