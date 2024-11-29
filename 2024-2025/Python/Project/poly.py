# Python Language Gr.1, Project: Dense polynomials based on python lists
# Implementation, author: Daniel Szarek

from typing import Union, Iterable
from itertools import zip_longest

# Oznaczenie wspieranych typów generycznych, w przyszłości możliwych
# o rozszerzenie o np. Fraction, czy Complex
scalar_types = (int, float)

class Poly:
    """Klasa implementująca wielomian gęsty na bazie obiektu iterowanego
    (domyślnie lista) python"""

    # Statyczne deklaracja typu, nie ma możliwości dynamicznego poinformowania
    # z wykorzystaniem zmiennej scalar_types, stąd zostawiam aktualną
    # implementację z Union[int, float]
    def __init__(self, coefficients: Iterable[Union[int, float]]):
        """Konstruktor klasy wielomianu gęstego na bazie obiektu iterowanego
        (domyślnie lista) python (poly = Poly(coefficients))"""

        if not isinstance(coefficients, Iterable):
            raise TypeError("Współczynniki wielomianu gęstego muszą być iterowalne \
            (domyślnie lista)!")
        if not all(isinstance(x, scalar_types) for x in coefficients):
            raise ValueError("Każdy współczynnik wielomianu gęstego \
            musi być liczbą wspierającą typ ze zmiennej scalar_types!")
        self.coefficients = list(coefficients)
        while self.coefficients and self.coefficients[-1] == 0:
            self.coefficients.pop()

        # Indeks dla metody __next__
        self._index = 0

    def __add__(self, other: Union[int, float, 'Poly']) -> 'Poly':
        """Dodawanie wielomianów gęstych na bazie obiektu iterowanego
        (domyślnie lista) (poly1 + poly2) lub wielomianu gęstego na bazie obiektu
        iterowanego (domyślnie lista) python z np. liczbą całkowitą
        lub rzeczywistą po prawej stronie (poly + number)"""
        
        if isinstance(other, scalar_types):
            if self.is_zero:
                return Poly([other])
            result = self.copy()
            result[0] += other
            return result
        elif isinstance(other, Poly):
            if self.is_zero:
                return other.copy()
            if other.is_zero:
                return self.copy()
            return Poly([x + y for x, y in zip_longest(
                self.coefficients, other.coefficients, fillvalue=0)])
        else:
            raise TypeError("Argument other musi być liczbą wspierającą typ ze \
            zmiennej scalar_types! albo wielomianem gęstym na bazie obiektu iterowanego \
            (domyślnie lista) python (Poly)!")

    # Dodawanie wielomianów gęstych na bazie obiektu iterowanego
    # (domyślnie lista) python (poly2 + poly1) lub wielomianu gęstego na bazie 
    # obiektu iterowanego (domyślnie lista) python z np. liczbą całkowitą
    # lub rzeczywistą po lewej stronie (number + poly)
    __radd__ = __add__

    def __sub__(self, other: Union[int, float, 'Poly']) -> 'Poly':
        """Odejmowanie wielomianów gęstych na bazie obiektu iterowanego
        (domyślnie lista) python (poly1 - poly2) lub wielomianu gęstego na bazie 
        obiektu iterowanego (domyślnie lista) python z np. liczbą całkowitą
        lub rzeczywistą po prawej stronie (poly - number)"""
        
        if isinstance(other, scalar_types):
            if self.is_zero:
                return Poly([-other])
            result = self.copy()
            result[0] -= other
            return result
        elif isinstance(other, Poly):
            if self.is_zero:
                return Poly([-x for x in other.coefficients])
            if other.is_zero:
                return self.copy()
            return Poly([x - y for x, y in zip_longest(
                self.coefficients, other.coefficients, fillvalue=0
                )])
        else:
            raise TypeError("Argument other musi być liczbą wspierającą typ ze \
            zmiennej scalar_types! albo wielomianem gęstym na bazie obiektu iterowanego \
            (domyślnie lista) python (Poly)!")

    def __rsub__(self, number: Union[int, float]) -> 'Poly':
        """Odejmowanie wielomianu gęstego na bazie obiektu iterowanego
        (domyślnie lista) python z np. liczbą całkowitą
        lub rzeczywistą po lewej stronie (number - poly)"""

        if not isinstance(number, scalar_types):
            raise TypeError("Argument number musi być liczbą wspierającą typ ze \
            zmiennej scalar_types!")
        return Poly([number]) - self    

    def __mul__(self, other: Union[int, float, 'Poly']) -> 'Poly':
        """Mnożenie wielomianów gęstych na bazie obiektu iterowanego
        (domyślnie lista) python (poly1 * poly2) lub wielomianu gęstego na bazie 
        obiektu iterowanego (domyślnie lista) python z np. liczbą całkowitą
        lub rzeczywistą po prawej stronie (poly * number)"""
        
        if isinstance(other, scalar_types):
            if self.is_zero:
                return Poly([])
            return Poly([x * other for x in self.coefficients])
        elif isinstance(other, Poly):
            if self.is_zero or other.is_zero:
                return Poly([])
            self_size = len(self.coefficients)
            other_size = len(other.coefficients)
            result_coefficients = [0] * (self_size + other_size - 1)
            for i_self in range(self_size):
                for i_other in range(other_size):
                    result_coefficients[i_self + i_other] += self[i_self] * other[i_other]
            return Poly(result_coefficients)
        else:
            raise TypeError("Argument other musi być liczbą wspierającą typ ze \
            zmiennej scalar_types! albo wielomianem gęstym na bazie obiektu iterowanego \
            (domyślnie lista) python (Poly)!")

    # Mnożenie wielomianów gęstych na bazie obiektu iterowanego 
    # (domyślnie lista) python (poly2 * poly1) lub wielomianu gęstego na bazie
    # obiektu iterowanego (domyślnie lista) python z np. liczbą całkowitą 
    # lub rzeczywistą po lewej stronie (number * poly)
    __rmul__ = __mul__

    def __eq__(self, other: 'Poly') -> bool:
        """Porównywanie identyczności wielomianów gęstych na bazie 
        obiektu iterowanego (domyślnie lista) python (poly1 == poly2)"""

        if not isinstance(other, Poly):
            raise TypeError("Argument other musi być wielomianem gęstym na bazie \
            obiektu iterowanego (domyślnie lista) python (Poly)!")
        result = self - other
        if result.is_zero:
            return True
        return False

    def __ne__(self, other: 'Poly') -> bool:
        """Porównywanie sprzeczności wielomianów gęstych na bazie 
        obiektu iterowanego (domyślnie lista) python (poly1 != poly2)"""

        if not isinstance(other, Poly):
            raise TypeError("Argument other musi być wielomianem gęstym na bazie \
            obiektu iterowanego (domyślnie lista) python (Poly)!")
        return not self == other

    def __str__(self) -> str:
        """Zwrócenie przyjaznej dla użytkownika reprezentacji wielomianu gęstego
        na bazie obiektu iterowanego (domyślnie lista) python (str(poly))"""

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
        """Zwrócenie oficjalnej reprezentacji wielomianu gęstego 
        na bazie obiektu iterowanego (domyślnie lista) python (repr(poly))"""

        return "Poly({})".format(self.coefficients)

    def __pos__(self) -> 'Poly':
        """Zwrócenie dodatniej wartości wielomianu gęstego 
        na bazie obiektu iterowanego (domyślnie lista) python (+poly)"""

        return self.copy()

    def __neg__(self) -> 'Poly':
        """Zwrócenie negacji wartości wielomianu gęstego 
        na bazie obiektu iterowanego (domyślnie lista) python (-poly)"""

        return Poly([-x for x in self.coefficients])

    def __getitem__(self, key: int) -> Union[int, float]:
        """Pobranie elementu o wskazanym indeksie, również ujemnym z wielomianu gęstego
        na bazie obiektu iterowanego (domyślnie lista) python (poly[key])"""

        if not isinstance(key, int):
            raise TypeError("Argument key musi być liczbą (int)!")
        if key < 0:
            key += len(self.coefficients)
        if key < 0 or key >= len(self.coefficients):
            raise ValueError("Argument key musi być liczbą (int) umożliwiającą pobranie \
            wartości z obiektu iterowanego (domyślnie lista) python na podstawie \
            której stworzony jest dany wielomian gęsty!")
        return self.coefficients[key]

    def __setitem__(self, key: int, value: Union[int, float]) -> None:
        """Wstawienie danego elementu o wskazanym indeksie, również ujemnym do 
        wielomianu gęstego na bazie obiektu iterowanego (domyślnie lista)
        python (poly[key] = value)"""
        
        if not isinstance(key, int):
            raise TypeError("Argument key musi być liczbą (int)!")
        if not isinstance(value, scalar_types):
            raise TypeError("Argument value musi być liczbą wspierającą \
            typ ze zmiennej scalar_types!")
        if key < 0:
            key += len(self.coefficients)
        if key < 0 or key >= len(self.coefficients):
            raise ValueError("Argument key musi być liczbą (int) umożliwiającą ustawienie \
            wartości z obiektu iterowanego (domyślnie lista) python na podstawie \
            której stworzony jest dany wielomian gęsty!")
        self.coefficients[key] = value

    def __delitem__(self, key: int) -> None:
        """Usunięcie danego elementu o wskazanym indeksie, również ujemnym 
        z wielomianu gęstego na bazie obiektu iterowanego 
        (domyślnie lista) python (del poly[key])"""

        if not isinstance(key, int):
            raise TypeError("Argument key musi być liczbą (int)!")
        if key < 0:
            key += len(self.coefficients)
        if key < 0 or key >= len(self.coefficients):
            raise ValueError("Argument key musi być liczbą (int) umożliwiającą usunięcie \
            wartości z obiektu iterowanego (domyślnie lista) python \
            na podstawie której stworzony jest dany wielomian gęsty!")
        if key == -1:
            self.coefficients.pop()
        if self.coefficients[key] == 0:
            return
        self.coefficients[key] = 0

    def __iter__(self) -> Union[int, float]:
        """Zwrócenie iteratora współczynników wielomianu gęstego 
        na bazie obiektu iterowanego (domyślnie lista) python (iter(poly)"""

        self._index = 0
        return self

    def __next__(self) -> 'Poly':
        """Zwrócenie kolejnego współczynnika wielomianu gęstego na bazie obiektu 
        iterowanego (domyślnie lista) python w trakcie iteracji (next(poly)"""

        if self._index >= len(self.coefficients):
            raise StopIteration
        result = self[self._index]
        self._index += 1
        return result

    def __len__(self) -> int:
        """Zwrócenie długości wielomianu gęstego na bazie obiektu 
        iterowanego (domyślnie lista) python (len(poly))"""
        
        return len([x for x in self.coefficients if x != 0])

    def __pow__(self, degree: int) -> 'Poly':
        """Obliczenie potęgi wielomianu gęstego na bazie obiektu iterowanego 
        (domyślnie lista) python o wskazanych stopniu potęgowania 
        (poly**degree, pow(poly, degree)"""

        if not isinstance(degree, int):
            raise TypeError("Argument degree musi być liczbą (int)!")
        if degree < 0:
            raise ValueError("Argument degree musi być liczbą (int) większą od zera!")
        elif degree == 0:
            return Poly([1])
        elif degree == 1:
            return self.copy()
        result = self.copy()
        for _ in range(degree - 1):
            result *= self
        return result

    def __call__(self, x: Union[int, float, 'Poly']) -> Union[int, float, 'Poly']: 
        """Wywołanie obiektu jako funkcji, dla x typu int lub float 
        do evaluate_horner, dla x typu Poly to combine (poly(x))"""

        if isinstance(x, scalar_types):
            return self.evaluate_horner(x)
        elif isinstance(x, Poly):
            return self.combine(x)
        else:
            raise TypeError("Argument x musi być liczbą wspierającą \
            typ ze zmiennej scalar_types!")
        
    def evaluate_horner(self, x: Union[int, float]) -> Union[int, float]:
        """Obliczanie wartości liczbowej wielomianu gęstego na bazie 
        obiektu iterowanego (domyślnie lista) python 
        schematem Hornera (poly.evaluate_horner(x))"""

        if not isinstance(x, scalar_types):
            raise TypeError("Argument x musi być liczbą wspierającą \
            typ ze zmiennej scalar_types!")
        result = 0
        for coef in reversed(self.coefficients):
            result = result * x + coef
        return result

    def combine(self, other: 'Poly') -> 'Poly':
        """Obliczenie złożenia wielomianów gęstych na bazie 
        obiektu iterowanego (domyślnie lista) python (poly1.combine(poly2))"""

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

    def differentiate(self) -> 'Poly':
        """Obliczenie pochodnej wielomianu gęstęgo na bazie obiektu 
        iterowanego (domyślnie lista) python (poly.differentiate)"""

        if self.is_zero:
            return Poly([])
        return Poly([indeks * self[indeks] for indeks in range(1, len(self.coefficients))])
    
    def integrate(self) -> 'Poly':
        """Obliczenie całki nieoznaczonej wielomianu gęstęgo na bazie obiektu 
        iterowanego (domyślnie lista) python (poly.integrate)"""

        if self.is_zero:
            return Poly([])

        # Stała całkowania C
        new_coefficients = [0]
        new_coefficients.extend(self[indeks] / (indeks + 1) for indeks in range(
            len(self.coefficients)))
        return Poly(new_coefficients)

    def copy(self) -> 'Poly':
        """Stworzenie płytkiej kopii wielomianu gęstego na bazie obiektu
        iterowanego (domyślnie lista) python (self.copy())"""

        return Poly(self.coefficients[:])       

    @property
    def is_zero(self) -> bool:
        """Zwrócenie czy wielomian gęsty na bazie obiektu iterowanego 
        (domyślnie lista) python jest wielomianem zerowym (poly.is_zero)"""

        return not self.coefficients

    @property
    def degree(self) -> int:
        """Zwrócenie stopnia wielomianu gęstego na bazie obiektu 
        iterowanego (domyślnie lista) python (poly.degree)"""

        return len(self.coefficients) - 1