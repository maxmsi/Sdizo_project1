#include "loadFile.h"
#include "Tablica.h"
#include "Time.h"

Tablica tablica;
Lista lista;
Kopiec kopiec;


loadFile::loadFile()
{
}


loadFile::~loadFile()
{
}


Tablica *loadFile::loadTablica() {

	int rozmiarTab, i=0 ,wartosc;
	

	cout << "Plik z danymi wejsciowymi: ";
	cin >> daneWejsciowe;
	cout << "Plik z wynikami testu: ";
	cin >> daneWyjsciowe;


	//Otw�rz pliki
	plikWejsciowy.open(daneWejsciowe);
	plikWyjsciowy.open(daneWyjsciowe, fstream::out);
	//Sprawd� czy plik jest otwarty poprawnie
	if (plikWejsciowy.is_open()) {
		cout << "Otwarto plik " << daneWejsciowe << endl;
	}
	else {
		cout << "Nie uda�o sie otworzyc pliku tekstowego!" << endl;
		return &tablica;
	}

	if (plikWyjsciowy.is_open()) {
		cout << "Otwarto plik " << daneWyjsciowe << endl;
	}
	else {
		cout << "Nie uda�o sie otworzyc pliku tekstowego!" << endl;
		return &tablica;
	}
	
	//wprowadzenie danych z pliku do tablicy
	while (plikWejsciowy.good()) {
		Time time;
		//Wczytaj pierwsza warto�� z pliku jako rozmiar tablicy
		if (i == 0) {
			plikWejsciowy >> rozmiarTab;
		}
		if (i != 0) {
			plikWejsciowy >> wartosc;
			time.start_time();
			tablica.dodajNaPoczatek(wartosc);
			//Zapisz do pliku wynik pomiaru
			time.stop_time();
			plikWyjsciowy << time.work_time() << endl;
			if (tablica.size == rozmiarTab)
				tablica.pokazTablice();
			
		}
		i++;
	}
	plikWejsciowy.close();
	plikWyjsciowy.close();

	Tablica *wsk = &tablica;
	return wsk;
}
Lista *loadFile::loadLista() {


	int rozmiarListy, i = 0, wartosc;


	cout << "Plik z danymi wejsciowymi: ";
	cin >> daneWejsciowe;
	cout << "Plik z wynikami testu: ";
	cin >> daneWyjsciowe;

	//Otw�rz pliki
	plikWejsciowy.open(daneWejsciowe);
	plikWyjsciowy.open(daneWyjsciowe, fstream::out);
	//Sprawd� czy plik jest otwarty poprawnie
	if (plikWejsciowy.is_open()) {
		cout << "Otwarto plik " << daneWejsciowe << endl;
	}
	else {
		cout << "Nie uda�o si� otworzy� pliku wej�ciowego!" << endl;
		return &lista;
	}

	if (plikWyjsciowy.is_open()) {
		cout << "Otwarto plik " << daneWyjsciowe << endl;
	}
	else {
		cout << "Nie uda�o si� otworzy� pliku wyj�ciowego!" << endl;
		return &lista;
	}

	//wprowadzenie danych z pliku do tablicy
	while (plikWejsciowy.good()) {
		//Wczytaj pierwsza warto�� z pliku jako rozmiar tablicy
		if (i == 0) {
			plikWejsciowy >> rozmiarListy;
		}
		if (i != 0) {
			plikWejsciowy >> wartosc;
			lista.dodajNaPoczatek(wartosc);
			

		}
		i++;
	}
	plikWejsciowy.close();
	plikWyjsciowy.close();

	Lista *wsk = &lista;
	return wsk;
}

Kopiec *loadFile::loadKopiec() {

	int rozmiarKopca, i = 0, wartosc;

	


	cout << "Plik z danymi wejsciowymi: ";
	cin >> daneWejsciowe;
	cout << "Plik z wynikami testu: ";
	cin >> daneWyjsciowe;

	
	//Otw�rz pliki
	plikWejsciowy.open(daneWejsciowe);
	plikWyjsciowy.open(daneWyjsciowe, fstream::out);
	//Sprawd� czy plik jest otwarty poprawnie
	if (plikWejsciowy.is_open()) {
		cout << "Otwarto plik " << daneWejsciowe << endl;
	}
	else {
		cout << "Nie uda�o sie otworzyc pliku wej�ciowego!" << endl;
		return &kopiec;
	}

	if (plikWyjsciowy.is_open()) {
		cout << "Otwarto plik " << daneWyjsciowe << endl;
	}
	else {
		cout << "Nie uda�o sie otworzyc pliku wyj�ciowego!" << endl;
		return &kopiec;
	}

	//wprowadzenie danych z pliku do tablicy
	while (plikWejsciowy.good()) {
		//Wczytaj pierwsza warto�� z pliku jako rozmiar tablicy
		if (i == 0) {
			plikWejsciowy >> rozmiarKopca;
		}
		if (i != 0) {
			plikWejsciowy >> wartosc;
			kopiec.dodaj(wartosc);
			

		}
		i++;
	}
	plikWejsciowy.close();
	plikWyjsciowy.close();

	
	return &kopiec;
}


