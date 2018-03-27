#include "stdafx.h"
#include "Tablica.h"





// *tab - wskaznik na poczatek tablicy, len -  rozmiar tablicy
Tablica::Tablica(int * tab, int len)
{
	head = tab;
	size = len;
}

/*Konstruktor bezargumentowy tablicy. Przypisuje poczatkowi tablicy nullptr*/
Tablica::Tablica()
{
	size = 0;
	head = nullptr;
}

/*Destruktor tablicy. Zwalnia pami?? spod wskaznika na poczatek tablicy*/
Tablica::~Tablica()
{
	delete[] head;
}


void Tablica::dodajNaPoczatek(int value) {
	//Jesli tablica jest pusta dodaje jeden element do head
	if (size == 0) {
		head = new int[1];
		*head = value;
		size++;
	}
	//Przekopiwowanie przy uzyciu tablicy dynamicznej
	else {

		int* wsk = new int[size + 1];
		memcpy(wsk + 1, head, size * sizeof(int));
		*wsk = value;
		head = wsk;
		size++;
	}

}

//Dodanie elementu na koniec tablicy

void Tablica::dodajNaKoniec(int value) {

	//Jesli tablica jest pusta dodaje jeden element do head
	if (size == 0) {
		head = new int[1];
		*head = value;
		size++;
	}
	else {

		int* wsk = new int[size + 1];
		memcpy(wsk, head, size * sizeof(int));
		*(wsk + size)   = value;
		head = wsk;
		size++;
	}





}

void Tablica::dodajGdziekolwiek(int wartosc, int where) {

	if (where <size || where >size) {

		cout << "W tablicy nie ma okreslonej pozycji: " << where<<endl ; 
		return;

	}
	
	int* wsk = new int[size + 1]; //tymczasowa tablica do wlo¿enia elementu
	memcpy(wsk, head, where * sizeof(int));//przekopiowuj? ze starej tablicy elementy z pocz?tku, zostawiaj?c na ko?cu miejsce na nowy element
	*(wsk + where) = wartosc;
	memcpy(wsk + where + 1, head + where, (size - where) * sizeof(int));
	head = wsk;
	size++;


}


/*Funkcja usuwajaca element z konca tablicy.*/
void Tablica::usunOstatni()
{
	usunIndeks(size -1);
}
/*Funkcja usuwajaca element z poczatku tablicy.*/
void Tablica::usunPierwszy()
{
	usunIndeks(0);
}

void Tablica::usunIndeks(int index){
	if (size == 0)
		return;
	if (index < 0 || index >= size)
		return;
	
	int* wsk = new int[size - 1];
	memcpy(wsk, head, (index)* sizeof(int) );
	size--;
	memcpy(wsk + index, head + index +1 , (size - index) * sizeof(int));
	delete[] head;
	head = wsk;
	

}



/*Wyszukiwanie inkesu w tablicy o zadanej wartosci. Zwraca indeks , lub 404 jesli wartosc nie zosta³a znaleziona.*/
int Tablica::wyszukajWartosc(int value)
{
	for (int i = 0; i < size; i++) {
		if (*(head + i) == value)
			return i;
	}
	return 404;
}

/*Funkcja zwracaj?ca warto?? elementu tablicy o zadanym indeksie.
Wyrzuca wyj?tek "OutOfBoundException" przy otrzymaniu indexu
wykraczaj?cego poza tablice. */
int Tablica::dostanWartosc(int index)
{
	if (index < 0 || index >= size) {
	return 0;
}
	return *(head + index);
}

void Tablica::zmienWartosc(int index, int value)
{
	if (size == 0) {
		head = new int[1]; size++;
	}
	if (index < 0 || index >= size)
		return ;

	*(head + index) = value;
}

void Tablica::pokazTablice() {
	cout << "Aktualny stan tablicy:" << endl;
	//Je¿eli tablica nie ma elementów, wyœwietl komunikat
	//W przeciwnym wypadku wydrukuj wszystkie elementy tablicy
	if (head != NULL) {
		for (int i = 0; i < size; i++) {
			cout << "    [" << i << "] " <<head[i] << endl;
		}
	}
	else {
		cout << "    Tablica nie ma ¿adnych elementów" << endl;
	}
}