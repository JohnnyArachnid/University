# Autor: Daniel Szarek
#=====================
# Dostepne polecenia
######################
# make run, clean, tar
######################
# Rozszerzenia
##############
.SUFFIXES: .cpp .x .h .o
# Nazwa obecnego katalogu
#########################
DIR = `basename $(CURDIR)`
#------------------------
# Nazwa plikow
##############
NAME1 = main
NAME2 = mypriorityqueue
#--------------
# Pliki wykonawcze
##################
EXEC1 = $(NAME1).x
#-----------------
# Pliki zrodlowe
##################
OBJS1 = $(NAME1).o
#-----------------
# Pliki naglowkowe
##################
HFILE1 = $(NAME2).h
#------------------
# Flagi kompilatora i linkera
#############################
CFLAGS = -Wall -std=c++11
LFLAGS = -Wall -std=c++11
#------------------------
# Kompilator i linker
#####################
CC = g++
LD = $(CC)
#---------
# Dolaczane biblioteki (poza standardowymi)
LIBS =
#------
# Definicja domyslnej reguly wzorcowej
######################################
%.o: %.cpp $(HFILE1) Makefile
	$(CC) $(CFLAGS) -c $< -o $@
#-------------------------------
# Jawna regula zaleznosci
#########################
$(EXEC1): $(OBJS1) $(LIBS) 
	$(LD) -o $@ $(LFLAGS) $^ $(LIBS)
#------------------------------------
# Okreslenie celow sztucznych
#############################
.PHONY: run clean tar
#--------------------
# Uruchomienie programu
#######################
run: $(EXEC1)
	./$(EXEC1)
#-----------------
# Porzadki
##########
clean:
	rm -f *.o *.x core;
#----------------------
# Archiwum
##########
tar: clean
	(cd ../; tar -cvzf $(DIR).tar.gz  $(DIR))
#--------------------------------------------

