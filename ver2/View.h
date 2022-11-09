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
	virtual void OnLButtonDown(MyEvent e);
	virtual void OnLButtonUp(MyEvent e);
	virtual void OnRButtonDown(MyEvent e);
	virtual void OnRButtonUp(MyEvent e);
	virtual void OnChar(long ch);

	void setPenColor(COLORREF color);         // �� ���� ����. �β��� 1�� �ڵ�.
	void setPen(COLORREF color, int width);   // �� ����� �β����� ����.
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
	MyEvent m_start;  // 1�ܰ迡�� �ʿ��� ����
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

