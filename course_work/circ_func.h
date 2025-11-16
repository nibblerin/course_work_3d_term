#pragma once
#include "figure.h"
#include <string>

using namespace std;


class ElipseWithText : public Figure
{
private:
	int x0, y0, r;
	HPEN pen;
	const wchar_t* text; //формат wide текст , чтобы отображалисть символы UNICODE
	COLORREF textColor;   // цвет текста


public:
	ElipseWithText(const wchar_t* txt = L"") : x0(10), y0(10), r(5), text(txt), pen(CreatePen(PS_SOLID, 0, RGB(255, 255, 255))) {}

	void Draw(HDC hdc, int x0, int y0, int r) override
	{
		this->x0 = x0;
		this->y0 = y0;
		this->r = r;

		SelectObject(hdc, pen);

		Ellipse(hdc, x0, y0, x0 + r, y0 + r);
		RECT rect;
		rect.left = x0 + 5;
		rect.top = y0 + 5;
		rect.right = x0 + r - 5;
		rect.bottom = y0 + r - 5;

		SetBkMode(hdc, TRANSPARENT); //фон текста - прозрачный
		SetTextColor(hdc, textColor);

		DrawTextW(hdc, this->text, -1, &rect,
			DT_CENTER | DT_WORDBREAK | DT_VCENTER);//два центрирования текста + перенос
	}

	void Set_Colour(unsigned char r, unsigned char g, unsigned char b) override
	{
		pen = CreatePen(PS_SOLID, 0, RGB(r, g, b));
		textColor = RGB(r, g, b);

	}	
	void SetText(const wchar_t* txt)
	{
		text=txt;
	}
	void Erase(HDC hdc, COLORREF bgColor = RGB(255, 255, 255)) override
	{
		int left = x0 - r;
		int top = y0 - r;
		int right = x0 + r;
		int bottom = y0 + r;
		HPEN erasePen = CreatePen(PS_SOLID, 0, bgColor);
		HBRUSH eraseBrush = CreateSolidBrush(bgColor);

		SelectObject(hdc, erasePen); 
		SelectObject(hdc, eraseBrush); 
		Ellipse(hdc, x0, y0, x0 + r, y0 + r);

		RECT fillRect = { left, top, right, bottom };
		FillRect(hdc, &fillRect, (HBRUSH)GetStockObject(WHITE_BRUSH));
		}
	void SetRadius(int newR) override
	{
		r = newR;
	}
	int X() const { return x0; }
	int Y() const { return y0; }
	int R() const { return r; }
	void SetX(int newX) { x0 = newX; }
	void SetY(int newY) { y0 = newY; }
	~ElipseWithText()
	{

	};
};

