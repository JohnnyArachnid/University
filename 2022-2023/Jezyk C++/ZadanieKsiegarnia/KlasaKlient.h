#include <string>
#include <iostream>

using namespace std;

class Klient
{
    string imie;
    string nazwisko;
    string adres;
    public:
        Klient(string i, string n, string a): imie{i},nazwisko{n},adres{a} {}
        Klient() = default;
        string get_Imie()const{return imie;};
        void set_Imie(string i){imie=i; return;}
        string get_Nazwisko()const{return nazwisko;};
        void set_Nazwisko(string n){nazwisko=n; return;}
        string get_Adres()const{return adres;};
        void set_Adres(string a){adres=a; return;}
};

ostream&operator<<(ostream &os, const Klient &c)
{
    os<<c.get_Imie()<<" "<<c.get_Nazwisko()<<" "<<"\n"<<c.get_Adres()<<endl;
    return os;
}

istream&operator>>(istream &is, Klient &c)
{
    string imie,nazwisko,adres;
    is>>imie>>nazwisko;
    is.ignore(100,'\n');
    getline(is,adres);
    c.set_Imie(imie);
    c.set_Nazwisko(nazwisko);
    c.set_Adres(adres);
    return is;
}