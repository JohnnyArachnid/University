# Python Language, Gr.1, LAB8 exercises implementation author: Daniel Szarek

import math

class Point:
    """Klasa reprezentująca punkty na płaszczyźnie."""

    def __init__(self, x: float, y: float):  # konstuktor
        self.x = x
        self.y = y

    def __str__(self) -> str:   # zwraca string "(x, y)"
        return "({}, {})".format(self.x, self.y)

    def __repr__(self) -> str:   # zwraca string "Point(x, y)"
        return "Point({}, {})".format(self.x, self.y)

    def __eq__(self, other: 'Point') -> bool:   # obsługa point1 == point2
        return self.x == other.x and self.y == other.y

    def __ne__(self, other: 'Point') -> bool:   # obsługa point1 != point2
        return not self == other

    # Punkty jako wektory 2D.
    def __add__(self, other: 'Point') -> 'Point':   # v1 + v2
        return Point(self.x + other.x, self.y + other.y)

    def __sub__(self, other: 'Point') -> 'Point':   # v1 - v2
        return Point(self.x - other.x, self.y - other.y)

    def __mul__(self, other: 'Point') -> float:   # v1 * v2, iloczyn skalarny, zwraca liczbę
        return self.x * other.x + self.y * other.y

    def cross(self, other: 'Point') -> float:   # v1 x v2, iloczyn wektorowy 2D, zwraca liczbę
        return self.x * other.y - self.y * other.x

    def length(self) -> float:   # długość wektora
        return math.hypot(self.x, self.y)

    def __hash__(self) -> int:
        return hash((self.x, self.y))   # bazujemy na tuple, immutable points