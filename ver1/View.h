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
	HWND m_WindowHandle;    //  ���� ���� handle
	HDC m_DCHandle;	// DC handle
	HBRUSH brushWhite, brushBlack;
	HPEN penWhite, penBlack;
	// �ӽ� ����
	int count = 0;
	HPEN thePen;
	HBRUSH theBrush;
	HINSTANCE m_InstanceHandle;
	WCHAR szTitle[MAX_LOADSTRING];                  // ���� ǥ���� �ؽ�Ʈ�Դϴ�.
	WCHAR szWindowClass[MAX_LOADSTRING];            // �⺻ â Ŭ���� �̸��Դϴ�.

public:
	// �ʱ�ȭ �Լ���
	ATOM MyRegisterClass(HINSTANCE hInstance);
	BOOL initInstance(/*HINSTANCE hInstance, */int nCmdShow);

	// �̺�Ʈ ó�� �Լ���
	virtual void OnMouseMove(Event e);
	virtual void OnLButtonDown(Event e);
	virtual void OnLButtonUp(Event e);
	virtual void OnRButtonDown(Event e);
	virtual void OnRButtonUp(Event e);
	virtual void OnChar(long ch);

	void setPenColor(COLORREF color);         // �� ���� ����. �β��� 1�� �ڵ�.
	void setPen(COLORREF color, int width);   // �� ����� �β����� ����.
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

