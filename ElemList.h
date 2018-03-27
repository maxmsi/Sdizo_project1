#pragma once
class ElemList
{


public:
	ElemList * nastepny;
	ElemList *poprzedni;
	int wartosc;

	ElemList(int, ElemList *, ElemList *);

};

