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
	Figure(static Point start, static Point end, static char *type);
	Figure(static Point start, static Point end, static char *type, static unsigned backgroundColor, static unsigned borderColor, static int backgroundStyle, static int borderStyle);

	BOOL draw(static HDC hdc, static float Scale);
	void move(static Point oldMousePos, static Point newMousePos);

	void setPosInList(static unsigned int value);

	unsigned int getPosInList();
	char * getType();

	~Figure();
};

