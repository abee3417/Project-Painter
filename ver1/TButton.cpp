#include "stdafx.h"
#include "TButton.h"


TButton::TButton(string str, View *data, int x1, int y1, int x2, int y2) : MyButton(str, data, x1, y1, x2, y2)
{
}


TButton::~TButton()
{
}

void TButton::button_draw() {
	m_data->setPenColor(RGB(220, 220, 220));
	m_data->setTextBkColor(RGB(220, 220, 220));
	m_data->setFillColor(RGB(220, 220, 220));
	m_data->drawRectangle(m_x1, m_y1, m_x2, m_y2);
	m_data->drawText(m_str, (m_x1 + m_x2) / 2, 6);
}

void TButton::push_redraw() {
	m_data->setPenColor(RGB(180, 180, 180));
	m_data->setFillColor(RGB(180, 180, 180));
	m_data->setTextBkColor(RGB(180, 180, 180));
	m_data->drawRectangle(m_x1, m_y1, m_x2, m_y2);
	m_data->drawText(m_str, (m_x1 + m_x2) / 2, 6);
}