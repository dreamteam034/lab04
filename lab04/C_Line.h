#pragma once

#include <windows.h>

class C_Line
{
private: 
	POINT A, B;
public:
	C_Line();
	C_Line(POINT A, POINT B);

	void Draw(HDC hdc, float Scale);
	void Remove();

	~C_Line();
};

