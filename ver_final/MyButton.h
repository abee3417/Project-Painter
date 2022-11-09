#pragma once
#include "string"
#include "Component.h"
class View;
class MyButton : public Component
{
public:
	MyButton(std::string title);
	~MyButton();
	void drawTButton(int count);
	void redrawTButton();
	void ccdrawTButton();
	void drawMenu(int count);
	void redrawMenu();
	void ccdrawMenu();
	void setView(View *);
	void makeRectIcon();
	void makeEllipseIcon();
	void makeLineIcon();
	void makeRLIcon();
	void makeGLIcon();
	void makeBLIcon();
	void makeOLIcon();
	void makeRFIcon();
	void makeGFIcon();
	void makeBFIcon();
	void makeOFIcon();
	void makeEraseIcon();
	void makeAllEraseIcon();
	//
	virtual void action();
protected:
	HICON m_icon;
	HICON m_icon_change;
	//HICON rectIcon;
};

