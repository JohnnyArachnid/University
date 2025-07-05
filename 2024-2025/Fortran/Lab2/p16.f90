PROGRAM p16
    INTEGER, PARAMETER :: st=8
    INTEGER :: wiersz, kolumna, r
    REAL, DIMENSION (2:10,-30:30,0:10) :: t, y, t_razy_y
    COMPLEX, DIMENSION (1:10, 2+ST) :: z,c
    t=2.0
    y=3.0
    t_razy_y = t * y
    PRINT *, t_razy_y
    z=(1.0, 0.0)
    DO r=1, 10
    z(1,r) = (0.0, 9.0)
    END DO
    c= (2.0,0.0) * z + (1.0,0.0)
    PRINT *, c(1:3,8:10)
    PRINT *
    DO wiersz=1,3
    PRINT *, (c(wiersz , kolumna), kolumna= 8, 10)
    END DO
    STOP
END PROGRAM p16