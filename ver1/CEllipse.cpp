#include "stdafx.h"
#include "CEllipse.h"
#include "MyButton.h"
//#include "Figure.h"
//#include "View.h"

CEllipse::CEllipse(int x1, int y1, int x2, int y2, View *data) :Figure(x1, y1, x2, y2, data) {
	//
}


CEllipse::~CEllipse() {
	//
}

void CEllipse::draw() {
	mainView->setPenColor(RGB(0, 0, 0));
	mainView->setTextBkColor(RGB(0, 0, 0));
	mainView->setFillColor(RGB(255, 255, 255));
	mainView->drawEllipse(startx, starty, endx, endy);
}