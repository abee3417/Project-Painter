#pragma once
#include "View.h"
#include "Figure.h"
#ifndef _CLINE_H
#define _CLINE_H
class View;
class CLine : public Figure {
private:

public:
	CLine(int x1, int y1, int x2, int y2, View *data);
	~CLine();
	virtual void draw();
};
#endif