.SUFFIXES: .c .cpp .o .x .h
#
# make: all, clean, tar  
#
#=========================================================================
#------------------------
DIR = $(notdir $(CURDIR))
#DIR = `basename $(CURDIR)`
#------------------------
# nazwy plikow .c
NAME1 = glowny
NAME2 = producent
NAME3 = konsument
NAME4 = obsluga_semaforow
NAME5 = obsluga_pamieci_dzielonej
#------------------------
DANE = dane.txt
WYNIK = wynik.txt
#------------------------
PAMIEC_NAME = pamiecdzielona
PRODUCENT_SEM_NAME = semaforproducenta
KONSUMENT_SEM_NAME = semaforkonsumenta
#------------------------
EXEC1S = $(NAME1)
EXEC1D = $(NAME1)
OBJS1 = $(NAME1).o
#------------------------
EXEC2S = $(NAME2)
EXEC2D = $(NAME2)
OBJS2 = $(NAME2).o
#------------------------
EXEC3S = $(NAME3)
EXEC3D = $(NAME3)
OBJS3 = $(NAME3).o
#------------------------
OBJS4 = $(NAME4).o
OBJS5 = $(NAME5).o
#----------------------
#######################
CFLAGS = -Wall -std=c99 -pedantic -pthread -lrt
LFLAGS = -Wall -std=c99 -pedantic -pthread -lrt
CO = gcc
LD = $(CO)
#######################
LIBDIR = ./lib
LDLIBS = -lm
LIB_OBJS1 = $(OBJS4)
LIB_OBJS2 = $(OBJS5)
LIB_NAME = MojeFunkcje
LIB_DIR = ./lib
LIB_STAT = lib$(LIB_NAME).a
LIB_DYNA = lib$(LIB_NAME).so
AR = ar
ARFLAGS = rsv
#######################
$(LIB_STAT): $(LIB_OBJS1) $(LIB_OBJS2)
	$(AR) $(ARFLAGS) $@ $?
	mkdir -p $(LIB_DIR)
	mv $(LIB_STAT) $(LIB_DIR)
#######################
$(LIB_DYNA): $(LIB_OBJS1) $(LIB_OBJS2)
	$(LD) -shared -o $@ $(LFLAGS) $(LIB_OBJS1) $(LIB_OBJS2)
	mkdir -p $(LIB_DIR)
	mv $(LIB_DYNA) $(LIB_DIR)
#######################
$(OBJS1) $(OBJS2) $(OBJS3):: $(LIB_STAT)
$(OBJS1) $(OBJS2) $(OBJS3):: $(LIB_DYNA)
%.o: %.c
	$(CO) $(CFLAGS) -c $<
#######################
.PHONY: all
all: $(EXEC1S) $(EXEC2S) $(EXEC3S) $(EXEC1D) $(EXEC2D) $(EXEC3D)
#######################
$(EXEC1S):: $(OBJS1) $(LIB_STAT)
	$(LD) -o $@ $(LFLAGS) $< -L$(LIB_DIR) -l$(LIB_NAME) $(LDLIBS)
$(EXEC2S):: $(OBJS2) $(LIB_STAT)
	$(LD) -o $@ $(LFLAGS) $< -L$(LIB_DIR) -l$(LIB_NAME) $(LDLIBS)
$(EXEC3S):: $(OBJS3) $(LIB_STAT)
	$(LD) -o $@ $(LFLAGS) $< -L$(LIB_DIR) -l$(LIB_NAME) $(LDLIBS)
$(EXEC1D):: $(OBJS1) $(LIB_DYNA)
	$(LD) -o $@ $(LFLAGS) $< -L$(LIB_DIR) -l$(LIB_NAME) $(LDLIBS) -Wl,-R $(LIB_DIR)
$(EXEC2D):: $(OBJS2) $(LIB_DYNA)
	$(LD) -o $@ $(LFLAGS) $< -L$(LIB_DIR) -l$(LIB_NAME) $(LDLIBS) -Wl,-R $(LIB_DIR)
$(EXEC3D):: $(OBJS3) $(LIB_DYNA)
	$(LD) -o $@ $(LFLAGS) $< -L$(LIB_DIR) -l$(LIB_NAME) $(LDLIBS) -Wl,-R $(LIB_DIR)
#######################
.PHONY: run1 run2
run1: $(EXEC1S) $(EXEC2S) $(EXEC3S)
	./$(EXEC1S) $(EXEC2S) $(EXEC3S) $(DANE) $(WYNIK) $(PAMIEC_NAME) $(PRODUCENT_SEM_NAME) $(KONSUMENT_SEM_NAME)
	diff -s $(DANE) $(WYNIK)
#######################
run2: $(EXEC1D) $(EXEC2D) $(EXEC3D)
	./$(EXEC1D) $(EXEC2D) $(EXEC3D) $(DANE) $(WYNIK) $(PAMIEC_NAME) $(PRODUCENT_SEM_NAME) $(KONSUMENT_SEM_NAME)
	diff -s $(DANE) $(WYNIK)
#######################
.PHONY: clean tar
# Porzadki
EXECS = $(EXEC1S) $(EXEC2S) $(EXEC3S) $(EXEC1D) $(EXEC2D) $(EXEC3D)
clean:
	rm -f *.o  *~ *.a *.so $(EXECS);rm -rf ${LIB_DIR}
#=========================================================================
# Archiwizacja i kompresja
tar: clean
	(cd ../; tar -cvzf $(DIR).tar.gz  $(DIR) )
#=========================================================================
