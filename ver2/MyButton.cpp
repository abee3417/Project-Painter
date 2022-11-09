#include "stdafx.h"
#include "MyButton.h"
#include "View.h"

MyButton::MyButton(int x, int y, int sizex, int sizey, std::string title)
	:m_x(x), m_y(y), m_sizex(sizex), m_sizey(sizey), m_title(title)
{
}


MyButton::~MyButton()
{
}


void MyButton::draw()
{
	m_view->setPenColor(RGB(0,0,0));
	m_view->drawRectangle(m_x, m_y, m_x + m_sizex, m_y + m_sizey);
	SIZE s = m_view->textSize(m_title);
	int xoff = (m_sizex - s.cx)/2;
	int yoff = (m_sizey - s.cy) / 2;
	m_view->drawText(m_title, m_x + xoff, m_y + yoff);
}

bool MyButton::inside(int x, int y) {
	return (m_x <= x && x <= m_x + m_sizex
		&& m_y <= y && y <= m_y + m_sizey);
}

void MyButton::action() {
	debugOutput(m_title);
}
void MyButton::setView(View *v) {
	m_view = v;
}