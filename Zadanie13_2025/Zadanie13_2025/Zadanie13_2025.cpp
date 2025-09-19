using namespace std;
#include <iostream>

// trudnosc to zrozumienie przeliczania liczb w systemach, do powtorzenia. Odpowiedz foo(0x5e) 5 X 16 + 14 X 1
//Funkcja foo() liczy liczbę jedynek(bitów ustawionych na 1) w liczbie całkowitej n.
// Działa na zasadzie sprawdzania każdego bitu z osobna — od najmłodszego do najstarszego.
// sizeof(int) << 3 oblicza liczbę bitów w typie int (np. 4 bajty × 8 = 32 bity).
// Uwaga: kod nie jest optymalny — zawsze wykonuje pełne 32 iteracje, nawet dla małych liczb.

int foo(int n) {
    int a = 0;
    int b = sizeof(int) << 3;
    for (int i = 0; i < b; i++) {
        if (n & (1 << i)) a++;
    }
    return a;
}


int main()
{
	cout << foo(94) << endl;
    cout << foo(50) << endl;
    cout << foo(0175) << endl;
    cout << foo(1101) << endl;
      
}



