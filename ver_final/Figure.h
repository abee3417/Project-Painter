#pragma once
class View;
class Figure
{
public:
	static const int RECT = 1, ELLIPSE = 2, LINE = 3;
	static const int REDLINE = 101, GREENLINE = 102, BLUELINE = 103, ORIGINLINE = 104;
	static const int REDFILL = 105, GREENFILL = 106, BLUEFILL = 107, ORIGINFILL = 108;
	static const int ERASERECT = 109, ERASEALL = 110;
	static const int origin_color = 10;
	static const int red_color = 20;
	static const int green_color = 30;
	static const int blue_color = 40;
	Figure(int x, int y, int x2, int y2, int line_state, int fill_state);
	~Figure();
	void setView(View *);
	virtual void draw() = 0;
	int m_x1, m_y1, m_x2, m_y2;
	View *m_view = 0;
protected:
	COLORREF m_red = RGB(255, 0, 0);
	COLORREF m_green = RGB(0, 255, 0);
	COLORREF m_blue = RGB(0, 0, 255);
	COLORREF m_origin_line = RGB(0, 0, 0);
	COLORREF m_origin_fill = RGB(255, 255, 255);
	COLORREF m_clean = RGB(255, 255, 255);
	COLORREF m_line_color;
	COLORREF m_fill_color;
};


