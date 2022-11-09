#pragma once
#include "Figure.h"
#include "iostream"
#include "Proj2018.h"
#include "CRect.h"
#include "CEllipse.h"
#include "TButton.h"
#include "CLine.h"
#include "MyButton.h"
#include "Toolbar.h"
#include <list>
#include <string>
#define MAX_LOADSTRING 100
using namespace std;

class Event;
class CRect;
class Figure;
class MyButton;
class Toolbar;
class View
{
public:
	View(HINSTANCE);
	View(HWND);
	~View();
protected:
	HWND m_WindowHandle;    //  바탕 윈도 handle
	HDC m_DCHandle;	// DC handle
	HBRUSH brushWhite, brushBlack;
	HPEN penWhite, penBlack;
	// 임시 변수
	int count = 0;
	HPEN thePen;
	HBRUSH theBrush;
	HINSTANCE m_InstanceHandle;
	WCHAR szTitle[MAX_LOADSTRING];                  // 제목 표시줄 텍스트입니다.
	WCHAR szWindowClass[MAX_LOADSTRING];            // 기본 창 클래스 이름입니다.

public:
	// 초기화 함수들
	ATOM MyRegisterClass(HINSTANCE hInstance);
	BOOL initInstance(/*HINSTANCE hInstance, */int nCmdShow);

	// 이벤트 처리 함수들
	virtual void OnMouseMove(Event e);
	virtual void OnLButtonDown(Event e);
	virtual void OnLButtonUp(Event e);
	virtual void OnRButtonDown(Event e);
	virtual void OnRButtonUp(Event e);
	virtual void OnChar(long ch);

	void setPenColor(COLORREF color);         // 펜 색깔 설정. 두께는 1로 자동.
	void setPen(COLORREF color, int width);   // 펜 색깔과 두께까지 설정.
	void setFillColor(COLORREF color);
	void setTextColor(COLORREF color);
	void setTextBkColor(COLORREF color);
 
	void drawRectangle(int x1, int y1, int x2, int y2);
	void drawEllipse(int x1, int y1, int x2, int y2);
	void drawLine(int x1, int y1, int x2, int y2);
	void drawText(std::string str, int x, int y);
	void redrawAll();
	//void eraseAll();
	void invalidate();
	void onInitialize();
	SIZE textSize(const std::string text);
	int getWindowWidth();
protected:

public:

	
	void eraseRect(int x, int y, int sizeX, int sizeY);
	RECT getClientRect();
	
private:
	
	string m_str;
	
	
	Toolbar *m_Toolbar;
	
};

