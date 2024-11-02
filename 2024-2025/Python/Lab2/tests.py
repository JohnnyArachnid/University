# Python Language, Gr.1, LAB2 exercises tests author: Daniel Szarek

from exercises import *

line = "first_word\tsecond word \nthirdWord GvR"
word = "word"
big_integer_number = 102045060708900
L = [1, 21, 312, 400, 55]

ex2_10 = exercise_2_10(line)
ex2_11 = exercise_2_11(word)
ex2_12_first_letter = exercise_2_12(line, True)
ex2_12_last_letter = exercise_2_12(line, False)
ex2_13 = exercise_2_13(line)
ex2_14 = exercise_2_14(line)
ex2_15 = exercise_2_15(L)
ex2_16 = exercise_2_16(line)
exercise_2_17_alphabetically = exercise_2_17(line, True)
exercise_2_17_length = exercise_2_17(line, False)
ex2_18 = exercise_2_18(big_integer_number)
ex2_19 = exercise_2_19(L)

assert ex2_10 == 5, "Wrong number of words in line!"
print(f"Positive result from exercise 2.10, expected: 5, got: {ex2_10}")
assert ex2_11 == "w_o_r_d", "Wrong characters in word!"
print(f"Positive result from exercise 2.11, expected: w_o_r_d, got: {ex2_11}")
assert ex2_12_first_letter == "fswtG", "Wrong characters result!"
print(f"Positive result from exercise 2.12 in first letter option, expected: fswtG, got: {ex2_12_first_letter}")
assert ex2_12_last_letter == "ddddR", "Wrong characters in result!"
print(f"Positive result from exercise 2.12 in last letter option, expected: ddddR, got: {ex2_12_last_letter}")
assert ex2_13 == 32, "Wrong number of characters in line!"
print(f"Positive result from exercise 2.13, expected: 32, got: {ex2_13}")
assert ex2_14 == ('first_word', 10), "Wrong set of longest word and it's length in line!"
print(f"Positive result from exercise 2.14, expected: ('first_word', 10), got: {ex2_14}")
assert ex2_15 == "12131240055", "Wrong string output in L!"
print(f"Positive result from exercise 2.15, expected: 12131240055, got: {ex2_15}")
assert ex2_16 == "first_word\tsecond word \nthirdWord Guido van Rossum", "Wrong string output in line!"
print(f"Positive result from exercise 2.16, expected: first_word\tsecond word \nthirdWord Guido van Rossum, got: {ex2_16}")
assert exercise_2_17_alphabetically == ['GvR', 'first_word', 'second', 'thirdWord', 'word'], "Wrong set of sorted words in alphabetical order output in line!"
print(f"Positive result from exercise 2.17 alphabetically, expected: ['GvR', 'first_word', 'second', 'thirdWord', 'word'], got: {exercise_2_17_alphabetically}")
assert exercise_2_17_length == ['GvR', 'word', 'second', 'thirdWord', 'first_word'], "Wrong set of sorted words by word length output in line!"
print(f"Positive result from exercise 2.17 alphabetically, expected: ['GvR', 'word', 'second', 'thirdWord', 'first_word'], got: {exercise_2_17_length}")
assert ex2_18 == 7, "Wrong number of 0 in big_integer_number!"
print(f"Positive result from exercise 2.18, expected: 7, got: {ex2_18}")
assert ex2_19 == "001021312400055", "Wrong string output in L!"
print(f"Positive result from exercise 2.19, expected: 001021312400055, got: {ex2_19}")

print("All test cases passed successfully!")


