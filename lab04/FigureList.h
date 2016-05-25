#pragma once

#include <fstream>

#include "Figure.h"

using namespace std;

class FigureList
{
private:
	Figure *list;
	unsigned int count;
public:
	FigureList();

	void printList(wchar_t *path);
	unsigned getLength();
	bool add(Figure figure);
	void drawList(HDC hdc, float Scale);
	bool remove(unsigned int pos); //	пока что не знаю что с этим делать

	~FigureList();
};

