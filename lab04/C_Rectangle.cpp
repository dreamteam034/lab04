#include "stdafx.h"
#include "C_Rectangle.h"


C_Rectangle::C_Rectangle()
{
	A = { 0, 0 };
	B = { 0, 0 };
}

C_Rectangle::C_Rectangle(POINT A, POINT B)
{
	this->A = A;
	this->B = B;
}

void C_Rectangle::Draw(HDC hdc, float Scale)
{
	Rectangle(hdc, A.x * Scale, A.y * Scale, B.x * Scale, B.y * Scale);
}

void C_Rectangle::Remove()
{
}


C_Rectangle::~C_Rectangle()
{
}
