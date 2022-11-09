#include "stdafx.h"
#include "Rect.h"
#include "View.h"

Rect::Rect(int x, int y, int x2, int y2, int line_state, int fill_state)
	:Figure(x, y, x2, y2, line_state, fill_state)
{
	if (m_x1 > m_x2) {  // ÁÂ-¿ì¸¦ ¹Ù²Û´Ù.
		int t = m_x1; m_x1 = m_x2; m_x2 = t;
	}
	if (m_y1 > m_y2) {  // »ó-ÇÏ¸¦ ¹Ù²Û´Ù.
		int t = m_y1; m_y1 = m_y2; m_y2 = t;
	}
}


Rect::~Rect()
{
}


void Rect::draw()
{
	
	m_view->setPenColor(m_line_color);
	m_view->setFillColor(m_fill_color);
	m_view->drawRectangle(m_x1, m_y1, m_x2, m_y2);
}
