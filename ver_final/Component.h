#pragma once
#include "iostream"
#include "string"
#include "Proj2018.h"
#include "Misc.h"
#include "list"

#define MAX_LOADSTRING 100
class View;
class Component
{
public:
	Component(std::string title);
	Component(HINSTANCE hInstance);
	Component(View *data);
	~Component();

protected: // MyButton에 있었던 것들
	
	std::string m_title;
	int m_x1, m_xplus1;
	int m_x2, m_xplus2;
	int m_y1, m_yplus1;
	int m_y2, m_yplus2;
	int m_y3, m_yplus3;
	int m_y4, m_yplus4;
	int state = 0;
	int stateMenu = 0;
	int recent_figure = 0;
	int line_state = origin_color;
	int fill_state = origin_color;
	int startX, startY;
	View *m_view, *m_viewMenu;
	COLORREF m_normal_bg_color = RGB(230, 230, 230);
	COLORREF m_temp_bg_color = RGB(200, 200, 200);
	COLORREF m_line_color = RGB(230, 230, 230);
	COLORREF m_temp_line_color = RGB(200, 200, 200);
	static const int origin_color = 10;
	static const int red_color = 20;
	static const int green_color = 30;
	static const int blue_color = 40;
	static const int closeMenu = 100;
	static const int openMenu = 200;
	static const int openFileMenu = 300;
	static const int openSetMenu = 400;
	static const int openLineMenu = 500;
	static const int openFillMenu = 600;
	static const int recent_rect = 1000;
	static const int recent_ellipse = 2000;
	static const int recent_line = 3000;
	static const int typeTButton = 10000;
	static const int typeMenu = 20000;
	
public:
	virtual void drawTButton(int count);
	virtual void redrawTButton();
	virtual void ccdrawTButton();
	virtual void drawMenu(int count);
	virtual void redrawMenu();
	virtual void ccdrawMenu();
	virtual void drawFileMenu(int count);
	virtual void redrawFileMenu();
	virtual void ccdrawFileMenu();
	virtual void drawSetMenu(int count);
	virtual void redrawSetMenu();
	virtual void ccdrawSetMenu();
	virtual void drawLineSetMenu(int count);
	virtual void redrawLineSetMenu();
	virtual void ccdrawLineSetMenu();
	virtual void drawFillSetMenu(int count);
	virtual void redrawFillSetMenu();
	virtual void ccdrawFillSetMenu();
	virtual void setView(View *);
	virtual void setView2(View *);
	virtual void action();
	virtual void makeRectIcon();
	virtual void makeEllipseIcon();
	virtual void makeLineIcon();
	virtual void makeRLIcon();
	virtual void makeGLIcon();
	virtual void makeBLIcon();
	virtual void makeOLIcon();
	virtual void makeRFIcon();
	virtual void makeGFIcon();
	virtual void makeBFIcon();
	virtual void makeOFIcon();
	virtual void makeEraseIcon();
	virtual void makeAllEraseIcon();
	virtual void addToolbarListener(ToolbarActionListener *l);
	virtual void addMenuListener(MenuActionListener *l);
	virtual void addMenubarListener(MenubarActionListener *l);
	bool insideTButton(int x, int y);
	bool insideMenu(int x, int y);
	bool insideFileMenu(int x, int y);
	bool insideSetMenu(int x, int y);
	bool insideLineMenu(int x, int y);
	bool insideFillMenu(int x, int y);
	HINSTANCE m_InstanceHandle;

protected: // View에 있었던 것들	
	HWND m_WindowHandle;    //  바탕 윈도 handle
	HDC m_DCHandle;	// DC handle
	HBRUSH brushWhite, brushBlack;
	HPEN penWhite, penBlack;
	HPEN thePen;
	HBRUSH theBrush;

public:
	ATOM MyRegisterClass(HINSTANCE hInstance);
	WCHAR szTitle[MAX_LOADSTRING];                  // 제목 표시줄 텍스트입니다.
	WCHAR szWindowClass[MAX_LOADSTRING];            // 기본 창 클래스 이름입니다.

protected:
	std::list<ToolbarActionListener *> m_ToolbarLList;
	std::list<MenuActionListener *> m_MenuLList;
	std::list<MenubarActionListener *> m_MenubarLList;
	
};