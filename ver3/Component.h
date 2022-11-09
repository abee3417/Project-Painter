#pragma once
#include "iostream"
#include "string"
#include "Proj2018.h"
#include "Misc.h"

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
	int m_x, m_xplus;
	int startX, startY;
	Component * lastBtn = 0;
	View *m_view;
	COLORREF m_normal_bg_color = RGB(230, 230, 230);
	COLORREF m_temp_bg_color = RGB(200, 200, 200);
	COLORREF m_line_color = RGB(230, 230, 230);
	COLORREF m_temp_line_color = RGB(200, 200, 200);
	
public:
	virtual void draw(int count);
	virtual void redraw();
	virtual void tempDraw();
	virtual void setView(View *);
	virtual void action();
	bool inside(int x, int y);

protected: // View에 있었던 것들
	HINSTANCE m_InstanceHandle;
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
};