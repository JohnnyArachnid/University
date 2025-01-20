# KarkMPK 

KrakMPK to aplikacja internetowa umożliwiająca zakup biletów do komunikacji miejskiej w Krakowie.


## Uruchomienie aplikacji

Aby uruchomić aplikację należy pobrać projekt z repozytorium.
    
## Aplikacja zawiera następujące funkcjonalności:

 - Inteligentny zakup biletu.

    Opcja dedykowana użytkownikom, którzy nie wiedzą jaki bilet powinni kupić, ale znają przystanek początkowy i końcowy. Po wprowadzeniu nazw przystanków, daty i godziny odjazdu aplikacja inteligentnie zaproponuje bilet, który umożliwi przejazd na podanym odcinku. Aplikacja sprawdzi czas przejazdu między podanymi przystankami i zaproponuje bilet czasowy lub np. jednoprzejazdowy. Proponowane bilety będą wyświetlały się w kolejności od najbardziej korzystnej opcji. Opcja ta umożliwia dodanie przystanku pośredniego oraz wybranie biletu z ulgą lub bez.
    
 - Szybki zakup biletu.

    Opcja dla użytkowników obeznanych z komunikacją miejską w Krakowie, którzy wiedzą jaki konkretnie bilet jest im potrzebny i chcą szybko go kupić. Możliwość filtracji dodatkowo przyspiesza znalezienie interesującego biletu. Użytkownik może wybrać kilka biletów w dowolnych ilościach i kupić wszystkie za jednym razem.

 - Sprawdzenie map i schematów Krakowa.

    Użytkownik może sprawdzić mapy i schematy przedstawiające linie komunikacji miejskiej i strefy biletowe Krakowa.

 - Sprawdzenie rozkładu jazdy.

    Użytkownik może sprawdzić rozkład jazdy wybranej linii tramwajowej lub autobusowej.

 - Zmiana języka na angielski.

    Aplikacja umożliwia wygodne korzystanie użytkownikom anglojęzycznym, dzięki czemu jest dostosowana dla turystów odwiedzających Kraków.

## Dla zalogowanych użytkowników dodatkowo dostępne są:
 - Zapisanie ulubionych biletów.

    Opcja ta umożliwia bardzo szybki zakup biletu użytkownikom korzystającym z komunikacji miejskiej na co dzień, którzy zwynajczęściej poruszają się tymi samymi liniami i często potrzebują szybko kupić ten sam bilet.

 - Historia zakupów.
    Użytkownik może kupić bilet z historii zakupów.

 - Zapisanie biletów do teczki.
     
    Po zakupie biletów oprócz opcji pobrania, która natychmiastowo aktywuje bilet, użytkownik może dodać kupiony bilet do teczki i aktywować go w dowolnym momencie. 

## Aktywacja biletów
Bilety mają formę kodu QR, który należy pokazać kontrolerowi. Bilet automatycznie aktywuje się po pobraniu lub jeśli bilet został zakupiony wcześniej i znajduje się w teczce, należy go aktywować samodzielnie tuż przed skorzystaniem z komunikacji miejskiej.

## Sposoby płatności
Użytkownicy mają udostępnione dwa sposoby płatności: płatność blikiem lub kartą. W przypadku zalogowanego użytkownika, jego karta zapisywana jest podczas rejestracji, co umożliwia szybsze dokonywanie zakupów.

## Koszyk
Podczas zakupów użytkownik może dodać wybrane bilety do koszyka, a następnie kontynuować zakupy za pomocą dowolnej opcji zakupu biletu. Koszyk jest dostępny zarówno dla zalogowanych, jaki i niezalogowanych użytkowników.
