#pragma once

#include <windows.h>

class C_Rectangle
{
private:
	POINT A, B;
public:
	C_Rectangle();
	C_Rectangle(POINT A, POINT B);

	void Draw(HDC hdc, float Scale);
	void Remove();

	~C_Rectangle();
};

