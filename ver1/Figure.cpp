#include "stdafx.h"
#include "View.h"


Figure::Figure(int x1, int y1, int x2, int y2, View *data) {
	startx = x1;
	starty = y1;
	endx = x2;
	endy = y2;
	mainView = data;
}


Figure::~Figure() {
	//
}

void Figure::draw() {
	//
}