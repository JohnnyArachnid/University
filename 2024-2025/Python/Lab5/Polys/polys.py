# poly1(x) + poly2(x)
def add_poly(poly1, poly2):
    result = []
    if(len(poly1) > len(poly2)):
        result = [x for x in poly1]
        for indeks in range(len(poly2)):
            result[indeks] += poly2[indeks]
    else:
        result = [x for x in poly2]
        for indeks in range(len(poly1)):
            result[indeks] += poly1[indeks]
    return result

# poly1(x) - poly2(x)
def sub_poly(poly1, poly2):
    result = []
    if(len(poly1) > len(poly2)):
        result = [x for x in poly1]
        for indeks in range(len(poly2)):
            result[indeks] -= poly2[indeks]
    else:
        result = [-x for x in poly2]
        for indeks in range(len(poly1)):
            result[indeks] += poly1[indeks]
    return result        

# poly1(x) * poly2(x)
def mul_poly(poly1, poly2):
    length = len(poly1) + len(poly2) - 1
    result = [0] * length
    for i, a in enumerate(poly1):
        for j, b in enumerate(poly2):
            result[i + j] += a * b
    return result


# bool, [0], [0,0], itp.
def is_zero(poly):
    return all(x == 0 for x in poly)

# bool, porównywanie poly1(x) == poly2(x)
def eq_poly(poly1, poly2):
    if is_zero(poly1) and is_zero(poly2):
        return True
    if(len(poly1) > len(poly2)):
        for indeks in range(len(poly2)):
            if poly1[indeks] != poly2[indeks]:
                return False
        if is_zero(poly1[len(poly2):]):
            return True
        return False
    else:
        for indeks in range(len(poly1)):
            if poly1[indeks] != poly2[indeks]:
                return False
        if is_zero(poly2[len(poly1):]):
            return True
        return False

# poly(x0), algorytm Hornera
def eval_poly(poly, x0):
    result = 0
    for x in reversed(poly):
        result = result * x0 + x
    return result

# poly1(poly2(x)), trudne!
def combine_poly(poly1, poly2):
    result = [0]
    temp_poly = [1]
    for x in poly1:
        term_poly = mul_poly(temp_poly, [x])
        result = add_poly(result, term_poly)
        temp_poly = mul_poly(temp_poly, poly2)
    return result    

# poly(x) ** n
def pow_poly(poly, n):
    result = [1]
    for _ in range(n):
        result = mul_poly(result, poly)
    return result            

# pochodna wielomianu
def diff_poly(poly):
    result = [poly[i] * i for i in range(1, len(poly))]
    return result            


