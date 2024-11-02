#include "KlasaUzupelniajaca.h"
#include <fstream>
#include <algorithm>
#include <iterator>

int main()
{
    ifstream ifs1{"zakupy1.txt"};
    if(!ifs1)
    {
        cerr<<"Blad otwarcia pliku1"<<endl;
        return -1;
    }
    ifstream ifs2{"zakupy2.txt"};
    if(!ifs2)
    {
        cerr<<"Blad otwarcia pliku2"<<endl;
        return -1;
    }
    istream_iterator<Zakup> it1{ifs1};
    istream_iterator<Zakup> it2{ifs2};
    istream_iterator<Zakup> eos1{};
    istream_iterator<Zakup> eos2{};
    vector<Zakup> vec1{};
    vector<Zakup> vec2{};
    copy(it1,eos1,back_inserter(vec1));
    copy(it2,eos2,back_inserter(vec2));
    sort(vec1.begin(), vec1.end());
    sort(vec2.begin(), vec2.end());
    //cout<<vec1.size()<<" "<<vec2.size()<<endl;
    vector<Zakup> vec{};
    vec.resize(vec1.size() + vec2.size());
    //cout<<vec.size()<<endl;
    vector<Zakup>::iterator vit;
    //merge(vec1.begin(), vec1.end(), vec2.begin(), vec2.end(), vec.begin());
    vit = set_union(vec1.begin(), vec1.end(), vec2.begin(), vec2.end(), vec.begin());
    vec.resize(distance(vec.begin(),vit));
    sort(vec.begin(), vec.end());
    cout<<vec.size()<<endl;
    ofstream ofs{"zapis.txt"};
    copy(vec.begin(), vec.end(), ostream_iterator<Zakup> {ofs,"\n"});
    ifs1.close();
    ifs2.close();
    ofs.close();
    return 0;
}