MODULE funkcja_korzysta_z_procedury
    IMPLICIT NONE
    PUBLIC :: module_function, module_subroutine
    TYPE, PUBLIC :: new
      INTEGER :: j, k
    END TYPE new
  
    TYPE(new), PUBLIC :: x = new(1234, 5678)
  CONTAINS
    FUNCTION module_function() RESULT(module_function_r)
      TYPE(new) :: module_function_r
      CALL internal_subroutine(module_function_r)
      RETURN
    CONTAINS
      SUBROUTINE internal_subroutine(u)
        TYPE(new), INTENT(OUT) :: u
        u = new(22, 11)
        CALL module_subroutine(u%j, u%k)
        RETURN
      END SUBROUTINE internal_subroutine
    END FUNCTION module_function
  
    SUBROUTINE module_subroutine(i1, i2)
      INTEGER, INTENT(IN OUT) :: i1, i2
      INTEGER :: x
      x = i1
      i1 = i2
      i2 = x
      RETURN
    END SUBROUTINE module_subroutine
END MODULE funkcja_korzysta_z_procedury

PROGRAM prog41
    USE funkcja_korzysta_z_procedury
    IMPLICIT NONE
    INTEGER, PARAMETER :: value = 789
    TYPE(new) :: exter
    INTEGER :: inter
  
    exter = module_function()
    inter = value
    WRITE(*,*) "exter%j=", exter%j, "exter%k=", exter%k
    WRITE(*,*) "value=", inter
END PROGRAM prog41  