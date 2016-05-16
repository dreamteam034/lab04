#pragma once

#include <windows.h>

class Point
{
private: 
	int x, y;
public:
	Point();
	Point(int x, int y);

	Point operator+ (const Point A);
	Point operator- (const Point A);

	int getX();
	int getY();
	Point get();

	~Point();
};

