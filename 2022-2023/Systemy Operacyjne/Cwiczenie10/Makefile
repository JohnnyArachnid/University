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
NAME2 = biblioteka
#------------------------
EXEC1 = $(NAME1)
OBJS1 = $(NAME1).o
#------------------------
EXEC2 = $(NAME2)
OBJS2 = $(NAME2).o
#------------------------
#######################
CFLAGS = -Wall -std=c99 -pedantic -lpthread
LFLAGS = -Wall -std=c99 -pedantic -lpthread
CO = gcc
LD = $(CO)
#######################
LIBDIR = ./lib
LDLIBS = -lm
LIB_OBJS = $(OBJS2)
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
$(OBJS1): $(LIB_STAT)
%.o: %.c
	$(CO) $(CFLAGS) -c $<
#######################
.PHONY: all
all: $(EXEC1)
#######################
$(EXEC1): $(OBJS1) $(LIB_STAT)
	$(LD) -o $@ $(LFLAGS) $< -L$(LIB_DIR) -l$(LIB_NAME) $(LDLIBS)
#######################
.PHONY: run1
run1: $(EXEC1)
	./$(EXEC1)
#######################
.PHONY: clean tar
# Porzadki
EXECS = $(EXEC1)
clean:
	rm -f *.o  *~ *.a $(EXECS);rm -rf ${LIB_DIR}
#=========================================================================
# Archiwizacja i kompresja
tar: clean
	(cd ../; tar -cvzf $(DIR).tar.gz  $(DIR) )
#=========================================================================
