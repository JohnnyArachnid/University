PROGRAM pierwiastki_rownania_kwadratowego
    IMPLICIT NONE
    REAL(8) :: a, b, c
    REAL(8) :: delta, x1, x2

    PRINT *, "Podaj wspolczynniki a, b, c dla rownania kwadratowego: ax^2 + bx + c = 0:"
    READ *, a, b, c

    IF (a == 0.0d0) THEN
        PRINT *, "To nie jest rownanie kwadratowe, ze wzgledu na a = 0."
        STOP
    END IF

    PRINT '(A, F6.2, A, F6.2, A, F6.2)', "Wspolczynniki: ", a, "x^2 + ", b, "x + ", c  

    delta = b**2 - 4.0d0 * a * c

    IF (delta > 0.0d0) THEN
        x1 = (-b + SQRT(delta)) / (2.0d0 * a)
        x2 = (-b - SQRT(delta)) / (2.0d0 * a)
        PRINT '(A, F10.2, A, F10.2)', "Dwa miejsca zerowe: x1 = ", x1, " oraz x2 = ", x2
    ELSE IF (delta == 0.0d0) THEN
        x1 = -b / (2.0d0 * a)
        PRINT '(A, F10.2)', "Jedno miejsce zerowe (pierwiastek podwojny): x0 = ", x1
    ELSE
        PRINT *, "Brak miejsc zerowych w zbiorze liczb rzeczywistych, ze wzgledu na ujemna delte."
    END IF

END PROGRAM pierwiastki_rownania_kwadratowego