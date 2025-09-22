#include <iostream>
using namespace std;

//19) Co zostanie wypisane na standardowe wyjście dla poniższego programu napisanego w języku C++ 17:
//#include <iostream>
//struct A {
//    void f() { std::cout << "A"; }
//};
//class B : public A {
//public:
//    void f() { std::cout << "B"; }
//};
//struct C : public B {
//    virtual void f() { std::cout << "C"; }
//};
//int main(int argc, char* argv[]) {
//    A* p1 = new A; A* p2 = new B; A* p3 = new C;
//    A a; B b = *(new B); C c = *(new C);
//    p1->f(); p2->f(); p3->f();
//    a.f(); b.f(); c.f();
//    return 0;
//}
//a) AAAABC b) AACABC c) ABCABC d) ABCAAA
//e) żadna z powyższych odpowiedzi nie jest prawidłowa


// ODPOWIEDZ TO A) AAAABC
    //Ten kod pokazuje przykład dziedziczenia klas oraz zachowanie funkcji f() w zależności od typu wskaźnika.
    //Klasy A, B i C dziedziczą po sobie, ale funkcja f() w klasie A NIE jest virtual — co ma kluczowe znaczenie.

    //STRUKTURA KLAS:
    //- A: posiada metodę f(), ale nie jest ona virtual.
    //- B: dziedziczy po A i przesłania f(), ale nadal bez virtual.
    //- C: dziedziczy po B i przesłania f() jako virtual.

    //WSKAŹNIKI:
    //A* p1 = new A;  // wywoła A::f()
    //A* p2 = new B;  // wywoła A::f() — brak virtual w A
    //A* p3 = new C;  // wywoła A::f() — brak virtual w A

    //OBIEKTY:
    //A a; B b; C c;
    //a.f(); // "A"
    //b.f(); // "B"
    //c.f(); // "C"

    //WYNIK KOŃCOWY:
    //AAABBC

    //WNIOSKI:
    //- Aby polimorfizm działał przez wskaźnik do klasy bazowej (np. A*), metoda musi być virtual w klasie A.
    //- W przeciwnym razie wywoływana jest wersja metody z klasy bazowej, niezależnie od rzeczywistego typu obiektu.

    //ĆWICZENIA:
    //1. Dodaj virtual do A::f() i override w B oraz C — sprawdź jak zmienia się wynik.
    //2. Dodaj destruktory do A, B, C i wypisz komunikaty — przetestuj delete p1, p2, p3.

#include <iostream>
using namespace std;

struct A {
    int* ptr;

    virtual void f() {
        std::cout << "A";
    }

    A(int val) {
        ptr = new int(val);
    }

    A() {
        ptr = nullptr;
    }

    virtual ~A() {
        std::cout << "\n~A destruktor\n";
        delete ptr;
    }
};

class B : public A {
public:
    void f() override {
        std::cout << "B";
    }

    B(int val) : A(val) {}

    B() {}

    ~B() override {
        std::cout << "~B destruktor\n";
    }
};

struct C : public B {
    void f() override {
        std::cout << "C";
    }

    C(int val) : B(val) {}

    C() {}

    ~C() override {
        std::cout << "~C destruktor\n";
    }
};

int main() {
    A* p1 = new A;
    A* p2 = new B;
    A* p3 = new C;

    A a;
    B b = *(new B);
    C c = *(new C);

    p1->f(); p2->f(); p3->f();
    a.f(); b.f(); c.f();

    delete p1;
    delete p2;
    delete p3;

    return 0;
}



