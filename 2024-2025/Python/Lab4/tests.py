# Python Language, Gr.1, LAB4 exercises tests author: Daniel Szarek

from exercises import *

ex4_2_ruler = make_ruler(12)
ex4_2_grid = make_grid(2,4)
ex4_3 = exercise_4_3(5)
ex4_4 = exercise_4_4(7)
L = ["a","b",3,4,5,"c",7,8]
odwracanie_iteracyjne(L, 0, 2)
ex4_6 = sum_seq([[1,3],(3,4.5,5,[1,2]),1])
ex4_7 = flatten([1,(2,3),[],[4,(5,6,7)],8,[9]])

assert ex4_2_ruler == "|....|....|....|....|....|....|....|....|....|....|....|....|\n0    1    2    3    4    5    6    7    8    9   10   11   12", "Wrong output of ruler!"
print("Positive result from exercise 4.2_ruler, expected:\n|....|....|....|....|....|....|....|....|....|....|....|....|\n0    1    2    3    4    5    6    7    8    9   10   11   12, got:\n{}".format(ex4_2_ruler))
assert ex4_2_grid == "+---+---+---+---+\n|   |   |   |   |\n+---+---+---+---+\n|   |   |   |   |\n+---+---+---+---+", "Wrong output of grid!"
print("Positive result from exercise 4.2_grid, expected:\n+---+---+---+---+\n|   |   |   |   |\n+---+---+---+---+\n|   |   |   |   |\n+---+---+---+---+, got:\n{}".format(ex4_2_grid))
assert ex4_3 == 120, "Wrong result from factorial!"
print("Positive result from exercise 4.3, expected: 120, got: {}".format(ex4_3))
assert ex4_4 == 13, "Wrong result from fibbonaci!"
print("Positive result from exercise 4.4, expected: 13, got: {}".format(ex4_4))
assert L == [3,"b","a",4,5,"c",7,8], "Wrong result from odwracanie_iteracyjne!"
print("Positive result from exercise 4.5_odwracanie_iteracyjne, expected: [3, 'b', 'a', 4,5, 'c', 7, 8], got: {}".format(L))

odwracanie_rekurencyjne(L, 0, 2)

assert L == ["a","b",3,4,5,"c",7,8], "Wrong result from odwracanie_rekurencyjne!"
print("Positive result from exercise 4.5_odwracanie_rekurencyjne, expected: ['a', 'b', 3, 4, 5, 'c', 7, 8], got: {}".format(L))
assert ex4_6 == 20.5, "Wrong result from sum_seq!"
print("Positive result from exercise 4.6, expected: 20.5, got: {}".format(ex4_6))
assert ex4_7 == [1,2,3,4,5,6,7,8,9], "Wrong result from flatten!"
print("Positive result from exercise 4.7, expected: [1, 2, 3, 4, 5, 6, 7, 8, 9], got: {}".format(ex4_7))

print("All test cases passed successfully!")


