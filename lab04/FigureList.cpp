#include "stdafx.h"
#include "FigureList.h"


FigureList::FigureList()
{
	count = 0;
	list = NULL;
}

bool FigureList::add(Figure figure)
{
	Figure * listPtr;
	count++;
	listPtr = (Figure *)realloc(list, count * sizeof(Figure));
	list = listPtr; 
	list[count - 1] = figure;
	return true;
}

void FigureList::drawList(HDC hdc, float Scale)
{
	for (int i = 0; i < count; i++) {
		list[i].draw(hdc, Scale);
	}
}

FigureList::~FigureList()
{
}
