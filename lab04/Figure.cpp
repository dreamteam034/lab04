#include "stdafx.h"
#include "Figure.h"
#include "Point.h"

Figure::Figure()
{
	start = Point( NULL, NULL ); 
	end = Point ( NULL, NULL );
	type = NULL;
}

Figure::Figure(Point start, Point end, char * type)
{
	this->start = start;
	this->end = end;
	this->type = type;
}

BOOL Figure::draw(HDC hdc, float Scale)
{
	BOOL tmp;

	if (strcmp(type, "line")) {
		tmp = MoveToEx(hdc, start.getX() * Scale, start.getY() * Scale, NULL);
		if (!tmp)
			return tmp;
		tmp = LineTo(hdc, end.getX() * Scale, end.getY() * Scale);
	}
	else if (strcmp(type, "rectangle")) {
		tmp = Rectangle(hdc, start.getX() * Scale, start.getY() * Scale, end.getX() * Scale, end.getY() * Scale);
	}
	else if (strcmp(type, "circle")) {
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


Figure::~Figure()
{
}
