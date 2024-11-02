#
# make: all, clean, tar  
#
#=========================================================================
DIR = $(notdir $(CURDIR))
#DIR = `basename $(CURDIR)`
#------------------------
NAME1 = cw5_a
NAME2 = cw5_bProducent
NAME3 = cw5_bKonsument
#----------------------
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
COFLAGS = -Wall -O
LDFLAGS = -Wall -O
CO = gcc
LD = $(CO)
#############################
%.o: %.c
	$(CO) $(COFLAGS) -c $<
#############################
.PHONY: all
all: $(EXEC1) $(EXEC2) $(EXEC3)
#############################
$(EXEC1): $(OBJS1)
	 $(LD) -o $@ $(LDFLAGS) $^
#############################
$(EXEC2): $(OBJS2)
	 $(LD) -o $@ $(LDFLAGS) $^
#############################
$(EXEC3): $(OBJS3)
	 $(LD) -o $@ $(LDFLAGS) $^
#############################
.PHONY: run1 run21 run22
#########################################
run1: $(EXEC1)
	./$(EXEC1);sleep 2;diff -s towar1.txt towar2.txt;
run22: $(EXEC2)
	./$(EXEC2);sleep 15;diff -s towar1.txt towar2.txt
run21: $(EXEC3)
	mkfifo myfilo -m644;./$(EXEC3);rm myfilo;sleep 2;diff -s towar1.txt towar2.txt
#####################################################
.PHONY: clean tar
# Porzadki
EXECS = $(EXEC1) $(EXEC2) $(EXEC3)
clean:                                                     
	rm -f *.o  *~ $(EXECS)
#=========================================================================
# Archiwizacja i kompresja
tar: clean
	(cd ../; tar -cvzf $(DIR).tar.gz  $(DIR) )
#=========================================================================
