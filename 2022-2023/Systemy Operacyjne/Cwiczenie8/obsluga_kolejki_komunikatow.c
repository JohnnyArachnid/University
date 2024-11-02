// Autor: Daniel Szarek,                           Krakow, 24.05.2023r.


//Plik Naglowkowy

#include "obsluga_kolejki_komunikatow.h"

//Utworzenie kolejki komunikatow

mqd_t UtworzKolejkeKomunikatow(char * NazwaKolejkiKomunikatow)
{
    mqd_t UtworzonaKolejka;
    UtworzonaKolejka = mq_open(NazwaKolejkiKomunikatow,O_CREAT | O_EXCL | O_RDONLY,0644,NULL);
    if(UtworzonaKolejka == (mqd_t)-1)
    {
        perror("Blad mq_open, utworzenie kolejki\n");
        exit(1);
    }
    return UtworzonaKolejka;
}

//Otworzenie kolejki komunikatow

mqd_t OtworzKolejkeKomunikatow(char * NazwaKolejkiKomunikatow)
{
    mqd_t OtworzonaKolejka;
    OtworzonaKolejka = mq_open(NazwaKolejkiKomunikatow,O_WRONLY);
    if(OtworzonaKolejka == (mqd_t)-1)
    {
        perror("Blad mq_open, otworzenie kolejki\n");
        exit(2);
    }
    return OtworzonaKolejka;
}

//Wyslanie komunikatu do danej kolejki komunikatow

void WyslanieKomunikatu(mqd_t DeskryptorKolejkiKomunikatow, char * TrescKomunikatu)
{
    if(mq_send(DeskryptorKolejkiKomunikatow,TrescKomunikatu,ROZMIARTRESCIKOMUNIKATUWYSYLANIA,0) == (mqd_t)-1)
    {
        perror("Blad mq_send\n");
        exit(3);
    }
}

//Odbior komunikatu z danej kolejki komunikatow

void OdbiorKomunikatu(mqd_t DeskryptorKolejkiKomunikatow, char * TrescKomunikatu)
{
    if(mq_receive(DeskryptorKolejkiKomunikatow,TrescKomunikatu,ROZMIARTRESCIKOMUNIKATUODBIERANIA,0) == (mqd_t)-1)
    {
        perror("Blad mq_receive\n");
        exit(4);
    }
}

//Zamkniecie danej kolejki komunikatow

void ZamknijKolejeKomunikatow(mqd_t DeskryptorKolejkiKomunikatow)
{
    if(mq_close(DeskryptorKolejkiKomunikatow) == (mqd_t)-1)
    {
        perror("Blad mq_close\n");
        exit(5);
    }
}

//Usuniecie danej kolejki komunikatow

void UsunKolejkeKomunikatow(char * NazwaKolejkiKomunikatow)
{
    if(mq_unlink(NazwaKolejkiKomunikatow) == (mqd_t)-1)
    {
        perror("Blad mq_unlink\n");
        exit(6);
    }
}