#include "stdafx.h"
#include "Figure.h"
#include "View.h"

Figure::Figure(int x, int y, int x2, int y2, int line_state, int fill_state)
	:m_x1(x), m_y1(y), m_x2(x2), m_y2(y2)
{
	if (line_state == origin_color) {
		m_line_color = m_origin_line;
	}
	else if(line_state == red_color) {
		m_line_color = m_red;
	}
	else if (line_state == green_color) {
		m_line_color = m_green;
	}
	else if (line_state == blue_color) {
		m_line_color = m_blue;
	}
	else if (line_state == m_clean) {
		m_line_color = m_clean;
	}
	if (fill_state == origin_color) {
		m_fill_color = m_origin_fill;
	}
	else if (fill_state == red_color) {
		m_fill_color = m_red;
	}
	else if (fill_state == green_color) {
		m_fill_color = m_green;
	}
	else if (fill_state == blue_color) {
		m_fill_color = m_blue;
	}
	else if (fill_state == m_clean) {
		m_fill_color = m_clean;
	}
}


Figure::~Figure()
{
}

void Figure::setView(View *v) {
	m_view = v;
}