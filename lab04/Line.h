#pragma once

#include <Windows.h>

class Line
{
private: 
	POINT A, B;
public:
	Line();
	Line(POINT A, POINT B);

	void Draw(HDC hdc, int Scale);
	void Remove();

	~Line();
};

