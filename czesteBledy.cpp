#include <iostream>

skrót
\n > endl

int main() {
    std::cout<<"tekst" << std::endl; // BAD
    std::cout<<"tekst" << '\n';      // GOOD
    // endl to manipulator strumienia - wstawienie znaku nowej linii i opróżnienie bufora strumienia std::flush. dłużej
    // \n + std::flush. natychmiast wypluwa bufor.
}

void init(StrComplex*pc, double _x, double _y) // przekazywane są z _zmienna aby odróżnic od globlanych
{
    pc->x=_x ;pc->y=_y;
}



[[nodiscard]] int calculate(int x, int y) { // dla kompilatora i PROGRAMISTÓW, że wynik nie powinien być ignorowany.
                        // np jakieś ważne dane, stan, np wskaźnik na zasób, który musi być zwolniony po użyciu.
                        // Zignorowanie może prowadzić do wycieków pamieci
    return x + y;
}

int main() {
    calculate(3, 4); // Warning: Ignoring return value of function declared with 'nodiscard' attribute
    return 0;
}

// this do asocjacji
class Owner;
class Child{
public:
    Owner*owner;
};

class Owner
{
public:
    void add (Child*child){
        child->owner=this; // przypisujemy dziecko do właściciela
        children.push_back(child);
    }
private:
    list<Child*> children;
};

int x;
int *p_tab=&x;
*(p_tab+1) // przesunięcie o jeden cały wksźnik
