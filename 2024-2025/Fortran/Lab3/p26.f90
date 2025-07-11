PROGRAM p26
    IMPLICIT NONE
    REAL :: maximal, minimal, il_skal
    INTEGER, DIMENSION(2,3) :: matrix_A
    INTEGER, DIMENSION(3,2) :: matrix_B
    INTEGER, DIMENSION(2,2) :: matrix_AB
    INTEGER, DIMENSION(3) :: vector_C
    INTEGER, DIMENSION(3) :: vector_D
    INTEGER, DIMENSION(6) :: vector_E
    INTEGER, DIMENSION(1:2) :: indeksy
    matrix_A(1,1) = 1 ; matrix_A(1,2) = 2 ; matrix_A(1,3) = 3
    matrix_A(2,1) = 4
    matrix_A(2,2) = 5
    matrix_A(2,3) = 6
    maximal = MAXVAL(matrix_A)
    indeksy = MAXLOC(matrix_A)
    PRINT *, "max matrix_A(", indeksy(1),",",indeksy(2),") ", maximal
    minimal = MINVAL(matrix_A)
    indeksy = MINLOC(matrix_A)
    PRINT *, "min matrix_A(", indeksy(1),",",indeksy(2),") ", minimal
    vector_E=PACK(matrix_A, .TRUE.)
    PRINT *
    PRINT *, "vector_E = ", vector_E
    vector_C = PACK(matrix_A, matrix_A <= 3)
    vector_D = PACK(matrix_A, matrix_A > 3)
    il_skal = DOT_PRODUCT(vector_C, vector_D)
    PRINT *
    PRINT *, "vector_C = ", vector_C
    PRINT *, "vector_D = ", vector_D
    PRINT *, "iloczyn skalarny vector_C razy vektor_D = ", il_skal
    STOP
END PROGRAM p26