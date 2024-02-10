#include <iostream>
#include <list>

int main() {
    std::cout << "Hello, World!" << std::endl;

class Room{         // klasa o nazwie room
public:     // część publiczna, dostępna z zewnątrz
    double getArea() const {return _area;} // METODY (funkcje składowe)

private:    // częśc prywatna atrybuty
    double _area; // ATRYBUTY (pola składowe, zmienne)
};
// METODY - za ich pośrednictwem jest dostęp do pól ( danych )
// ATRYBUTY powinny zaczynać się od _nazwa


class Appartment {
public:
    double calculateArea() const; // jeśli metoda nie modyfikuje pól to musi mieć const
private:
    std::list<Room> _rooms; // SKŁADNIK KLASY pole, lista obiektów klasy Room. to jest
};

// GRUPOWANIE ( bez seterow i getterow)
class Adres{
    std::string miescowosc;
    std::string ulica;
    std::string nr_domu;
    std::string nr_lokalu;
    int kod;
};

class Pracownik{
public:
    std::string imie;
    std::string nazwisko;
    std::string pesel;
    Adres adres;
    std::string stanowisko;
};

class Firma{
public:
    std::string nazwa;
    Adres adres;
    std::string nip;
    std::list<Pracownik> pracownicy;
};

// Definiowanie Klas
/*
• komponenty klasy (elementy składowe)
• interfejs klasy (zbiór komunikatów, które obiekt może przyjmować) oraz
• implementację klasy, czyli opis, w jaki sposób obiekt danej klasy będzie reagował w odpowiedzi na wysyłane komunikaty.
*/

class Light{
public:
    // interfejs     implementacja
    void on()      {_voltage = 230;}
    void off(){_voltage = 0;}
    void brighten(){if(_voltage<=220) _voltage+=10;}
    void dim(){if(_voltage>=10) _voltage-=10;}
private:
    double _voltage; // atrybut
};

// tak naprawdę we wszystkich metodach adresy obiektów &lt lub plt są dostarczane do
// metod obiektu jako ich pierwszy (ukryty) argument. O wskaźnikach niżej "Metody Obiektu"
class Light{
public:
    void on(){this->voltage = 230;}
    void off(){this->voltage = 0;}
    void brighten(){if(this->voltage<=220) this->voltage+=10;}
    void dim(){if(this->voltage>=10) this->voltage-=10;}
private:
    double voltage;
};



Light lampa; // stos, alokacja automatyczna, usuwany automatycznie gdy zakres wygasa np gdy funkcja kończy swe działanie
lampa.on(); // wysłanie komunikatu = wywołanie funkji należącej do obiektu


Light*plt = new Light();  // sterta, dynamicznie new. wskaźnik plt wskazuje na instancję. nie jest automatycznie usuwany.
plt->on();
delete plt; // zwolnienie pamięci za pomoca delete wskaźnik

    return 0;
}

// friend deklarację przyjąxni dajemy w klasie która udostępnia
class Klasa
{
private:
    int moj_tajny_int;
    friend class ZaprzyjaznionaKlasa; //friend <deklaracja klasy>
    friend void ZaprzyjaznionaFunkcja( Klasa & ); //friend <deklaracja funkcji> może być też zdefiniowana wewnątrz klasy
    friend void ZaprzyjaznionaFunkcja2 (Klasa & ){ // będziemy przekazywać referencję na klasę
        std::cout << "siemka";
    }
};

class ZaprzyjaznionaKlasa
{
public:
    void metoda( Klasa &k )
    {
        k.moj_tajny_int = 0; //Dostęp do prywatnej składowej innej klasy!
    }
};
void ZaprzyjaznionaFunkcja( Klasa & k )
{
    k.moj_tajny_int = 0; //Jest dostęp!
}
/*
int main()
{
    Klasa k;

    ZaprzyjaznionaKlasa zk;
    zk.metoda( k );
    ZaprzyjaznionaFunkcja( k );
}
*/





// Wyklad2 Wyklad W2 Wykład
// Referencje - "stały" automatyczny wskaźnik
int x=7;
int&r1 = x; // (1)        deklaruje referencję inicjując ją adresem obiektu x.
const int&r2 = 12; // (2)  alokuje pamięć dla zmiennej typu int, inicjuje ją wartością 12 oraz deklaruje referencję, która wskazuje to miejsce
// Wszelkie operacje na referencjach są w rzeczywistości operacjami na obiektach wskazywanych przez referencje.
r1++; // (3) zwiększenie wartości zmiennej x.
printf(”r1=%d, r2=%d”,r1,r2);

