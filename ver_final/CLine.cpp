#include "stdafx.h"
#include "CLine.h"
#include "View.h"

CLine::CLine(int x1, int y1, int x2, int y2, int line_state, int fill_state)
	:Figure(x1, y1, x2, y2, line_state, fill_state)
{
}


CLine::~CLine()
{
}


void CLine::draw()
{
	// TODO: 여기에 구현 코드 추가.
	m_view->setPenColor(m_line_color);
	m_view->drawLine(m_x1, m_y1, m_x2, m_y2);
}