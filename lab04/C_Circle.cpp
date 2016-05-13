#include "stdafx.h"
#include "C_Circle.h"


C_Circle::C_Circle()
{
	C = { 0, 0 };
	R = 0;
}

C_Circle::C_Circle(POINT C, unsigned int R)
{
	this->C = C;
	this->R = R;
}

void C_Circle::Draw(HDC hdc, float Scale)
{
	Ellipse(hdc, C.x - R, C.y - R, C.x + R, C.y + R);
}

void C_Circle::Remove()
{
}


C_Circle::~C_Circle()
{
}
