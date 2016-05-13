#include "stdafx.h"
#include "C_Line.h"


C_Line::C_Line()
{
	A = { 0, 0 };
	B = { 0, 0 };
}

C_Line::C_Line(POINT A, POINT B)
{
	this->A = A;
	this->B = B;
}

void C_Line::Draw(HDC hdc, float Scale)
{
	MoveToEx(hdc, A.x * Scale, A.y * Scale, NULL);
	LineTo(hdc, B.x * Scale, B.y * Scale);
}

void C_Line::Remove()
{
}

C_Line::~C_Line()
{
}

