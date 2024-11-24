# Python Language Gr.1, Project: Dense polynomials based on python lists
# Implementation, author: Daniel Szarek

from typing import Union, List, Dict
from itertools import zip_longest
import copy

class Poly:
    """Klasa implementująca wielomian gęsty na bazie listy python"""

    def __init__(self, coefficients: List[Union[int, float]]):
        """Konstruktor klasy wielomianu gęstego na bazie listy python (poly = Poly(coefficients))"""

        if not isinstance(coefficients, list):
            raise TypeError("Współczynniki wielomianu gęstego muszą być listą!")
        if not all(isinstance(x, (int, float)) for x in coefficients):
            raise ValueError("Każdy współczynnik wielomianu gęstego musi być liczbą (int lub float)!")
        self.coefficients = coefficients[:]
        while self.coefficients and self.coefficients[-1] == 0:
            self.coefficients.pop()

        # Indeks dla metody __next__
        self._index = 0

    def __add__(self, other: Union[int, float, 'Poly']) -> 'Poly':
        """Dodawanie wielomianów gęstych na bazie list python (poly1 + poly2) lub wielomianu gęstego na bazie listy python z liczbą całkowitą lub rzeczywistą po prawej stronie (poly + number)"""
        
        if isinstance(other, (int, float)):
            if self.is_zero:
                return Poly([other])
            result = copy.copy(self)
            result[0] += other
            return result
        elif isinstance(other, Poly):
            if self.is_zero:
                return copy.copy(other)
            if other.is_zero:
                return copy.copy(self)
            return Poly([x + y for x, y in zip_longest(self.coefficients, other.coefficients, fillvalue=0)])
        else:
            raise TypeError("Argument other musi być liczbą (int lub float)! albo wielomianem gęstym na bazie listy python (Poly)!")

    # Dodawanie wielomianów gęstych na bazie list python (poly2 + poly1) lub wielomianu gęstego na bazie listy python z liczbą całkowitą lub rzeczywistą po lewej stronie (number + poly)
    __radd__ = __add__

    def __sub__(self, other: Union[int, float, 'Poly']) -> 'Poly':
        """Odejmowanie wielomianów gęstych na bazie list python (poly1 - poly2) lub wielomianu gęstego na bazie listy python z liczbą całkowitą lub rzeczywistą po prawej stronie (poly - number)"""
        
        if isinstance(other, (int, float)):
            if self.is_zero:
                return Poly([-other])
            result = copy.copy(self)
            result[0] -= other
            return result
        elif isinstance(other, Poly):
            if self.is_zero:
                return Poly([-x for x in other.coefficients])
            if other.is_zero:
                return copy.copy(self)
            return Poly([x - y for x, y in zip_longest(self.coefficients, other.coefficients, fillvalue=0)])
        else:
            raise TypeError("Argument other musi być liczbą (int lub float)! albo wielomianem gęstym na bazie listy python (Poly)!")

    def __rsub__(self, number: Union[int, float]) -> 'Poly':
        """Odejmowanie wielomianu gęstego na bazie listy python z liczbą całkowitą lub rzeczywistą po lewej stronie (number - poly)"""

        if not isinstance(number, (int, float)):
            raise TypeError("Argument number musi być liczbą (int lub float)!")
        return Poly([number]) - self    

    def __mul__(self, other: Union[int, float, 'Poly']) -> 'Poly':
        """Mnożenie wielomianów gęstych na bazie list python (poly1 * poly2) lub wielomianu gęstego na bazie listy python z liczbą całkowitą lub rzeczywistą po prawej stronie (poly * number)"""
        
        if isinstance(other, (int, float)):
            if self.is_zero:
                return Poly([])
            return Poly([x * other for x in self.coefficients])
        elif isinstance(other, Poly):
            if self.is_zero or other.is_zero:
                return Poly([])
            self_size = len(self)
            other_size = len(other)
            result_coefficients = [0] * (self_size + other_size - 1)
            for indeks_self in range(self_size):
                for indeks_other in range(other_size):
                    result_coefficients[indeks_self + indeks_other] += self[indeks_self] * other[indeks_other]
            return Poly(result_coefficients)
        else:
            raise TypeError("Argument other musi być liczbą (int lub float)! albo wielomianem gęstym na bazie listy python (Poly)!")

    # Mnożenie wielomianów gęstych na bazie list python (poly2 * poly1) lub wielomianu gęstego na bazie listy python z liczbą całkowitą lub rzeczywistą po lewej stronie (number * poly)
    __rmul__ = __mul__

    def __eq__(self, other: 'Poly') -> bool:
        """Porównywanie identyczności wielomianów gęstych na bazie list python (poly1 == poly2)"""

        if not isinstance(other, Poly):
            raise TypeError("Argument other musi być wielomianem gęstym na bazie listy python (Poly)!")
        result = self - other
        if result.is_zero:
            return True
        return False

    def __ne__(self, other: 'Poly') -> bool:
        """Porównywanie sprzeczności wielomianów gęstych na bazie list python (poly1 != poly2)"""

        if not isinstance(other, Poly):
            raise TypeError("Argument other musi być wielomianem gęstym na bazie listy python (Poly)!")
        return not self == other

    def __str__(self) -> str:
        """Zwrócenie przyjaznej dla użytkownika reprezentacji wielomianu gęstego na bazie listy python (str(poly))"""

        if self.is_zero:
            return "Wielomian Zerowy"

        result = []
        for indeks, x in reversed(list(enumerate(self.coefficients))):
            if x == 0:
                continue
            if x > 0 and result:
                result.append(" + ")
            elif x < 0:
                result.append("- " if not result else " - ")
                x = -x 
            if indeks == 0:
                result.append("{}".format(x))
            elif indeks == 1:
                result.append("x" if x == 1 else "{}x".format(x))
            else:
                result.append("x^{}".format(indeks) if x == 1 else "{}x^{}".format(x, indeks))
        return "".join(result)

    def __repr__(self) -> str:
        """Zwrócenie oficjalnej reprezentacji wielomianu gęstego na bazie listy python (repr(poly))"""

        return "Poly({})".format(self.coefficients)

    def __pos__(self) -> 'Poly':
        """Zwrócenie dodatniej wartości wielomianu gęstego na bazie listy python (+poly)"""

        return copy.copy(self)

    def __neg__(self) -> 'Poly':
        """Zwrócenie negacji wartości wielomianu gęstego na bazie listy python (-poly)"""

        return Poly([-x for x in self.coefficients])

    def __getitem__(self, key: int) -> Union[int, float]:
        """Pobranie elementu o wskazanym indeksie, również ujemnym z wielomianu gęstego na bazie listy python (poly[key])"""

        if not isinstance(key, int):
            raise TypeError("Argument key musi być liczbą (int)!")
        if key < 0:
            key += len(self)
        if key < 0 or key >= len(self):
            raise ValueError("Argument key musi być liczbą (int) umożliwiającą pobranie wartości z listy python na podstawie której stworzony jest dany wielomian gęsty!")
        return self.coefficients[key]

    def __setitem__(self, key: int, value: Union[int, float]) -> None:
        """Wstawienie danego elementu o wskazanym indeksie, również ujemnym do wielomianu gęstego na bazie listy python (poly[key] = value)"""
        
        if not isinstance(key, int):
            raise TypeError("Argument key musi być liczbą (int)!")
        if not isinstance(value, (int, float)):
            raise TypeError("Argument value musi być liczbą (int lub float)!")
        if key < 0:
            key += len(self)
        if key < 0 or key >= len(self):
            raise ValueError("Argument key musi być liczbą (int) umożliwiającą ustawienie wartości z listy python na podstawie której stworzony jest dany wielomian gęsty!")
        self.coefficients[key] = value

    def __delitem__(self, key: int) -> None:
        """Usunięcie danego elementu o wskazanym indeksie, również ujemnym z wielomianu gęstego na bazie listy python (del poly[key])"""

        if not isinstance(key, int):
            raise TypeError("Argument key musi być liczbą (int)!")
        if key < 0:
            key += len(self)
        if key < 0 or key >= len(self):
            raise ValueError("Argument key musi być liczbą (int) umożliwiającą usunięcie wartości z listy python na podstawie której stworzony jest dany wielomian gęsty!")
        del self.coefficients[key]

    def __iter__(self) -> Union[int, float]:
        """Zwrócenie iteratora współczynników wielomianu gęstego na bazie listy python (iter(poly)"""

        self._index = 0
        return self

    def __next__(self) -> 'Poly':
        """Zwrócenie kolejnego współczynnika wielomianu gęstego na bazie listy python w trakcie iteracji (next(poly)"""

        if self._index >= len(self):
            raise StopIteration
        result = self[self._index]
        self._index += 1
        return result
    
    def __copy__(self) -> 'Poly':
        """Stworzenie płytkiej kopii wielomianu gęstego na bazie listy python (copy.copy(poly))"""

        return Poly(self.coefficients[:])

    def __deepcopy__(self, memo: Dict[int, object]) -> 'Poly':
        """Stworzenie głębokiej kopii wielomianu gęstego na bazie listy python (copy.deepcopy(poly))"""

        copied_coefficients = copy.deepcopy(self.coefficients, memo)
        return Poly(copied_coefficients)

    def __len__(self) -> int:
        """Zwrócenie długości wielomianu gęstego na bazie listy python (len(poly))"""
        
        return len(self.coefficients)

    def __pow__(self, degree: int) -> 'Poly':
        """Obliczenie potęgi wielomianu gęstego na bazie listy python o wskazanych stopniu potęgowania (poly**degree, pow(poly, degree)"""

        if not isinstance(degree, int):
            raise TypeError("Argument degree musi być liczbą (int)!")
        if degree < 0:
            raise ValueError("Argument degree musi być liczbą (int) większą od zera!")
        elif degree == 0:
            return Poly([1])
        elif degree == 1:
            return copy.copy(self)
        result = copy.copy(self)
        for _ in range(degree - 1):
            result *= self
        return result

    def __call__(self, x: Union[int, float, 'Poly']) -> Union[int, float, 'Poly']: 
        """Wywołanie obiektu jako funkcji, dla x typu int lub float to evaluate_horner, dla x typu Poly to combine (poly(x))"""

        if isinstance(x, (int, float)):
            return self.evaluate_horner(x)
        elif isinstance(x, Poly):
            return self.combine(x)
        else:
            raise TypeError("Argument x musi być liczbą (int lub float)!")
        
    def evaluate_horner(self, x: Union[int, float]) -> Union[int, float]:
        """Obliczanie wartości liczbowej wielomianu gęstego na bazie listy python schematem Hornera (poly.evaluate_horner(x))"""

        if not isinstance(x, (int, float)):
            raise TypeError("Argument x musi być liczbą (int lub float)!")
        result = 0
        for coef in reversed(self.coefficients):
            result = result * x + coef
        return result

    def combine(self, other: 'Poly') -> 'Poly':
        """Obliczenie złożenia wielomianów gęstych na bazie list python (poly1.combine(poly2))"""

        if not isinstance(other, Poly):
            raise TypeError("Argument other musi być instancją klasy Poly!")
        if self.is_zero:
            return Poly([])
        result = Poly([0])
        current_power = Poly([1])
        for x in self.coefficients:
            result += current_power * x
            current_power *= other
        return result        

    @property
    def is_zero(self) -> bool:
        """Zwrócenie czy wielomian gęsty na bazie listy python jest wielomianem zerowym (poly.is_zero)"""

        return not self.coefficients

    @property
    def degree(self) -> int:
        """Zwrócenie stopnia wielomianu gęstego na bazie listy python (poly.degree)"""

        return len(self) - 1

    @property
    def differentiate(self) -> 'Poly':
        """Obliczenie pochodnej wielomianu gęstęgo na bazie listy python (poly.differentiate)"""

        if self.is_zero:
            return Poly([])
        return Poly([indeks * self[indeks] for indeks in range(1, len(self))])
    
    @property
    def integrate(self) -> 'Poly':
        """Obliczenie całki nieoznaczonej wielomianu gęstęgo na bazie listy python (poly.integrate)"""

        if self.is_zero:
            return Poly([])

        # Stała całkowania C
        new_coefficients = [0]
        new_coefficients.extend(self[indeks] / (indeks + 1) for indeks in range(len(self)))
        return Poly(new_coefficients)