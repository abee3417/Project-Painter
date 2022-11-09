#pragma once
#include "View.h"
#include "Figure.h"
#ifndef _CELLIPSE_H
#define _CELLIPSE_H
class View;
class CEllipse : public Figure {
private:

public:
	CEllipse(int x1, int y1, int x2, int y2, View *data);
	~CEllipse();
	virtual void draw();
};
#endif