// Autor: Daniel Szarek,                           Krakow, 24.05.2023r.


//Plik Naglowkowy

#include "obsluga_kolejki_komunikatow.h"

char NazwaKolejkiKomunikatowKLienta[DLUGOSCNAZWYKOLEJKIKOMUNIKATOW];

//Funkcje do usuwania kolejki komunikatow

void CzyszczenieAtexit(void)
{
    UsunKolejkeKomunikatow(NazwaKolejkiKomunikatowKLienta);
}

void CzyszczenieAtexitSygnal(int sig)
{
    CzyszczenieAtexit();
    _exit(1);
}

int main()
{

//Obsluga bledu, sprawdzam poprawnosc inicjacji funkcji usuwajacej kolejke komunikatow przed zakonczeniem programu

    if(atexit(CzyszczenieAtexit) != 0)
    {
	    perror("Blad atexit\n");
	    exit(2);
    }

//Wlasna obsluga sygnalu podanego w poleceniu, usuwanie kolejki komunikatow

    if(signal(SIGINT,CzyszczenieAtexitSygnal) == SIG_ERR)
    {
	    perror("Blad signal\n");
	    exit(3);
    }

//Zainicjowanie kolejki komunikatow

    mqd_t Klient,Serwer;
    int RozmiarNazwy;

//Utworzenie nazwy kolejki komunikatow klienta

    RozmiarNazwy = snprintf(NazwaKolejkiKomunikatowKLienta,DLUGOSCNAZWYKOLEJKIKOMUNIKATOW,"%s%d",POCZATEKNAZWY,getpid());
    if(RozmiarNazwy < 0 || RozmiarNazwy>=DLUGOSCNAZWYKOLEJKIKOMUNIKATOW)
	{
        perror("Blad snprintf\n");
        exit(4);
	}

//Utworzenie kolejki komunikatow klienta

    Klient = UtworzKolejkeKomunikatow(NazwaKolejkiKomunikatowKLienta);

//Opoznienie w celu unikniecia blednej kolejnosci otwierania kolejek

    sleep(1);

//Otworzenie kolejki komunikatow serwera

    Serwer = OtworzKolejkeKomunikatow(NAZWAKOLEJKIKOMUNIKATOWSERWERA);
    printf("Przekaz tresc dzialania arytmetycznego do wykonania w formie: liczba znak liczba.\n");
    char TrescKomunikatuTymczasowa[ROZMIARTRESCIKOMUNIKATUWYSYLANIA];

//Obsluga bledu, sprawdzam czy dane z terminala zostaly pobrane w prawidlowy sposob

    if(fgets(TrescKomunikatuTymczasowa,ROZMIARTRESCIKOMUNIKATUWYSYLANIA,stdin) == 0)
    {
        perror("Blad fgets\n");
        exit(5);
    }

//Uzyskanie liczb oraz znaku operacji z pobranych z terminala

        double LiczbaPoprzednik, LiczbaNastepnik;
        char ZnakOperacjiArytmetycznej;

//Obsluga bledu, sprawdzam czy dane z terminala zostaly uzyskane prawidlowo

    if(sscanf(TrescKomunikatuTymczasowa,"%lf %c %lf",&LiczbaPoprzednik,&ZnakOperacjiArytmetycznej,&LiczbaNastepnik) == EOF)
    {
        perror("Blad sscanf");
        exit(6);
    }

//Ograniczenie dziedziny liczb przy operacji dzielenia, zwracamy blad przy operacji dzielenia przez 0

    if((ZnakOperacjiArytmetycznej == '/' && LiczbaPoprzednik == 0) || (ZnakOperacjiArytmetycznej == '/' && LiczbaNastepnik == 0))
    {
        perror("Blad, jedna z wartosci liczbowych przy operatorze dzielenia jest rowna 0\n");
        exit(7);
    }

//Utworzenie tresci komunikatu klienta

    char TrescKomunikatu[ROZMIARTRESCIKOMUNIKATUWYSYLANIA];
    RozmiarNazwy = snprintf(TrescKomunikatu,ROZMIARTRESCIKOMUNIKATUWYSYLANIA,"%d %s",getpid(),TrescKomunikatuTymczasowa);

//Obsluga bledu, sprawdzam czy tresc komunikatow klienta zostala utworzonona prawidlowo

    if(RozmiarNazwy < 0 || RozmiarNazwy >= ROZMIARTRESCIKOMUNIKATUWYSYLANIA)
	{
        perror("Blad snprintf\n");
        exit(8);
	}

//Wyslanie komunikatu klienta do serwera

    WyslanieKomunikatu(Serwer,TrescKomunikatu);

//Zamkniecie kolejki komunikatu serwera

    ZamknijKolejeKomunikatow(Serwer);

//Odebranie komunikatu wyslanego przez serwer przez klienta

    OdbiorKomunikatu(Klient,TrescKomunikatu);

//Wypisanie wyniku operacji arytmetycznej podanej przez serwer

    printf("Otrzymany wynik: %s\n",TrescKomunikatu);
    return 0;
}