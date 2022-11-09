#include "stdafx.h"
#include "MyButton.h"
#include "View.h"

MyButton::MyButton(std::string title)
	:Component(title)
{
}


MyButton::~MyButton()
{
}

// ó���� ��ư�� �׸��� �Լ� draw
void MyButton::draw(int count)
{
	m_view->setPenColor(m_line_color);
	m_view->setFillColor(m_normal_bg_color);
	m_view->drawRectangle(count, 0, count + 32, 32);
	m_x = count;
	m_xplus = count + 32;
	SIZE s = m_view->textSize(m_title);
	int xoff = (32 - s.cx) / 2;
	int yoff = (32 - s.cy) / 2;
	m_view->setTextBkColor(m_normal_bg_color);
	m_view->drawText(m_title, m_x + xoff, yoff);
}

// �����ؼ� ��ư�� �׸��� �Լ� redraw
void MyButton::redraw()
{
	m_view->setPenColor(m_line_color);
	m_view->setFillColor(m_normal_bg_color);
	m_view->drawRectangle(m_x, 0, m_x + 32, 32);
	SIZE s = m_view->textSize(m_title);
	int xoff = (32 - s.cx) / 2;
	int yoff = (32 - s.cy) / 2;
	m_view->setTextBkColor(m_normal_bg_color);
	m_view->drawText(m_title, m_x + xoff, yoff);
}

// ��ư ���� ���콺�� �ö���� �� �׸� �׸��� �Լ�.
void MyButton::tempDraw() {
	m_view->setPenColor(m_temp_line_color);
	m_view->setFillColor(m_temp_bg_color);
	m_view->drawRectangle(m_x, 0, m_x + 32, 32);
	SIZE s = m_view->textSize(m_title);
	int xoff = (32 - s.cx) / 2;
	int yoff = (32 - s.cy) / 2;
	m_view->setTextBkColor(m_temp_bg_color);
	m_view->drawText(m_title, m_x + xoff, yoff);
}

// ���콺�� ��ư ��ġ�� �ִ��� �Ǻ��ϴ� �Լ�

void MyButton::action() {
	//
}

void MyButton::setView(View *v) {
	m_view = v;
}