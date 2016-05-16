#pragma once

#include <windows.h>
#include "Point.h"

class Figure
{
private:
	Point start, end;
	char *type = "";
	
public:
	Figure();
	Figure(Point start, Point end, char *type);

	BOOL draw(HDC hdc, float Scale);
	void move(Point oldMousePos, Point newMousePos);
	void destroy();

	~Figure();
};

