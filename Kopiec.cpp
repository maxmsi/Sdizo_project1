#include "Kopiec.h"

using namespace std;
#include <iostream>

Kopiec::Kopiec() {


	root = new Tablica();
	size = 0;

}

Kopiec::~Kopiec() {

	delete root;

}


//Dodanie elementu do kopca
void Kopiec::dodaj(int value)
{

	if (size == 0) {
		//root->dodajNaPoczatek(value);
		//size++;
		//return;
	}
	size++;
	root->dodajNaKoniec(value);
	//naprawa kopca
	napraw_w_gore(root, size);


}


//naprawia strukture kopca w gore
void Kopiec::napraw_w_gore(Tablica* tab, int len)
{
	//indeks na ostatni elemnt w tablicy.
	int i = len - 1;
	//znalezienie rodzica
	int rodzic = (i - 1) / 2;
	while (tab->dostanWartosc(rodzic) < tab->dostanWartosc(i)) {
		int bufor = tab->dostanWartosc(rodzic);
		//zamiana miejscami rodzica z nowym elementem
		tab->zmienWartosc(rodzic, tab->dostanWartosc(i));
		tab->zmienWartosc(i, bufor);
		//przypisanie nowego indeksu nowego elementu
		i = rodzic;
		//znalezienie rodzica dla nowego indeksu
		rodzic = (i - 1) / 2;
	}
}


/*usuwanie elementu z korzenia.*/
void Kopiec::usun() {
	//jeœli kopiec pusty to koniec
	if (size == 0)
		return;
	//wstawienie ostatniego liœcia na miejsce korzenia

	root->zmienWartosc(0, root->dostanWartosc(size - 1));
	//usuniêcie ostatniego liœcia
	root->usunIndeks(size - 1);
	size--;
	napraw_w_dol(root,0,size);
}

//naprawie strukture kopca w dol
void Kopiec::napraw_w_dol(Tablica*tab, int index, int len) {


	int j = 2 * index + 1; //indeks syna (teraz lewego)
	while (j < len) {

		//szukam wiêkszego syna
		if (j + 1 < len && tab->dostanWartosc(j) < tab->dostanWartosc(j + 1))
			j = j + 1;

		if (tab->dostanWartosc(index) >= tab->dostanWartosc(j))
			break;

		int buf = tab->dostanWartosc(index);
		tab->zmienWartosc(index, tab->dostanWartosc(j));
		tab->zmienWartosc(j, buf);
		index = j;
		j = 2 * index + 1;
	}


}


/*zwraca indeks od podanej wartosci, zaczynajac od wskazanego indexu w dol, lub 404 jesli nie istnieje*/
int Kopiec::znajdzWartosc(int value,int index)
{


	if (index >= this->size || index < 0)
		return 404;
	if (root->dostanWartosc(index) == value)
		return index;
	int lewySyn = 2 * index + 1;
	int prawySyn = lewySyn + 1;
	int x = 404;
	x = znajdzWartosc(value,lewySyn);
	if (x == 404)
		x = znajdzWartosc(value,prawySyn);
	return x;
}

/*prywatna funckja zwracajaca wartosc od podanego indeksu*/
int Kopiec::get(int index)
{
	return root->dostanWartosc(index);
}




void Kopiec::pokazKopiec() {

	cout << "Aktualny stan kopca:" << endl;
	//Je¿eli tablica nie ma elementów, wyœwietl komunikat
	//W przeciwnym wypadku wydrukuj wszystkie elementy tablicy
	if (root != NULL) {
		for (int i = 0; i < size; i++) {
			cout << "    [" << i << "] " << root->dostanWartosc(i) << endl;
		}
	}
	else {
		cout << "    Tablica nie ma ¿adnych elementów" << endl;
	}

}


void Kopiec::wydrukujKopiec(string sp, string sn, int v) {
	string cr, cl, cp;
	cr = cl = cp = "  ";
	cr[0] = 218; cr[1] = 196;
	cl[0] = 192; cl[1] = 196;
	cp[0] = 179;

	string s;

	if (v < size)
	{
		s = sp;
		if (sn == cr) s[s.length() - 2] = ' ';
		wydrukujKopiec(s + cp, cr, 2 * v + 2);

		s = s.substr(0, sp.length() - 2);

		cout << s << sn << root->dostanWartosc(v) << endl;

		s = sp;
		if (sn == cl) s[s.length() - 2] = ' ';
		wydrukujKopiec(s + cp, cl, 2 * v + 1);
	}
}



