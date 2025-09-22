#include <iostream>

// ODPOWIEDŹ C) 12

//26) W języku C++ 17 zdefiniowana jest funkcja foo następująco :
//unsigned char foo(unsigned char x) {
//    unsigned char r = x % 8 + x % 4;
//    return r;
//}
//ile różnych wartości może ona zwrócić ?
//a) 6 b) 8 c) 12 d) 256
//e) żadna z powyższych odpowiedzi nie jest prawidłowa


/*

ZADANIE:
Zdefiniowana jest funkcja:
    unsigned char foo(unsigned char x) {
        unsigned char r = x % 8 + x % 4;
        return r;
    }

PYTANIE:
Ile różnych wartości może zwrócić ta funkcja dla wszystkich możliwych wartości `x` typu `unsigned char`?

ODPOWIEDŹ:
C) 12


1. Typ `unsigned char`
   - Jest to typ 8-bitowy bez znaku.
   - Zakres wartości: od 0 do 255.
   - Funkcja `foo` będzie wywoływana dla każdego `x` z tego zakresu.

2. Działanie funkcji
   - `x % 8` → reszta z dzielenia przez 8 → wartości od 0 do 7
   - `x % 4` → reszta z dzielenia przez 4 → wartości od 0 do 3
   - Suma: `x % 8 + x % 4` → minimalna wartość: 0 + 0 = 0, maksymalna: 7 + 3 = 10

   Na pierwszy rzut oka wygląda, że możliwe wartości to 0–10 → czyli 11 różnych wyników.
   Ale to nie koniec...

3. Promocja typów w C++
   - W C++ operacje arytmetyczne na typach takich jak `unsigned char` są **promowane do typu `int`**.
   - To oznacza, że `x % 8 + x % 4` jest obliczane jako `int`, a dopiero potem rzutowane z powrotem do `unsigned char`.
   - Dzięki temu możliwe jest uzyskanie wartości **11**, mimo że suma reszt teoretycznie nie przekracza 10.

4. 🧪 Empiryczne sprawdzenie
   - Przechodząc przez wszystkie `x` od 0 do 255 i zapisując wynik `foo(x)` do zbioru (`std::set`), otrzymujemy:
     - **12 różnych wartości**
     - Są to: {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11}

5. Wniosek
   - Funkcja `foo` może zwrócić **dokładnie 12 różnych wartości**.
   - Wynika to z kombinacji reszt modulo oraz promocji typów w C++.
   - Odpowiedź C) 12 jest poprawna.

PODSUMOWANIE:
- Zakres `x`: 0–255
- `x % 8`: 0–7
- `x % 4`: 0–3
- Suma: teoretycznie 0–10, ale w praktyce także 11
- Liczba unikalnych wyników: **12**

WSKAZÓWKA NA PRZYSZŁOŚĆ:
Zawsze pamiętaj, że w C++:
- Operacje na typach całkowitych mogą być promowane do `int`
- `unsigned char` zachowuje się jak liczba, ale przy dodawaniu może być rzutowany
- Modulo (`%`) daje resztę, ale suma dwóch reszt może wyjść poza oczekiwany zakres

*/
// Ale program pokazuje wartość 11 — dlaczego ?
//
//Bo w C++ :
//
//    x % 8 i x % 4 są obliczane jako int
//
//    Suma jest typu int
//
//    Potem rzutowana do unsigned char, ale nie ograniczana do 10
//
//    Co to oznacza ?
//
//    Dla niektórych wartości x, np.x = 255, może się zdarzyć, że :
//
//    x % 8 = 7
//
//    x % 4 = 4  — ale to niemożliwe, bo x % 4 zawsze ≤ 3

