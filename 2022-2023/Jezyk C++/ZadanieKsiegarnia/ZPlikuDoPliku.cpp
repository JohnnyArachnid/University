#include "KlasaUzupelniajaca.h"
#include <fstream>

int main()
{
    ifstream ifs{"dane.txt"};
    if(!ifs)
    {
        cerr<<"Blad otwarcia pliku1"<<endl;
        return -1;
    }
    ofstream ofs{"zapis.txt"};
    Order order;
    while(ifs>>order)
    {
        ofs<<order<<endl;
    }
    ifs.close();
    ofs.close();
    return 0;
}