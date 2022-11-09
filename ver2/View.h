#pragma once
#include "iostream"
#include "string"
#include "Proj2018.h"
#include "list"
#include "Misc.h"
#define MAX_LOADSTRING 100

class Figure;
class MyButton;
class View
{
public:
	View(HINSTANCE);
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
	virtual void OnLButtonDown(MyEvent e);
	virtual void OnLButtonUp(MyEvent e);
	virtual void OnRButtonDown(MyEvent e);
	virtual void OnRButtonUp(MyEvent e);
	virtual void OnChar(long ch);

	void setPenColor(COLORREF color);         // 펜 색깔 설정. 두께는 1로 자동.
	void setPen(COLORREF color, int width);   // 펜 색깔과 두께까지 설정.
	void setFillColor(COLORREF color);
	void setTextColor(COLORREF color);
 
	void drawRectangle(int x, int y, int sizeX, int sizeY);
	void drawEllipse(int x, int y, int sizeX, int sizeY);
	void drawLine(int x, int y, int sizeX, int sizeY);
	void drawText(std::string str, int x, int y);
	void redrawAll();
	//void eraseAll();
	void invalidate();
	void onInitialize();

protected:
	MyEvent m_start;  // 1단계에서 필요한 변수
	std::list<Figure *> m_rectList ;
	std::list<MyButton *> m_btnList;
	bool is_drawing;  //  
public:
	void eraseRect(int x, int y, int sizeX, int sizeY);
	RECT getClientRect();
	SIZE textSize(std::string text);

	void addFigure(Figure *);
	void addButton(MyButton *b);
	MyButton * btnRect, *btnEllipse, *btnLine;
	MyButton * findButton(int x, int y);
};

