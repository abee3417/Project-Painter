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

// 처음에 버튼을 그리는 함수 draw
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

// 반족해서 버튼을 그리는 함수 redraw
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

// 버튼 위로 마우스가 올라왔을 때 그림 그리는 함수.
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

// 마우스가 버튼 위치에 있는지 판별하는 함수

void MyButton::action() {
	//
}

void MyButton::setView(View *v) {
	m_view = v;
}