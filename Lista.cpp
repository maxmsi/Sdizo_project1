#include "Lista.h"


//Konstruktor  

Lista::Lista() {

	Lista::pierwszyElement = NULL;
	Lista::aktualnyElement = NULL;
	Lista::ostatniElement = NULL;
	Lista::rozmiar = 0;

}
/*Destruktor listy. Usuwa po kolei wszystkie elementy zaczynaj¹c od g³owy.*/
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
		//Ustaw element ktory by³ pierwszym jako aktualny
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
		//Zast¹p ostatni element nowym, a wczesniejszy ostatni, jako poprzedni.
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
	//Jeœli index wykracza poza listê to zwraca wskaŸnik NULL.
	if (index < 0 || index >= rozmiar)
		return nullptr;

	ElemList* node;
	/*Jeœli szukany indeks w pierwszej po³owie listy
	to zaczynamy szukanie od wskaŸnika na g³owê listy.*/
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

	//Usuñ pierwszy element
	delete pierwszyElement;

	//SprawdŸ, czy w liœcie s¹ jeszcze jakieœ elementy
	//Je¿eli tak, ustaw aktualny element jako pierwszy
	//Je¿eli nie, wyzeruj elementy listy
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
	//Usuñ ostatni element
	delete ostatniElement;

	//SprawdŸ, czy w liœcie s¹ jeszcze jakieœ elementy
	//Je¿eli tak, ustaw aktualny element jako ostatni
	//Je¿eli nie, wyzeruj elementy listy
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

	//SprawdŸ czy w liœcie istnieje pozycja podana przez u¿ytkownika
	if (pozycja < 0 || pozycja > rozmiar) {
		cout << "W liœcie nie istnieje pozycja [" << pozycja << "]" << endl;
		return;
	}
	//SprawdŸ czy wybrana pozycja jest pierwsz¹
	if (pozycja == 0) {
		usunPierwszy();
		return;
	}

	//SprawdŸ czy wybrana pozycja jest ostatni¹
	if (pozycja == rozmiar - 1) {
		usunOstatni();
		return;
	}

	//SprawdŸ w której po³owie listy znajduje siê wybrany element
	if (pozycja < rozmiar / 2) {

		//Przypisz za aktualny element pierwszy
		aktualnyElement = pierwszyElement;

		//Przesuñ wszyskie elementy o jeden dalej
		for (int i = 1; i < pozycja - 1; ++i) {
			aktualnyElement = aktualnyElement->nastepny;
		}

	}
	else {

		//Przypisz za aktualny element ostatni
		aktualnyElement = ostatniElement;

		//Przesuñ wszystkie elementy o jedn¹ pozycjê wstecz
		for (int i = 0; i < rozmiar - pozycja - 1; ++i) {
			aktualnyElement = aktualnyElement->poprzedni;
		}

	}

	//Stwórz nowy element listy z podanymi parametrami
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



