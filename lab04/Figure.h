#pragma once

#include <windows.h>
#include "Point.h"

class Figure
{
private:
	Point start, end;
	unsigned backgroundColor, borderColor;
	int backgroundStyle, borderStyle ;
	char *type = "";
	bool selected;

	unsigned int posInList; 
public:
	Figure();
	Figure(Point start, Point end, char *type);
	Figure(Point start, Point end, char *type, unsigned backgroundColor, unsigned borderColor, int backgroundStyle, int borderStyle);

	BOOL draw(HDC hdc, float Scale);
	void move(Point oldMousePos, Point newMousePos);
	void destroy();

	void setPosInList(unsigned int value);

	unsigned int getPosInList();

	~Figure();
};

