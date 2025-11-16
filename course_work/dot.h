#pragma once
#include "circ_func.h"


using namespace std;


class Dot : public Figure
{
private:
	int x0, y0, r;
	HPEN pen;
	HBRUSH brush;

public:				
	Dot(): 
		x0(10), 
		y0(10), 
		r(10), 
		pen(CreatePen(PS_SOLID, 0, RGB(0, 0, 0))), 
		brush(CreateSolidBrush(RGB(0, 0, 0)))
	{}

	void Draw(HDC hdc, int x0, int y0, int r) override
	{
		this->x0 = x0;
		this->y0 = y0;
		this->r = r;
		SelectObject(hdc, pen);
		SelectObject(hdc, brush);

		Ellipse(hdc, x0, y0, x0 + r, y0 + r);
	}

	void Set_Colour(unsigned char r, unsigned char g, unsigned char b) override
	{
		DeleteObject(pen);
		DeleteObject(brush);

		pen = CreatePen(PS_SOLID, 0, RGB(r, g, b));
		brush = CreateSolidBrush(RGB(r, g, b));
	}
	void Erase(HDC hdc, COLORREF bgColor = RGB(255, 255, 255)) override
	{
		HPEN erasePen = CreatePen(PS_SOLID, 0, bgColor);
		HBRUSH eraseBrush = CreateSolidBrush(bgColor);

		SelectObject(hdc, erasePen);
		SelectObject(hdc, eraseBrush);

		Ellipse(hdc, x0, y0, x0 + r, y0 + r);

		DeleteObject(erasePen);
		DeleteObject(eraseBrush);
	}
	void SetRadius(int newR) override
	{
		r = newR;
	}
	int X() const { return x0; }
	int Y() const { return y0; }
	int R() const {return r;}
	void SetX(int newX) { x0 = newX; }
	void SetY(int newY) { y0 = newY; }

	bool HitTest(int mx, int my) override
	{
		int cx = x0 + r / 2, cy = y0 + r / 2;
		int dx = mx - cx, dy = my - cy;
		return dx * dx + dy * dy <= (r / 2) * (r / 2);
	}

	~Dot()
	{

	};
};

