#pragma once
#include <iostream>
#include <string>
#include "Proj2018.h"
#include "View.h"
#include "Toolbar.h"
#include "TButton.h"
using namespace std;
class View;
class Toolbar;
class MyButton {
protected:
	string m_str;
	View *m_data;
	Toolbar *m_tool;
	int m_x1, m_y1, m_x2, m_y2;
public:
	MyButton(string str, View *data, int x1, int y1, int x2, int y2);
	MyButton();
	~MyButton();
	virtual void button_draw() = 0;
	virtual void push_redraw() = 0;
};

