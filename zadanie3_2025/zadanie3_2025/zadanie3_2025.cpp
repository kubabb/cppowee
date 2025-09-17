#include <iostream>
using namespace std;
int x, y;

/*
Kod definiuje dwie globalne zmienne int x, y (domyślnie = 0).
Tworzona jest lambda:
    auto f = [&](int& x) mutable { x--; };

[&]  -> przechwytuje wszystkie zmienne z zewnętrznego zakresu przez referencję,
        ale w tym przypadku przechwytywanie nie jest użyte, bo w ciele lambdy
        'x' to parametr funkcji, a nie globalna zmienna.
(int& x) -> parametr przekazywany przez referencję; cieniowanie nazw powoduje,
            że globalny ::x jest niewidoczny w ciele lambdy.
mutable -> zbędne tutaj; pozwalałoby modyfikować przechwycone przez wartość zmienne.

Wywołanie f(y):
    - parametr x w lambdzie staje się referencją do globalnego y
    - x-- zmniejsza y o 1
    - globalny x pozostaje bez zmian

Wynik:
    x = 0, y = -1
    Output: "0 -1"
*/



int main() {

	/*auto f = [&](int& x) mutable {x--;};
	f(y);
    std::cout << x << ' ' << y << std::endl;*/\



    /*Zadanie 1 — modyfikacja globalnej zmiennej przez lambdę
    Napisz lambdę, która nie ma parametrów, ale przechwytuje globalną zmienną x przez referencję i zmniejsza ją o 5. Wypisz x przed i po wywołaniu lambdy.
    Cel: zobaczyć różnicę między operacją na parametrze a operacją na przechwyconej zmiennej.*/

    /*auto f = [&](int& x) mutable {x-=5;};
    f(x);
    cout << x;*/



    /*Zadanie 2 — przekazywanie przez wartość vs referencję
    Napisz dwie lambdy :
    pierwsza przyjmuje int przez wartość i dekrementuje go
    druga przyjmuje int& przez referencję i dekrementuje go.
    Wywołaj obie na tej samej zmiennej z i wypisz jej wartość po każdym wywołaniu.
    Cel: zrozumieć, kiedy zmiana w lambdzie wpływa na oryginalną zmienną, a kiedy nie.*/

 //   int z = 10;
	//auto f = [&](int x) mutable {x--;};
	//auto g = [&](int& x) mutable {x--;};

 //   f(z);
 //   cout << z << endl; // z pozostaje 10, bo f zmienia tylko kopię
 //   g(z);
	//cout << z << endl; // z staje się 9, bo g zmienia oryginał przez referencję









}


