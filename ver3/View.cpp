#include "stdafx.h"
#include "View.h"
#include "stdio.h"
#include "iostream"
#include "string"
#include "Misc.h"
#include "Rect.h"
#include "Ellipse.h"
#include "CLine.h"
#include "MyButton.h"
#include "MyView.h"
#include "TButton.h"
#include "Toolbar.h"
using namespace std;

View::View(HINSTANCE hInstance):Container(hInstance) {
	
}

View::~View()
{

}

BOOL View::initInstance( int nCmdShow )
{
	//m_InstanceHandle = hInstance; // �ν��Ͻ� �ڵ��� ���� ������ �����մϴ�.
	m_WindowHandle = CreateWindowW(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
		0, 0, 1000,  600, nullptr, nullptr, m_InstanceHandle, nullptr);

	if (!m_WindowHandle)
	{
		return FALSE;
	}

	ShowWindow(m_WindowHandle, nCmdShow);
	UpdateWindow(m_WindowHandle);
	m_DCHandle = ::GetDC(m_WindowHandle);
	onInitialize();
	//mainView = new View(hWnd);

	return TRUE;
}

void View::onInitialize() {

}

void View::OnMouseMove(MyEvent e)
{
	myToolbar->OnMouseMove(e);
}

void View::OnLButtonDown(MyEvent e)
{
	//debugOutput("Click\n");  // IDE�� '���' â�� ���´�.
	m_startX = e.x; m_startY = e.y;
	myToolbar->OnLButtonDown(e, m_startX, m_startY);
}

void View::OnLButtonUp(MyEvent e)
{
	myToolbar->OnLButtonUp(e);
}

void View::OnRButtonDown(MyEvent e)
{

}

void View::OnRButtonUp(MyEvent e)
{
	// ���α׷� ���� ����� �����ϱ� ���� ���� ��ư Ŭ���� �Ʒ� ���� ȣ���ϰ� ��������ϴ�.
	//eraseRect(e.x, e.y, 100, 100);
	//::PostMessage(m_WindowHandle, WM_CLOSE, NULL, NULL);
}

void View::OnChar(long ch)
{
	// Ű���� �Է��� �Ǹ� �� �Լ��� �ڵ� ȣ��˴ϴ�.  cin�̳� getchar, scanf ����
	// ǥ�� �Է��Լ��� �۵����� ������ onchar �� �� �̿��ؾ� �մϴ�.
}

void View::addFigure(Figure *r) {
	m_rectList.push_back(r);
	r->setView(this);
}

void View::buttonActions(TButton *b) {
	
}

// ������ ���� �����ϱ�
void View::setPenColor(COLORREF color)
{
	thePen = CreatePen(PS_SOLID, 1, color);
	SelectObject(m_DCHandle, thePen);
}

// ���� ���� �β��� ���ÿ� �����ϱ�
void View::setPen(COLORREF color, int width)
{
	thePen = CreatePen(PS_SOLID, width, color);
	SelectObject(m_DCHandle, thePen);
}

// ä�� ���� �����ϴ� �Լ�.
void View::setFillColor(COLORREF color)
{
	theBrush = CreateSolidBrush(color);
	SelectObject(m_DCHandle, theBrush);
}

// ���� ���� �����ϴ� �Լ�.
void View::setTextColor(COLORREF color)
{
	SetTextColor(m_DCHandle, color);
}
// ���� ������ �����ϴ� �Լ�.
void View::setTextBkColor(COLORREF color)
{
	SetBkColor(m_DCHandle, color);
}

void View::drawRectangle(int x1, int y1, int x2, int y2)
{
	Rectangle(m_DCHandle, x1, y1, x2, y2);
}

void View::drawEllipse(int x1, int y1, int x2, int y2)
{
	Ellipse(m_DCHandle, x1, y1, x2, y2);
}

void View::drawLine(int x1, int y1, int x2, int y2)
{
	MoveToEx(m_DCHandle, x1, y1, NULL);
	LineTo(m_DCHandle, x2, y2);
}


void View::drawText(std::string str, int x, int y)
{
	TextOutA(m_DCHandle, x, y, str.c_str(), strlen(str.c_str()));
}

// ���  ���빰���� �ٽ� �׷��ִ� �Լ�.  ������ �ʿ��� ���̴�.
void View::redrawAll()
{	
	
}

// ȭ���� ���� ����� �ȵǾ� �ִٰ� �˸��� �Լ��Դϴ�.
// �� �Լ��� ȣ���ϸ� ȭ���� �������� 
// Main.cpp �ʿ� case WM_PAINT: �κ��� ����˴ϴ�.
// �ᱹ�� View ��ü�� display�� ����ǰ���.
void View::invalidate()
{
	InvalidateRect(m_WindowHandle, NULL, true);
}

// �簢�� ��ġ�� �����.
void View::eraseRect(int x, int y, int sizeX, int  sizeY) // �»�� x y �׸��� x�� y�� ũ��
{
	// TODO: ���⿡ ���� �ڵ� �߰�.
	setPenColor(RGB(255, 255, 255));
	setFillColor(RGB(255, 255, 255));
	drawRectangle(x, y, sizeX, sizeY);
}

// ������ ��ġ�� �����ش�.
RECT View::getClientRect()   // RECT���� left, right, top, bottom ��� ������ �ִ�.
{
	// TODO: ���⿡ ���� �ڵ� �߰�.
	RECT r;
	GetClientRect(m_WindowHandle, &r);
	return r;
}


// ���� ��Ʈ���� text�� ������� ��, ȭ��� �����ϴ� ũ�⸦ �����ִ� �Լ�
SIZE View::textSize(const std::string text)
{
	// TODO: ���⿡ ���� �ڵ� �߰�.
	SIZE size;
	const char *s = text.c_str();
	GetTextExtentPoint32A(m_DCHandle, s, strlen(s), &size);
	return size;
}

int View::getWindowWidth() {
	RECT r;
	GetWindowRect(m_WindowHandle, &r);
	return r.right - r.left;
}

void View::figureAdd(MyEvent e) {

}