#include "stdafx.h"
#include "MyView.h"
#include "Figure.h"
#include "CLine.h"
#include "Rect.h"
#include "Ellipse.h"
#include "TButton.h"

MyView::MyView(HINSTANCE hInstance) : View(hInstance)
{
}


MyView::~MyView()
{
}

void MyView::redrawAll() {
	width = getWindowWidth();
	setPenColor(RGB(230, 230, 230));
	setFillColor(RGB(230, 230, 230));
	drawRectangle(0, 0, width, 32);
	myToolbar->drawButton();
	for (auto r : m_rectList) {
		r->draw();
	}
}
// ��� �������� onInitialize �Լ����� �ʱ�ȭ����.
void MyView::onInitialize()
{
	// *** ��� ������Ʈ���� ���⿡�� �ʱ�ȭ����.
	btnRect = new TButton("R");
	btnEllipse = new TButton("E");
	btnLine = new TButton("L");
	Container::addComponent(btnRect);
	Container::addComponent(btnEllipse);
	Container::addComponent(btnLine);
	invalidate();
}

void MyView::OnMouseMove(MyEvent e)
{
	View::OnMouseMove(e);
}

void MyView::OnLButtonDown(MyEvent e)
{
	View::OnLButtonDown(e);
}

void MyView::OnLButtonUp(MyEvent e)
{
	View::OnLButtonUp(e);
}

void MyView::OnRButtonDown(MyEvent e)
{
	View::OnRButtonDown(e);
}

void MyView::OnRButtonUp(MyEvent e)
{
	View::OnRButtonUp(e);
}


void MyView::OnChar(long ch)
{
	View::OnChar(ch);
}

void MyView::addFigure(Figure *r) {
	
}

void MyView::buttonActions(TButton *b) {
	if (b == nullptr)
		return;
	if (b == btnRect) {
		currentFig = Figure::RECT;
	}
	else if (b == btnEllipse) {
		currentFig = Figure::ELLIPSE;
	}
	else {
		currentFig = Figure::LINE;
	}
}

void MyView::figureAdd(MyEvent e) {
	if (currentFig == Figure::LINE) { // ����
		addFigure(new CLine(startX, startY, e.x, e.y));
	}
	else if (currentFig == Figure::ELLIPSE) {  // Ÿ��
		addFigure(new CEllipse(startX, startY, e.x, e.y));
	}
	else if (currentFig == Figure::RECT) {  // �簢��
		addFigure(new Rect(startX, startY, e.x, e.y));
	}
	invalidate();
}