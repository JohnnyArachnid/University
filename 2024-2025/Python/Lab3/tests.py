# Python Language, Gr.1, LAB3 exercises tests author: Daniel Szarek

from exercises import *

ex3_3 = exercise_3_3()
ex3_5 = exercise_3_5(12)
ex3_6 = exercise_3_6(2,4)
ex3_8 = exercise_3_8("kitten","cleopatra")
ex3_9 = exercise_3_9([[], [4], (1, 2), [3, 4], (5, 6, 7)])
ex3_10_1_v1 = exercise_3_10_v1("III")
ex3_10_2_v1 = exercise_3_10_v1("IV")
ex3_10_3_v1 = exercise_3_10_v1("IX")
ex3_10_4_v1 = exercise_3_10_v1("LVIII")
ex3_10_5_v1 = exercise_3_10_v1("MCMXCIV")
ex3_10_1_v2 = exercise_3_10_v2("III")
ex3_10_2_v2 = exercise_3_10_v2("IV")
ex3_10_3_v2 = exercise_3_10_v2("IX")
ex3_10_4_v2 = exercise_3_10_v2("LVIII")
ex3_10_5_v2 = exercise_3_10_v2("MCMXCIV")


assert ex3_3 == [1, 2, 4, 5, 7, 8, 10, 11, 13, 14, 16, 17, 19, 20, 22, 23, 25, 26, 28, 29], "Wrong set of numbers!"
print("Positive result from exercise 3.3, expected: [1, 2, 4, 5, 7, 8, 10, 11, 13, 14, 16, 17, 19, 20, 22, 23, 25, 26, 28, 29], got: {}".format(ex3_3))
assert ex3_5 == "|....|....|....|....|....|....|....|....|....|....|....|....|\n0    1    2    3    4    5    6    7    8    9   10   11   12", "Wrong output of measure!"
print("Positive result from exercise 3.5, expected:\n|....|....|....|....|....|....|....|....|....|....|....|....|\n0    1    2    3    4    5    6    7    8    9   10   11   12, got:\n{}".format(ex3_5))
assert ex3_6 == "+---+---+---+---+\n|   |   |   |   |\n+---+---+---+---+\n|   |   |   |   |\n+---+---+---+---+", "Wrong output of rectangle!"
print("Positive result from exercise 3.6, expected:\n+---+---+---+---+\n|   |   |   |   |\n+---+---+---+---+\n|   |   |   |   |\n+---+---+---+---+, got:\n{}".format(ex3_6))
assert ex3_8 == (['e', 't'], ['a', 'c', 'e', 'i', 'k', 'l', 'n', 'o', 'p', 'r', 't']), "Wrong result of chars in words!"
print("Positive result from exercise 3.8, expected: (['e', 't'], ['a', 'c', 'e', 'i', 'k', 'l', 'n', 'o', 'p', 'r', 't']), got: {}".format(ex3_8))
assert ex3_9 == [0, 4, 3, 7, 18], "Wrong result of sums in sequences!"
print("Positive result from exercise 3.9, expected: [0, 4, 3, 7, 18], got: {}".format(ex3_9))
assert ex3_10_1_v1 == 3, "Wrong result of translating into arabic from roman version 1!"
print("Positive result from exercise 3.10_1_v1, expected: 3, got: {}".format(ex3_10_1_v1))
assert ex3_10_2_v1 == 4, "Wrong result of translating into arabic from roman version 1!"
print("Positive result from exercise 3.10_2_v1, expected: 4, got: {}".format(ex3_10_2_v1))
assert ex3_10_3_v1 == 9, "Wrong result of translating into arabic from roman version 1!"
print("Positive result from exercise 3.10_3_v1, expected: 9, got: {}".format(ex3_10_3_v1))
assert ex3_10_4_v1 == 58, "Wrong result of translating into arabic from roman version 1!"
print("Positive result from exercise 3.10_4_v1, expected: 58, got: {}".format(ex3_10_4_v1))
assert ex3_10_5_v1 == 1994, "Wrong result of translating into arabic from roman version 1!"
print("Positive result from exercise 3.10_5_v1, expected: 1994, got: {}".format(ex3_10_5_v1))
assert ex3_10_1_v2 == 3, "Wrong result of translating into arabic from roman version 1!"
print("Positive result from exercise 3.10_1_v2, expected: 3, got: {}".format(ex3_10_1_v2))
assert ex3_10_2_v2 == 4, "Wrong result of translating into arabic from roman version 1!"
print("Positive result from exercise 3.10_2_v2, expected: 4, got: {}".format(ex3_10_2_v2))
assert ex3_10_3_v2 == 9, "Wrong result of translating into arabic from roman version 1!"
print("Positive result from exercise 3.10_3_v2, expected: 9, got: {}".format(ex3_10_3_v2))
assert ex3_10_4_v2 == 58, "Wrong result of translating into arabic from roman version 1!"
print("Positive result from exercise 3.10_4_v2, expected: 58, got: {}".format(ex3_10_4_v2))
assert ex3_10_5_v2 == 1994, "Wrong result of translating into arabic from roman version 1!"
print("Positive result from exercise 3.10_5_v2, expected: 1994, got: {}".format(ex3_10_5_v2))

print("All test cases passed successfully!")


