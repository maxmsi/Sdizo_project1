#include "Test.h"
#include "loadFile.h"
#include "Tablica.h"
#include "Time.h"



Test::Test()
{
}


Test::~Test()
{
}

void Test::testTablicy(Tablica *tab) {

	int wybor=99;

	while (wybor != 0) {
		cout << "Wybierz funkcje tablicy:" << endl;
		cout << "    1. Dodaj na poczatek" << endl;
		cout << "    2. Dodaj na koniec" << endl;
		cout << "    3. Dodaj gdziekolwiek" << endl;
		cout << "    4. Usun pierwszy" << endl;
		cout << "    5. Usun ostatni" << endl;
		cout << "    6. Usun wedlug indeksu" << endl;
		cout << "    7. Wyszukaj element po wartosci" << endl;
		cout << "    8. Wyszukaj element po indeksie" << endl;
		cout << "    9. Pokaz tablice" << endl;
		cout << "    0. Wyjscie" << endl << endl;
		cout << "Wybor: ";
		cin >> wybor;

		Time time;
		switch (wybor) {
		default:
			cout << "B³êdny wybór!" << endl;
			break;

		case 0:
			return;

		case 1:
			int x;
			cout << " Podaj wartosc do dodania: "; cin >> x;
			cout << "Rozpoczynanie pomiaru...";
			time.start_time();
			tab->dodajNaPoczatek(x);
			time.stop_time();
			cout<< "Czas wykonania operacji:  "<<time.work_time()<<" nanosekund \n";
			break;
		case 2:
			int x2;
			cout << " Podaj wartosc do dodania: "; cin >> x2;
			cout << "Rozpoczynanie pomiaru...";
			time.start_time();
			tab->dodajNaKoniec(x2);
			time.stop_time();
			cout << "Czas wykonania operacji:  " << time.work_time() << " nanosekund \n";
			
			break;

		case 3:
			int x3, where;
			cout << " Podaj wartosc do dodania: "; cin >> x3;
			cout << " Podaj miejsce dodania : "; cin >> where;
			cout << "Rozpoczynanie pomiaru...";
			time.start_time();
			tab->dodajGdziekolwiek(x,where);
			time.stop_time();
			cout << "Czas wykonania operacji:  " << time.work_time() << " nanosekund \n ";
		
			break;

		case 4:
			cout << "Rozpoczynanie pomiaru...";
			time.start_time();
			tab->usunPierwszy();
			time.stop_time();
			cout << "Czas wykonania operacji:  " << time.work_time() << " nanosekund \n";
			break;

		case 5:
			cout << "Rozpoczynanie pomiaru...";
			time.start_time();
			tab->usunOstatni();
			time.stop_time();
			cout << "Czas wykonania operacji:  " << time.work_time() << " nanosekund \n";
			
			break;

		case 6:
			int x4;
			cout << " Podaj wartosc indeksu do usuniecia: "; cin >> x4;
			cout << "Rozpoczynanie pomiaru...";
			time.start_time();
			tab->usunIndeks(x4);
			time.stop_time();
			cout << "Czas wykonania operacji:  " << time.work_time() << " nanosekund \n";
			
			break;

		case 7:
			int x5;
			cout << " Podaj wartosc do wyszukania: "; cin >> x5;
			cout << "Rozpoczynanie pomiaru...";
			time.start_time();
			tab->wyszukajWartosc(x5);
			time.stop_time();
			cout << "Czas wykonania operacji:  " << time.work_time() << " nanosekund \n";
			
			break;

		case 8:
			int x6;
			cout << " Podaj wartosc indeksu do wyszukania: "; cin >> x6;
			cout << "Rozpoczynanie pomiaru...";
			time.start_time();
			tab->dostanWartosc(x6);
			time.stop_time();
			cout << "Czas wykonania operacji:  " << time.work_time() << " nanosekund \n";
			
			break;
		case 9:
			
			time.start_time();
			tab->pokazTablice();
			time.stop_time();
			cout << "Czas wykonania operacji:  " << time.work_time() << " nanosekund \n";

			break;
		}

	}


}

