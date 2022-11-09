#include "stdafx.h"
#include "Rect.h"
#include "View.h"
Rect::Rect(int x, int y, int x2, int y2)
	:Figure(x,y,x2,y2)
{
	if (m_x1 > m_x2) {  // 좌-우를 바꾼다.
		int t = m_x1; m_x1 = m_x2; m_x2 = t;
	}
	if (m_y1 > m_y2) {  // 상-하를 바꾼다.
		int t = m_y1; m_y1 = m_y2; m_y2 = t;
	}
}


Rect::~Rect()
{
}


void Rect::draw()
{
	// TODO: 여기에 구현 코드 추가.
	m_view->setPenColor(RGB(0, 0, 0));
	m_view-> drawRectangle(m_x1, m_y1, m_x2, m_y2);
}
