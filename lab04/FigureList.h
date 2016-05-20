#pragma once

#include "Figure.h"

class FigureList
{
private:
	Figure *list;
	unsigned int count;
public:
	FigureList();

	unsigned getLength();
	bool add(Figure figure);
	void drawList(HDC hdc, float Scale);
	bool remove(unsigned int pos); //	пока что не знаю что с этим делать

	~FigureList();
};