void Test::testListy(Lista *list) {

	int wybor = 99;

		while (wybor != 0) {
			cout << "Wybierz funkcje listy:" << endl;
			cout << "    1. Dodaj na poczatek" << endl;
			cout << "    2. Dodaj na koniec" << endl;
			cout << "    3. Dodaj gdziekolwiek" << endl;
			cout << "    4. Usun pierwszy" << endl;
			cout << "    5. Usun ostatni" << endl;
			cout << "    6. Usun którykolwiek" << endl;
			cout << "    7. Wyszukaj element" << endl;
			cout << "    8. Wydrukuj liste" << endl;
			cout << "    0. Wyjscie" << endl << endl;
			cout << "Wybor: ";
			cin >> wybor;

			Time time;
			switch (wybor) {
			default:
				cout << "B³êdny wybór!" << endl;
				break;

			case 0:
				return;

			case 1:
				int x;
				cout << " Podaj wartosc do dodania: "; cin >> x;
				cout << "Rozpoczynanie pomiaru...";
				time.start_time();
				list->dodajNaPoczatek(x);
				time.stop_time();
				cout << "Czas wykonania operacji:  " << time.work_time() << " nanosekund \n";
				break;
			case 2:
				int x2;
				cout << " Podaj wartosc do dodania: "; cin >> x2;
				cout << "Rozpoczynanie pomiaru...";
				time.start_time();
				list->dodajNaKoniec(x2);
				time.stop_time();
				cout << "Czas wykonania operacji:  " << time.work_time() << " nanosekund \n";

				break;

			case 3:
				int x3, where;
				cout << " Podaj wartosc do dodania: "; cin >> x3;
				cout << " Podaj miejsce dodania : "; cin >> where;
				cout << "Rozpoczynanie pomiaru...";
				time.start_time();
				list->dodajGdziekolwiek(where, x3);
				time.stop_time();
				cout << "Czas wykonania operacji:  " << time.work_time() << " nanosekund \n ";

				break;

			case 4:
				cout << "Rozpoczynanie pomiaru...";
				time.start_time();
				list->usunPierwszy();
				time.stop_time();
				cout << "Czas wykonania operacji:  " << time.work_time() << " nanosekund \n";
				break;

			case 5:
				cout << "Rozpoczynanie pomiaru...";
				time.start_time();
				list->usunOstatni();
				time.stop_time();
				cout << "Czas wykonania operacji:  " << time.work_time() << " nanosekund \n";

				break;

			case 6:
				int x4;
				cout << " Podaj wartosc indeksu do usuniecia: "; cin >> x4;
				cout << "Rozpoczynanie pomiaru...";
				time.start_time();
				list->usunKtorys(x4);
				time.stop_time();
				cout << "Czas wykonania operacji:  " << time.work_time() << " nanosekund \n";

				break;

			

			case 7:
				int x6;
				cout << " Podaj wartosc indeksu do wyszukania: "; cin >> x6;
				cout << "Rozpoczynanie pomiaru...";
				time.start_time();
				list->search(x6);
				time.stop_time();
				cout << "Czas wykonania operacji:  " << time.work_time() << " nanosekund \n";

				break;
			case 8:

				time.start_time();
				list->wydrukujListe();
				time.stop_time();
				cout << "Czas wykonania operacji:  " << time.work_time() << " nanosekund \n";

				break;
			}

		}


	}

void Test::testKopca(Kopiec kop) {

	int wybor = 99;

	while (wybor != 0) {
		cout << "Wybierz funkcje Kopca:" << endl;
		cout << "    1. Dodaj" << endl;
		cout << "    2. Usun" << endl;
		cout << "    3. Wyszukaj" << endl;
		cout << "    4. Wydrukuj kopiec" << endl;
		cout << "    5. Rysuj kopiec" << endl;
		cout << "    0. Wyjscie" << endl << endl;
		cout << "Wybor: ";
		cin >> wybor;

		Time time;
		switch (wybor) {
		default:
			cout << "Bledny wybor!" << endl;
			break;

		case 0:
			return;

		case 1:
			int x;
			cout << " Podaj wartosc do dodania: "; cin >> x;
			cout << "Rozpoczynanie pomiaru...";
			time.start_time();
			kop.dodaj(x);
			time.stop_time();
			cout << "Czas wykonania operacji:  " << time.work_time() << " nanosekund \n";
			break;
		case 2:
		
			cout << "Rozpoczynanie pomiaru...";
			time.start_time();
			kop.usun();
			time.stop_time();
			cout << "Czas wykonania operacji:  " << time.work_time() << " nanosekund \n";

			break;

		case 3:
			int x3, where;
			
			cout << " Podaj wartosc do odszukania : "; cin >>x3;
			cout << " Zacznij poszukiwania od indeksu : "; cin >> where;
			cout << "Rozpoczynanie pomiaru...";
			time.start_time();
			kop.znajdzWartosc(x3,where);
			time.stop_time();
			cout << "Czas wykonania operacji:  " << time.work_time() << " nanosekund \n ";

			break;

		case 4:
			cout << "Drukowanie kopca :\n";
			time.start_time();
			kop.pokazKopiec();
			time.stop_time();
			cout << "Czas wykonania operacji:  " << time.work_time() << " nanosekund \n";
			break;

		case 5:
			cout << "Rysowanie kopca..\n";
			time.start_time();
			kop.wydrukujKopiec("","",0);
			time.stop_time();
			cout << "Czas wykonania operacji:  " << time.work_time() << " nanosekund \n";

			break;




		}

	}


}