// Referencje używanie jako argumenty do funkcji. Obiekty poprzez adres
// poprzez &
// przyklady:
int&rx=x;
void zmiana(int&x){
    x=5;
}
zmiana(rx);
// lub
int x;
void zmiana(int& x){
    x=5;
}
zmiana(x);

void min_max(int tab[],int n,int&min,int&max){ // przekazanie normalne i referencji
    int i;
    max=min=tab[0];
    for(i=0;i<n;i++){
        if(min>tab[i])min=tab[i];
        if(max<tab[i])max=tab[i];
    }
}

// Referencje jako wartości zwracane, najczęściej to funkcje składowe zwracające referencję do obiektu do którego należy.
// do przeciążania operatorów (łańcuchowe przypisanie), modyfikacja z zewnątrz
class A {
public:
    A&foo() {
        _x+=5;
        return *this;
    }
private:
    int _x=5;
};
A a;
a.foo().foo(); // mozna wielokrotnie, _x będzie 15

class MyVector {
public:
    MyVector& operator=(const MyVector& other) {
        if (this != &other) {
            // Skopiuj elementy z other
        }
        return *this; // do przeciażania
    }
};

class Person {
public:
    [[nodiscard]] const std::string& getName() const { // wskazówka (kompilator / informatyk) że wartość zwracana nie może byc ignorowana, wskaźnik na pam, ingorowanie = wyciek pamięci
        return _name;
    }

    int& getAge() {
        return _age;
    }

private:
    std::string _name;
    int _age;
};
Person adam;
int& age = adam.getAge(); // bo to nam zwraca referencję do składowej.
age = 30; // przypisujemy 30 w miejsce gdzie wskaujze referencja, czyli do pola instancji klasy Person o nazwie adam

// LISTA INICJALIZACYJNA
// mogą być jako Atrybuty klasy, ale muszą byc inicjalizowane na liście inicjalizacyjnej
// Ten sposób inicjalizacji przypisuje wartość do zmiennej podczas tworzenia obiektu, zanim zostanie uruchomiony konstruktor klasy.
// Stałe i referencje konieczne jest użycie listy inicjalizacyjnej, ponieważ zmienne te
// muszą być zainicjalizowane w momencie tworzenia obiektu, a nie po jego utworzeniu.!
// bo B ma pole r, a lista przekazanie wartości do konstruktora, później używamy do inicjalizacji pól.
// Inaczej skończyłoby się to próbą przypisania wartości do samej referencji, czego nie można w Cpp
class B{
public:
    B(int&a) : r(a){};
private:
    int&r;
};
// wartość referencji musi być adresem ISTNIEJĄCEGO obiektu!
// Wartość referencji jest ustalana w momencie inicjalizacji i jest to statycznie sprawdzane przez kompilator.
// Wartośc nie może być równa NULL!

int &r1; // błąd r1 nie wskazuje żadnego obiektu
int x=5;
int &r2=x; // OK. r2 wskazuje zmienną x


// Atrybuty Klas

class File
{
public:
    File(); // standardowy konstruktor
    File(const char*name, const char*mode); // dodatkowy konstruktor
    ~File(); // destruktor
    int open(const char*name, const char*mode); // Metody
    int close();
    int get();
    int put(int);
private:
    FILE*fp; // Atrybuty
};

// Implementacja metod:
File::File(){fp = 0;}
File::File(const char*name, const char*mode){
    open(name,mode);
}
int File::open(const char*name,const char*mode)
{
    fp = fopen(name,mode);
    return fp!=0;
}
int File::close(){
    if(fp)fclose(fp);
    fp=0;
    return 1;
}
int File::get(){
    if(fp)return getc(fp);
    else return -1;
}
int File::put(int c){
    if(fp){
        putc(c,fp);
        return 1;
    }
    return 0;
}
// Użycie klasy
void f(){
    File file; // obiekt typu File

    File file2("plikwy.txt","wt");

    File *pfile = new File("plikwe.txt", "rt");
    for(;;){
        int c = pfile->get();
        if(c<0)break;
        file2.put(c);
    }
    delete pfile;
}

