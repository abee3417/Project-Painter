#pragma once
#include "Figure.h"
class CEllipse : 
	public Figure
{
public:
	CEllipse(int x, int y, int sizex, int sizey);
	~CEllipse();
	void draw();
};

