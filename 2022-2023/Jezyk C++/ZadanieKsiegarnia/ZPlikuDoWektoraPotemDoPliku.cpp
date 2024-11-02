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
    vector<Order> orders_vector{};
    Order order;
    while(ifs>>order)
    {
        orders_vector.push_back(order);
    }
    vector<Order>::iterator it;
    for(it=orders_vector.begin();it!=orders_vector.end();it++)
    {
        ofs<<*it<<endl;
    }
    ifs.close();
    ofs.close();
    return 0;
}