// Podział Plików:
// Definicje klas w plikach nagłówkowych (*.h) bo w wielu miejscach są używane
a.h
class A
{
public:
    A();
};
b.h
#include "a.h"
class B //potrzebujemy znać a dlatego wyżej ją dołączamy
{
public:
    B();
    A a;
};

// Cpp do klas nie musi być, ale zaleca się.
// Implementacje metod klas umieszcza się w plikach *.cpp
#include "a.h"
A::A(){}

// Może być tylko jedna definicja klasy, aby zapobiec errorom jest
// użycie dyrektyw warunkowych
a.h
#if !defined _a_h_ // albo  #pragma once
#define _a_h_
class A
{
public:
    A();
};
#endif // _a_h_ 2
// i teraz w takim kodzie
#include "a.h" // (1)
#include "b.h" // (2)
void main()
{
    A a;
    B b;
}
// raz zdefiniujemy klasę A, gdy będziemy chcieli wywołać drugi raz z B, to się nie zdefinuje i nie rzuci błędu
// Opis w ogolne_zalozenia

//Elementy składowe: metody, atrybuty, klasy wewnętrzne(zagnieżdżone), wyliczenia(enum), pola bitowe, deklaracje friend, wewnętrzne deklaracje typów

// deklaracja struktury
typedef struct { double x,y;} StrComplex; // tam gdzie StrComplex tam będzie struktura
void init(StrComplex*pc, double _x, double _y){ // nadanie wartości początkowych lub przypisanie
    pc->x=_x ;pc->y=_y;
}
double module(const StrComplex*pc) { // oblicza moduł liczby zespolonej
    return sqrt(pc->x*pc->x + pc->y*pc->y);
}

void dump(const StrComplex*pc) { // wypisuje wartość składowych oraz moduł
    printf("[x=%g, y=%g,module=%g]”,
    pc->x,pc->y, module(pc)) ;
}
void f(){
    StrComplex c;
    init(&c,2.4,3.76); // nadajemy wartość początkową
    dump(&c); // wypisujemy informacje
}

// To samo na klasach
class Complex
{
public:
    double x,y;
    Complex(double _x,double _y)
            :x(_x),y(_y){}
    double module()const{
        return sqrt(x*x+y*y );
    }
    void dump()const;
    void set(double _x,double _y){
        x=_x;
        y=_y;}
};
void Complex::dump()const
{
    printf("[x=%g, y=%g,module=%g]”,
    this->x, this->y, this->module()) ;
}
void g() {
    Complex c(2.4, 3.76);
    c.dump();
    Complex *pc = &c;
    pc->dump();
    Complex &rc = c;
    rc.set(2.0, 3.0);
    rc.dump();
}

// Porównanie 1
void init(StrComplex*pc, double _x, double _y) {
    pc->x=_x ;pc->y=_y;
}
//vs
Complex(double _x,double _y):x(_x),y(_y){}
void set(double _x,double _y){x=_x ;y=_y ;}

//2
double module(const StrComplex*pc) {
    return sqrt(pc->x*pc->x + pc->y*pc->y);
}
//vs
double module()const{return sqrt(x*x+y*y ) ;}

//3
void dump(const StrComplex*pc) {
    printf("[x=%g, y=%g,module=%g]”,
    pc->x,pc->y, module(pc)) ;
}
//vs
void Complex::dump()const {
    printf("[x=%g, y=%g,module=%g]”,
    this->x, this->y, this->module()) ;
}

// Metody Obiektu
// wewnątrz mamy dostęp do danych (odwołania do obiektu, którego metoda jest wołana)
// wewnątrz można wołac inne metody danego obiektu
// musimy podać obiekt, podając nazwę, wskaźnik, referencję
// Funkcje, które nie modyfikują jako const.
// Funkcje składowe implementowane wewnątrz definicji klasy lub poza nią

//Wewnątrz niestatycznych metod
CLASS * const this;

//Wewnątrz metod zadeklarowanych jako const wskaźnik widać jako
const CLASS * const this;

// Przykład z lampą na początku Light *plt

// używamy gdy chcemy zwrócic referencję do danego obiektu
Complex& Complex::set(double x,double y)
{
    this->x=x ;
    this->y=y ;
    return *this ;
}

//Może on służyć do ustalania asocjacji (powiązania) pomiędzy obiektam
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

