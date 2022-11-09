#pragma once
#include "string"
#include "list"
#include "Component.h"
#include "Toolbar.h"
#include "Container.h"
#include "MyButton.h"
#include "Menu.h"
#include "MenuBar.h"
#include "map"

class MenuBar;
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
	void OnMouseMove(MyEvent e);
	void OnLButtonDown(MyEvent e);
	void OnLButtonUp(MyEvent e);
	void OnRButtonDown(MyEvent e);
	void OnRButtonUp(MyEvent e);
	void OnChar(long ch);
	void buttonActions(TButton *b);//
	void menuActions(Menu *m);
	void menubarActions(MenuItem *t);
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
	int getWindowHeight();
	RECT getClientRect();
	SIZE textSize(std::string text);

	//void eraseAll();
	void invalidate();
	void addFigure(Figure *);
	virtual void redrawAll();
	virtual void onInitialize();
	void addTButton(Component *c);
	void addMenu(Component *c);
	void addFile(Component *c);
	void addSet(Component *c);
	void addLineSet(Component *c);
	void addFillSet(Component *c);
	void redrawColor(MyEvent e);
	void drawIcon(int x, int y, HICON i);

protected:
	int m_startX, m_startY;  // 1단계에서 필요한 변수
	int count = 0;
	int currentFig = 0;
	int currentMenu = 0;
	int width, height;
	int whatType = 0;
	std::list<Figure *> m_rectList; 
	Component * btnRect, *btnEllipse, *btnLine;
	Component * btnLineRed, *btnLineGreen, *btnLineBlue, *btnLineOrigin;
	Component * btnFillRed, *btnFillGreen, *btnFillBlue, *btnFillOrigin;
	Component * btnErase, *btnAllErase;
	Component * fileButton, *figureButton, *lineButton, *fillButton;
	Component * save, *open;
	Component * rectSet, *ellipseSet, *lineSet;
	Component * originLineSet, *redLineSet, *greenLineSet, *blueLineSet;
	Component * originFillSet, *redFillSet, *greenFillSet, *blueFillSet;
	std::map<COLORREF, HPEN> penMap;
	std::map<COLORREF, HBRUSH> brushMap;
	Component * lastBtn = 0;
	bool is_drawing;
	//Toolbar * myToolbar = new Toolbar(this);
	//MenuBar * myMenuBar = new MenuBar(this);

	//아이콘
	HICON rectIcon;
	HICON rectIcon_change;
	
	

};

