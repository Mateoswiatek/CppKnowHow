#include <iostream>
using namespace std;

Wszystko jest w pamięci,
adres - nieujemna liczba całkowita

Wskaźniki to zmiene których wartościami są adresy. mozna:
    - odczytać, zmodyfikować wartość zmiennej
    - wywołać funkcję
Zmienne wskaźnikowe mają OKRESLONE TYPY - kompilator wie ile miejsca zajmuje wskazywany element i jak interpretowac dane.
int* p = 102;
int i = -2; // w komórce numer 102 jest -2

deklaracje:
składnia:
type-specifier * pointer; type- definuje typ wskazywanego obiektu, pointer - identyfikator zmiennej

int *pi, tab[10]; //pi to wskaźnik na inta, tab[10] to normalna tablica
double *pd;
float*px,*py,x,y;

Operatory moliwe na wskaźnikach:
adresu (&) - argumentem musi byc obiekt który jest w pamięci (zmienna, identyfikator funkcji)
    nie można zmiennych rejestrowych i pól bitowych

int x;
int *px;
px=&x; // pobranie adresu gdzie ta zmienna się znajduje

i dereferencji (*)
*px = 7; // odwołanie się do zawartości wskaźnika, odwołanie do tego na co wskazuje
printf("%d", *px + 3 ); // wypisze 10, bo *px to 7

nie powinno się dereferencji do niezainicjowanych zmiennych (albo mających takie
wartości jak 0 lub NULL)
int *pi, *pj=NULL;
printf("%d", *pi); // to te bez sensu trochę, ale odcytać "nic" można
*pj = 7; // się tu zawiesi bo zawartość NULLA, WTF

Deklaracja przydziela pamięć, ale wskaźnik nie musi wskazywać na coś.
int *pi;
int i;
pi=&i;
można odrau
int i, *pi=&i;

Typ argumentu określa typ zwracanego wyrażenia: jeżeli wskaźnik jest typu TYPE* zwracane wyrażenie jest typu TYPE
*(int*)20000=7; // zawartość  wskaźnika typu int, w komórce pamięci numer 20000 jest int, i ma byc treraz równy 7
// ale nie *20000

i=10
j = *&i; // zawartość &i, &i to adres komórki w której jest zmienna i. więc * odczytuje zawartośc i
// ale nie j=&*i; bo to byłoby, operator * zwraca lvalue, czyli on musi byc najbardiej po lewo. tyle

int x=1, *px=&x;
int y=2, *py=&y;

*px = *py; // przypisanie zawartości, czyli x = y, spełnione *px==*py
px=py; // wskaźniki wskazują na ten sam obszar *px = 2, spełnione px==py i *px==*py

operator kropkowy "." do pól i struktór ma więksy priorytet ni dereferencji:

struct complex {double re; double im;};
struct complex vx={1,0};
struct complex *pc=&vx;
printf("(%f,%f)",*pc.re,*pc.im); // będie błąd, bo wskaźnik jest do struktury, a tu dostaje "na pole" więc treba
albo nawias, albo operator ->
(*pc).re; albo pc->re;

Do
    modyfikacji obiektu definiowanego poa funkcją
    ustalenie powiąań międy obiektami
    dane tworzone dynamicnie (tablice, listy, drewa)
    polimprfim w Cpp;

przykłady

// będie 2 3 3
void foo(int *px){ // px jest wskaźnikiem, więc musimy przekazać adres, to takk jakby int *px=(to co wprowadamy)
    (*px)++;
    printf("x in foo = %d\n", *x);
}

int main(){
    int x = 2; // tworzymy normalnie
    printf("x in main=%d", x);
    foo(&x);
    printf("x in main=%d", x);
}


void min_max(int tab[],int n,int*min,int*max){
    int i;
    *max=*min=tab[0]; // zawartośc min i maxa ustawiamy na wartość pierwsego elementu
    for(i=0;i<n;i++){ // sprawdamy każdy, można dać i=1, bo pierwszego nie musimy sprawdać
        if(*min>tab[i])*min=tab[i]; // jesli awartość min jest większe od tab[i], to nowym min staje się zawartość tab[i]
        if(*max<tab[i])*max=tab[i];
    }
}
// sizeof t/sizeof t[0] - ilość elementów w tablicy
int main()
{
    int min_var, max_var;// nasze zmienne
    int t[]={3,4,7,2,-2,234};
    min_max(t,sizeof t/sizeof t[0],&min_var,&max_var);
    printf("min = %d max = %d\n",min_var, max_var);
    return 0;
}

// zespolone
struct complex {double re,im;};

void init(struct complex*pc,double x,double y){ // dostajemy w pc adres naszej liczby.
    pc->re=x; // -> działa na wskaźnikach
    pc->im=y;
    (*pc).im=y; // równoważne
}
void add(struct complex*c, struct complex*a, struct complex*b){
    c->re=a->re + b->re;
    c->im=a->im + b->im;
}
double module(struct complex*c) {
    return(sqrt(c->re * c->re + c->im * c->im));
}

void dump(struct complex*c) {
    printf("(%f, %f) ",c->re,c->im);
}
int main()
{
    struct complex c1,c2,c3;
    init(&c1,12.34,1.5); // inicjalizacja, chcemy zmodyfikować c1
    dump(&c1);
    init(&c2,-12.34,1.5);
    dump(&c2);
    add(&c3,&c1,&c2);
    dump(&c3);
    return 0;
}
