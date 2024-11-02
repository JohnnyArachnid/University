// Autor: Daniel Szarek,                           Krakow, 04.05.2023r.

//Liczba elementow bufora

#define NBUF 5

//Rozmiar elementu bufora (jednostki towaru) w bajtach

#define NELE 50

//Segment Pamieci Dzielonej

typedef struct {
  char Bufor[NBUF][NELE];
  int Dodaj,Uzyskaj,Rozmiar,Koniec;
}SegmentPD;

//Utworzenie obiektu pamieci dzielonej

int UtworzObiektPamieci(char * nazwa);

//Otworzenie obiektu pamieci dzielonej z odwzorowanie pamieci

int OtworzObiektPamieci(SegmentPD ** adres, char * nazwa, int prot, int flagi);

//Zamknięcie obiektu pamieci dzielonej bez odwzorowania pamieci

void ZamknijObiektPamieci(int deskryptor);

//Zamknięcie obiektu pamieci dzielonej z odwzorowaniem pamieci

void ZamknijObiektPamieciZOdwzorowaniem(int deskryptor, SegmentPD * adres);

//Usuniecie obiektu pamieci dzielonej

void UsunObiektPamieci(char * nazwa);
