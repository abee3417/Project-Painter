#pragma once
#include "string"
#include "list"
#include "Component.h"
#include "Toolbar.h"
#include "Container.h"
#include "MyButton.h"

class Toolbar;
class Figure;
class MyButton;
class View : public Container
{
public:
	View(HINSTANCE hInstance);
	~View();

	// 초기화 함수들
	BOOL initInstance(/*HINSTANCE hInstance, */int nCmdShow);

	// 이벤트 처리 함수들
	virtual void OnMouseMove(MyEvent e);
	virtual void OnLButtonDown(MyEvent e);
	virtual void OnLButtonUp(MyEvent e);
	virtual void OnRButtonDown(MyEvent e);
	virtual void OnRButtonUp(MyEvent e);
	virtual void OnChar(long ch);
	virtual void buttonActions(TButton *b);

	void setPenColor(COLORREF color);         // 펜 색깔 설정. 두께는 1로 자동.
	void setPen(COLORREF color, int width);   // 펜 색깔과 두께까지 설정.
	void setFillColor(COLORREF color);
	void setTextColor(COLORREF color);
	void setTextBkColor(COLORREF color);
	void drawRectangle(int x, int y, int sizeX, int sizeY);
	void drawEllipse(int x, int y, int sizeX, int sizeY);
	void drawLine(int x, int y, int sizeX, int sizeY);
	void drawText(std::string str, int x, int y);

	void eraseRect(int x, int y, int sizeX, int sizeY);
	int getWindowWidth();
	RECT getClientRect();
	SIZE textSize(std::string text);

	//void eraseAll();
	void invalidate();
	virtual void addFigure(Figure *);
	virtual void redrawAll();
	virtual void onInitialize();
	virtual void figureAdd(MyEvent e);

protected:

	int m_startX, m_startY;  // 1단계에서 필요한 변수
	int count = 0;
	int currentFig = 0;
	int width;
	std::list<Figure *> m_rectList;
	Toolbar * myToolbar = new Toolbar(this);
	Component * btnRect, *btnEllipse, *btnLine;
	
};

