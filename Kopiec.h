#pragma once

#include "Tablica.h"
#include <fstream>
#include <string>
#include <sstream>
#include <math.h>


class Kopiec
{
private:
	Tablica * root;
	int size;

	void napraw_w_gore(Tablica* tab, int len);
	void napraw_w_dol(Tablica*tab, int index, int len);

public:
	Kopiec();
	~Kopiec();

	void wydrukujKopiec(string sp, string sn, int v);
	void pokazKopiec();
	void dodaj(int value);
	void usun();
	int znajdzWartosc(int value,int index);
	int get(int index);
};