// Inline - jednolinijkowe, mniejszy narzut na stos, krótsze
class Int
{
    int value;
public:
    Int(int v):value(v){}
    int get()const{return value;} // inline
    void set(int v){value = v;} // inline
};
// dodająć inline - podpowiedź aby kompilator robił w jednej linii.
inline void Complex::dump()const
{
    printf("[x=%g, y=%g,module=%g]”,
    this->x, this->y, this->module()) ;
}

// Składowe Static
Pola, metody typu static - elementy składnowe KLASY a nie obiektu - wspólne dla wszystkich, dostępne z zewnątrz
Nie mają dostępu do wskaźnika *this. w metodach static  można używać tylko tych atrybutów które są statyczne

np:

class A
{
public:
    A(){instanceCounter ++;} // tu se jest modyfikowana
    ~ A(){instanceCounter --;}
    static int getInstaceCounter(){ // tu jest statyczna, wspólna dla wszystkich obiektów, brak dostępu do this
        return instanceCounter;}
    void dump()const;
private:
    static int instanceCounter; // atrybut prywatny, styatyczny
};
void A::dump()const
{
    printf("A has %d instances", getInstaceCounter());
}

Statyczne pola istnieją nawet jesli nie ma obiektów, jesli w definicji są pola static, to jest to extern i
trzeba odrębnie definiować, (można w tym czasie również inicjalizować statyczne wartościami początkowymi)

int A::instanceCounter=0;

Metody statyczne mogą być wołane z :

niestatycznej metody (przez nazwę), tak samo atrybuty

    void A::dump()const{
        printf("A has %d instances", getInstaceCounter());
    }

zewnątrz (poprzez obiekt)

    A a;
    int n = a.getInstaceCounter();

zewnątrz poprzez operator zasięgu "::" (scope)

    printf("%d", A::getInstaceCounter());

Klasy zagnieżdżone (ang. nested, inner class)
zadeklarowane wewnątrz innej klasy, jako pomocniczne struktury danych,
aby nie wprowadzać nazwy która by kolidowała z już istniejącymi

Deklaracja klasy zagnieżdżonej jest jedynie deklaracją typu

implementacja globalna
class Point {
    double x,y;
public:
    Point(double _x, double _y);
};

implementacja zagnioeżdżona:
class Circle
{
public:
    Circle(double _x, double _y, double r);

    class Point{
        double t[2] ;
    public:
        Point(double _x, double _y);
    };

    Point center;
    double radius ;
};

// konstruktor klasy globalnej
Point::Point(double _x, double _y){
    x=_x;
    y=_y;
}

// konstruktor klasy wewnętrznej
Circle::Point::Point(double _x, double _y){
    t[0]=_x;
    t[1]=_y;
}

// konstruktor klasy zwewnętrznej
Circle::Circle(double _x, double _y, double r)
        :center(_x,_y),radius(r){}

używając zagnieżdżonej w metodach klasy zewnętrznej, można bezpośrednio nazwą klasy
Poza metodami trzeba pełnej nazwy używać: Outer::Inner,

Circle::Point pointInCircle;

Z zewnątrz nie możemy uzyskać dostępu do definicji klasy , jeżeli dostęp do niej
jest ograniczony jako private lub protected.

class Map
{
protected:
    class Pair // klasa wewnętrzna
    {
        friend class Map;
        double x;
        double y;
    };
    Pair tab[1000]; // lista elementów jakimi są pary
    int cnt;

public:
    bool add(double x,double y){
        if (cnt==1000 )return false;
        tab[cnt].x=x;
        tab[cnt].y=y;
        cnt++;
    }
    double get(double x){
        for(int i=0;i<cnt;i++){
            if(fabs(tab[i].x-x)<1e-5)return tab[i].y;
        }
        return -1e308;
    }
}
;

mozna robić zagnieżdżone typy za pomocą typedef, do zagnieżdżonych definicji podobnie jak do klas

class Tree
{
public:
    typedef Tree * PTREE;
    PTREE Left;
    PTREE Right;
    void *vData;
};
PTREE pTree; // Error: not in class scope.
Tree::PTREE pTree; // Ok.

Wyliczenia

class HasState
{
    int state;
public:
    enum {good=0, bad, }; // jedno z dwóch
    HasState(){ state = good;} // domyślna
    int getState()const {return state;}
};

