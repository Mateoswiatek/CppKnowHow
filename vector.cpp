<vector> - nie ma okreslonego typu bo to szablon, dopiero podczas instancji jest nadawany
vector<T>
instancja T=int     vecotr<int>
instancja T=double  vector<double>

Wektor, lista mogą być parametryzowane elementami dowolnego typu…
for(auto&e:vector){}

#include <vector>
#include <iostream>
int main(){
    std::vector<int> liczby;
    for(int i=0;i<20;i++)liczby.push_back(i);
    for(int i=0;i<liczby.size();i++){
        std::cout<<liczby[i]<<" ";
    }
    std::cout<<std::endl;
}

Włączamy nagłówek <vector>
Możemy utworzyć wektor o zadanym rozmiarze
Dodajemy elementy na końcu wektora za pomocą metody push_back()
Metoda size() zwraca rozmiar tablicy (liczbę zajętych elementów)
Operator [] umożliwia dostęp do elementu o danym indeksie
Iterujemy za pomocą pętli
for(int i=0;i<liczby.size();i++){
cout<<liczby[i]<<endl;
}

int main(){
    vector<int> liczby{1,1}; // inicjuje tablicę dwóch jedynek
    while(true){
        int e = liczby[liczby.size()-1]+liczby[liczby.size()-2];
        if(e>200)break;
        liczby.push_back(e);
    }
    //iteracja range-based for
    for(int e:liczby){ // wartość – tylko odczyt
        cout<<e<<" ";
    }
    for(int&e:liczby){ // referencja – możliwa zmiana elementu
        e*=-1;
    }
    for(int e:liczby){
        cout<<e<<" ";
    }
}