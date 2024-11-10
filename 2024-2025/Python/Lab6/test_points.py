# Python Language, Gr.1, LAB6 exercises tests author: Daniel Szarek

from points import *
import unittest

class TestPoint(unittest.TestCase):

    def setUp(self):
        self.zero = Point(0, 0)
        self.p1 = Point(1, 2)
        self.p2 = Point(-3, 7)
        self.p3 = Point(4, -5)
        self.p4 = Point(-6, -6)
        self.p5 = Point(17, 12)

    def test_str(self):
        self.assertEqual(str(self.p1) , "(1, 2)")
        self.assertEqual(str(self.p3), "(4, -5)")
        self.assertEqual(str(self.p5), "(17, 12)")

    def test_repr(self):
        self.assertEqual(repr(self.p1) , "Point(1, 2)")
        self.assertEqual(repr(self.p3), "Point(4, -5)")
        self.assertEqual(repr(self.p5), "Point(17, 12)")

    def test_eq(self):
        self.assertTrue(self.p1 == Point(1, 2))
        self.assertFalse(self.p2 == self.p3)

    def test_ne(self):
        self.assertTrue(self.p2 != self.p3)
        self.assertFalse(self.p1 != Point(1, 2))

    def test_add(self):
        self.assertEqual(self.p1 + self.p2, Point(-2, 9))
        self.assertEqual(self.p3 + self.p4, Point(-2, -11))
        self.assertEqual(self.p5 + self.zero, self.p5)

    def test_sub(self):
        self.assertEqual(self.p1 - self.p2, Point(4, -5))
        self.assertEqual(self.p3 - self.p4, Point(10, 1))
        self.assertEqual(self.p5 - self.zero, self.p5)

    def test_mul(self):
        self.assertEqual(self.p1 * self.p2, 11)
        self.assertEqual(self.p3 * self.p4, 6)
        self.assertEqual(self.p5 * self.zero, 0)

    def test_cross(self):
        self.assertEqual(self.p1.cross(self.p2), 13)
        self.assertEqual(self.p3.cross(self.p4), -54)
        self.assertEqual(self.p5.cross(self.zero), 0)

    def test_length(self):
        self.assertAlmostEqual(self.p1.length(), math.sqrt(5), places=6)
        self.assertAlmostEqual(self.p2.length(), math.sqrt(58), places=6)
        self.assertAlmostEqual(self.p3.length(), math.sqrt(41), places=6)
        self.assertEqual(self.zero.length(), 0)

    def tearDown(self):
        pass

if __name__ == '__main__':
    unittest.main()     # uruchamia wszystkie testy