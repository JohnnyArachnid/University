# Python Language, Gr.1, LAB7 exercises tests author: Daniel Szarek

from fracs import *
import unittest

class TestFrac(unittest.TestCase):

    def setUp(self):
        self.f1 = Frac(1, 2)
        self.f2 = Frac(1, -3)
        self.f3 = Frac(-2, 5)
        self.f4 = Frac(-4, -9)
        self.f5 = Frac(6, 10)
        self.f6 = Frac(0, 5)
        self.f7 = Frac(2.5)

    def test_init_valid(self):
        self.assertEqual(self.f1.x, 1)
        self.assertEqual(self.f1.y, 2)
        self.assertEqual(self.f2.x, -1)
        self.assertEqual(self.f2.y, 3)
        self.assertEqual(self.f4.x, 4)
        self.assertEqual(self.f4.y, 9)
        self.assertEqual(self.f5.x, 3)
        self.assertEqual(self.f5.y, 5)
        self.assertEqual(self.f6.x, 0)
        self.assertEqual(self.f6.y, 1)
        self.assertEqual(self.f7.x, 5)
        self.assertEqual(self.f7.y, 2)

    def test_init_invalid_denominator(self):
        with self.assertRaises(ValueError):
            Frac(1, 0)

    def test_init_invalid_type(self):
        with self.assertRaises(TypeError):
            Frac(1.5, 'string')

    def test_string_representation(self):
        self.assertEqual(str(self.f1), "1/2")
        self.assertEqual(str(self.f3), "-2/5")
        self.assertEqual(str(self.f6), "0")

    def test_repr_representation(self):
        self.assertEqual(repr(self.f1), "Frac(1, 2)")
        self.assertEqual(repr(self.f3), "Frac(-2, 5)")
        self.assertEqual(repr(self.f6), "Frac(0, 1)")

    def test_equality(self):
        self.assertTrue(self.f4 == Frac(4, 9))
        self.assertFalse(self.f3 == self.f6)
        self.assertFalse(self.f1 == self.f2)

    def test_inequality(self):
        self.assertTrue(self.f2 != self.f3)
        self.assertFalse(self.f6 != Frac(0, 2))
        self.assertFalse(self.f1 != self.f1)

    def test_less_than(self):
        self.assertTrue(self.f2 < self.f1)
        self.assertTrue(self.f3 < self.f2)
        self.assertFalse(self.f5 < self.f6)

    def test_less_or_equal(self):
        self.assertTrue(self.f4 <= self.f5)
        self.assertTrue(self.f2 <= Frac(1, -3))
        self.assertFalse(self.f6 <= self.f2)

    def test_greather_than(self):
        self.assertTrue(self.f1 > self.f6)
        self.assertTrue(self.f5 > self.f3)
        self.assertFalse(self.f3 > self.f4)

    def test_greather_or_equal(self):
        self.assertTrue(self.f2 >= Frac(-1, 3))
        self.assertTrue(self.f5 >= self.f4)
        self.assertFalse(self.f2 >= self.f1)

    def test_addition(self):
        result = self.f1 + self.f4
        self.assertEqual(result.x, 17)
        self.assertEqual(result.y, 18)
        result = self.f7 + self.f3
        self.assertEqual(result.x, 21)
        self.assertEqual(result.y, 10)
        result = self.f5 + self.f6
        self.assertEqual(result.x, 3)
        self.assertEqual(result.y, 5)

    def test_addition_with_int(self):
        result = self.f1 + 1
        self.assertEqual(result.x, 3)
        self.assertEqual(result.y, 2)
        result = self.f3 + 2
        self.assertEqual(result.x, 8)
        self.assertEqual(result.y, 5)
        result = self.f6 + 3
        self.assertEqual(result.x, 3)
        self.assertEqual(result.y, 1)

    def test_subtraction(self):
        result = self.f1 - self.f1
        self.assertEqual(result.x, 0)
        self.assertEqual(result.y, 1)
        result = self.f4 - self.f3
        self.assertEqual(result.x, 38)
        self.assertEqual(result.y, 45)
        result = self.f6 - self.f4
        self.assertEqual(result.x, -4)
        self.assertEqual(result.y, 9)

    def test_substraction_with_int(self):
        result = self.f4 - 1
        self.assertEqual(result.x, -5)
        self.assertEqual(result.y, 9)
        result = self.f2 - 2
        self.assertEqual(result.x, -7)
        self.assertEqual(result.y, 3)
        result = self.f6 - 3
        self.assertEqual(result.x, -3)
        self.assertEqual(result.y, 1)

    def test_multiplication(self):
        result = self.f2 * self.f2
        self.assertEqual(result.x, 1)
        self.assertEqual(result.y, 9)
        result = self.f1 * self.f3
        self.assertEqual(result.x, -1)
        self.assertEqual(result.y, 5)
        result = self.f6 * self.f4
        self.assertEqual(result.x, 0)
        self.assertEqual(result.y, 1)

    def test_multiplication_with_int(self):
        result = self.f5 * 1
        self.assertEqual(result.x, 3)
        self.assertEqual(result.y, 5)
        result = self.f3 * 2
        self.assertEqual(result.x, -4)
        self.assertEqual(result.y, 5)
        result = self.f6 * 3
        self.assertEqual(result.x, 0)
        self.assertEqual(result.y, 1)

    def test_division(self):
        result = self.f1 / self.f1
        self.assertEqual(result.x, 1)
        self.assertEqual(result.y, 1)
        result = self.f2 / self.f3
        self.assertEqual(result.x, 5)
        self.assertEqual(result.y, 6)
        with self.assertRaises(ZeroDivisionError):
            self.f2 / self.f6 

    def test_division_with_int(self):
        result = self.f5 / 1
        self.assertEqual(result.x, 3)
        self.assertEqual(result.y, 5)
        result = self.f2 / 2
        self.assertEqual(result.x, -1)
        self.assertEqual(result.y, 6)
        with self.assertRaises(ZeroDivisionError):
            self.f6 / 0        
    
    def test_positive(self):
        result = +self.f1
        self.assertEqual(result.x, 1)
        self.assertEqual(result.y, 2)
        result = +self.f3
        self.assertEqual(result.x, -2)
        self.assertEqual(result.y, 5)
        result = +self.f6
        self.assertEqual(result.x, 0)
        self.assertEqual(result.y, 1)

    def test_negation(self):
        result = -self.f5
        self.assertEqual(result.x, -3)
        self.assertEqual(result.y, 5)
        result = -self.f2
        self.assertEqual(result.x, 1)
        self.assertEqual(result.y, 3)
        result = -self.f6
        self.assertEqual(result.x, 0)
        self.assertEqual(result.y, 1)

    def test_float_conversion(self):
        self.assertEqual(float(self.f1), 0.5)
        self.assertEqual(float(self.f3), -0.4)
        self.assertAlmostEqual(float(self.f4), 0.444444, places=6)

if __name__ == '__main__':
    unittest.main()     # uruchamia wszystkie testy