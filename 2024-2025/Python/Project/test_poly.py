# Python Language Gr.1, Project: Dense polynomials based on python lists
# Tests, author: Daniel Szarek

from poly import *
import pytest

class TestPoly:
    """Klasa implementująca testy dla mojej klasy Poly implementującej wielomian
    gęsty na obiektu iterowanego (domyślnie lista) 
    listy python z wykorzystaniem modułu pytest"""

    # Inicjalizacja różnych przykładów wielomianów gęstych na bazie obiektu
    # iterowanego (domyślnie lista) python mojej klasy Poly do testów
    @pytest.fixture(scope="class")
    def ex(self):
        return {
            "zero": Poly([]),
            "constant_1": Poly([5]),
            "constant_2": Poly([-3]),
            "linear_1": Poly([2, -1]),
            "linear_2": Poly([-4, 7]),
            "quadratic_1": Poly([-1, 3, -2]),
            "quadratic_2": Poly([5, -6, 1]),
            "cubic_1": Poly([3, -4, 1, -2]),
            "cubic_2": Poly([-2, 3, -1, 4]),
        }
    
    # Testowanie metody __init__ mojej klasy Poly
    def test_init(self, ex):
        assert ex["linear_1"] == Poly([2, -1])
        assert ex["quadratic_1"] == Poly([-1, 3, -2, 0, 0, 0])
        assert ex["cubic_1"] == Poly((3, -4, 1, -2, 0))
        with pytest.raises(TypeError):
            _ = Poly(1)
        with pytest.raises(ValueError):
            _ = Poly(["a", "b", 12, "d"])

    # Testowanie metody __add__ mojej klasy Poly
    def test_addition(self, ex):
        assert ex["linear_1"] + ex["linear_2"] == Poly([-2, 6])
        assert ex["quadratic_1"] + ex["constant_1"] == Poly([4, 3, -2])
        assert ex["cubic_1"] + ex["zero"] == Poly([3, -4, 1, -2])
        assert ex["linear_2"] + 2 == Poly([-2, 7])
        assert 5 + ex["cubic_1"] == Poly([8, -4, 1, -2])
        with pytest.raises(TypeError):
            _ = ex["linear_1"] + "test"

    # Testowanie metody __sub__ mojej klasy Poly
    def test_subtraction(self, ex):
        assert ex["linear_2"] - ex["linear_1"] == Poly([-6, 8])
        assert ex["quadratic_2"] - ex["constant_2"] == Poly([8, -6, 1])
        assert ex["cubic_2"] - ex["zero"] == Poly([-2, 3, -1, 4])
        assert ex["linear_1"] - 4 == Poly([-2, -1])
        assert 12 - ex["cubic_2"] == Poly([14, -3, 1, -4])
        with pytest.raises(TypeError):
            _ = ex["linear_1"] - "test"

    # Testowanie metody __mul__ mojej klasy Poly
    def test_multiplication(self, ex):
        assert ex["constant_1"] * ex["constant_2"] == Poly([-15])
        assert ex["quadratic_2"] * ex["linear_1"] == Poly([10, -17, 8, -1])
        assert ex["cubic_1"] * ex["zero"] == Poly([])
        assert ex["linear_2"] * -6 == Poly([24, -42])
        assert 6 * ex["cubic_1"] == Poly([18, -24, 6, -12])
        with pytest.raises(TypeError):
            _ = ex["linear_1"] * "test"

    # Testowanie metod __eq__ i __ne__ mojej klasy Poly
    def test_equality(self, ex):
        assert ex["linear_1"] == Poly([2, -1])
        assert not ex["quadratic_1"] == ex["quadratic_2"]
        assert ex["zero"] != ex["constant_1"]
        assert not ex["cubic_1"] != Poly([3, -4, 1, -2])
        with pytest.raises(TypeError):
            _ = ex["linear_1"] == "test"
        with pytest.raises(TypeError):
            _ = ex["linear_1"] != "test"

    # Testowanie metod __str__ i __repr__ mojej klasy Poly
    def test_str_repr(self, ex):
        assert str(ex["zero"]) == "Wielomian Zerowy"
        assert str(ex["constant_1"]) == "5"
        assert str(ex["linear_1"]) == "- x + 2"
        assert str(ex["quadratic_1"]) == "- 2x^2 + 3x - 1"
        assert str(ex["cubic_1"]) == "- 2x^3 + x^2 - 4x + 3"
        assert repr(ex["zero"]) == "Poly([])"
        assert repr(ex["constant_2"]) == "Poly([-3])"
        assert repr(ex["linear_2"]) == "Poly([-4, 7])"
        assert repr(ex["quadratic_2"]) == "Poly([5, -6, 1])"
        assert repr(ex["cubic_2"]) == "Poly([-2, 3, -1, 4])"

    # Testowanie metod __pos__ i __neg__ mojej klasy Poly
    def test_pos_neg(self, ex):
        assert +ex["quadratic_1"] == Poly([-1, 3, -2])
        assert +ex["zero"] == Poly([])
        assert -ex["quadratic_2"] == Poly([-5, 6, -1])
        assert -ex["zero"] == Poly([])

    # Testowanie metody __getitem__ mojej klasy Poly
    def test_getitem(self, ex):
        assert ex["cubic_1"][0] == 3
        assert ex["cubic_1"][1] == -4
        assert ex["cubic_1"][-1] == -2
        with pytest.raises(TypeError):
            _ = ex["linear_1"]["test"]
        with pytest.raises(ValueError):
            _ = ex["linear_1"][10]
        with pytest.raises(ValueError):
            _ = ex["linear_1"][-10]

    # Testowanie metody __setitem__ mojej klasy Poly
    def test_setitem(self):
        test = Poly([1, 2, 3, 4, 5])
        test[0] = 42
        test[1] = -21
        test[-1] = 10
        assert test[0] == 42
        assert test[1] == -21
        assert test[-1] == 10
        with pytest.raises(TypeError):
            test["test"] = 5
        with pytest.raises(TypeError):
            test[3] = "test"
        with pytest.raises(ValueError):
            test[10] = 5
        with pytest.raises(ValueError):
            test[-10] = 5

    # Testowanie metod __delitem__ mojej klasy Poly
    def test_delitem(self):
        test = Poly([1, 2, 3, 4, 5])
        del test[0]
        assert test == Poly([0, 2, 3, 4, 5])
        del test[1]
        assert test == Poly([0, 0, 3, 4, 5])
        del test[-1]
        assert test == Poly([0, 0, 3, 4])
        with pytest.raises(TypeError):
            del test["test"]
        with pytest.raises(ValueError):
            del test[10]
        with pytest.raises(ValueError):
            del test[-10]

    # Testowanie metod __iter__ i __next__ mojej klasy Poly
    def test_iterator(self, ex):
        test = iter(ex["quadratic_1"])
        assert next(test) == -1
        assert next(test) == 3
        assert next(test) == -2
        with pytest.raises(StopIteration):
            next(test)

    # Testowanie metody __len__ mojej klasy Poly
    def test_len(self, ex):
        test = Poly([1, 0, 2, 0, 3, 0])
        assert len(ex["cubic_1"]) == 4
        assert len(ex["zero"]) == 0
        assert len(test) == 3

    # Testowanie metody __pow__ mojej klasy Poly
    def test_power(self, ex):
        assert pow(ex["cubic_2"], 1) == Poly([-2, 3, -1, 4])
        assert ex["quadratic_1"] ** 2 == Poly([1, -6, 13, -12, 4])
        assert pow(ex["linear_2"], 3) == Poly([-64, 336, -588, 343])
        assert ex["constant_1"] ** 4 == Poly([625])
        assert pow(ex["zero"], 5) == Poly([])
        with pytest.raises(TypeError):
            _ = ex["linear_1"] ** "test"
        with pytest.raises(ValueError):
            _ = ex["linear_1"] ** -20

    # Testowanie metody __call__ mojej klasy Poly
    def test_call(self, ex):
        assert ex["constant_1"](1) == 5
        assert ex["constant_1"](ex["constant_2"]) == Poly([5])
        with pytest.raises(TypeError):
            _ = ex["linear_1"]("test")

    # Testowanie metody evaluate_horner(x) mojej klasy Poly
    def test_evaluation(self, ex):
        assert ex["constant_1"].evaluate_horner(42) == 5
        assert ex["linear_1"].evaluate_horner(2) == 0
        assert ex["quadratic_1"].evaluate_horner(-1) == -6
        assert ex["cubic_1"].evaluate_horner(1) == -2
        assert ex["zero"].evaluate_horner(100) == 0
        with pytest.raises(TypeError):
            ex["linear_1"].evaluate_horner("test")

    # Testowanie metody combine(poly) mojej klasy Poly
    def test_combination(self, ex):
        assert ex["linear_2"].combine(ex["constant_1"]) == Poly([31])
        assert ex["quadratic_1"].combine(ex["linear_1"]) == Poly([-3, 5, -2])
        assert ex["cubic_1"].combine(ex["quadratic_2"]) == Poly(
            [-242, 864, -1188, 780, -245, 36, -2])
        assert ex["zero"].combine(ex["linear_1"]) == Poly([])
        with pytest.raises(TypeError):
            ex["linear_1"].combine("test")

    # Testowanie metody differentiate() mojej klasy Poly
    def test_differentiation(self, ex):
        assert ex["zero"].differentiate() == Poly([])
        assert ex["constant_1"].differentiate() == Poly([0])
        assert ex["linear_1"].differentiate() == Poly([-1])
        assert ex["quadratic_1"].differentiate() == Poly([3, -4])
        assert ex["cubic_1"].differentiate() == Poly([-4, 2, -6])

    # Testowanie metody integrate() mojej klasy Poly
    def test_integration(self, ex):
        assert ex["zero"].integrate() == Poly([])
        assert ex["constant_2"].integrate() == Poly([0, -3])
        assert ex["linear_2"].integrate() == Poly([0, -4, 7/2])
        assert ex["quadratic_2"].integrate() == Poly([0, 5, -3, 1/3])
        assert ex["cubic_2"].integrate() == Poly([0, -2, 3/2, -1/3, 1])

    # Testowanie metody copy() mojej klasy Poly
    def test_copy(self):
        test = Poly([-1, 5, 2.5, -16, 8])
        test1 = test.copy()
        assert test1 == test
        assert test1 is not test
        test1[0] = 0
        assert test1 != Poly([-1, 5, 2.5, -16, 8])

    # Testowanie właściwości is_zero mojej klasy Poly
    def test_is_zero(self, ex):
        assert ex["zero"].is_zero
        assert not ex["constant_1"].is_zero

    # Testowanie właściwości degree mojej klasy Poly
    def test_degree(self, ex):
        assert ex["cubic_2"].degree == 3
        assert ex["zero"].degree == -1
