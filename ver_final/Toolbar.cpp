#include "stdafx.h"
#include "Toolbar.h"
#include "View.h"
#include "figure.h"
#include "CLine.h"
#include "Ellipse.h"
#include "MyButton.h"
#include "TButton.h"
#include "Rect.h"
#include "list"
#include "Menu.h"


Toolbar::Toolbar(View *data)
	:Container(data)
{
}


Toolbar::~Toolbar()
{
}


/*
void Toolbar::OnLButtonDown(MyEvent e, int m_startX, int m_startY) {
	startX = m_startX;
	startY = m_startY;
	Component *c = findButton(e.x, e.y);
	if (c == nullptr) {
		is_drawing = true;
	}
	else {
		is_drawing = false;
	}
}

void Toolbar::OnLButtonUp(MyEvent e) {
	Component *c = findButton(e.x, e.y);
	if (c) {
		c->action();
		m_view->drawTButton();
		return;
	}
	if (!is_drawing) {
		// �� ���� ��ư�� ���� �� �̵��Ͽ� ĵ�������� �� ����̴�. 
		return;
	}
}

void Toolbar::OnMouseMove(MyEvent e) {
	// TODO: ���⿡ ���� �ڵ� �߰�.
	Component *c = findButton(e.x, e.y);
	if (lastBtn == c) return;
	// hover in or out
	if (lastBtn != nullptr) {
		lastBtn->redraw();
	}
	if (c != nullptr) {
		c->tempDraw();
	}
	lastBtn = c;
}
*/
