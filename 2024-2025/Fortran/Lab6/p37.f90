MODULE zawiera_funkcje_Large
    IMPLICIT NONE
    PUBLIC :: Large
  CONTAINS
    FUNCTION Large(list, k) result(large_R)
      INTEGER, INTENT(IN), DIMENSION(:) :: list
      INTEGER, INTENT(IN) :: k
      INTEGER :: large_R
      IF(ANY(list <= k)) THEN
        large_R = MAXVAL(list, MASK=(list <= k))
      ELSE
        large_R = k
      END IF
      RETURN
    END FUNCTION Large
END MODULE zawiera_funkcje_Large
  
PROGRAM prog37
USE zawiera_funkcje_Large
IMPLICIT NONE
INTEGER :: n, k
INTEGER, ALLOCATABLE, DIMENSION(:) :: list

DO
    PRINT *, 'podaj rozmiar macierzy "list"'
    READ(*,*) n
    IF(n <= 0) EXIT
    ALLOCATE(list(n))
    PRINT *, "podaj wartosci n-elementowej macierzy oddzielajac spacjami lub w nowej linii"
    READ(*,*) list
    PRINT *, "podaj liczbe 'k'"
    READ(*,*) k
    PRINT *, "najwiekszy element macierzy ""list"" sposrod mniejszych od liczby ""k"""
    WRITE(*,*) Large(list, k)
    DEALLOCATE(list)
END DO
STOP
END PROGRAM prog37  