HasState hs;
int s = hs.getState(); // zwraca nam aktualny stan
if(s== HasState::good) printf("good");
if(s== HasState::bad) printf("bad");

Biblioteki Standardowe
vector,     std::vector<int> liczby;
stringi,    string s="Tekst";
listy,      list<int> lst{11,23,}
słowniki,   map<string,int> dict;  kluczbe muszą mieć <
zbiory.     set<int> cont;         wszystko musi mieć <



Wyklad 2

class Temperature{
    double value;
public:
    Temperature(double v = 0):value(v){}
    double getKelvin(){return value;}
    double getCelsius(){return value-272.15;}
    double getFahrenheit(){return value * 9 / 5 - 459.67;}
    void setKelvin(double v){value = v;}
    void setCelsius(double v){value = v + 272.15;}
    void setFahrenheit(double v){value=(v+459.67)*5/9;}
};

// Przechowuje wartość temperatury w stopniach Kelvina
// Potrafi dokonać konwersji do stopni Celsiusza i Fahrenheita

class Weather{
public:
    enum sky_state{sun,partly_cloudy,cloudy,rain,snow}; // wyliczenie, jedno z.
    enum sky_state sky;
    Temperature temp; // to jest kompozucja włączyliśmy klasę jako komponent
    double humidity;
    double windSpeed;
    Weather(double t, double h, double w, sky_state s) : temp(t),humidity(h),windSpeed(w),sky(s){} // przekazujemy do obiektu temp klay Temperature wartość t.
    void setKelvin();
    void setCelsius(double v);
    void setFahrenheit(double v);
    double getKelvin();
    double getCelsius();
    double getFahrenheit();
};

Delegacja, delegujemy komunikaty do podobiketu temp, który jest instancją klasy Temperature
double Weather::getKelvin(){
    return temp.getKelvin();
}
double Weather::getCelsius(){
    return temp.getCelsius();
}
double Weather::getFahrenheit(){
    return temp.getFahrenheit();
}


Dziedziczenie:
// rozszeżenie o nazwę substancji oraz ograniczenia.
class MeltingTemperature : public Temperature{
public:
    MeltingTemperature(const char*n, double v) : Temperature(v), name(n) {};
    // przekazujemy parametry, nie ma obiektu typu Temperature, dlatego przekazujemy do
    // całego obiektu zmienną v.
    // trzeba przez listę inicjalizacyjną, bo
    const char*getName() { return name.c_str();}
    bool setCelcsius(double v){
        if(v<272.15 or v>=2000) return false;
        setCelcsius(v);
        return true;
    }
private:
    string name;
};


MeltingTemperature water("water",272.15);
cout<<water.getCelsius()<<endl;
water.setCelsius(-500); // zareaguje zabezpoeczenie, celcius nadal będzie 0
cout<<water.getCelsius()<<endl;
water.Temperature::setCelsius(-500); // wywołanie metody bezpośrednio z klasy bazowej poprzez ::
cout<<water.getCelsius()<<endl;

// drugi sposób
MeltingTemperature water("water",272.15);
cout<<water.getCelsius()<<endl;
MeltingTemperature&r1 = water;
r1.setCelsius(-500);
cout<<r1.getCelsius()<<endl;

Temperature&r2 = water;
r2.setCelsius(-500); // za pomocą referencji typu klasy bazowej.
cout<<r2.getCelsius()<<endl;
// będzie 0 0 -500

// Jak zmienimy na
//class MeltingTemperature : private Temperature {…}
//to za pośrednictwem MeltingTemperature nie będziemy mieli dostepu z zewnątrz
// do żadnego komponentu (pola, metody, definicji) klasy Temperature.
// nie będziemy mogli ustawić temperatury na -500

// przykład

class Light{
protected:
    double voltage; // nie można z zewnątrz do tego się dostać, ale można tego uzywać w metodach klas potomnych.
public:
    Light(){voltage=0;}
    virtual void on(){voltage = 230;}
    virtual void off(){voltage=0;}
};
//czyli takie coś
//Light lt;
//lt.voltage = 400; nie zadziała

class DimmableLight:public Light{
    double level; // coś w rodzaju potencjometru od 0 do 1.
    void updateVoltage(){ // skalujemy wartość voltage od 0 do 230
        voltage=level*230;
        std::cout<<voltage<<std::endl;
    }
public:
    DimmableLight(){
        level=0;
        updateVoltage();}

