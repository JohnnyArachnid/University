# Python Language, Gr.1, LAB5 exercises tests author: Daniel Szarek

from fracs import *
import unittest

class TestFractions(unittest.TestCase):

    def setUp(self):
        self.zero = [0, 1]
        self.frac1 = [1, 2]
        self.frac2 = [1, 3]
        self.frac3 = [1, -5]
        self.frac4 = [-2, 8]
        self.frac5 = [-3, -7]

    def test_add_frac(self):
        self.assertEqual(add_frac(self.frac1, self.frac2), [5, 6])
        self.assertEqual(add_frac(self.frac3, self.frac4), [-9, 20])
        self.assertEqual(add_frac(self.frac5, self.zero), [3, 7])

    def test_sub_frac(self):
        self.assertEqual(sub_frac(self.frac1, self.frac2), [1, 6])
        self.assertEqual(sub_frac(self.frac3, self.frac4), [1, 20])
        self.assertEqual(sub_frac(self.frac5, self.zero), [3, 7])

    def test_mul_frac(self):
        self.assertEqual(mul_frac(self.frac1, self.frac2), [1, 6])
        self.assertEqual(mul_frac(self.frac3, self.frac4), [1, 20])
        self.assertEqual(mul_frac(self.frac5, self.zero), [0, 1])

    def test_div_frac(self):
        self.assertEqual(div_frac(self.frac1, self.frac2), [3, 2])
        self.assertEqual(div_frac(self.frac3, self.frac4), [4, 5])
        with self.assertRaises(ValueError) as context:
            div_frac(self.frac5, self.zero)
        self.assertEqual(str(context.exception), "Mianownik ułamka nie może być zerem.")

    def test_is_positive(self):
        self.assertFalse(is_positive(self.zero))
        self.assertTrue(is_positive(self.frac1))
        self.assertTrue(is_positive(self.frac2))
        self.assertFalse(is_positive(self.frac3))
        self.assertFalse(is_positive(self.frac4))
        self.assertTrue(is_positive(self.frac5))

    def test_is_zero(self):
        self.assertTrue(is_zero(self.zero))
        self.assertFalse(is_zero(self.frac1))
        self.assertFalse(is_zero(self.frac2))
        self.assertFalse(is_zero(self.frac3))
        self.assertFalse(is_zero(self.frac4))
        self.assertFalse(is_zero(self.frac5))

    def test_cmp_frac(self):
        self.assertEqual(cmp_frac(self.frac1, self.frac2), 1)
        self.assertEqual(cmp_frac(self.frac3, self.frac4), 1)
        self.assertEqual(cmp_frac(self.frac1, self.frac1), 0)
        self.assertEqual(cmp_frac(self.frac5, self.frac1), -1)
        self.assertEqual(cmp_frac(self.frac5, self.zero), 1)

    def test_frac2float(self): 
        self.assertEqual(frac2float(self.zero), 0)
        self.assertEqual(frac2float(self.frac1), 0.5)
        self.assertAlmostEqual(frac2float(self.frac2), 0.333, 3)
        self.assertEqual(frac2float(self.frac3), -0.2)
        self.assertEqual(frac2float(self.frac4), -0.25)
        self.assertAlmostEqual(frac2float(self.frac5), 0.429, 3)

    def tearDown(self):
        pass

if __name__ == '__main__':
    unittest.main()     # uruchamia wszystkie testy