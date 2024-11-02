#include "KlasaUzupelniajaca.h" //Klasa z Order
#include <fstream>
#include <algorithm>
#include <iterator>

int main()
{
    ifstream ifs{"dane.txt"};
    if(!ifs)
    {
        cerr<<"Blad otwarcia pliku1"<<endl;
        return -1;
    }
    ifstream ifs1{"dane1.txt"};
    if(!ifs)
    {
        cerr<<"Blad otwarcia pliku1"<<endl;
        return -1;
    }
    ifstream ifs2{"dane2.txt"};
    if(!ifs)
    {
        cerr<<"Blad otwarcia pliku1"<<endl;
        return -1;
    }
    ofstream ofs{"zapis.txt"};
    ofstream ofs1{"zakupy1.txt"};
    ofstream ofs2{"zakupy2.txt"};
    istream_iterator<Order> it{ifs};
    istream_iterator<Order> eos{};
    vector<Order> vec{};
    istream_iterator<Order> it1{ifs1};
    istream_iterator<Order> eos1{};
    vector<Order> vec1{};
    istream_iterator<Order> it2{ifs2};
    istream_iterator<Order> eos2{};
    vector<Order> vec2{};
    copy(it,eos,back_inserter(vec));
    copy(it1,eos1,back_inserter(vec1));
    copy(it2,eos2,back_inserter(vec2));
    vector<Zakup> ksiazki{};
    vector<Zakup> ksiazki1{};
    vector<Zakup> ksiazki2{};
    for(auto&x:vec)
    {
        vector<Zakup> order_books = x.get_zakupy();
        copy(order_books.begin(), order_books.end(), back_inserter(ksiazki));
    }
    for(auto&y:vec1)
    {
        vector<Zakup> order_books1 = y.get_zakupy();
        copy(order_books1.begin(), order_books1.end(), back_inserter(ksiazki1));
    }
    for(auto&z:vec2)
    {
        vector<Zakup> order_books2 = z.get_zakupy();
        copy(order_books2.begin(), order_books2.end(), back_inserter(ksiazki2));
    }
    copy(ksiazki.begin(), ksiazki.end(), ostream_iterator<Zakup> {ofs,"\n"});
    copy(ksiazki1.begin(), ksiazki1.end(), ostream_iterator<Zakup> {ofs1,"\n"});
    copy(ksiazki2.begin(), ksiazki2.end(), ostream_iterator<Zakup> {ofs2,"\n"});
    //copy(vec.begin(),vec.end(),ostream_iterator<Order>{ofs,"\n"});
    ifs.close();
    ofs.close();
    ifs1.close();
    ofs1.close();
    ifs2.close();
    ofs2.close();
    return 0;
}