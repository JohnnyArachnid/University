PROGRAM lokata
    IMPLICIT NONE
    INTEGER :: i, lata
    REAL(8) :: kwota, oprocentowanie, poczatkowa_kwota

    poczatkowa_kwota = 1000.0d0
    kwota = poczatkowa_kwota
    oprocentowanie = 0.02d0
    lata = 30

    DO i = 1, lata
        kwota = kwota + kwota * oprocentowanie
    END DO

    PRINT '(A,I2,A,F10.2,A)', 'Kwota koncowa po ', lata, ' latach lokaty z wartoscia poczatkowa ', poczatkowa_kwota, ' PLN'
    PRINT '(A,F5.2,A,F10.2,A)', 'i oprocentowaniem ', oprocentowanie * 100.0d0, '% w skali roku wynosi: ', kwota, ' PLN.'

END PROGRAM lokata