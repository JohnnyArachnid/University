# Python Language, Gr.1, LAB8 exercises tests author: Daniel Szarek

from rectangle import *
import pytest

class TestRectangles:
    
    @pytest.fixture(scope="class")
    def setR1(self):
        return Rectangle(1, 2, 3, 4)
    
    @pytest.fixture(scope="class")
    def setR2(self):
        return Rectangle(-8, -3, 5, 5)
    
    @pytest.fixture(scope="class")
    def setR3(self):
        return Rectangle(3, 1, -15, -2)
    
    @pytest.fixture(scope="class")
    def setR4(self):
        return Rectangle(-8, -23, -5, -20)
    
    @pytest.fixture(scope="class")
    def setR5(self):
        return Rectangle(6, 12, 7, 21)
    
    def test_init(self, setR1):
        assert setR1 == Rectangle(1, 2, 3, 4)
        with pytest.raises(TypeError, match="Argumenty prostokąta muszą być liczbami całkowitymi albo rzeczywistymi!"):
            test = Rectangle("a", "b", 12, "d")

    def test_str(self, setR1, setR2):
        assert str(setR1) == "[(1, 2), (3, 4)]"
        assert str(setR2) == "[(-8, -3), (5, 5)]"

    def test_repr(self, setR1, setR3):
        assert repr(setR1) == "Rectangle(1, 2, 3, 4)"
        assert repr(setR3) == "Rectangle(3, 1, -15, -2)"

    def test_eq(self, setR1, setR4):
        assert setR1 == Rectangle(1, 2, 3, 4)
        assert setR4 == Rectangle(-8, -23, -5, -20)

    def test_ne(self, setR2, setR5):
        assert setR2 != Rectangle(1, 2, 3, 4)
        assert setR5 != Rectangle(6, 13, 7, 21)

    def test_move(self, setR1, setR4):
        setR1.move(2, 3)
        assert setR1.pt1 == Point(3, 5)
        assert setR1.pt2 == Point(5, 7)

        setR4.move(-3, -3)
        assert setR4.pt1 == Point(-11, -26)
        assert setR4.pt2 == Point(-8, -23)

    def test_center(self, setR1, setR2):
        assert setR1.center == Point(4, 6) # Punkt przesunięty
        assert setR2.center == Point(-1.5, 1)

    def test_area(self, setR4, setR5):
        assert setR4.area == 9
        assert setR5.area == 9

    def test_top(self, setR1, setR2):
        assert setR1.top == 7
        assert setR2.top == 5

    def test_left(self, setR2, setR3):
        assert setR2.left == -8
        assert setR3.left == -15

    def test_right(self, setR3, setR4):
        assert setR3.right == 3
        assert setR4.right == -8 # Punkt przesunięty

    def test_bottom(self, setR4, setR5):
        assert setR4.bottom == -26 # Punkt przesunięty
        assert setR5.bottom == 12

    def test_width(self, setR5, setR1):
        assert setR5.width == 1
        assert setR1.width == 2

    def test_height(self, setR1, setR2):
        assert setR1.height == 2
        assert setR2.height == 8

    def test_topleft(self, setR2, setR3):
        assert setR2.topleft.x == -8
        assert setR3.topleft.x == -15
        assert setR2.topleft.y == 5
        assert setR3.topleft.y == 1

    def test_bottomleft(self, setR3, setR4):
        assert setR3.bottomleft.x == -15
        assert setR4.bottomleft.x == -11 # Punkt przesunięty
        assert setR3.bottomleft.y == -2
        assert setR4.bottomleft.y == -26 # Punkt przesunięty

    def test_topright(self, setR4, setR5):
        assert setR4.topright.x == -8 # Punkt przesunięty
        assert setR5.topright.x == 7
        assert setR4.topright.y == -23 # Punkt przesunięty
        assert setR5.topright.y == 21

    def test_bottomright(self, setR5, setR1):
        assert setR5.bottomright.x == 7
        assert setR1.bottomright.x == 5 # Punkt przesunięty
        assert setR5.bottomright.y == 12
        assert setR1.bottomright.y == 5 # Punkt przesunięty