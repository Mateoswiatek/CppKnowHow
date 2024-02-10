Szablon definiuje listę dwukierunkową.
Wektor, lista mogą być parametryzowane elementami dowolnego typu… za pomocą auto
for(auto&e:lst){}

Możliwe jest:
    – dodawanie elementów na początku i końcu listy,
    – wstawianie, usuwanie, łączenie ze sobą list.
    – automatyczne sortowanie listy.

Nie jest możliwy swobodny dostęp do elementów za pośrednictwem operatora [].

Lista jest efektywna, jeżeli liczba elementów i ich miejsce wstawienia nie są z góry określone.

Iteracja po liście wymaga użycia iteratorów albo pętli range-based for

Funkcja emplace_back() – woła „w miejscu”
konstruktor przekazując mu parametry z zewnątrz.
Czasem wygodniejsze…

#include<list>
using namespace std;
int main(){
    list<int> lst{11,23,123,11,4,56,-9,};
    for(int e:lst){
        cout<<e<<" ";
    }
}

int main(){
    list<int> lst{11,23,123,11,4,56,-9,};
    for(int i=0;i<5;i++){
        lst.push_back(i);
        lst.push_front(i);
    }
    for(int e:lst){
        cout<<e<<" ";
    }
    cout<<endl;
    lst.sort();
    for(int e:lst){
        cout<<e<<" ";
    }
}
// 4 3 2 1 0 11 23 123 11 4 56 -9 0 1 2 3 4
// -9 0 0 1 1 2 2 3 3 4 4 4 11 11 23 56 123

auto
int main(){
    list<string> lst{"Ala","ma","kota"};
    for(const string& e:lst){
        cout<<e<<" ";
    }
    cout<<endl;
    lst.sort();
    for(auto&e:lst){ // Jeżeli użyjemy auto kompilator sam wywnioskuje, jakiego typu jest zmienna
        cout<<e<<" ";
    }
}
//Ala ma kota
//Ala kota ma

class Student{
public:
    string imie;
    string nazwisko;
    int nr_legitymacji;
};
int main(){
    vector<Student> grupa;
    Student jk;
    jk.imie = "Jan";
    jk.nazwisko = "Kowalski";
    jk.nr_legitymacji=1234;
    grupa.push_back(jk);
    for(int i=0;i<grupa.size();i++){
        cout<<grupa[i].imie<<" "<<grupa[i].nazwisko<<" "
            <<grupa[i].nr_legitymacji<<endl;
    }
}

emplace_back() - woła w miejscu konstruktor, przekazując parametry
class Student{
public:
    Student(const char*im,const char*naz,int nr)
            :imie(im), nazwisko(naz),nr_legitymacji(nr){}
    string imie;
    string nazwisko;
    int nr_legitymacji;
};
int main(){
    vector<Student> grupa;
    grupa.emplace_back("Jan","Kowalski",1234);
    grupa.emplace_back("Anna","Nowak",1235);
    for(int i=0;i<grupa.size();i++){
        cout<<grupa[i].imie<<" "<<grupa[i].nazwisko<<" "
            <<grupa[i].nr_legitymacji<<endl;
    }
}
// Jan Kowalski 1234
// Anna Nowak 1235
