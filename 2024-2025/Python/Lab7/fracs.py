# Python Language, Gr.1, LAB7 exercises implementation author: Daniel Szarek

from typing import Union

class Frac:
    """Klasa reprezentująca ułamki."""

    def __init__(self, x: Union[float, int] = 0, y: int = 1):
        # Sprawdzamy, czy y=0.
        if y == 0:
            raise ValueError("Mianownik ułamka nie może być zerem!")
        if not (isinstance(x, (float, int)) and isinstance(y, int)):
            raise TypeError("Jako argumenty ułamka przyjmujemy albo Float jako x albo Int jako x oraz y!")
        if isinstance(x, float):
            values = x.as_integer_ratio()
            self.x = values[0]
            self.y = values[1]
        else:
            self.x = x
            self.y = y
        if self.y < 0:
            self.x *= -1
            self.y *= -1
        self.__fraction_reduce__()

    def __str__(self) -> str:         # zwraca "x/y" lub "x" dla y=1
        if self.y == 1:
            return "{}".format(self.x)
        return "{}/{}".format(self.x, self.y)

    def __repr__(self) -> str:         # zwraca "Frac(x, y)"
        return "Frac({}, {})".format(self.x, self.y)

    # Py2
    def __cmp__(self, other: Union['Frac', int]) -> int:  # cmp(frac1, frac2)  
        if isinstance(other, Frac):
            diff = self.x * other.y - self.y * other.x
        else: 
            diff = self.x * 1 - self.y * other
        if diff < 0:
            return -1
        elif diff > 0:
            return 1
        else:
            return 0

    # Py2.7 i Py3
    def __eq__(self, other: Union['Frac', int]) -> bool:
        if isinstance(other, Frac):
            return self.x * other.y == self.y * other.x
        return self.x == other * self.y

    def __ne__(self, other: Union['Frac', int]) -> bool:
        return not self == other

    def __lt__(self, other: Union['Frac', int]) -> bool:
        if isinstance(other, Frac):
            return self.x * other.y < self.y * other.x
        return self.x < other * self.y

    def __le__(self, other: Union['Frac', int]) -> bool:
        if isinstance(other, Frac):
            return self.x * other.y <= self.y * other.x
        return self.x <= other * self.y

    def __gt__(self, other: Union['Frac', int]) -> bool:
        return not self <= other

    def __ge__(self, other: Union['Frac', int]) -> bool:
        return not self < other

    def __add__(self, other: Union['Frac', int]) -> 'Frac':  # frac1+frac2, frac+int
        if isinstance(other, Frac):
            new_denominator = self.__nww__(self.y, other.y)
            new_numerator = self.x * (new_denominator // self.y) + other.x * (new_denominator // other.y)
            result = Frac(new_numerator, new_denominator)
            result.__fraction_reduce__()
            return result
        return Frac(self.x + other * self.y, self.y)

    __radd__ = __add__              # int+frac

    def __sub__(self, other: Union['Frac', int]) -> 'Frac':  # frac1-frac2, frac-int
        if isinstance(other, Frac):
            new_denominator = self.__nww__(self.y, other.y)
            new_numerator = self.x * (new_denominator // self.y) - other.x * (new_denominator // other.y)
            result = Frac(new_numerator, new_denominator)
            result.__fraction_reduce__()
            return result
        return Frac(self.x - other * self.y, self.y)

    def __rsub__(self, other: int) -> 'Frac':      # int-frac
        # tutaj self jest frac, a other jest int!
        return Frac(self.y * other - self.x, self.y)

    def __mul__(self, other: Union['Frac', int]) -> 'Frac':  # frac1*frac2, frac*int
        if isinstance(other, Frac):
            result = Frac(self.x * other.x, self.y * other.y)
            result.__fraction_reduce__()
            return result
        return Frac(self.x * other, self.y)

    __rmul__ = __mul__              # int*frac

    def __div__(self, other: Union['Frac', int]) -> 'Frac':  # frac1/frac2, frac/int, Py2
        if isinstance(other, Frac):
            if other.x == 0:
                raise ZeroDivisionError("Nie można dzielić przez ułamek zerowy!")
            result = Frac(self.x * other.y, self.y * other.x)
        else:
            if other == 0:
                raise ZeroDivisionError("Nie można dzielić przez zero!")
            result = Frac(self.x, self.y * other)
        result.__fraction_reduce__()
        return result

    def __rdiv__(self, other: int) -> 'Frac': # int/frac, Py2
        if self.x == 0:
            raise ZeroDivisionError("Nie można dzielić przez zero!")
        result = Frac(self.y * other, self.x)
        result.__fraction_reduce__()
        return result
    
    __truediv__ = __div__  

    __rtruediv__ = __rdiv__ 

    # def __truediv__(self, other): pass   # frac1/frac2, frac/int, Py3

    # def __rtruediv__(self, other): pass   # int/frac, Py3

    # operatory jednoargumentowe
    def __pos__(self) -> 'Frac':  # +frac = (+1)*frac
        return self

    def __neg__(self) -> 'Frac':         # -frac = (-1)*frac
        return Frac(self.x * -1, self.y)

    def __invert__(self) -> 'Frac':      # odwrotnosc: ~frac
        return self / 1

    def __float__(self) -> float:       # float(frac)
        return float(self.x) / self.y

    def __hash__(self) -> int:
        return hash(float(self))   # immutable fracs
        # w Pythonie set([2]) == set([2.0])
        # chcemy set([2]) == set([Frac(2)])

    # Funckje pomocniczne

    def __nwd__(self, n: int, k: int) -> int:
        while k != 0:
            n, k = k, n % k
        return n

    def __nww__(self, n: int, k: int) -> int:
        return n*k // self.__nwd__(n, k)

    def __fraction_reduce__(self) -> None:
        if self.x == 0:
            self.y = 1
            return 
        nwd = self.__nwd__(self.x, self.y)
        self.x //= nwd
        self.y //= nwd
        return