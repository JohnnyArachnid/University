// Autor: Daniel Szarek,                           Krakow, 27.05.2023r.


//Kod wielokrotnego uzytku

#define _REENTRANT

//Plik Naglowkowy

#include "biblioteka.h"

//Zmienne globalne: Liczba - zasob dzielony, x,y - wspolrzedne do wypisywania na ekranie, Numer - numer watku obslugujacy sekcje krytyczna

int Liczba = 0; 
int x = 0, y = 0;

//Zainicjowanie mutexu

pthread_mutex_t Mutex;

//Wlasna funkcja w ramach obslugi watkow zadania wzajemnego wykluczania

void* Funkcja(void* arg)
{

//Numer watku wykonujacego sekcje krytyczna

    int Numer = *(int *)arg;

//Zamkniecie mutexu

    ZamkniecieMutexu(&Mutex);    

//Zmienne iteracyjne, wyzerowanie zmiennej i dla optymalizacji programu i unikniecia bledu formatowania zmiennej przez kilka watkow i przedwczesne wyjscie z petli do while

    int i = 0, k;

//Przypisanie zmiennej globalnej do prywatnego licznika watku

    int LiczbaPrywatna = Liczba;

//Zmienna przechowujacy pseudolosowy czas opoznienia

    int Czas;

//Wlaczenie pogrubienia i podkreslenia tekstu

    printf("\033[1;4m");
    y = 1; 
    x = 5;
    UstawienieNapisu(x, y);
    printf("///////////////////////////////////////////////////////////////////////////////////////////////////\n");

//Powrocenie do domyslnego trybu wyswietlania tekstu

    printf("\033[0m");
    do{

//Wypisanie watkow na ekranie

        for(k = 0; k < LICZBAWATKOW; k++) 
        {

//Watek w sekcji krytycznej

            if (k == Numer)
            {

//Wlaczenie pogrubienia i podkreslenia tekstu

                printf("\033[1;4m");
                y = 3 + LICZBAWATKOW * k; 
                x = 30;
                UstawienieNapisu(x, y);
                printf("Watek o numerze : %d w sekcji krytycznej o numerze: %d, wartosc zmiennej: %d\n", k + 1, i + 1, LiczbaPrywatna + 1);

//Powrocenie do domyslnego trybu wyswietlania tekstu

                printf("\033[0m");
            }

//Pozostale watki

            else
            {
                y = 3 + LICZBAWATKOW * k;
                x = 5;
                UstawienieNapisu(x, y);
                printf("Watek o numerze: %d\n", k + 1);

            }
        }

//Zwiekszenie wartosci prywatnego licznika o 1

        LiczbaPrywatna++;

//Ustalenie losowej liczby sekund w progu 1-4 sekund w ramach oczekiwania sleep

		Czas = rand()%3 + 1;
        sleep(Czas);
        i++;
    }while(i < LICZBASEKCJIKRYTYCZNYCH);

//Przypisanie wartosci zmiennej globalnej zmodyfikowanej liczby tymczasowej przez watek w ramach pracy w seksji krytycznej

    Liczba = LiczbaPrywatna;

//Zwolnienie pamieci argumentu

    free(arg);

//Otwarcie mutexu z wlasnosci mutexu tylko przez watek ktory go zamknal

    OtwarcieMutexu(&Mutex);

//Zwrocenie wartosci NULL oczekiwanego przez funkcje typu void*, w przeciwnym wypadku -Wall zwroci blad 

    return NULL;
}
int main(int argc, char* argv[]){

//Ustawienie punktu startowego dla generowania liczb pseudolosowych

    srand(time(NULL));

//Wlaczenie migotania i odwrotnego obrazu tekstu

    printf("\033[5;7m");
    printf("Nacisnij klawisz [Enter], uruchomic program");
    getchar();

//Powrocenie do domyslnego trybu wyswietlania tekstu

    printf("\033[0m");

//Obsluga bledow, wyczyszczenie ekranu

    if(system("clear") == -1)
    {
        perror("Blad system\n");
        exit(1);
    }

//Zainicjowanie watkow

    pthread_t Watki[LICZBAWATKOW];

//Utworzenie mutexu

    UtworzenieMutexu(&Mutex);

//Utworzenie watkow, sprawienie ze proces oczekuje na zakonczenie tych watkow

    for(int j = 0; j < LICZBAWATKOW; j++)
    {
        UtworzenieWatku(Watki + j, &Funkcja, j);
    }
    for(int j = 0; j < LICZBAWATKOW; j++)
    {
        OczekiwanieNaWatek(Watki[j]);
    }   

//Usuniecie mutexu
    
    UsuniecieMutexu(&Mutex);

//Obsluga bledow, wyczyszczenie ekranu

    if(system("clear") == -1)
    {
        perror("Blad system\n");
        exit(2);
    }

//Sprawdzenie czy wartosc koncowa jest poprawna

//Wlaczenie pogrubienia i podkreslenia tekstu

    printf("\033[1;4m");

    if(Liczba == LICZBAWATKOW * LICZBASEKCJIKRYTYCZNYCH)
    {
        printf("Zmienna globalna modyfikowana w sekcji krytycznej zgodna z oczekiwana wartoscia iloczynu liczby watkow i liczby sekcji krytycznej wynoszacej: %d\n", Liczba);
    }
    else
    {
        printf("Zmienna globalna modyfikowana w sekcji krytycznej wynoszaca: %d, nie zgodna z oczekiwana wartoscia iloczynu liczby watkow i liczby sekcji krytycznej wynoszacej: %d\n", Liczba, LICZBAWATKOW * LICZBASEKCJIKRYTYCZNYCH); 
    }

//Powrocenie do domyslnego trybu wyswietlania tekstu

    printf("\033[0m");

    return 0;
}