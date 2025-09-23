//ODPOWIEDZ A

/*
Analiza działania programu:

class A:
  - posiada metodę void f(), która wypisuje "fA"
class B:
  - dziedziczy po A
  - nadpisuje metodę f() jako virtual, wypisując "fB"
class C:
  - dziedziczy po B
  - nadpisuje metodę f(), wypisując "fC"

W main():
A* o1 = new A;         // wskaźnik do obiektu A → wywołanie A::f() → "fA"
A* o2 = new B;         // wskaźnik do obiektu B, ale typ statyczny to A → brak virtual w A → wywołanie A::f() → "fA"
B* o3 = new C;         // wskaźnik do obiektu C, typ statyczny B → virtual w B → wywołanie C::f() → "fC"

A a;                   // obiekt A → A::f() → "fA"
B b;                   // obiekt B → B::f() → "fB"
B c = *(new C);        // obiekt B, skopiowany z C → slicing → tracimy część C → B::f() → "fB"

Podsumowanie wywołań:
o1->f();               // "fA"
o2->f();               // "fA"
o3->f();               // "fC"
a.f();                 // "fA"
b.f();                 // "fB"
c.f();                 // "fB"

Wynik na standardowym wyjściu:
fAfAfCfAfBfB

Poprawna odpowiedź: **a) fAfAfCfAfBfB**
*/


//8) Co zostanie wypisane na standardowe wyjście dla poniższego programu napisanego w języku C++11
//(C++ wersja 11)
//#include <iostream>
//using namespace std;
//class A {
//public:
//    void f() { cout << "fA"; }
//};
//struct B : public A {
//    virtual void f() { cout << "fB"; }
//};
//class C : public B {
//public:
//    void f() { cout << "fC"; }
//};
//int main() {
//    A* o1 = new A; A* o2 = new B; B* o3 = new C;
//    A a; B b; B c = *(new C);
//    o1->f(); o2->f(); o3->f();
//    a.f(); b.f(); c.f();
//    return 0;
//}
//a) fAfAfCfAfBfB
//b) fAfBfCfAfBfC
//c) fAfBfCfAfBfB
//d) fAfAfBfAfBfB


//Zadanie jako przykład:

#include <iostream>
using namespace std;

class Message {
public:
    void send() { 
        cout << "Sending generic message";
    }
};

struct Email : public Message{
    virtual void send() { cout << "Sending email"; }
};

class SMS : public Email {
public:
    void send() { cout << "Sending SMS"; }
};

int main() {
	Message* m1 = new Email;
    m1->send();

    Email* m2 = new SMS;
	m2->send();

	Email e = *(new SMS);
	e.send();

    SMS s;
	s.send();

    return 0;
}

/*
Hierarchia klas:
- Message: klasa bazowa, metoda send() NIE jest virtual → "Sending generic message"
- Email: dziedziczy po Message, nadpisuje send() jako virtual → "Sending email"
- SMS: dziedziczy po Email, nadpisuje send() → "Sending SMS"

W main():

1. Message* m1 = new Email;
   - Typ wskaźnika: Message
   - Obiekt: Email
   - Message::send() NIE jest virtual → wywołanie statyczne → "Sending generic message"

2. Email* m2 = new SMS;
   - Typ wskaźnika: Email
   - Obiekt: SMS
   - Email::send() JEST virtual → dynamiczne wywołanie → "Sending SMS"

3. Email e = *(new SMS);
   - Tworzymy obiekt Email przez kopiowanie z SMS → object slicing
   - Część SMS zostaje "ucięta"
   - Wywołanie e.send() → Email::send() → "Sending email"

4. SMS s;
   - Obiekt SMS → wywołanie SMS::send() → "Sending SMS"

WYPIS NA STANDARDOWE WYJŚCIE:
Sending generic messageSending SMSSending emailSending SMS
*/
