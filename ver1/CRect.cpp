#include "stdafx.h"
#include "CRect.h"
#include "MyButton.h"
//#include "Figure.h"
//#include "View.h"

CRect::CRect(int x1, int y1, int x2, int y2, View *data):Figure(x1, y1, x2, y2, data) {
	//
}


CRect::~CRect(){
	//
}

void CRect::draw() {
	mainView->setPenColor(RGB(0, 0, 0));
	mainView->setTextBkColor(RGB(0, 0, 0));
	mainView->setFillColor(RGB(255, 255, 255));
	mainView->drawRectangle(startx, starty, endx, endy);
}