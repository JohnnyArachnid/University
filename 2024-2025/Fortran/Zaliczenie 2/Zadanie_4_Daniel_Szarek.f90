MODULE MathUtils
    IMPLICIT NONE
    INTEGER, PARAMETER :: iK = SELECTED_INT_KIND(9)
    INTEGER, PARAMETER :: iL = SELECTED_INT_KIND(18)

CONTAINS

    RECURSIVE FUNCTION suma(n1, n2) RESULT(sum)
        INTEGER(kind=iK), INTENT(IN) :: n1, n2
        INTEGER(kind=iL) :: sum

        IF (n1 > n2) THEN
            sum = 0
        ELSE
            sum = n1 + suma(n1 + 1, n2)
        END IF
    END FUNCTION suma

END MODULE MathUtils


PROGRAM suma_naturalnych
    USE MathUtils
    IMPLICIT NONE

    INTEGER(kind=iK) :: N1, N2
    INTEGER(kind=iL) :: wynik

    PRINT *, "Program liczacy rekurencyjnie sume liczb naturalnych od N1 do N2."
    PRINT *, "Podaj wartosc N1:"
    READ *, N1
    PRINT *, "Podaj wartosc N2:"
    READ *, N2

    IF (N1 < 0 .OR. N2 < 0) THEN
        PRINT *, "Blad: Podano liczby ujemne. Wprowadz liczby naturalne."
        STOP
    END IF

    IF (N1 > N2) THEN
        PRINT *, "Blad: N1 musi byc mniejsze lub rowne N2."
        STOP
    END IF

    wynik = suma(N1, N2)

    PRINT "(A,I10,A,I10,A,I10)", "Suma liczb naturalnych od ", N1, " do ", N2, " wynosi: ", wynik

END PROGRAM suma_naturalnych