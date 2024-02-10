Klasa std::string reprezentującą tablicę znakową, która może dynamicznie zmieniać swoje rozmiary.
Poza funkcjami do zarządzania pamięcią, klasa zawiera szereg metod umożliwiających dostęp
do znaków lub działania na całych tekstach (konkatenacja, usuwanie, wstawianie, zastępowanie, itd.)

capacity() - Zwraca rozmiar bufora.
size() lub length() - Zwraca długość tekstu (liczbę znaków umieszczonych w buforze).
reserve (size_type n =0) - Zmienia rozmiary bufora. Gwarantuje, że po jej wykonaniu funkcja
capacity() będzie zwracała co najmniej n.

resize(size_type n, E c = E()) - Gwarantuje, że funkcja size()będzie zwracała co najmniej n.
W razie potrzeby powiększa tablicę i wypełnia znakiem c.

c_str() - zwraca const char* // do funkcji które tego wymagają
        operator [] - dostęp do znaku
append()  - przeciążone, do dodawania lub + / +=
substr()  - wyodrębnianie fragmentów, indeks początku, długość
erase()   - przeciążone, usuwanie fragmetu / całego tekstu
insert()  - przeciązona, wstawianie fragmentów
find()    - znajdywanie / wytępienie znaków, mozna 2 argumenty, co ma znaleźć i od którego miejsca ma szukać, jak nie ma to npos
replace() - zamiana danego fragmentu innym. od którego miejsca, długość tekstu do wymiany, trzeci - tekst którym zastapimy

#include <string>
#include <iostream>
#include <fstream>
using namespace std;
int main(int argc, char* argv[]){
    string s;
    ifstream is("readme.txt"); // is to plik
    s.reserve(40); // rezerwujemy 40 znaków
    for(int i=0;;i++){ // zwiększamy i bez ograniczeń
        int c=is.get(); // c to aktualny kod asci znaku, bo get zwraca kod ASCII, jesli EOF no to koniec pliku
        if(c<0)break; // jesli c jest mniejsze od 0, czyli jeśli już nie ma więcej liter do odczytu to break
        s+=(char)c; // lub: s.append(1,c); dodajemy do s aktualny znak z pliku
        if(i%100==0){ //100, 200, 300 etc
            cout<<s.capacity()<<" "; // tu jaka jest pojemność
            cout<<"("<<s.size()<<") "; // ile jest faktycznie
        }
    }
    cout<<endl<<s;
    return 0;
}

Metoda zwraca stały wskaźnik do tekstu. Może być użyta tam, gdzie wymagane jest użycie danych typu const char*.
int main(){
    string s="Tekst";
    cout<<strcmp(s.c_str(),"Tekst")<<endl;
}

operator [] - dostęp do znaków
int main(){
    string s="Ala ma kota";
    for(int i=0;i<s.size();i++){
        s[i]+=3;
    }
    cout<<s<<endl;
    for(int i=0;i<s.size();i++){
        s[i]+=253;
    }
    cout<<s<<endl;
}
/*
 * Dod#pd#nrwd
 * Ala ma kota
 *
 */

Do konkatenacji (łączenia) tekstów służy metoda append()
występująca w kilku przeciążonych wersjach lub operatory
+ i +=.
int main(int argc, char* argv[])
{
    string s("Ala ma");
    s.append(" kota");
    s+=" i psa";
    cout<<endl<<s;
    return 0;
}

Do wyodrębniania fragmentów tekstu służy metoda substr(). Jej parametrami są indeks
początkowy i długość tekstu.
int main(int argc, char* argv[])
{
    string s="abcdefgijklmn";
    cout<<s.substr(3,3)<<endl;
    return 0;
}
//def

Usuwanie fragmentu tekstu
W klasie string zdefiniowano kilka przeciążonych wersji metody erase() pozwalającej
na usuwanie fragmentów (lub całego) tekstu.

int main(int argc, char* argv[])
{
    string s="abcdefgijklmn";
    int n1= s.find('d');
    int n2 = 3; // ile znakow
    s.erase(n1,n2);
    cout<<s<<endl;
    return 0;
}
//abcgijklmn


Do wstawiania fragmentów tekstu służy (przeciążona na kilka sposobów) funkcja insert(). Funkcja wstawia w
miejsce określone przez indeks lub iterator tekst, który może być tablicą znaków, fragmentem
innego obiektu klasy string lub sekwencją identycznych znaków.

int main(int argc, char* argv[]){
    string s("Ala ma kota");
    s.insert(strlen("Ala ma "), "psa i ");
    cout<<s<<endl;
    s="abcdefgijklmn";
    s.insert(1,2,'x');
    cout<<s<<endl;
    return 0;
}
// Ala ma psa i kota
// axxbcdefgijklmn

znajdywanie i zastępowanie
Funkcja find() pozwala na wyszukanie w tekście łańcucha znaków lub wystąpienia znaku. Funkcja
replace() pozwala na zastąpienie wskazanego fragmentu tekstu innym.

int main(int argc, char* argv[])
{
    string s("Witaj $user, jestes zalogowany");
    string userTag="$user";
    int start=s.find(userTag);
    s.replace(start,userTag.size(),"Piotr Szwed");
    cout<<s<<endl;
    return 0;
}
// Witaj Piotr Szwed, jestes zalogowany