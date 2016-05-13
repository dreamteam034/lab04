#pragma once

#include <windows.h>

class C_Circle
{
private:
	POINT C;
	unsigned int R;
public:
	C_Circle();
	C_Circle(POINT C, unsigned int R);

	void Draw(HDC hdc, float Scale);
	void Remove();

	~C_Circle();
};

