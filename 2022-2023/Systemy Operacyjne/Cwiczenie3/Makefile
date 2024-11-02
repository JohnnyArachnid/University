#
# make: all, clean, tar  
#
#=========================================================================
DIR = $(notdir $(CURDIR))
#DIR = `basename $(CURDIR)`
#------------------------
NAME1 = cw3_a
NAME2 = cw3_b
NAME31 = cw3_cG
NAME32 = cw3_cP
NRSYGNALU = 5
NROPCJI = 1
#----------------------
EXEC1 = $(NAME1)
OBJS1 = $(NAME1).o
#----------------------
EXEC2 = $(NAME2)
OBJS2 = $(NAME2).o
#----------------------
EXEC31 = $(NAME31)
OBJS31 = $(NAME31).o
#----------------------
EXEC32 = $(NAME32)
OBJS32 = $(NAME32).o
#----------------------
#######################
COFLAGS = -Wall -O
LDFLAGS = -Wall -O
CO = gcc
LD = $(CO)
#############################
%.o: %.c
	$(CO) $(COFLAGS) -c $<
#############################
.PHONY: all
all: $(EXEC1) $(EXEC2) $(EXEC31) $(EXEC32)
#############################
$(EXEC1): $(OBJS1)
	 $(LD) -o $@ $(LDFLAGS) $^
#############################
$(EXEC2): $(OBJS2)
	 $(LD) -o $@ $(LDFLAGS) $^
#############################
$(EXEC31): $(OBJS31)
	 $(LD) -o $@ $(LDFLAGS) $^
#############################
$(EXEC32): $(OBJS32)
	 $(LD) -o $@ $(LDFLAGS) $^
#############################
.PHONY: run1 run2 run3 NRSYGNALU NROPCJI
#########################################
run1: $(EXEC1)
	./$(EXEC1) $(NROPCJI) $(NRSYGNALU)
#W osobnym terminalu nalezy przeslac sygnal komenda kill -NRSYGNALU PID_PROCESU, ktory wyswietli sie na ekranie przy uruchomieniu programu
run2: $(EXEC2) $(EXEC1)
	./$(EXEC2) $(NROPCJI) $(NRSYGNALU) $(EXEC1)
run3: $(EXEC31) $(EXEC32) $(EXEC1)
	./$(EXEC31) $(NROPCJI) $(NRSYGNALU) $(EXEC1) $(EXEC32)
##############
.PHONY: clean tar
# Porzadki
EXECS = $(EXEC1) $(EXEC2) $(EXEC31) $(EXEC32)
clean:                                                     
	rm -f *.o  *~ $(EXECS)
#=========================================================================
# Archiwizacja i kompresja
tar: clean
	(cd ../; tar -cvzf $(DIR).tar.gz  $(DIR) )
#=========================================================================
