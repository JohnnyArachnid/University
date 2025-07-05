MODULE MathUtils
    IMPLICIT NONE
    INTEGER, PARAMETER :: iK = SELECTED_INT_KIND(9)

CONTAINS

    RECURSIVE FUNCTION suma(n) RESULT(sum)
        INTEGER(kind=iK), INTENT(IN) :: n
        INTEGER(kind=iK) :: sum
        IF (n <= 0) THEN
            sum = 0
        ELSE
            sum = n + suma(n - 1)
        END IF
    END FUNCTION suma

END MODULE MathUtils

PROGRAM suma_naturalnych
    USE MathUtils
    IMPLICIT NONE

    INTEGER(kind=iK) :: N, wynik

    PRINT *, "Witaj w programie liczacym rekurencyjnie sume liczb naturalnych od 0 do N."
    PRINT *, "Podaj wartosc N: "
    READ *, N

    IF (N < 0) THEN
        PRINT *, "Blad: Podano ujemna liczbe!"
        STOP
    END IF

    wynik = suma(N)

    PRINT "(A,I10,A,I10)", "Suma liczb naturalnych od 0 do ", N, " wynosi: ", wynik
  
END PROGRAM suma_naturalnych