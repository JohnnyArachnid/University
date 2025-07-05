!==================================================
! Program 2: statystyki_wielomianu_stopnia_2
! Opis: Obliczenie podstawowych własności wielomianu ax^2 + bx + c
! Autor: Daniel Szarek
!==================================================
PROGRAM statystyki_wielomianu_stopnia_2
   IMPLICIT NONE
   REAL :: a, b, c
   REAL :: f_minus10, f_0, f_10
   REAL :: pochodna_0
   REAL :: x_w, y_w
   REAL :: delta, x1, x2

   ! Prośba o podanie wspołczynników wielomianu kwadratowego
   PRINT *, "Podaj wspolczynniki a, b, c dla wielomianu ax^2 + bx + c:"
   READ *, a, b, c

   ! Sprawdzenie czy a != 0
   IF (a == 0.0) THEN
       PRINT *, "To nie jest wielomian stopnia 2 (a = 0)"
       STOP
   END IF

   PRINT *, "Podstawowe wartosci dla wielomianu: ", a, "x^2 + ", b, "x + ", c  

   ! Wartości funkcji w wybranych punktach
   f_minus10 = a*(-10.0)**2 + b*(-10.0) + c
   f_0 = a*0.0**2 + b*0.0 + c
   f_10 = a*10.0**2 + b*10.0 + c

   PRINT *, "Wartosc funkcji dla x = -10:", f_minus10
   PRINT *, "Wartosc funkcji dla x = 0:", f_0
   PRINT *, "Wartosc funkcji dla x = 10:", f_10

   ! Pochodna funkcji w punkcie x = 0
   ! Dla ax^2 + bx + c pochodna to f'(x) = 2a*x + b
   pochodna_0 = 2.0*a*0.0 + b
   PRINT *, "Pochodna w punkcie x = 0 wynosi:", pochodna_0

   ! Wierzcholek paraboli (x_w, y_w)
   x_w = -b / (2.0*a)
   y_w = a*x_w**2 + b*x_w + c
   PRINT *, "Wspolrzedne wierzcholka paraboli:"
   PRINT *, "x_w =", x_w, ", y_w =", y_w

   ! Kierunek ramion paraboli
   IF (a > 0.0) THEN
       PRINT *, "Ramiona paraboli skierowane sa do gory (minimum lokalne)"
   ELSE
       PRINT *, "Ramiona paraboli skierowane sa w dol (maksimum lokalne)"
   END IF

   ! Obliczanie miejsc zerowych
   delta = b**2 - 4.0*a*c

   IF (delta > 0.0) THEN
       ! Dwa pierwiastki rzeczywiste
       x1 = (-b + SQRT(delta)) / (2.0*a)
       x2 = (-b - SQRT(delta)) / (2.0*a)
       PRINT *, "Dwa miejsca zerowe: x1 =", x1, " oraz x2 =", x2
   ELSE IF (delta == 0.0) THEN
       ! Jedno miejsce zerowe (podwojny pierwiastek)
       x1 = -b / (2.0*a)
       PRINT *, "Jedno miejsce zerowe (pierwiastek podwojny): x =", x1
   ELSE
       PRINT *, "Brak miejsc zerowych w zbiorze liczb rzeczywistych."
   END IF

END PROGRAM statystyki_wielomianu_stopnia_2