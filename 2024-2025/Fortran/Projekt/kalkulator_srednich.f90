!==================================================
! Program 1: kalkulator_srednich
! Opis: Obliczenie podstawowych średnich dla wskazanych liczb
! Autor: Daniel Szarek
!==================================================
PROGRAM kalkulator_srednich
   IMPLICIT NONE
   INTEGER :: n, i
   REAL :: liczba, suma, srednia_arytmetyczna, srednia_geometryczna, srednia_harmoniczna
   REAL, ALLOCATABLE :: dane(:)
   LOGICAL :: zawiera_zero

   ! Prośba o podanie liczby elementów, które mają zostać wprowadzone
   PRINT *, "Podaj ile liczb chcesz wprowadzic:"
   READ *, n

   ALLOCATE(dane(n))
   suma = 0.0
   zawiera_zero = .FALSE.
   srednia_geometryczna = 1.0
   srednia_harmoniczna = 0.0

   ! Pętla do wprowadzenia danych liczbowych
   DO i = 1, n
      PRINT *, "Podaj liczbe nr", i
      READ *, liczba
      dane(i) = liczba
      suma = suma + liczba
      IF (liczba == 0.0) zawiera_zero = .TRUE.
      IF (liczba > 0.0) THEN
         srednia_geometryczna = srednia_geometryczna * liczba
      END IF
      IF (liczba /= 0.0) THEN
         srednia_harmoniczna = srednia_harmoniczna + 1.0 / liczba
      END IF
   END DO
  
   ! Obliczenia średnich
   srednia_arytmetyczna = suma / n
   srednia_geometryczna = srednia_geometryczna**(1.0/n)
   srednia_harmoniczna = n / srednia_harmoniczna

   PRINT *, "Podstawowe srednie:"

   ! Wyświetlenie średnich
   PRINT *, "Srednia arytmetyczna:", srednia_arytmetyczna
   IF (zawiera_zero) THEN
      PRINT *, "Srednia geometryczna nie istnieje (zero w danych)"
   ELSE
      PRINT *, "Srednia geometryczna:", srednia_geometryczna
   END IF
   PRINT *, "Srednia harmoniczna:", srednia_harmoniczna

   DEALLOCATE(dane)

END PROGRAM kalkulator_srednich