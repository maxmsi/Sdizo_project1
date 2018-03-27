
#pragma once

#include <cstring>
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Tablica{
public:


	int *head;
	int size;
	Tablica();
	Tablica(int *tab, int len);
	~Tablica();

		void dodajNaPoczatek(int);
		void dodajNaKoniec(int value);
		void dodajGdziekolwiek(int value, int where);

		void usunOstatni();
		void usunPierwszy();
		void usunIndeks(int index);
		
		void pokazTablice();

		int wyszukajWartosc(int value);
		int dostanWartosc(int index);
		void zmienWartosc(int index, int value);
	
};

