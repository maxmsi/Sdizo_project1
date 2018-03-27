#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include "Tablica.h"
#include "Lista.h"
#include "Kopiec.h"
#include "Time.h"


using namespace std;

class loadFile
{
public:

	ofstream plikWyjsciowy;
	ifstream plikWejsciowy;

	string daneWejsciowe, daneWyjsciowe;


	Tablica *loadTablica();
	Lista *loadLista();
	Kopiec *loadKopiec();

	

	loadFile();
	~loadFile();


};

