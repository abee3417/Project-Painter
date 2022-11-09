#pragma once
#include "string"
#include "Component.h"
class View;
class MyButton : public Component
{
public:
	MyButton(std::string title);
	~MyButton();
	void draw(int count);
	void redraw();
	void tempDraw();
	void setView(View *);
	virtual void action();
};

