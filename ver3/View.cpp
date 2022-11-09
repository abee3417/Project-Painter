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
	//m_InstanceHandle = hInstance; // 인스턴스 핸들을 전역 변수에 저장합니다.
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
	//debugOutput("Click\n");  // IDE의 '출력' 창에 나온다.
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
	// 프로그램 종료 방법을 데모하기 위해 우측 버튼 클릭시 아래 줄을 호출하게 만들었습니다.
	//eraseRect(e.x, e.y, 100, 100);
	//::PostMessage(m_WindowHandle, WM_CLOSE, NULL, NULL);
}

void View::OnChar(long ch)
{
	// 키보드 입력이 되면 이 함수가 자동 호출됩니다.  cin이나 getchar, scanf 같은
	// 표준 입력함수는 작동하지 않으니 onchar 를 잘 이용해야 합니다.
}

void View::addFigure(Figure *r) {
	m_rectList.push_back(r);
	r->setView(this);
}

void View::buttonActions(TButton *b) {
	
}

// 라인의 색을 지정하기
void View::setPenColor(COLORREF color)
{
	thePen = CreatePen(PS_SOLID, 1, color);
	SelectObject(m_DCHandle, thePen);
}

// 선의 색과 두께를 동시에 지정하기
void View::setPen(COLORREF color, int width)
{
	thePen = CreatePen(PS_SOLID, width, color);
	SelectObject(m_DCHandle, thePen);
}

// 채움 색을 결정하는 함수.
void View::setFillColor(COLORREF color)
{
	theBrush = CreateSolidBrush(color);
	SelectObject(m_DCHandle, theBrush);
}

// 글자 색을 지정하는 함수.
void View::setTextColor(COLORREF color)
{
	SetTextColor(m_DCHandle, color);
}
// 글자 배경색을 지정하는 함수.
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

// 모든  내용물들을 다시 그려주는 함수.  수정이 필요할 것이다.
void View::redrawAll()
{	
	
}

// 화면이 현재 제대로 안되어 있다고 알리는 함수입니다.
// 이 함수를 호출하면 화면이 지워지고 
// Main.cpp 쪽에 case WM_PAINT: 부분이 실행됩니다.
// 결국은 View 객체의 display가 실행되겠죠.
void View::invalidate()
{
	InvalidateRect(m_WindowHandle, NULL, true);
}

// 사각형 위치를 지운다.
void View::eraseRect(int x, int y, int sizeX, int  sizeY) // 좌상귀 x y 그리고 x축 y축 크기
{
	// TODO: 여기에 구현 코드 추가.
	setPenColor(RGB(255, 255, 255));
	setFillColor(RGB(255, 255, 255));
	drawRectangle(x, y, sizeX, sizeY);
}

// 윈도의 위치를 돌려준다.
RECT View::getClientRect()   // RECT에는 left, right, top, bottom 멤버 변수가 있다.
{
	// TODO: 여기에 구현 코드 추가.
	RECT r;
	GetClientRect(m_WindowHandle, &r);
	return r;
}


// 현재 폰트에서 text를 출력했을 때, 화면상에 차지하는 크기를 돌려주는 함수
SIZE View::textSize(const std::string text)
{
	// TODO: 여기에 구현 코드 추가.
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