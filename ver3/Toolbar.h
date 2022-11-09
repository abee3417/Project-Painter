#pragma once
#include "iostream"
#include "TButton.h"
#include "Container.h"
class Component;
class View;
class MyEvent;
class MyButton;
class Toolbar : public Container
{
public:
	Toolbar(View *data);
	~Toolbar();
	void drawButton();
	void OnLButtonDown(MyEvent e, int m_startX, int m_startY);
	void OnLButtonUp(MyEvent e);
	void OnMouseMove(MyEvent e);
	void draw();
private:
	bool is_drawing;
};

