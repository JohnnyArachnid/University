# Python Language, Gr.1, LAB2 exercises implementation author: Daniel Szarek

from typing import Tuple, List

def exercise_2_10(line: str) -> int:
    return len(line.split())

def exercise_2_11(word: str) -> str:
    return '_'.join(word)

def exercise_2_12(line: str, first: bool) -> str:
    return ''.join(word[0] if first else word[-1] for word in line.split())

def exercise_2_13(line: str) -> int:
    return sum(len(word) for word in line.split())

def exercise_2_14(line: str) -> Tuple[str, int]:
    words = line.split()
    longest_word = max(words, key=len) if words else ""   
    return longest_word, len(longest_word)

def exercise_2_15(L: List[int]) -> str:
    return ''.join(str(integer) for integer in L)

def exercise_2_16(line: str) -> str:
    return line.replace("GvR", "Guido van Rossum")

def exercise_2_17(line: str, type: bool) -> List[str]:
    words = line.split()
    return sorted(words) if type else sorted(words, key=len)

def exercise_2_18(big_integer_number: int) -> int:
    return str(big_integer_number).count("0")

def exercise_2_19(L: List[int]) -> str:
    return ''.join([(str(integer).zfill(3)) for integer in L])






