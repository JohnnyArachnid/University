# Python Language, Gr.1, LAB8 exercises implementation author: Daniel Szarek

from points import Point
from typing import Union, List, Tuple

class Rectangle:
    """Klasa reprezentująca prostokąt na płaszczyźnie."""

    def __init__(self, x1: Union[int, float], y1: Union[int, float], x2: Union[int, float], y2: Union[int, float]):
        for value in (x1, y1, x2, y2):
            if not isinstance(value, (int, float)):
                raise TypeError("Argumenty prostokąta muszą być liczbami całkowitymi albo rzeczywistymi!")
        self.pt1 = Point(x1, y1)
        self.pt2 = Point(x2, y2)

    def __str__(self) -> str:   # "[(x1, y1), (x2, y2)]"
        return "[{}, {}]".format(str(self.pt1), str(self.pt2))

    def __repr__(self) -> str:   # "Rectangle(x1, y1, x2, y2)"
        return "Rectangle({}, {}, {}, {})".format(self.pt1.x, self.pt1.y, self.pt2.x, self.pt2.y)

    def __eq__(self, other: 'Rectangle') -> bool:   # obsługa rect1 == rect2
        return (min(self.pt1.x, self.pt2.x) == min(other.pt1.x, other.pt2.x) and
                max(self.pt1.x, self.pt2.x) == max(other.pt1.x, other.pt2.x) and
                min(self.pt1.y, self.pt2.y) == min(other.pt1.y, other.pt2.y) and
                max(self.pt1.y, self.pt2.y) == max(other.pt1.y, other.pt2.y))

    def __ne__(self, other: 'Rectangle') -> bool:   # obsługa rect1 != rect2
        return not self == other

    def move(self, x: Union[int, float], y: Union[int, float]) -> None:   # przesunięcie o (x, y)
        self.pt1 = self.pt1 + Point(x, y)
        self.pt2 = self.pt2 + Point(x, y)

    @classmethod
    def from_points(cls, points: Union[Tuple[Point, Point], List[Point]]) -> 'Rectangle':
        if len(points) != 2:
            raise ValueError("Funkcja wymaga dokładnie dwóch punktów: lewego dolnego i prawego górnego!")
        return cls(points[0].x, points[0].y, points[1].x, points[1].y)

    # atrybuty wirtualne

    @property
    def center(self) -> 'Point':   # zwraca środek prostokąta
        return Point((self.pt1.x + self.pt2.x) / 2, (self.pt1.y + self.pt2.y) / 2)

    @property
    def area(self) -> Union[int, float]:   # pole powierzchni
        if (self.pt1.x >= self.pt2.x and self.pt1.y >= self.pt1.y):
            return abs(self.pt1.x - self.pt2.x) * abs(self.pt1.y - self.pt2.y)
        elif (self.pt1.x >= self.pt2.x and self.pt1.y < self.pt1.y):
            return abs(self.pt1.x - self.pt2.x) * abs(self.pt2.y - self.pt1.y)
        elif (self.pt1.x < self.pt2.x and self.pt1.y >= self.pt1.y):
            return abs(self.pt2.x - self.pt1.x) * abs(self.pt1.y - self.pt2.y)
        return abs(self.pt2.x - self.pt1.x) * abs(self.pt2.y - self.pt1.y)
    
    @property
    def top(self) -> Union[int, float]:
        return max(self.pt1.y, self.pt2.y)
    
    @property
    def left(self) -> Union[int, float]:
        return min(self.pt1.x, self.pt2.x)
    
    @property
    def right(self) -> Union[int, float]:
        return max(self.pt1.x, self.pt2.x)
    
    @property
    def bottom(self) -> Union[int, float]:
        return min(self.pt1.y, self.pt2.y)
    
    @property
    def width(self) -> Union[int, float]:
        return self.right - self.left
    
    @property
    def height(self) -> Union[int, float]:
        return self.top - self.bottom
    
    @property
    def topleft(self) -> Point:
        return Point(self.left, self.top)
    
    @property
    def bottomleft(self) -> Point:
        return Point(self.left, self.bottom)
    
    @property
    def topright(self) -> Point:
        return Point(self.right, self.top)
    
    @property
    def bottomright(self) -> Point:
        return Point(self.right, self.bottom)