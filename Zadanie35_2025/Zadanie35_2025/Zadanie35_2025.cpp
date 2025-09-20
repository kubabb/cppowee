using namespace std;
#include <iostream>
#include <map>
#include <string>
#include <cstdint>

/*
Ten program demonstruje użycie std::map w C++ oraz operacje takie jak insert, count, erase i dostęp do elementów. 
Mapa `v` przypisuje liczby całkowite do napisów. Na początku wypisywany jest rozmiar pustej mapy (0). 
\Następnie w pętli od 0 do 5 próbuje się wstawić pary (i, "i") — jeśli klucz `i` nie istnieje, zostaje dodany. 
Wstawienie zwraca true tylko raz dla danego klucza, więc druga próba z (i, "-i") zawsze się nie udaje. Wartość `i` 
jest modyfikowana dynamicznie przez `i += ...`, ale ponieważ drugie wstawienie się nie udaje, `i` rośnie tylko o 1 w każdej iteracji. 
Po pętli mapa zawiera 6 elementów (klucze 0–5), więc wypisywany jest rozmiar 6. Następnie, jeśli mapa zawiera klucze 0 i 5, 
wypisywana jest konkatenacja ich wartości ("5" + "0" = "50"). Potem usuwany jest klucz 4, a jeśli mapa nie jest pusta, wypisywany jest jej nowy rozmiar (5). Wynik działania programu to: `0 6 50 5`.


- `std::map<int, std::string>` – uporządkowana mapa klucz-wartość
- `insert(pair)` – dodaje element, jeśli klucz nie istnieje
- `.second` – informuje, czy wstawienie się powiodło
- `count(k)` – sprawdza, czy klucz istnieje
- `at(k)` – dostęp do wartości z wyjątkiem przy braku klucza
- `erase(k)` – usuwa element o podanym kluczu
*/

//bool dodaj(map<int, string>& m, int i) {
//	return m.insert(make_pair(i, to_string(i))).second;
//}

int main()
{
	/*Zadanie 3:*/
	/*std::map<int, std::string> v;
	std::cout << v.size() << ' ';
	for (int_fast16_t i = 0; i <= 5; ++i)
		i += v.insert(std::make_pair(i, std::to_string(i))).second
		? v.insert(std::make_pair(i, std::to_string(-i))).second
		: false;
	std::cout << v.size() << ' ';
	if (v.count(5) && v.count(0))
		std::cout << v[5] + v.at(0) << ' ';
	v.erase(4);
	if (!v.empty()) { std::cout << v.size() << ' '; }
	std::cout << std::endl;*/



	/*Podobne zadania*/

	/*Zmień pętlę tak, aby dodawała tylko liczby parzyste jako klucze do mapy.Wypisz zawartość mapy po zakończeniu pętli w formacie :*/

	/*map<int, string> v;
	for (int_fast16_t i = 0; i <= 5; ++i) {
		if (i % 2 == 0) {
			v.insert(make_pair(i, to_string(i)));
			cout << v.at(i) << endl;
		}
		
	}*/

	/*Stworzyć funkcję dodaj, która przyjmuje mapę i liczbę, a następnie próbuje dodać parę(i, std::to_string(i)).Funkcja zwraca true, jeśli wstawienie się powiodło.*/

	/*map<int, string> v;*/

	/*for (int_fast16_t i = 0; i <= 5; ++i) {
		if (i % 2 == 0) {
			if (dodaj(v, i)) {
				cout << "Dodano: " << i << " → " << v.at(i) << endl;
			}
			else {
				cout << "Klucz " << i << " już istnieje." << endl;
			}
		}
	}*/

	/*Po zakończeniu pętli wypisać wszystkie klucze i wartości w mapie w czytelnym formacie.*/

	/*map<int, string> v;

	for (int_fast16_t i = 0; i <= 5; ++i) {
		if (i % 2 == 0) {
			v.insert(make_pair(i, to_string(i)));
		}
	}

	cout << "Zawartość mapy:" << endl;
	for (const auto& pair : v) {
		cout << "Klucz: " << pair.first << " → Wartość: " << pair.second << endl;
	}*/




}

