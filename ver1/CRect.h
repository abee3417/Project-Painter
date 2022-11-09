#pragma once
#include "View.h"
#include "Figure.h"
#ifndef _CRECT_H
#define _CRECT_H
class View;
class CRect : public Figure {
private:

public:
	CRect(int x1, int y1, int x2, int y2, View *data);
	~CRect();
	virtual void draw();
};
#endif

