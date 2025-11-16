#pragma once
#include "framework.h"
#include "course_work.h"
#include <iostream>
class Figure
{
protected:
public:
	virtual void Draw(HDC hdc, int x0, int y0, int r) = 0;
	virtual void Erase(HDC hdc, COLORREF bgColor) = 0;
	virtual void Set_Colour(unsigned char r, unsigned char g, unsigned char b) = 0;
	virtual void SetRadius(int newR) = 0;
	virtual bool HitTest(int mx, int my) = 0;
	virtual int X() const = 0;
	virtual int Y() const = 0;
	virtual int R() const = 0;
	virtual void SetX(int newX) = 0;
	virtual void SetY(int newY) = 0;
	virtual ~Figure() {};
};
