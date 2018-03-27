#include "Lista.h"


//Konstruktor  

Lista::Lista() {

	Lista::pierwszyElement = NULL;
	Lista::aktualnyElement = NULL;
	Lista::ostatniElement = NULL;
	Lista::rozmiar = 0;

}
/*Destruktor listy. Usuwa po kolei wszystkie elementy zaczynaj�c od g�owy.*/
Lista::~Lista() {


	while (pierwszyElement != ostatniElement) {
		pierwszyElement = pierwszyElement->nastepny;
		delete pierwszyElement->poprzedni;
	}

	delete ostatniElement;

}


void Lista::dodajNaPoczatek(int wartosc) {

	
	if (pierwszyElement == NULL) {
		//Jesli nie istnieje element poczatkowy ustawiomy jako poczatkowy i koncowy
		pierwszyElement = new ElemList(wartosc, NULL, NULL);
		ostatniElement = pierwszyElement;

	}
	else {
		//Ustaw element ktory by� pierwszym jako aktualny
		aktualnyElement = pierwszyElement;
		
		//pierwszy element jako nowy, wczesniejszy pierwszy ustawiany jako nastepny.
		pierwszyElement = new ElemList(wartosc, aktualnyElement, NULL);
		aktualnyElement->poprzedni = pierwszyElement;

	}

	
	rozmiar++;

}

void Lista::dodajNaKoniec(int wartosc) {
	//Jesli nie istnieje element poczatkowy ustawiomy jako poczatkowy i koncowy
	if (pierwszyElement == NULL) {
		ostatniElement = new ElemList(wartosc, NULL, NULL);
		pierwszyElement = ostatniElement;

	}
	else {
		//Ustatni jako akutalny
		aktualnyElement = ostatniElement;
		//Zast�p ostatni element nowym, a wczesniejszy ostatni, jako poprzedni.
		ostatniElement = new ElemList(wartosc, NULL, aktualnyElement);
		aktualnyElement->nastepny = ostatniElement;
	}
rozmiar++;
}



void Lista::dodajGdziekolwiek(int index, int _value)
{
	ElemList* node = search(index);
	if (node == nullptr)
		return;

	ElemList* newNode = new ElemList(_value, node, node->poprzedni);
	(newNode->poprzedni)->nastepny = newNode;
	node->poprzedni = newNode;
	rozmiar++;

}




ElemList* Lista::search(int index)
{
	//Je�li index wykracza poza list� to zwraca wska�nik NULL.
	if (index < 0 || index >= rozmiar)
		return nullptr;

	ElemList* node;
	/*Je�li szukany indeks w pierwszej po�owie listy
	to zaczynamy szukanie od wska�nika na g�ow� listy.*/
	if (index <= rozmiar / 2) {

		node = pierwszyElement;
		for (int i = 0; i != index; i++)
			node = node->nastepny
;

	}
	/*W przeciwnym wypadku zaczynamy szukanie od ostatniego elementu listy.*/
	else {
		node = ostatniElement->poprzedni;
		for (int i = rozmiar - 2; i != index; i--)
			node = node->poprzedni;
	}

	return node;
}



void Lista::usunPierwszy() {

	//przypisz drugi element jako aktualny
	aktualnyElement = pierwszyElement->nastepny;

	//Usu� pierwszy element
	delete pierwszyElement;

	//Sprawd�, czy w li�cie s� jeszcze jakie� elementy
	//Je�eli tak, ustaw aktualny element jako pierwszy
	//Je�eli nie, wyzeruj elementy listy
	if (rozmiar > 1) {
		aktualnyElement->poprzedni = NULL;
		pierwszyElement = aktualnyElement;
	}
	else {
		aktualnyElement = NULL;
		pierwszyElement = NULL;
		ostatniElement = NULL;
	}

	//Zmniejsz rozmiar listy
	rozmiar--;
}

void Lista::usunOstatni() {

	//Przypisz przedostani element jako aktualny
	aktualnyElement = ostatniElement->poprzedni;
	//Usu� ostatni element
	delete ostatniElement;

	//Sprawd�, czy w li�cie s� jeszcze jakie� elementy
	//Je�eli tak, ustaw aktualny element jako ostatni
	//Je�eli nie, wyzeruj elementy listy
	if (rozmiar > 1) {
		aktualnyElement->nastepny = NULL;
		ostatniElement = aktualnyElement;
	}
	else {
		aktualnyElement = NULL;
		pierwszyElement = NULL;
		ostatniElement = NULL;
	}

	//Zmniejsz rozmiar listy
	rozmiar--;

}

void Lista::usunKtorys(int pozycja) {

	//Sprawd� czy w li�cie istnieje pozycja podana przez u�ytkownika
	if (pozycja < 0 || pozycja > rozmiar) {
		cout << "W li�cie nie istnieje pozycja [" << pozycja << "]" << endl;
		return;
	}
	//Sprawd� czy wybrana pozycja jest pierwsz�
	if (pozycja == 0) {
		usunPierwszy();
		return;
	}

	//Sprawd� czy wybrana pozycja jest ostatni�
	if (pozycja == rozmiar - 1) {
		usunOstatni();
		return;
	}

	//Sprawd� w kt�rej po�owie listy znajduje si� wybrany element
	if (pozycja < rozmiar / 2) {

		//Przypisz za aktualny element pierwszy
		aktualnyElement = pierwszyElement;

		//Przesu� wszyskie elementy o jeden dalej
		for (int i = 1; i < pozycja - 1; ++i) {
			aktualnyElement = aktualnyElement->nastepny;
		}

	}
	else {

		//Przypisz za aktualny element ostatni
		aktualnyElement = ostatniElement;

		//Przesu� wszystkie elementy o jedn� pozycj� wstecz
		for (int i = 0; i < rozmiar - pozycja - 1; ++i) {
			aktualnyElement = aktualnyElement->poprzedni;
		}

	}

	//Stw�rz nowy element listy z podanymi parametrami
	ElemList *nowyElementListy = aktualnyElement->nastepny;

	//przypisz nowy element w odpowiednim miejscu tablicy
	aktualnyElement->nastepny = nowyElementListy->nastepny;
	aktualnyElement->nastepny->poprzedni = nowyElementListy;

	delete[]nowyElementListy;

	//Zmniejsz rozmiar listy
	rozmiar--;

}

void Lista::wydrukujListe() {

	//Ustaw jako akutualny element pierwszy element listy
	aktualnyElement = pierwszyElement;

	for (int i = 0; i < rozmiar-1; i++) {
		cout << "[" << i << "] " << aktualnyElement->wartosc << endl;

		//Przypisz kolejny element listy jako aktualny
		aktualnyElement = aktualnyElement->nastepny;

	}

}



