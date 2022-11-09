#pragma once
#include "string"
class View;
class MyButton
{
public:
	MyButton(int x, int y, int sizex, int siezy, std::string title);
	~MyButton();
protected:
	std::string m_title;
	int m_x, m_y, m_sizex, m_sizey;
	View *m_view = 0;
public:
	void draw();
	bool inside(int x, int y);
	void action();
	void setView(View *);
};

