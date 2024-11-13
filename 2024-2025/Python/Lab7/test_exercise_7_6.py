# Python Language, Gr.1, LAB7 exercises tests author: Daniel Szarek

from exercise_7_6 import *
import unittest

class TestIterators(unittest.TestCase):

    def setUp(self):
        self.iter1 = InfinityIteratorZeroAndOneSequence()
        self.iter2 = RandomNESWValueSequence()
        self.iter3 = InfinityIteratorWeekDaysSequence()

    def test_a(self):
        temp = []
        for i, value in enumerate(self.iter1):
            if i == 10:
                break
            temp.append(value)
        print("\nWartości z iteratora 0, 1, 0, 1...:", temp)
        self.assertEqual(temp, [0, 1, 0, 1, 0, 1, 0, 1, 0, 1])

    def test_b(self):
        temp = []
        valid_values = {"N", "E", "S", "W"}
        for i, value in enumerate(self.iter2):
            if i == 10:
                break
            temp.append(value)
            self.assertIn(value, valid_values)
        print("\nWartości z losowego iteratora NESW:", temp)

    def test_c(self):
        temp = []
        for i, value in enumerate(self.iter3):
            if i == 10:
                break
            temp.append(value)
        print("\nWartości z iteratora dni tygodnia:", temp)
        self.assertEqual(temp, [0, 1, 2, 3, 4, 5, 6, 0, 1, 2])

    def tearDown(self):
        pass

if __name__ == '__main__':
    print("Testy dla nieskończonych iteratorów z zestawu nr 7 dla licznika równego 10")
    unittest.main()     # uruchamia wszystkie testy
