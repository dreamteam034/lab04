#include "stdafx.h"
#include "Figure.h"
#include "Point.h"

Figure::Figure()
{
	start = Point( NULL, NULL ); 
	end = Point ( NULL, NULL );
	type = NULL;
	backgroundColor = RGB(0, 0, 0);
	borderColor = RGB(0, 0, 0);
	backgroundStyle = 0;
	borderStyle = PS_SOLID;
}

Figure::Figure(Point start, Point end, char * type) {
	this->start = start;
	this->end = end;
	this->type = type;
	backgroundColor = RGB(0, 0, 0);
	borderColor = RGB(0, 0, 0);
	backgroundStyle = 0;
	borderStyle = PS_SOLID;
}

Figure::Figure(Point start, Point end, char * type, unsigned backgroundColor, unsigned borderColor, int backgroundStyle, int borderStyle)
{
	this->start = start;
	this->end = end;
	this->type = type;
	this->backgroundColor = backgroundColor;
	this->borderColor = borderColor; 
	this->backgroundStyle = backgroundStyle;
	this->borderStyle = borderStyle;
}

BOOL Figure::draw(HDC hdc, float Scale)
{
	BOOL tmp;
	wchar_t buffer[64];

	if (strcmp(type, "line") == 0) {
		tmp = MoveToEx(hdc, start.getX() * Scale, start.getY() * Scale, NULL);
		if (!tmp)
			return tmp;
		tmp = LineTo(hdc, end.getX() * Scale, end.getY() * Scale);
	}
	else if (strcmp(type, "rectangle") == 0) {
		tmp = Rectangle(hdc, start.getX() * Scale, start.getY() * Scale, end.getX() * Scale, end.getY() * Scale);
	}
	else if (strcmp(type, "circle") == 0) {
		tmp = Ellipse(hdc, start.getX() * Scale, start.getY()* Scale, end.getX() * Scale, end.getY() * Scale);
	}

	return tmp;
}

void Figure::move(Point oldMousePos, Point newMousePos)
{
	Point mouseDelta = newMousePos - oldMousePos;
	start = start + mouseDelta;
	end = end + mouseDelta;
}


void Figure::setPosInList(unsigned int value)
{
	posInList = value;
}

unsigned int Figure::getPosInList()
{
	return posInList;
}

Figure::~Figure()
{
}