    // Typowe rozszeżenie funkcjonalności klasy
    void dim(){
        if(level>=0.1)level -= 0.1;
        updateVoltage();}
    void brighten(){
        if(level<=0.9)level += 0.1;
        updateVoltage();}
    void on(){
        level=1.0;
        updateVoltage();}
    void off(){
        level=0;
        updateVoltage();}
};

// dziedziczenie wielobazowe:

class A1
{
    int i;
public:
    A1(int _i):i(_i){}
    void f(){
        printf("A1[i=%d] ",i);
    }
};
class A2
{
public:
    A2(){}
    void f(){
        printf("A2 ");
    }
};

class B: public A1, public A2 {
public:
    B():A2(),A1(7){} // A1 musimy na liście inicjalizacyjnej, bo A1 nie ma konstruktora bezargumentowego.
    // To nie są wywołania konstruktorów, bo konstruktory będą wywoływane w kolejności ich deklaracji.
    // Lista inicjalizacyjna to nie jest kod wykonywalny, to jest mechanizm przekazywania parametrów.
    void f(){ // Metoda B::f() przedefiniowuje metody A1::f() oraz A2::f(). ale są dostępne poprzez ::
        printf("B[ ");
        A1::f();
        A2::f();
        printf("]");
    }
};
int main(){
    B b;
    b.f();
    cout << endl;
    b.A1::f();
    cout << endl;
    b.A2::f();
}
// wypisze się
//B[ A1[i=7] A2 ]
//A1[i=7]
//A2

// Problem podwójnego:
class A {
    int k;
public:
    A(int _k):k(_k){}
    void f(){
        printf("A[k=%d]", k);
    }
};

class A1 : public A {
    int i;
public:
    A1(int _i):A(1),i(_i){}
    void f(){
        printf("A1[i=%d] ",i);
    }
};
class A2 : public A
{
public:
    A2():A(2){}
    void f(){printf("A2 ");}
};
class B: public A1, public A2
{
public:
    B():A2(),A1(7){}
};

int main(){
    B b;
    b.A1::f();
    b.A2::f();
};
// podobiekt A w A1 k=1, A w A2 k=2
// tu będzie błąd bo nie wie którą ma wywołać
int main(){
    B b;
    b.A::f()
};

//Można rozwiązać ten problem za pomcą odpowiednich referencji
//(rzutowanie w górę) upcasting
A2&ra = b;
ra.A::f();
// Ta referencja wybierze nam obiekt A który jest w klasie A2.
// ra, jest referencją na b, typu A2. czyli jakby bierze to co jest w A2?

Albo na wskaźnikach:
((A*)(A2*)&b)->f()


Aby to rozwiązać / ominąć jest dziedziczenie Wirtualne...
virtual public.
jeśli dziedziczy po A1 i A2 -> to A jest wspólne, dziedziczą tak jakby po tym samym przodku. jest niejednoznaczność

class A {
    int k;
public:
    A(int _k):k(_k){}
    void f(){
        printf("A[k=%d]", k);
    }
};
class A1 : virtual public A
{
    int i;
public:
    A1(int _i):A(1),i(_i){}
    void f(){
        printf("A1[i=%d] ",i);
    }
};

class A2 : virtual public A
{
public:
    A2():A(2){}
    void f(){printf("A2 ");}
};
class B:
        public A1,
        public A2
{
public:
    B():A2(),A1(7),A(3){} // Obiekt klasy B będzie zawierał trzy podobiekty:
    // A (ze stanem k=3), A1 oraz A2.
    // Konstruktor klasy B musi jawnie zainicjować składowy obiekt klasy A.
    // Inicjacje za pośrednictwem konstruktorów A1 oraz A2 są ignorowane.
};
int main(){
    A1 a1(23);
    a1.A::f();
    A2 a2;
    a2.A::f();
    B b;
    b.A::f();
};

// I tu już wie co i jak.







class D : public A1 {
public:
    A2 a2;
}








/*
// odniesienia do składników obiektu:
obiekt.składnik
wskaźnik->składnik
referencja.składnik
*/
Room syplialnia; // definicja egzemplarza obiektu
Room *garderoba; // definicja wskaźnika
Room &badroom = syplialnia; // definicja referencji
