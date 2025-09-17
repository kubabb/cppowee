#include <iostream>
#include <cstdint>
#include <numeric>
using namespace std;
int main() {

	/*
	Cały sens zadania polega na tym, że int16_t zajmuje 2 bajty, a int32_t zajmuje 4 bajty. Gdy tworzymy tablicę int16_t arr[] = { 0, 1, 2, 3, 4 }; to w pamięci dla wersji int 32 wygląda to tak: [0,1], [2,3], [4,0] 
	(każdy nawias to 4 bajty). Gdy tworzymy wskaźnik int32_t* ptr = reinterpret_cast<int32_t*>(arr); to wskazuje on na pierwszy element tablicy arr, czyli na [0,1]. Gdy wykonujemy ++ptr; 
	to wskaźnik przesuwa się o 4 bajty do przodu i teraz wskazuje na [2,3]. Gdy wykonujemy *ptr = {}; to zerujemy te 4 bajty, czyli zmieniamy [2,3] na [0,0]. W efekcie tablica arr 
	wygląda teraz tak: {0, 1, 0, 0, 4}. Suma tych elementów to 0 + 1 + 0 + 0 + 4 = 5.
	gdy zmieniamy *ptr[1] = 35; to zmieniamy drugi element wskazywany przez ptr, czyli [4,0] na [35,0]. W efekcie tablica arr wygląda teraz tak: {5, 5, 35, 0, 5}. Suma tych elementów to 50
	*/

	/*zadanie 1/2025*/
	/*int16_t arr[] = { 0, 1, 2, 3, 4 };
	auto* ptr = reinterpret_cast<int32_t*>(arr);
	++ptr;
	*ptr = {};
	cout << accumulate(begin(arr), end(arr),
		decay_t<decltype(arr[0])>{}) << endl;*/


	/*zadanie1*/
	/*int16_t arr[] = { 10, 20, 30, 40, 50 }; 
	int16_t* wsk = arr; 
	wsk[2] = 999; 
	for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++) { cout << arr[i] << endl; }*/

	/*zadanie2*/
	/*int16_t arr[] = { 1, 2, 3, 4, 5 }; 
	int32_t* ptr = reinterpret_cast<int32_t*>(arr); 
	for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++) { 
		cout << arr[i] << endl; 
	} 
	*ptr = {}; 
	for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++) { 
		cout << arr[i] << endl; 
	}*/


	/*zadanie 3*/
	//int16_t arr[] = { 5, 5, 5, 5, 5 };
	//int32_t* ptr = reinterpret_cast<int32_t*>(arr);

	//ptr[1] = 35; // ustawia arr[2] = 35, arr[3] = 0

	//int sum = accumulate(begin(arr), end(arr), 0);
	//cout << sum << endl; // 






}

