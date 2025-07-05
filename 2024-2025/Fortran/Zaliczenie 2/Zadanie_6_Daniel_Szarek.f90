MODULE MathUtils
  IMPLICIT NONE

  INTEGER, PARAMETER :: dp = SELECTED_REAL_KIND(15, 307)

CONTAINS

  FUNCTION funkcja_f(x) RESULT(y)
    REAL(kind=dp), INTENT(IN) :: x
    REAL(kind=dp) :: y
    y = x**3 - 3.0_dp * x**2 - 4.0_dp * x + 12.0_dp
  END FUNCTION funkcja_f

END MODULE MathUtils

PROGRAM znajdz_pierwiastki_numerycznie
  USE MathUtils
  IMPLICIT NONE

  REAL(kind=dp), PARAMETER :: x_poczatek = -3.0_dp
  REAL(kind=dp), PARAMETER :: x_koniec =  4.0_dp
  REAL(kind=dp), PARAMETER :: krok =  0.001_dp
  REAL(kind=dp) :: x1, x2, y1, y2, pierwiastek_przyblizony
  REAL(kind=dp) :: ostatni_znaleziony_x = -9999.0_dp
  INTEGER, PARAMETER :: n_punktow = 7000
  INTEGER :: i, liczba_znalezionych

  liczba_znalezionych = 0

  PRINT *, 'Program szacuje miejsca zerowe funkcji f(x) = x^3 - 3x^2 - 4x + 12'
  PRINT '(A, F5.2, A, F5.2, A, F7.3)', 'Zakres poszukiwania: [', x_poczatek, ', ', x_koniec, '], krok: ', krok
  PRINT '(A, I0)', 'Liczba analizowanych punktow: ', n_punktow
  PRINT *

  DO i = 1, n_punktow - 1
    x1 = x_poczatek + REAL(a=i - 1, kind=dp) * krok
    x2 = x_poczatek + REAL(a=i, kind=dp) * krok
    y1 = funkcja_f(x1)
    y2 = funkcja_f(x2)

    IF (y1 * y2 <= 0.0_dp) THEN
      pierwiastek_przyblizony = (x1 + x2) / 2.0_dp

      IF (ABS(pierwiastek_przyblizony - ostatni_znaleziony_x) > krok * 2.0_dp) THEN
        liczba_znalezionych = liczba_znalezionych + 1
        ostatni_znaleziony_x = pierwiastek_przyblizony

        PRINT '(A, I2, A, F12.6)', 'Oszacowano pierwiastek nr ', liczba_znalezionych, ' wynosi okolo: ', pierwiastek_przyblizony
      END IF
    END IF
  END DO

  PRINT *
  IF (liczba_znalezionych == 0) THEN
    PRINT *, 'Nie znaleziono zadnych pierwiastkow w podanym zakresie.'
  ELSE
    PRINT '(A, I0, A)', 'Zakonczono. Znaleziono lacznie ', liczba_znalezionych, ' pierwiastkow.'
  END IF

END PROGRAM znajdz_pierwiastki_numerycznie