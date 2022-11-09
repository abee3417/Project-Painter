#pragma once
#include "Figure.h"
class CLine :
	public Figure
{
public:
	CLine(int x1, int y1, int x2, int y2);
	~CLine();
	void draw();
};

