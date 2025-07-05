!==================================================
! Program 3: gra_zgadywanie_liczby
! Opis: Gra w zgadywanie liczby z poziomami
! Autor: Daniel Szarek
!==================================================
PROGRAM gra_zgadywanie_liczby
   IMPLICIT NONE
   REAL :: liczba
   INTEGER :: strzal, proby, max_liczba
   CHARACTER(LEN=10) :: poziom
  
   ! Inicjalizacja ziarna generatora liczb losowych
   CALL init_random_seed()
  
   ! Prośba o wybór poziomu trudności gry
   PRINT *, "Wybierz poziom trudnosci: latwy, sredni, trudny"
   READ *, poziom
  
   ! Przypisanie wartości maksymalnej liczby w zależności od poziomu trudności
   SELECT CASE (TRIM(poziom))
      CASE ("latwy")
         max_liczba = 50
      CASE ("sredni")
         max_liczba = 100
      CASE ("trudny")
         max_liczba = 500
      CASE DEFAULT
         max_liczba = 100
         PRINT *, "Nieznany poziom, ustawiono domyslnie: sredni"
   END SELECT
  
   ! Generowanie losowej liczby
   CALL RANDOM_NUMBER(liczba)

   ! Skalowanie liczby do odpowiedniego zakresu
   liczba = INT(liczba * max_liczba) + 1

   PRINT *, "Zgadnij liczbe od 1 do", max_liczba
   proby = 0

   ! Pętla do zgadywania liczby przez użytkownika
   DO
      PRINT *, "Podaj swoja propozycje:"
      READ *, strzal
      proby = proby + 1
      IF (strzal < liczba) THEN
         PRINT *, "Za malo!"
      ELSE IF (strzal > liczba) THEN
         PRINT *, "Za duzo!"
      ELSE
         PRINT *, "Zgadles w", proby, "probach!"
         EXIT
      END IF
   END DO
  
   ! Podprogram do inicjalizacji ziarna generatora liczb losowych
   CONTAINS
      SUBROUTINE init_random_seed()
         INTEGER :: i, n, clock
         INTEGER, DIMENSION(:), ALLOCATABLE :: seed
         CALL RANDOM_SEED(SIZE=n)
         ALLOCATE(seed(n))
         CALL SYSTEM_CLOCK(COUNT=clock)
         seed = clock + 37 * (/ (i-1, i=1,n) /)
         CALL RANDOM_SEED(PUT=seed)
         DEALLOCATE(seed)
      END SUBROUTINE

END PROGRAM gra_zgadywanie_liczby