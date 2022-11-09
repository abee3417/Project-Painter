#include "stdafx.h"
#include "CLine.h"
#include "Figure.h"
#include "MyButton.h"

CLine::CLine(int x1, int y1, int x2, int y2, View *data):Figure(x1, y1, x2, y2, data) {
	//
}

CLine::~CLine() {
	//
}

void CLine::draw() {
	mainView->setPenColor(RGB(0, 0, 0));
	mainView->setTextBkColor(RGB(0, 0, 0));
	mainView->setFillColor(RGB(255, 255, 255));
	mainView->drawLine(startx, starty, endx, endy);
}