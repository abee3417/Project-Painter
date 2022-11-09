#pragma once
#include "Figure.h"
class CEllipse : 
	public Figure
{
public:
	CEllipse(int x, int y, int sizex, int sizey, int line_state, int fill_state);
	~CEllipse();
	void draw();
};

