# Python Language, Gr.1, LAB5 exercises implementation author: Daniel Szarek

# Funckje główne na ułamkach

def add_frac(frac1, frac2):         # frac1 + frac2
    fraction_check(frac1)
    fraction_check(frac2)
    if frac1[1] != frac2[1]:
        new_denominator = int(nww(frac1[1], frac2[1]))
        new_numerator = int(frac1[0] * new_denominator / frac1[1] + frac2[0] * new_denominator / frac2[1])
        return fraction_reduce([new_numerator, new_denominator])
    return fraction_reduce([frac1[0] + frac2[0] , frac1[1]])

def sub_frac(frac1, frac2):         # frac1 - frac2
    fraction_check(frac1)
    fraction_check(frac2)
    if frac1[1] != frac2[1]:
        new_denominator = int(nww(frac1[1], frac2[1]))
        new_numerator = int(frac1[0] * new_denominator / frac1[1] - frac2[0] * new_denominator / frac2[1])
        return fraction_reduce([new_numerator, new_denominator])
    return fraction_reduce([frac1[0] - frac2[0] , frac1[1]])

def mul_frac(frac1, frac2):         # frac1 * frac2
    fraction_check(frac1)
    fraction_check(frac2)
    return fraction_reduce([frac1[0] * frac2[0] , frac1[1] * frac2[1]])

def div_frac(frac1, frac2):         # frac1 / frac2
    fraction_check(frac1)
    fraction_check(frac2)
    return fraction_reduce([frac1[0] * frac2[1] , frac1[1] * frac2[0]])

def is_positive(frac):             # bool, czy dodatni
    fraction_check(frac)
    if frac[0] > 0 and frac[1] > 0:
        return True
    return False

def is_zero(frac):                 # bool, typu [0, x]
    fraction_check(frac)
    if frac[0] == 0:
        return True
    return False

def cmp_frac(frac1, frac2):         # -1 | 0 | +1
    fraction_check(frac1)
    fraction_check(frac2)
    subtraction = sub_frac(frac1, frac2)
    if subtraction[0] > 0:
        return 1
    elif subtraction[0] < 0:
        return -1
    else:
        return 0

def frac2float(frac):               # konwersja do float
    fraction_check(frac)
    if frac[0] == 0:
        return 0
    return frac[0] / frac[1]

# Funckje pomocniczne

def nwd(n, k):
    while k != 0:
        n, k = k, n % k
    return n

def nww(n, k):
    return n*k / nwd(n, k)

def fraction_check(frac):
    if not (isinstance(frac, list) and len(frac) == 2 and isinstance(frac[0], int) and isinstance(frac[1], int)):
        raise ValueError("Fraction musi być listą o dwóch elementach typu int.")

    if frac[1] == 0:
        raise ValueError("Mianownik ułamka nie może być zerem.")

    if frac[1] < 0:
        frac[0] *= -1
        frac[1] *= -1

def fraction_reduce(frac):
    fraction_check(frac)
    if frac[0] == 0:
        return [0, 1]  
    new_numerator = int(frac[0] / nwd(frac[0], frac[1]))
    new_denominator = int(frac[1] / nwd(frac[0], frac[1]))
    return [new_numerator, new_denominator] 

