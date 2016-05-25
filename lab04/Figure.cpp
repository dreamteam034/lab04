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
	backgroundStyle = -1;
	borderStyle = 0;
}

Figure::Figure(static Point start, static Point end, static char * type) {
	this->start = start;
	this->end = end;
	this->type = type;
	backgroundColor = RGB(0, 0, 0);
	borderColor = RGB(0, 0, 0);
	backgroundStyle = -1;
	borderStyle = 0;
}

Figure::Figure(static Point start, static Point end, static char * type, static unsigned backgroundColor, static unsigned borderColor, static int backgroundStyle, static int borderStyle)
{
	this->start = start;
	this->end = end;
	this->type = type;
	this->backgroundColor = backgroundColor;
	this->borderColor = borderColor; 
	this->backgroundStyle = backgroundStyle;
	this->borderStyle = borderStyle;
}

BOOL Figure::draw(static HDC hdc, static float Scale)
{
	BOOL tmp;
	wchar_t buffer[64];

	HPEN hPen = CreatePen(borderStyle, 0, borderColor);
	
	HBRUSH hBrush;
	if (backgroundStyle >= 0)
		hBrush = CreateHatchBrush(backgroundStyle, backgroundColor);
	else
		hBrush = CreateSolidBrush(backgroundColor);
		
	SelectObject(hdc, hPen);
	SelectObject(hdc, hBrush);

	if (strcmp(type, "line") == 0) {
		MoveToEx(hdc, start.getX() * Scale, start.getY() * Scale, NULL);
		tmp = LineTo(hdc, end.getX() * Scale, end.getY() * Scale);
	}
	else if (strcmp(type, "rectangle") == 0) {
		tmp = Rectangle(hdc, start.getX() * Scale, start.getY() * Scale, end.getX() * Scale, end.getY() * Scale);
	}
	else if (strcmp(type, "circle") == 0) {
		tmp = Ellipse(hdc, start.getX() * Scale, start.getY()* Scale, end.getX() * Scale, end.getY() * Scale);
	}

	DeleteObject(hPen);
	DeleteObject(hBrush);

	return tmp;
}

void Figure::move(static Point oldMousePos, static Point newMousePos)
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

char * Figure::getType()
{
	return type;
}

Figure::~Figure()
{
}
