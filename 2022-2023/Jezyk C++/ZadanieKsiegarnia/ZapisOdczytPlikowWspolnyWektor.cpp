#include "class.h"
#include <fstream>
#include <vector>
#include <algorithm>
#include <iterator>


using namespace std;

bool Porownanie(Klient k1, Klient k2)
{
    return k1.get_Nazwisko()<k2.get_Nazwisko();
}

bool CzyRowne(Klient k1, Klient k2)
{
    return k1.get_Imie() == k2.get_Imie() && k1.get_Nazwisko() == k2.get_Nazwisko();
}

int main()
{   
    ifstream ifs1{"dane1.txt"};
    ifstream ifs2{"dane2.txt"};
    if(!ifs1)
    {
        cerr<<"Blad otwarcia pliku1"<<endl;
        return -1;
    }
    if(!ifs2)
    {
        cerr<<"Blad otwarcia pliku2"<<endl;
        return -1;
    }
    Klient klient{};
    vector<Klient> Klienci1{};
    vector<Klient> Klienci2{};
    string s1;
    string s2;
    while(ifs1>>klient)
    {
        Klienci1.push_back(klient);

        while(getline(ifs1,s1) && s1!="");
    }
    while(ifs2>>klient)
    {
        Klienci2.push_back(klient);

        while(getline(ifs2,s2) && s2!="");
    }
    cout<<"Wczytano z pliku1:"<<Klienci1.size()<<endl;
    cout<<"Wczytano z pliku2:"<<Klienci2.size()<<endl;
    ifs1.close();
    ifs2.close();
    sort(Klienci1.begin(),Klienci1.end(),Porownanie);
    sort(Klienci2.begin(),Klienci2.end(),Porownanie);
    vector<Klient> Klienci_Merge(Klienci1.size()+Klienci2.size());
    merge(Klienci1.begin(),Klienci2.end(),Klienci2.begin(),Klienci2.end(),Klienci_Merge.begin(),Porownanie);
    Klienci_Merge.resize(distance(Klienci_Merge.begin(),unique(Klienci_Merge.begin(),Klienci_Merge.end(), CzyRowne)));
    cout<<"Rozmiar merge Vectorow:"<<Klienci_Merge.size()<<endl;
    ofstream ofs("zapis.txt");
    /*for(int i=0;i<Klienci_Merge.size();++i)
    {
        ofs<<Klienci_Merge[i]<<endl;
    }*/
    ostream_iterator<Klient> out_it(ofs,"\n");
    copy(Klienci_Merge.begin(),Klienci_Merge.end(),out_it);
    ofs.close();
    
    /*ofstream ofs1{"klienci1.txt"};
    ofstream ofs2{"klienci2.txt"};

    //for(vector<Klient>::iterator it = Klienci.begin();it!=Klienci.end();++it) - Pierwszy sposob deklaracji pentli drugi ponizej, dzialaja tak samo
    /*for(Klienci k: klienci)
    {
        fout<<k<<std::endl;
    }
    */
   /*for(auto it: Klienci)
    {
        ofs<<it<<endl<<endl;
    }
    for(auto it1 = Klienci1.begin();it1!=Klienci1.end();++it1)
    {
        ofs1<<*it1<<endl<<endl;
    }
    for(auto it2 = Klienci2.begin();it2!=Klienci2.end();++it2)
    {
        ofs2<<*it2<<endl<<endl;
    }
    ofs1.close();
    ofs2.close();
    */

    return 0;
}