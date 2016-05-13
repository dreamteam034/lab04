#include "stdafx.h"
#include "Line.h"


Line::Line()
{
	A = { 0, 0 };
	B = { 0, 0 };
}

Line::Line(POINT A, POINT B)
{
	this->A = A;
	this->B = B;
}

void Line::Draw(HDC hdc, int Scale)
{
	MoveToEx(hdc, A.x, A.y, NULL);
	LineTo(hdc, B.x * Scale, B.y * Scale);
}

void Line::Remove()
{
}


Line::~Line()
{
}
