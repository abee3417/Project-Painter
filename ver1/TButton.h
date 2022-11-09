#pragma once
#include <iostream>
#include <string>
#include "MyButton.h"
#include "View.h"
#include "Toolbar.h"
using namespace std;
class MyButton;
class Toolbar;
class TButton : public MyButton
{
public:
	TButton(string str, View *data, int x1, int y1, int x2, int y2);
	~TButton();
	void make_button();
	virtual void button_draw();
	virtual void push_redraw();
private:

};

