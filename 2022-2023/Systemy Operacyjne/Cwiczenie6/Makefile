.SUFFIXES: .c .cpp .o .x .h
#
# make: all, clean, tar  
#
#=========================================================================
#------------------------
DIR = $(notdir $(CURDIR))
#DIR = `basename $(CURDIR)`
#------------------------
NAME1 = powielacz
NAME2 = wzajemne_wykluczanie
NAME3 = obsluga_semaforow
#------------------------
PLIK_NUMER = numer.txt
ILE_PROCESOW = 2
ILE_SEKCJI_KRYT = 3
#------------------------
EXEC1 = $(NAME1)
OBJS1 = $(NAME1).o
#----------------------
EXEC2 = $(NAME2)
OBJS2 = $(NAME2).o
#----------------------
EXEC3 = $(NAME3)
OBJS3 = $(NAME3).o
#----------------------
#######################
CFLAGS = -Wall -std=c99 -pedantic -pthread
LFLAGS = -Wall -std=c99 -pedantic -pthread
CO = gcc
LD = $(CO)
#######################
LDLIBS = -lm
LIB_OBJS = $(OBJS3)
LIB_NAME = MojeFunkcje
LIB_DIR = ./lib
LIB_STAT = lib$(LIB_NAME).a
AR = ar
ARFLAGS = rsv
#######################
$(LIB_STAT): $(LIB_OBJS)
	$(AR) $(ARFLAGS) $@ $?
	mkdir -p $(LIB_DIR)
	mv $(LIB_STAT) $(LIB_DIR)
#######################
$(OBJS1) $(OBJS2): $(LIB_STAT)
#######################
%.o: %.c
	$(CO) $(CFLAGS) -c $<
#######################
.PHONY: all
all: $(EXEC1) $(EXEC2) $(EXEC3)
#######################
$(EXEC1): $(OBJS1) $(LIB_STAT)
	$(LD) -o $@ $(LFLAGS) $< -L$(LIB_DIR) -l$(LIB_NAME) $(LDLIBS)
$(EXEC2): $(OBJS2) $(LIB_STAT)
	$(LD) -o $@ $(LFLAGS) $< -L$(LIB_DIR) -l$(LIB_NAME) $(LDLIBS)
#######################
.PHONY: run1
run1: $(EXEC1) $(EXEC2)
	./$(EXEC1) $(EXEC2) $(ILE_PROCESOW) $(ILE_SEKCJI_KRYT) $(PLIK_NUMER)
#######################
.PHONY: clean tar
# Porzadki
EXECS = $(EXEC1) $(EXEC2) $(EXEC3)
clean:
	rm -f *.o  *~ *.a $(EXECS);rm -rf ${LIB_DIR}
#=========================================================================
# Archiwizacja i kompresja
tar: clean
	(cd ../; tar -cvzf $(DIR).tar.gz  $(DIR) )
#=========================================================================
