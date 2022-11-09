#pragma once
#include "View.h"
#ifndef _FIGURE_H
#define _FIGURE_H
class View;
class Figure {
protected:
	int startx, starty, endx, endy;
	View *mainView;
public:
	Figure(int x1, int y1, int x2, int y2, View *data);
	~Figure();
	virtual void draw();
};
#endif
