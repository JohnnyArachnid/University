import unittest
from polys import add_poly, sub_poly, mul_poly, is_zero, eq_poly, eval_poly, combine_poly, pow_poly, diff_poly

class TestPolynomials(unittest.TestCase):

    def setUp(self):
        self.p1 = [0, 1]      
        self.p2 = [0, 0, 1]
        self.p3 = [2, 1]
        self.p4 = [2, 1, 0]
        self.p5 = [-3, 0, 1]
        self.p6 = [3]
        self.p7 = [0]
        self.p8 = [0, 0, 0]

    def test_add_poly(self):
        self.assertEqual(add_poly(self.p1, self.p2), [0, 1, 1])
        self.assertEqual(add_poly(self.p6, self.p7), [3])
        self.assertEqual(add_poly(self.p4, self.p5), [-1, 1, 1])

    def test_sub_poly(self):
        self.assertEqual(sub_poly(self.p1, self.p2), [0, 1, -1])
        self.assertEqual(sub_poly(self.p7, self.p6), [-3])
        self.assertEqual(sub_poly(self.p4, self.p5), [5, 1, -1])

    def test_mul_poly(self):
        self.assertEqual(mul_poly(self.p1, self.p2), [0, 0, 0, 1])
        self.assertEqual(mul_poly(self.p7, self.p6), [0])
        self.assertEqual(mul_poly(self.p3, self.p5), [-6, -3, 2, 1])

    def test_is_zero(self):
        self.assertFalse(is_zero(self.p3))
        self.assertTrue(is_zero(self.p7))
        self.assertTrue(is_zero(self.p8))

    def test_eq_poly(self):
        self.assertTrue(eq_poly(self.p7, self.p8))
        self.assertTrue(eq_poly(self.p3, self.p4))
        self.assertFalse(eq_poly(self.p1, self.p2))

    def test_eval_poly(self):
        self.assertEqual(eval_poly(self.p1, 0), 0)
        self.assertEqual(eval_poly(self.p3, 1), 3)
        self.assertEqual(eval_poly(self.p5, 2), 1)

    def test_combine_poly(self):
        self.assertEqual(combine_poly(self.p1, self.p2), [0, 0, 1])
        self.assertEqual(combine_poly(self.p6, self.p7), [3])
        self.assertEqual(combine_poly(self.p4, self.p5), [-1, 0, 1, 0, 0])

    def test_pow_poly(self):
        self.assertEqual(pow_poly(self.p1, 0), [1])
        self.assertEqual(pow_poly(self.p3, 1), [2, 1])
        self.assertEqual(pow_poly(self.p5, 2), [9, 0, -6, 0, 1])

    def test_diff_poly(self):
        self.assertEqual(diff_poly(self.p2), [0, 2])
        self.assertEqual(diff_poly(self.p4), [1, 0])
        self.assertEqual(diff_poly(self.p7), [])

    def tearDown(self): pass

# uruchamia wszystkie testy
if __name__ == '__main__':
    unittest.main()     