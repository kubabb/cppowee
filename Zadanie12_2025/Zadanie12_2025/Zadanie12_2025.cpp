#include <iostream>
using namespace std;
#include <cstdint>

// ODPOWIEDZ TO B) f(395)

//12. W języku C++ 17 zdefiniowana jest funkcja f jak poniżej :
//#include <cstdint>
//int f(int num) {
//    std::uint8_t a = num & 0x1F;
//    std::uint8_t b = ((a << 2) | 0x03) ^ 0xA5;
//    std::uint8_t c = (b % 26);
//    return c;
//}
//Dla którego z czterech wywołań : f(11); f(305); f(557); f(1101); funkcja f zwróci największą wartość :
//a) f(11); b) f(305);
//c) f(557); d) f(1101);
//e) żadna z powyższych odpowiedzi nie jest prawidłowa



int f(int num) {
    std::uint8_t a = num & 0x1F;
    std::uint8_t b = ((a << 2) | 0x03) ^ 0xA5;
    std::uint8_t c = (b % 26);
    return c;
}

int main()
{
    
    cout << f(11) << endl; 
    cout << f(305) << endl;
    cout << f(557) << endl;
    cout << f(1101) << endl;



}

/*

FUNKCJA:
    int f(int num) {
        std::uint8_t a = num & 0x1F;
        std::uint8_t b = ((a << 2) | 0x03) ^ 0xA5;
        std::uint8_t c = (b % 26);
        return c;
    }
CO ROBI FUNKCJA?

1. `a = num & 0x1F`
   - `0x1F` to liczba binarna `00011111` (czyli 31 dziesiętnie).
   - Operator `&` (AND bitowy) wycina 5 najmłodszych bitów z liczby `num`.
   - Przykład: `num = 305` → binarnie `100110001` → `a = 305 & 31 = 17`

2. `b = ((a << 2) | 0x03) ^ 0xA5`
   - `a << 2` przesuwa bity o 2 miejsca w lewo (czyli mnoży przez 4).
   - `| 0x03` ustawia 2 najmłodsze bity na 1 (OR bitowy z `00000011`).
   - `^ 0xA5` wykonuje XOR z `0xA5` (czyli `10100101` binarnie).
   - Wynik `b` to zakodowana wersja `a`.

3. `c = b % 26`
   - Reszta z dzielenia przez 26 — wynik mieści się w zakresie 0–25.
   - Może być używany np. jako indeks litery alfabetu (A–Z).

TYPY:
- `std::uint8_t` to typ z `<cstdint>` — dokładnie 8-bitowa liczba bez znaku.
- Gwarantuje przewidywalne działanie operacji bitowych.

PRZYKŁADOWE WYWOŁANIA:
    cout << f(11) << endl;
    cout << f(305) << endl;
    cout << f(557) << endl;
    cout << f(1101) << endl;

Każde wywołanie zwraca liczbę z zakresu 0–25, zakodowaną przez operacje bitowe.

WNIOSKI:
- Funkcja `f()` to przykład szyfrowania lub kodowania danych za pomocą operacji bitowych.
- Wynik może być używany jako indeks, litera, lub element tablicy.
- Kod pokazuje praktyczne zastosowanie masek bitowych, przesunięć, OR, XOR i modulo.

*/
