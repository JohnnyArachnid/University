# Autor: Daniel Szarek
#=====================
# Dostepne polecenia
######################
# make run, clean, tar
######################
# Rozszerzenia
##############
.SUFFIXES: .cpp .x .h .o .txt
# Nazwa obecnego katalogu
#########################
DIR = `basename $(CURDIR)`
#------------------------
# Nazwa plikow
##############
NAME1 = main
NAME2 = funkcje
#--------------
# Pliki wykonawcze
##################
EXEC1 = $(NAME1).x
#-----------------
# Pliki zrodlowe
##################
OBJS1 = $(NAME1).o
OBJS2 = $(NAME2).o
# Biblioteki include
####################
INCLUDEPATH1 = /home/vboxuser/Desktop/gsl/include
#------------------------------------------------
# Biblioteka wlasna
###################
LIB_NAME = MojeFunkcje
LIB_DIR = ./lib
LIB_STAT = lib$(LIB_NAME).a
# Budowa biblioteki statycznej
##############################
$(LIB_STAT): $(OBJS2)
	ar rsv $@ $?
	mkdir -p $(LIB_DIR)
	mv $(LIB_STAT) $(LIB_DIR)
#--------------------------------
# Flagi kompilatora i linkera
#############################
CFLAGS = -Wall -std=c++11 -I$(INCLUDEPATH1)
LFLAGS = -Wall -std=c++11 -L$(LIB_DIR) -l$(LIB_NAME) -lgsl -lgslcblas
#--------------------------------------------------------------------
# Kompilator i linker
#####################
CC = g++
LD = $(CC)
#---------
# Definicja domyslnej reguly wzorcowej
######################################
%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@
#----------------------------------
# Jawna regula zaleznosci
#########################
$(EXEC1): $(OBJS1) $(LIB_STAT)
	$(LD) -o $@ $(OBJS1) $(LFLAGS)
#-------------------------------------
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
	rm -f *.o *.x *.txt core; rm -rf $(LIB_DIR)
#--------------------------------------------------
# Archiwum
##########
tar: clean
	(cd ../; tar -cvzf $(DIR).tar.gz  $(DIR))
#------------------------------------------------
