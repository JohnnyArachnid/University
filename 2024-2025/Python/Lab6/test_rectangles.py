# Python Language, Gr.1, LAB6 exercises tests author: Daniel Szarek

from rectangle import *
import unittest

class TestRectangle(unittest.TestCase):

    def setUp(self):
        self.zero = Rectangle(0, 0, 0, 0)
        self.r1 = Rectangle(1, 2, 3, 4)
        self.r2 = Rectangle(-8, -3, 5, 5)
        self.r3 = Rectangle(3, 1, -15, -2)
        self.r4 = Rectangle(-8, -23, -5, -20)
        self.r5 = Rectangle(6, 12, 7, 21)

    def test_str(self):
        self.assertEqual(str(self.r1), "[(1, 2), (3, 4)]")
        self.assertEqual(str(self.r2), "[(-8, -3), (5, 5)]")

    def test_repr(self):
        self.assertEqual(repr(self.r1), "Rectangle(1, 2, 3, 4)")
        self.assertEqual(repr(self.r2), "Rectangle(-8, -3, 5, 5)")

    def test_eq(self):
        self.assertTrue(self.r1 == Rectangle(1, 2, 3, 4))
        self.assertTrue(self.r1 == Rectangle(3, 4, 1, 2))
        self.assertFalse(self.r1 == self.r2)

    def test_ne(self):
        self.assertFalse(self.r1 != Rectangle(1, 2, 3, 4))
        self.assertFalse(self.r1 != Rectangle(3, 4, 1, 2))
        self.assertTrue(self.r1 != self.r2)

    def test_center(self):
        self.assertEqual(self.r1.center(), Point(2, 3))
        self.assertEqual(self.r2.center(), Point(-1.5, 1))
        self.assertEqual(self.r5.center(), Point(6.5, 16.5))

    def test_area(self):
        self.assertEqual(self.r1.area(), 4)
        self.assertEqual(self.r2.area(), 104)
        self.assertEqual(self.r3.area(), 54)
        self.assertEqual(self.r4.area(), 9)
        self.assertEqual(self.r5.area(), 9)

    def test_move(self):
        self.r1.move(2, 3)
        self.assertEqual(self.r1.pt1, Point(3, 5))
        self.assertEqual(self.r1.pt2, Point(5, 7))

        self.r4.move(-3, -3)
        self.assertEqual(self.r4.pt1, Point(-11, -26))
        self.assertEqual(self.r4.pt2, Point(-8, -23))

    def tearDown(self):
        pass

if __name__ == '__main__':
    unittest.main()     # uruchamia wszystkie testy