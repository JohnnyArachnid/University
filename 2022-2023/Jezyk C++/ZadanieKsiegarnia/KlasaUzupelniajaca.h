#include <vector>
#include <sstream>
#include "KlasaKlient.h"


class Zakup
{
    string tytul;
    int ilosc;
    double cena;
    public:
        friend istream& operator>>(istream &is, Zakup &o)
        {
            getline(is,o.tytul,'|');
            is>>o.cena;
            char znak;
            is>>znak;
            is>>o.ilosc;
            return is;
        }
        friend ostream& operator<<(ostream &os, const Zakup &o)
        {
            os<<o.tytul<<" | "<<o.cena<<" | "<<o.ilosc;
            return os;
        }
        bool operator<(const Zakup &zakup)
        {
            return this->tytul<zakup.tytul;
        }
        bool operator==(const Zakup &zakup)
        {
            return this->tytul==zakup.tytul;
        }
};


class Data
{
    int day,month,year;
    public:
        Data(int _day,int _month,int _year): day{_day}, month{_month},year{_year} {} 
        Data() = default;
        friend ostream& operator<<(ostream &os, const Data &d)
        {
            os<<d.day<<"."<<d.month<<"."<<d.year;
            return os;
        }
        friend istream& operator>>(istream &is, Data &d)
        {
            char kropka[2];
            is>>d.day>>kropka[0]>>d.month>>kropka[1]>>d.year;
            return is;
        }
};

class Order
{
    Klient klient;
    Data data;
    vector<Zakup> Zakupy;
    public:
        vector<Zakup> &get_zakupy() {return Zakupy;}
        //vector<Zakup> get_zakupy() const {return Zakupy;}
        friend istream& operator>>(istream &is,Order &o)
        {
            is>>o.klient;
            is>>o.data;
            is.ignore(100,'\n');
            o.Zakupy.clear();
            Zakup z{};
            string line;
            while(getline(is,line)&&line!="")
            {
                istringstream iss{line};
                iss>>z;
                o.Zakupy.push_back(z);
            }
            return is;
        }
        friend ostream& operator<<(ostream &os,const Order &o)
        {
            os<<o.klient<<endl;
            os<<o.data<<endl;
            int i;
            for(i=0;i<o.Zakupy.size();i++)
            {
                os<<o.Zakupy[i]<<endl;
            }
            return os;
        }
};