#pragma once

#include "ElemList.h"
#include <iostream>

using namespace std;


class Lista {

public:

	int rozmiar;

	Lista();
	~Lista();
	
	ElemList *pierwszyElement;
	ElemList *ostatniElement;
	ElemList *aktualnyElement;
	ElemList* search(int index);

	void dodajNaPoczatek(int wartosc);

	void dodajGdziekolwiek(int pozycja, int wartosc);

	void dodajNaKoniec(int wartosc);

	void wydrukujListe();

	void usunPierwszy();

	void usunOstatni();

	void usunKtorys(int);
};
