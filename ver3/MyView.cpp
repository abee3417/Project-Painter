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
// 모든 윈도들을 onInitialize 함수에서 초기화하자.
void MyView::onInitialize()
{
	// *** 모든 컴포넌트들을 여기에서 초기화하자.
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
	if (currentFig == Figure::LINE) { // 선분
		addFigure(new CLine(startX, startY, e.x, e.y));
	}
	else if (currentFig == Figure::ELLIPSE) {  // 타원
		addFigure(new CEllipse(startX, startY, e.x, e.y));
	}
	else if (currentFig == Figure::RECT) {  // 사각형
		addFigure(new Rect(startX, startY, e.x, e.y));
	}
	invalidate();
}