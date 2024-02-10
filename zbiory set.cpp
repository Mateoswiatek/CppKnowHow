Zbiór jest kontenerem, który przechowuje unikalne wartości elementów.
Szablon definiuje trzy podstawowe metody:
    insert() – dodaje element
    empty() – testuje czy zbiór jest pusty
    find() – znajduje element w zbiorze
Zbiór jest implementowany jako drzewo, dlatego elementy zbioru muszą spełniać takie same
wymagania dotyczące interfejsu, jak klucze dla słownika: definiować operator <.

#include <set>
int main()
{
    set<int> cont;
    cout<<(cont.empty()?"empty":"!empty")<<endl;
    for(int i=10;i>=0;i--)cont.insert(i);
    for(int i=5;i<15;i++)cont.insert(i);
    cout<<(cont.empty()?"empty":"!empty")<<endl;

    const auto it = cont.find(10);
    if(it != cont.end())cout<<"has:"<<*it<<endl;

    for(auto it=cont.begin();it!=cont.end();it++)
        cout<<*it<<" ";
    cout<<endl;
}
// empty
// !empty
// has:10
// 0 1 2 3 4 5 6 7 8 9 10 11 12 13 14

#include <iostream>
#include <string>
#include <set>
#include <algorithm>
#include <cstdlib>
using namespace std;
class A{
public:
    int v = random()%100;
    bool operator<(const A&other)const{
        return v<other.v;
    }
};
int main()
{
    set<A> s;
    for(int i=0;i<20;i++)s.insert(A());;
    for(auto &a:s){
        cout<<a.v<<" ";
    }
}
// 15 21 26 27 35 36 40 49 59 62 63 72 77 83 86 90 92 93