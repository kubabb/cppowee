#include <iostream>

// ODPOWIEDŹ A) 6

//26) W języku C++ 17 zdefiniowana jest funkcja foo następująco :
//unsigned char foo(unsigned char x) {
//    unsigned char r = x % 8 + x % 4;
//    return r;
//}
//ile różnych wartości może ona zwrócić ?
//a) 6 b) 8 c) 12 d) 256
//e) żadna z powyższych odpowiedzi nie jest prawidłowa


/*
 NOTATKA DO ZADANIA — ILE WARTOŚCI ZWRACA FUNKCJA `foo`

Funkcja:
    unsigned char foo(unsigned char x) {
        return x % 8 + x % 4;
    }

Zakres typu `unsigned char`: 0–255

Działanie:
- `x % 8` → 0–7
- `x % 4` → 0–3
- Suma: 0–10

Ale nie każda wartość od 0 do 10 występuje. Po analizie wszystkich kombinacji i empirycznym sprawdzeniu okazuje się, że funkcja zwraca tylko:

**6 różnych wartości**: {0, 2, 4, 6, 8, 10}

Wynika to z tego, że wiele kombinacji daje te same sumy. Funkcja `foo` jest deterministyczna i nie generuje wszystkich możliwych wartości od 0 do 10.

 Poprawna odpowiedź: **6**
*/
