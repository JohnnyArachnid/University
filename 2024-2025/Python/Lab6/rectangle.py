# Python Language, Gr.1, LAB6 exercises implementation author: Daniel Szarek

from points import Point

class Rectangle:
    """Klasa reprezentująca prostokąt na płaszczyźnie."""

    def __init__(self, x1: float, y1: float, x2: float, y2: float):
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

    def center(self) -> 'Point':   # zwraca środek prostokąta
        return Point((self.pt1.x + self.pt2.x) / 2, (self.pt1.y + self.pt2.y) / 2)

    def area(self) -> float:   # pole powierzchni
        if (self.pt1.x >= self.pt2.x and self.pt1.y >= self.pt1.y):
            return abs(self.pt1.x - self.pt2.x) * abs(self.pt1.y - self.pt2.y)
        elif (self.pt1.x >= self.pt2.x and self.pt1.y < self.pt1.y):
            return abs(self.pt1.x - self.pt2.x) * abs(self.pt2.y - self.pt1.y)
        elif (self.pt1.x < self.pt2.x and self.pt1.y >= self.pt1.y):
            return abs(self.pt2.x - self.pt1.x) * abs(self.pt1.y - self.pt2.y)
        return abs(self.pt2.x - self.pt1.x) * abs(self.pt2.y - self.pt1.y)

    def move(self, x, y) -> None:   # przesunięcie o (x, y)
        self.pt1 = self.pt1 + Point(x, y)
        self.pt2 = self.pt2 + Point(x, y)

