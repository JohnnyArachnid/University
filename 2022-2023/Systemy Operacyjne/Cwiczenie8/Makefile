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
NAME1 = serwer
NAME2 = klient
NAME3 = obsluga_kolejki_komunikatow
#------------------------
EXEC1 = $(NAME1)
OBJS1 = $(NAME1).o
#------------------------
EXEC2 = $(NAME2)
OBJS2 = $(NAME2).o
#------------------------
EXEC3 = $(NAME3)
OBJS3 = $(NAME3).o
#------------------------
#######################
CFLAGS = -Wall -std=c99 -pedantic
LFLAGS = -Wall -std=c99 -pedantic
CO = gcc
LD = $(CO)
#######################
LIBDIR = ./lib
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
$(OBJS1) $(OBJS2) $(OBJS3): $(LIB_STAT)
%.o: %.c
	$(CO) $(CFLAGS) -c $<
#######################
.PHONY: all
all: $(EXEC1S) $(EXEC2S) $(EXEC3S) $(EXEC1D) $(EXEC2D) $(EXEC3D)
#######################
$(EXEC1): $(OBJS1) $(LIB_STAT)
	$(LD) -o $@ $(LFLAGS) $< -L$(LIB_DIR) -l$(LIB_NAME) $(LDLIBS)
$(EXEC2): $(OBJS2) $(LIB_STAT)
	$(LD) -o $@ $(LFLAGS) $< -L$(LIB_DIR) -l$(LIB_NAME) $(LDLIBS)
#######################
.PHONY: run1 run2
run1: $(EXEC1) $(EXEC2)
	xterm -hold -title SERWER -bg red -fg black -e ./$(EXEC1) & xterm -hold -title KLIENT1 -bg green -fg black -e ./$(EXEC2) & xterm -hold -title KLIENT2 -bg green -fg black -e ./$(EXEC2)
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
