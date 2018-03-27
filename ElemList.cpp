#include "ElemList.h"





ElemList::ElemList(int wartosc , ElemList * nastepny, ElemList *poprzedni) {

	ElemList::wartosc = wartosc;
	ElemList::nastepny = nastepny;
	ElemList::poprzedni = poprzedni;



}