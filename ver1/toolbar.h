#pragma once
#include "stdafx.h"
#include "CRect.h"
#include "CEllipse.h"
#include "View.h"
#include "CLine.h"
#include "Figure.h"
#include "TButton.h"
#include "MyButton.h"
#include "Misc.h"
#include <list>
#include <string>
using namespace std;

class Figure;
class TButton;
class MyButton;
class View;
class Toolbar
{
public:
	Toolbar(View *data);
	~Toolbar();
	void addButton(TButton *data);
	void checkButton(Event e);
	void downButton(Event e);
	void upButton(Event e);
	void checkInitialize();
	void allDraw();
private:
	Event m_event;
	View *m_data;
	int width;
	int m_startx; int m_starty;
	int m_endx; int m_endy;
	int type;
	int draw_type;
	int move_type = 0;
	int move_data = 0;
	static const int type_none = 0;
	static const int type_line = 1;
	static const int type_circle = 2;
	static const int type_square = 3;
	static const int draw_prepare = 11;
	static const int draw_pass = 12;
	Figure *f;
	TButton *line;
	TButton *circle;
	TButton *square;
	list<Figure*> make;
	list<MyButton*> button;
};
