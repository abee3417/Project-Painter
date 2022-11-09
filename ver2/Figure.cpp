#include "stdafx.h"
#include "Figure.h"
#include "View.h"

Figure::Figure(int x, int y, int x2, int y2)
	:m_x1(x), m_y1(y), m_x2(x2), m_y2(y2)
{

}


Figure::~Figure()
{
}

void Figure::setView(View *v) {
	m_view = v;
}


