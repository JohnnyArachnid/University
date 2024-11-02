// Autor: Daniel Szarek,                           Krakow, 24.05.2023r.


//Plik Naglowkowy

#include "obsluga_kolejki_komunikatow.h"

//Funkcje do usuwania kolejki komunikatow

void CzyszczenieAtexit(void)
{
    UsunKolejkeKomunikatow(NAZWAKOLEJKIKOMUNIKATOWSERWERA);
}

void CzyszczenieAtexitSygnal(int sig)
{
    printf("\nZakonczenie dzialanie serwera\n");
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

    mqd_t Serwer,Klient;

//Utworzenie kolejki komunikatow serwera

    Serwer = UtworzKolejkeKomunikatow(NAZWAKOLEJKIKOMUNIKATOWSERWERA);
    char TrescKomunikatu[ROZMIARTRESCIKOMUNIKATUWYSYLANIA],NazwaKolejkiKomunikatowKLienta[DLUGOSCNAZWYKOLEJKIKOMUNIKATOW];
    int RozmiarNazwy;

//Wprawienie serwera w stala gotowosc na odbior kolejek

    while(1)
    {

//Odebranie komunikatu wyslanego przez klienta przez serwer

        OdbiorKomunikatu(Serwer,TrescKomunikatu);

//Uzyskanie Pid procesu realizujacy program klienta

        int PidKlienta = atoi(TrescKomunikatu);

//Utworzenie nazwy kolejki komunikatow klienta

        RozmiarNazwy = snprintf(NazwaKolejkiKomunikatowKLienta,DLUGOSCNAZWYKOLEJKIKOMUNIKATOW,"%s%d",POCZATEKNAZWY,PidKlienta);


//Obsluga bledu, sprawdzam czy nazwa kolejki komunikatow klienta zostala utworzonona prawidlowo

        if(RozmiarNazwy < 0 || RozmiarNazwy >= DLUGOSCNAZWYKOLEJKIKOMUNIKATOW)
	    {
            perror("Blad snprintf\n");
            exit(4);
	    }

//Otworzenie kolejki komunikatow klienta

        Klient = OtworzKolejkeKomunikatow(NazwaKolejkiKomunikatowKLienta);

//Uzyskanie liczb oraz znaku operacji z komunikatu klienta

        double LiczbaPoprzednik, LiczbaNastepnik, LiczbaWynik;
        char ZnakOperacjiArytmetycznej;

//Obsluga bledu, sprawdzam czy dane z komunikatu klienta zostaly uzyskane prawidlowo

        if(sscanf(TrescKomunikatu,"%*d %lf %c %lf",&LiczbaPoprzednik,&ZnakOperacjiArytmetycznej,&LiczbaNastepnik) == EOF)
        {
            perror("Blad sscanf\n");
            exit(5);
        }

//Wykonanie dzialania arytmetycznego na dwoch liczbach podanych w komunikacie

        switch(ZnakOperacjiArytmetycznej)
        {
            case '+':
                LiczbaWynik = LiczbaPoprzednik + LiczbaNastepnik;
                break;
            case '-':
                LiczbaWynik = LiczbaPoprzednik - LiczbaNastepnik;
                break;
            case '*':
                LiczbaWynik = LiczbaPoprzednik * LiczbaNastepnik;
                break;
            case '/':
                LiczbaWynik = LiczbaPoprzednik / LiczbaNastepnik;
                break;
        }

//Utworzenie tresci komunikatu serwera

        RozmiarNazwy = snprintf(TrescKomunikatu,ROZMIARTRESCIKOMUNIKATUWYSYLANIA,"%lf",LiczbaWynik);

//Obsluga bledu, sprawdzam czy tresc komunikatow serwera zostala utworzonona prawidlowo

        if(RozmiarNazwy < 0 || RozmiarNazwy >= ROZMIARTRESCIKOMUNIKATUWYSYLANIA)
	    {
            perror("Blad snprintf\n");
            exit(6);
	    }

//Wyslanie komunikatu serwera do klienta

        WyslanieKomunikatu(Klient,TrescKomunikatu);

//Zamkniecie kolejki komunikatu klienta

        ZamknijKolejeKomunikatow(Klient);
    }
    return 0;
}