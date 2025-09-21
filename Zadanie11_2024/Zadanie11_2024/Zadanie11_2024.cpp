#include <iostream>
using namespace std;

/*
/*
Funkcja foo(int x) wykonuje kombinację operacji arytmetycznych i bitowych:
- Oblicza wartość a na podstawie:
  - reszty z dzielenia x % 7,
  - bitowego AND z 3 (czyli x & 3, co odpowiada x % 4),
  - warunku: jeśli x > 2, dodaje -3, w przeciwnym razie +5,
  - bitowego OR z x / 4,
  - zmiany znaku zależnie od parzystości (x % 2),
  - oraz dodaje stałą wartość 12 (bo 2 * (96 % 9) = 12).

Uwaga: operator & ma niższy priorytet niż +, więc wyrażenie:
  x % 7 + x & 3 + (...)
jest interpretowane jako:
  ((x % 7 + x) & 3) + (...)

WAZNE:
x & 3 to operacja na bitach np w uproszczeniu 7 to 111 w binarnym a 3 to 011 wiec przy tym operatorze zostaje to co w 3 czyli 011

Dla poniższych wywołań:
  foo(-101) → 29
  foo(-68)  → -5
  foo(32)   → 20
  foo(121)  → -18

→ Największą wartość zwraca foo(-101). ODPOWIEDZ TO A) foo(-101)
*/

int foo(int x) {
    int a = x % 7 + x & 3 + ((x > 2) ? -3 : 5);
    a |= x / 4;
    a *= ((x % 2) ? -1 : 1);
    a += 2 * (96 % 9);
    return a;

    /*Inne zadania*/

    


}

int main()
{
    
    cout << foo(-101) << endl;
    cout << foo(-68) << endl;
    cout << foo(32) << endl;
    cout << foo(121) << endl;

    /*Inne zadania*/

    /*
    Zadanie 1 — analiza rozkładu wyników funkcji foo(x) w zakresie od -150 do 150.

    Program zlicza, ile razy wynik funkcji foo(x):
    - jest dodatni (plus),
    - jest ujemny (minus),
    - jest równy zero (zero).

    Wyniki są wypisywane na końcu. Pozwala to ocenić, jak funkcja foo rozkłada wartości
    w zadanym zakresie wejściowym. Przydatne do testowania, debugowania i analizy zachowania funkcji.
    */

    int zero = 0;
    int plus = 0;
    int minus = 0;


    for (int i = -150; i <= 150; i++) {
		foo(i);
        if (foo(i) > 0) {
            plus++;
        }else if (foo(i) < 0) {
            minus++;
        }else {
            zero++;
        }

    }
    cout << "Liczba wartosci dodatnich: " << plus << endl;
    cout << "Liczba wartosci ujemnych: " << minus << endl;
    cout << "Liczba wartosci zerowych: " << zero << endl;


    /*
    Zadanie 2 — znajdowanie lokalnych maksimów funkcji foo(x) w zakresie od -100 do 100.

    Program sprawdza dla każdej liczby x, czy wartość foo(x) jest większa niż sąsiednie wartości:
    foo(x - 1) oraz foo(x + 1)

    Jeśli tak — wypisuje x jako lokalne maksimum oraz wartość foo(x).
    Pozwala to zaobserwować, gdzie funkcja foo osiąga lokalne wzrosty i jak zmienia się w otoczeniu.

    Uwaga: funkcja foo wywoływana jest trzykrotnie w każdej iteracji — można zoptymalizować
    kod przez zapisanie foo(i) do zmiennej pomocniczej.
*/



    for (int i = -100; i <= 100; i++) {
        foo(i);
        if ((foo(i) > foo(i - 1)) &&  (foo(i) > foo(i + 1))) {
			cout << "Lokalne maksimum dla x = " << i << " wynosi: " << foo(i) << endl;
        }
    }



}



