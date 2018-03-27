#pragma once
#include <iostream>
#include "Tablica.h"
#include "Lista.h"
#include <chrono>
#include "Time.h"
#include "Kopiec.h"



using namespace std::chrono;

using namespace std;

class Test
{
public:



	Test();
	~Test();



	void testTablicy(Tablica *tab);
	void testListy(Lista *list);
	void testKopca(Kopiec kopiec);

};

