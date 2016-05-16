#include "stdafx.h"
#include "Point.h"


Point::Point()
{
	x = NULL;
	y = NULL;
}

Point::Point(int x, int y) {
	this->x = x;
	this->y = y;
}

Point Point::operator+(const Point A) {
	return Point(x + A.x, y + A.y);
}

Point Point::operator-(const Point A)
{
	return Point(x - A.x, y - A.y);
}

int Point::getX()
{
	return x;
}

int Point::getY()
{
	return x;
}

Point Point::get()
{
	return Point(x, y);
}

Point::~Point()
{
}

