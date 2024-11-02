// Autor: Daniel Szarek,                           Krakow, 06.04.2023r.


//Plik Naglowkowy

#include "funkcje.h"

//Funkcja glowna pobierajaca tablice oraz liczbe danych przy wywolaniu w terminalu, wykonujaca zadanie podane w poleceniu cwiczenie 3a)

int main(int argc, char *argv[]){

//Obsluga bledow, sprawdzam czy liczba argumentow podana przy wywolaniu jest rowna tej potrzebnej do prawidlowego dzialania programu

    if(argc != 3)
    {
        printf("Liczba argumentow przy wywolaniu %d jest rozna od 3\n",argc);
        exit(1);
    }

//Wypisanie PID procesu macierzystego

    PID();

//Przeksztalcenie typu string podanego przy wywolaniu na typ int

    int nr_sygnalu = atoi(argv[2]);

//Wyluskanie znaku ze stringa podanego przy wywolaniu

    char znak = argv[1][0];
    switch(znak)
    {

//Przypadek wykonania operacji domyslnej dla sygnalu

        case '1':
            printf("Wykonanie operacji domyslnej\n");
            signal(nr_sygnalu, SIG_DFL);
            break;

//Przypadek wykonania operacji zignorowania dla sygnalu

        case '2':
            printf("Ignoracja Sygnalu\n");
            signal(nr_sygnalu, SIG_IGN);
            break;
        case '3':

//Przypadek wykonania operacji wlasnej dla sygnalu, u mnie jest to funkcja sighandler(int sig), zdefiniowana w pliku funkcje.h

            signal(nr_sygnalu, &sighandler);
            break;
        default:

//Obsluga bledow, sprawdzam czy uzytkownik nie podal zlego znaku przy wywolaniu

            printf("Podany bledny numer obslugi procesu\n");
            exit(2);

//Zawieszenie procesu do czasu odebrania sygnalu, ktory nie zostal zignorowany dzieki wykorzystaniu funkcji pause(). Instrukcja if zostanie wykonana tylko w przypadku 3, przechwycenia sygnalu

    }
    if(pause()==-1)
    {
        printf("Przechwycono sygnal\n");
    }
    return 0;
}