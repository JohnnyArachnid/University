# Python Language Gr.1, Project: Dense polynomials based on python lists
# Tests, author: Daniel Szarek

from poly import *
import pytest

class TestPoly:
    """Klasa implementująca testy dla mojej klasy Poly implementującej wielomian gęsty na bazie listy python z wykorzystaniem modułu pytest"""

    @pytest.fixture(scope="class")
    def polynomials_examples(self):
        """Inicjalizacja różnych przykładów wielomianów gęstych na bazie listy python mojej klasy Poly do testów"""

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
    
    def test_init(self, polynomials_examples):
        """Testowanie metody __init__ mojej klasy Poly"""

        assert polynomials_examples["linear_1"] == Poly([2, -1])
        assert polynomials_examples["quadratic_1"] == Poly([-1, 3, -2, 0, 0, 0])
        with pytest.raises(TypeError):
            _ = Poly(1)
        with pytest.raises(ValueError):
            _ = Poly(["a", "b", 12, "d"])

    def test_addition(self, polynomials_examples):
        """Testowanie metody __add__ mojej klasy Poly"""

        assert polynomials_examples["linear_1"] + polynomials_examples["linear_2"] == Poly([-2, 6])
        assert polynomials_examples["quadratic_1"] + polynomials_examples["constant_1"] == Poly([4, 3, -2])
        assert polynomials_examples["cubic_1"] + polynomials_examples["zero"] == Poly([3, -4, 1, -2])
        assert polynomials_examples["linear_2"] + 2 == Poly([-2, 7])
        assert 5 + polynomials_examples["cubic_1"] == Poly([8, -4, 1, -2])
        with pytest.raises(TypeError):
            _ = polynomials_examples["linear_1"] + "test"

    def test_subtraction(self, polynomials_examples):
        """Testowanie metody __sub__ mojej klasy Poly"""

        assert polynomials_examples["linear_2"] - polynomials_examples["linear_1"] == Poly([-6, 8])
        assert polynomials_examples["quadratic_2"] - polynomials_examples["constant_2"] == Poly([8, -6, 1])
        assert polynomials_examples["cubic_2"] - polynomials_examples["zero"] == Poly([-2, 3, -1, 4])
        assert polynomials_examples["linear_1"] - 4 == Poly([-2, -1])
        assert 12 - polynomials_examples["cubic_2"] == Poly([14, -3, 1, -4])
        with pytest.raises(TypeError):
            _ = polynomials_examples["linear_1"] - "test"

    def test_multiplication(self, polynomials_examples):
        """Testowanie metody __mul__ mojej klasy Poly"""

        assert polynomials_examples["constant_1"] * polynomials_examples["constant_2"] == Poly([-15])
        assert polynomials_examples["quadratic_2"] * polynomials_examples["linear_1"] == Poly([10, -17, 8, -1])
        assert polynomials_examples["cubic_1"] * polynomials_examples["zero"] == Poly([])
        assert polynomials_examples["linear_2"] * -6 == Poly([24, -42])
        assert 6 * polynomials_examples["cubic_1"] == Poly([18, -24, 6, -12])
        with pytest.raises(TypeError):
            _ = polynomials_examples["linear_1"] * "test"

    def test_equality(self, polynomials_examples):
        """Testowanie metod __eq__ i __ne__ mojej klasy Poly"""

        assert polynomials_examples["linear_1"] == Poly([2, -1])
        assert not polynomials_examples["quadratic_1"] == polynomials_examples["quadratic_2"]
        assert polynomials_examples["zero"] != polynomials_examples["constant_1"]
        assert not polynomials_examples["cubic_1"] != Poly([3, -4, 1, -2])
        with pytest.raises(TypeError):
            _ = polynomials_examples["linear_1"] == "test"
        with pytest.raises(TypeError):
            _ = polynomials_examples["linear_1"] != "test"

    def test_str_repr(self, polynomials_examples):
        """Testowanie metod __str__ i __repr__ mojej klasy Poly"""

        assert str(polynomials_examples["zero"]) == "Wielomian Zerowy"
        assert str(polynomials_examples["constant_1"]) == "5"
        assert str(polynomials_examples["linear_1"]) == "- x + 2"
        assert str(polynomials_examples["quadratic_1"]) == "- 2x^2 + 3x - 1"
        assert str(polynomials_examples["cubic_1"]) == "- 2x^3 + x^2 - 4x + 3"
        assert repr(polynomials_examples["zero"]) == "Poly([])"
        assert repr(polynomials_examples["constant_2"]) == "Poly([-3])"
        assert repr(polynomials_examples["linear_2"]) == "Poly([-4, 7])"
        assert repr(polynomials_examples["quadratic_2"]) == "Poly([5, -6, 1])"
        assert repr(polynomials_examples["cubic_2"]) == "Poly([-2, 3, -1, 4])"

    def test_pos_neg(self, polynomials_examples):
        """Testowanie metod __pos__ i __neg__ mojej klasy Poly"""

        assert +polynomials_examples["quadratic_1"] == Poly([-1, 3, -2])
        assert +polynomials_examples["zero"] == Poly([])
        assert -polynomials_examples["quadratic_2"] == Poly([-5, 6, -1])
        assert -polynomials_examples["zero"] == Poly([])

    def test_getitem(self, polynomials_examples):
        """Testowanie metody __getitem__ mojej klasy Poly"""

        assert polynomials_examples["cubic_1"][0] == 3
        assert polynomials_examples["cubic_1"][1] == -4
        assert polynomials_examples["cubic_1"][-1] == -2
        with pytest.raises(TypeError):
            _ = polynomials_examples["linear_1"]["test"]
        with pytest.raises(ValueError):
            _ = polynomials_examples["linear_1"][10]
        with pytest.raises(ValueError):
            _ = polynomials_examples["linear_1"][-10]

    def test_setitem(self):
        """Testowanie metody __setitem__ mojej klasy Poly"""

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

    def test_delitem(self):
        """Testowanie metod __delitem__ mojej klasy Poly"""

        test = Poly([1, 2, 3, 4, 5])
        del test[0]
        assert test == Poly([2, 3, 4, 5])
        del test[1]
        assert test == Poly([2, 4, 5])
        del test[-1]
        assert test == Poly([2, 4])
        with pytest.raises(TypeError):
            del test["test"]
        with pytest.raises(ValueError):
            del test[10]
        with pytest.raises(ValueError):
            del test[-10]

    def test_iterator(self, polynomials_examples):
        """Testowanie metod __iter__ i __next__ mojej klasy Poly"""

        test = iter(polynomials_examples["quadratic_1"])
        assert next(test) == -1
        assert next(test) == 3
        assert next(test) == -2
        with pytest.raises(StopIteration):
            next(test)

    def test_copy_methods(self, polynomials_examples):
        """Testowanie metod __copy__ i __deepcopy__ mojej klasy Poly"""

        test = Poly([-1, 5, 2.5, -16, 8])
        test1 = copy.copy(test)
        assert test1 == test
        assert test1 is not test
        test2 = copy.deepcopy(polynomials_examples["quadratic_2"])
        assert test2 == polynomials_examples["quadratic_2"]
        assert test2 is not polynomials_examples["quadratic_2"]
        test2[0] = 0
        assert test2 != polynomials_examples["quadratic_2"]

    def test_len(self, polynomials_examples):
        """Testowanie metody __len__ mojej klasy Poly"""

        assert len(polynomials_examples["cubic_1"]) == 4
        assert len(polynomials_examples["zero"]) == 0

    def test_power(self, polynomials_examples):
        """Testowanie metody __pow__ mojej klasy Poly"""

        assert pow(polynomials_examples["cubic_2"], 1) == Poly([-2, 3, -1, 4])
        assert polynomials_examples["quadratic_1"] ** 2 == Poly([1, -6, 13, -12, 4])
        assert pow(polynomials_examples["linear_2"], 3) == Poly([-64, 336, -588, 343])
        assert polynomials_examples["constant_1"] ** 4 == Poly([625])
        assert pow(polynomials_examples["zero"], 5) == Poly([])
        with pytest.raises(TypeError):
            _ = polynomials_examples["linear_1"] ** "test"
        with pytest.raises(ValueError):
            _ = polynomials_examples["linear_1"] ** -20

    def test_call(self, polynomials_examples):
        """Testowanie metody __call__ mojej klasy Poly"""

        assert polynomials_examples["constant_1"](1) == 5
        assert polynomials_examples["constant_1"](polynomials_examples["constant_2"]) == Poly([5])
        with pytest.raises(TypeError):
            _ = polynomials_examples["linear_1"]("test")

    def test_evaluation(self, polynomials_examples):
        """Testowanie metody evaluate_horner(x) mojej klasy Poly"""

        assert polynomials_examples["constant_1"].evaluate_horner(42) == 5
        assert polynomials_examples["linear_1"].evaluate_horner(2) == 0
        assert polynomials_examples["quadratic_1"].evaluate_horner(-1) == -6
        assert polynomials_examples["cubic_1"].evaluate_horner(1) == -2
        assert polynomials_examples["zero"].evaluate_horner(100) == 0
        with pytest.raises(TypeError):
            polynomials_examples["linear_1"].evaluate_horner("test")

    def test_combination(self, polynomials_examples):
        """Testowanie metody combine(poly) mojej klasy Poly"""

        assert polynomials_examples["linear_2"].combine(polynomials_examples["constant_1"]) == Poly([31])
        assert polynomials_examples["quadratic_1"].combine(polynomials_examples["linear_1"]) == Poly([-3, 5, -2])
        assert polynomials_examples["cubic_1"].combine(polynomials_examples["quadratic_2"]) == Poly([-242, 864, -1188, 780, -245, 36, -2])
        assert polynomials_examples["zero"].combine(polynomials_examples["linear_1"]) == Poly([])
        with pytest.raises(TypeError):
            polynomials_examples["linear_1"].combine("test")

    def test_is_zero(self, polynomials_examples):
        """Testowanie właściwości is_zero mojej klasy Poly"""

        assert polynomials_examples["zero"].is_zero
        assert not polynomials_examples["constant_1"].is_zero

    def test_degree(self, polynomials_examples):
        """Testowanie właściwości degree mojej klasy Poly"""

        assert polynomials_examples["cubic_2"].degree == 3
        assert polynomials_examples["zero"].degree == -1

    def test_differentiation(self, polynomials_examples):
        """Testowanie właściwości differentiate mojej klasy Poly"""

        assert polynomials_examples["zero"].differentiate == Poly([])
        assert polynomials_examples["constant_1"].differentiate == Poly([0])
        assert polynomials_examples["linear_1"].differentiate == Poly([-1])
        assert polynomials_examples["quadratic_1"].differentiate == Poly([3, -4])
        assert polynomials_examples["cubic_1"].differentiate == Poly([-4, 2, -6])

    def test_integration(self, polynomials_examples):
        """Testowanie właściwości integrate mojej klasy Poly"""

        assert polynomials_examples["zero"].integrate == Poly([])
        assert polynomials_examples["constant_2"].integrate == Poly([0, -3])
        assert polynomials_examples["linear_2"].integrate == Poly([0, -4, 7/2])
        assert polynomials_examples["quadratic_2"].integrate == Poly([0, 5, -3, 1/3])
        assert polynomials_examples["cubic_2"].integrate == Poly([0, -2, 3/2, -1/3, 1])
