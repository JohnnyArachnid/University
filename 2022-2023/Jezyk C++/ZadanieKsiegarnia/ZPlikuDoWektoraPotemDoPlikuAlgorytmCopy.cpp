#include "KlasaUzupelniajaca.h"
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
    ofstream ofs{"zapis.txt"};
    istream_iterator<Order> it{ifs};
    istream_iterator<Order> eos{};
    vector<Order> vec{};
    copy(it,eos,back_inserter(vec));
    copy(vec.begin(),vec.end(),ostream_iterator<Order>{ofs,"\n"});
    ifs.close();
    ofs.close();
    return 0;
}