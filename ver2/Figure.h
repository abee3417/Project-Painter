#pragma once
class View;
class Figure
{
public:
	static const int RECT = 0, ELLIPSE = 1, LINE = 2;
	Figure(int x, int y, int x2, int y2);
	~Figure();
	void setView(View *);
	virtual void draw() = 0;
	int m_x1, m_y1, m_x2, m_y2;
	View *m_view = 0;
};


