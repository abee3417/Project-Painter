#pragma once
#include "View.h"
#include "Misc.h"
#include "Figure.h"
class Container;
class MyView : public View
{
public:
	MyView(HINSTANCE hInstance);
	~MyView();
	void onInitialize();
	void redrawAll();
	void OnMouseMove(MyEvent e);
	void OnLButtonDown(MyEvent e);
	void OnLButtonUp(MyEvent e);
	void OnRButtonDown(MyEvent e);
	void OnRButtonUp(MyEvent e);
	void OnChar(long ch);
	void addFigure(Figure *);
	void buttonActions(TButton *b);
};

