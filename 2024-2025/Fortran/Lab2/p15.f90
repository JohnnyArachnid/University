PROGRAM p15
    IMPLICIT NONE
    REAL, DIMENSION(2:10,-30:30,0:10) :: t, y, t_plus_y
    t=2.0
    y=3.0
    t_plus_y= t+y
    PRINT *, t_plus_y
    STOP
END PROGRAM p15