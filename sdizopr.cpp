// sdizopr.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"


#include <iostream>
#include "Tablica.h"
#include "Lista.h"
#include "Kopiec.h"
#include "Time.h"
#include "loadFile.h"
#include "Test.h"

using namespace std;






int main() {

	loadFile file;
	Test test;
	
	//Inicjalizacja klasy testującej
	int wybor = -1;

	cout << "SDiZO, Projekt 1, Kamil Babik, 235030" << endl << endl;


	//poczatkowe menu
	while (wybor != 0) {
		cout << "Wybierz strukture do testow:" << endl;
		cout << "    1. Tablica Dynamiczna" << endl;
		cout << "    2. Lista" << endl;
		cout << "    3. Kopiec Binarny" << endl;
		cout << "    0. Wyjscie" << endl << endl;
		cout << "Wybor: ";
		cin >> wybor;

		//Wyjscie z programu
		if (wybor == 0) return 0;



		switch (wybor) {
		default:
			cout << "Bledny wybór!" << endl;
			break;

		case 0:
			break;

		case 1:
			cout << "Testowanie tablicy dynamicznej..." << endl;
			
			test.testTablicy(file.loadTablica());
			break;

		case 2:
			cout << "Testowanie listy..." << endl;

			test.testListy(file.loadLista());

		case 3:
			cout << "Testowanie kopca binarnego..." << endl;

			test.testKopca(*file.loadKopiec());
			break;
		}
	}


		system("pause");
		return 0;
	}



