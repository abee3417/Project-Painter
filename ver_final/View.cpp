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
#include "list"
#include "TButton.h"
#include "Toolbar.h"
#include "MenuItem.h"
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
	//myToolbar->OnMouseMove(e);
	
	Component *c = findButton(e.x, e.y, whatType);
	if (lastBtn == c) return;
	// hover in or out
	if (lastBtn != nullptr) {
		if (state == openMenu) {

		}
		else {
			if (whatType == typeTButton) {
				lastBtn->redrawTButton();
			}
			else if (whatType == typeMenu) {
				lastBtn->redrawMenu();
			}
		}
	}
	if (c != nullptr) {
		if (state == openMenu) {

		}
		else {
			if (whatType == typeTButton) {
				c->ccdrawTButton();
			}
			else if (whatType == typeMenu) {
				c->ccdrawMenu();
			}
		}
	}
	lastBtn = c;
	
}

void View::OnLButtonDown(MyEvent e)
{
	//myToolbar->OnLButtonDown(e);

	m_startX = e.x; m_startY = e.y;
	startX = m_startX;
	startY = m_startY;
	Component *c = findButton(e.x, e.y, whatType);
		if (c == nullptr) {
			is_drawing = true;
		}
		else {
			is_drawing = false;
		}
}

void View::OnLButtonUp(MyEvent e)
{
	//debugOutput("Click\n");  // IDE의 '출력' 창에 나온다.
	//myToolbar->OnLButtonUp(e);

	Component *c = findButton(e.x, e.y, whatType);
	if (c) {
		c->action();
		if (state == closeMenu) {
			this->drawTButton();
			this->drawMenu();
			if (0 <= e.x && e.x <= 48 && 0 <= e.y && e.y <= 32) {
				this->drawFile();
				state = openMenu;
				stateMenu = openFileMenu;
			}
			else if (48 <= e.x && e.x <= 96 && 0 <= e.y && e.y <= 32) {
				this->drawSet();
				state = openMenu;
				stateMenu = openSetMenu;
			}
			else if (96 <= e.x && e.x <= 144 && 0 <= e.y && e.y <= 32) {
				this->drawLineSet();
				state = openMenu;
				stateMenu = openLineMenu;
			}
			else if (144 <= e.x && e.x <= 192 && 0 <= e.y && e.y <= 32) {
				this->drawFillSet();
				state = openMenu;
				stateMenu = openFillMenu;
			}
		}
		else if (state == openMenu) {	
			if (currentMenu == Menu::OPENFILEMENU) {
				if (stateMenu != openFileMenu) {
					invalidate();
					stateMenu = openFileMenu;
					state = openMenu;
					this->drawFile();
				}
				else {
					state = closeMenu;
					invalidate();
				}
			}
			else if (currentMenu == Menu::OPENSETMENU) {
				if (stateMenu != openSetMenu) {
					invalidate();
					stateMenu = openSetMenu;
					state = openMenu;
					this->drawSet();
				}
				else {
					state = closeMenu;
					invalidate();
				}
			}
			else if (currentMenu == Menu::OPENLINEMENU) {
				if (stateMenu != openLineMenu) {
					invalidate();
					stateMenu = openLineMenu;
					state = openMenu;
					this->drawLineSet();
				}
				else {
					state = closeMenu;
					invalidate();
				}
			}
			else if (currentMenu == Menu::OPENFILLMENU) {
				if (stateMenu != openFillMenu) {
					invalidate();
					stateMenu = openFillMenu;
					state = openMenu;
					this->drawFillSet();
				}
				else {
					state = closeMenu;
					invalidate();
				}
			}
		}
		return;
	}
	if (!is_drawing) {
		// 이 경우는 버튼을 누른 뒤 이동하여 캔버스에서 뗀 경우이다. 
		return;
	}
	if (state == closeMenu) {
		if (currentFig == Figure::LINE) { // 선분
			addFigure(new CLine(startX, startY, e.x, e.y, line_state, fill_state));
			recent_figure = recent_line;
		}
		else if (currentFig == Figure::ELLIPSE) {  // 타원
			addFigure(new CEllipse(startX, startY, e.x, e.y, line_state, fill_state));
			recent_figure = recent_ellipse;
		}
		else if (currentFig == Figure::RECT) {  // 사각형
			addFigure(new Rect(startX, startY, e.x, e.y, line_state, fill_state));
			recent_figure = recent_rect;
		}
		else if (currentFig == Figure::REDLINE) {
			line_state = red_color;
			redrawColor(e);
		}
		else if (currentFig == Figure::GREENLINE) {
			line_state = green_color;
			redrawColor(e);
		}
		else if (currentFig == Figure::BLUELINE) {
			line_state = blue_color;
			redrawColor(e);
		}
		else if (currentFig == Figure::ORIGINLINE) {
			line_state = origin_color;
			redrawColor(e);
		}
		else if (currentFig == Figure::REDFILL) {
			fill_state = red_color;
			redrawColor(e);
		}
		else if (currentFig == Figure::GREENFILL) {
			fill_state = green_color;
			redrawColor(e);
		}
		else if (currentFig == Figure::BLUEFILL) {
			fill_state = blue_color;
			redrawColor(e);
		}
		else if (currentFig == Figure::ORIGINFILL) {
			fill_state = origin_color;
			redrawColor(e);
		}
		else if (currentFig == Figure::ERASERECT) {
			addFigure(new Rect(startX, startY, e.x, e.y, RGB(255, 255, 255), RGB(255, 255, 255)));

		}
		else if (currentFig == Figure::ERASEALL) {
			addFigure(new Rect(0, 64, width, height, RGB(255, 255, 255), RGB(255, 255, 255)));
		}
	}
	invalidate();
}

void View::OnRButtonDown(MyEvent e)
{
	// 프로그램 종료 방법을 데모하기 위해 우측 버튼 클릭시 아래 줄을 호출하게 만들었습니다.
	// eraseRect(e.x - 50, e.y - 50, e.x + 50, e.y + 50);
	//::PostMessage(m_WindowHandle, WM_CLOSE, NULL, NULL);
}

void View::OnRButtonUp(MyEvent e)
{
	
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

// 툴바 버튼 액션 정해주기
void View::buttonActions(TButton *b) {//
	if (state == closeMenu) {
		if (b == nullptr) {
			return;
		}
		if (b == btnRect) {
			currentFig = Figure::RECT;
		}
		else if (b == btnEllipse) {
			currentFig = Figure::ELLIPSE;
		}
		else if (b == btnLine) {
			currentFig = Figure::LINE;
		}
		else if (b == btnLineRed) {
			currentFig = Figure::REDLINE;
		}
		else if (b == btnLineGreen) {
			currentFig = Figure::GREENLINE;
		}
		else if (b == btnLineBlue) {
			currentFig = Figure::BLUELINE;
		}
		else if (b == btnLineOrigin) {
			currentFig = Figure::ORIGINLINE;
		}
		else if (b == btnFillRed) {
			currentFig = Figure::REDFILL;
		}
		else if (b == btnFillGreen) {
			currentFig = Figure::GREENFILL;
		}
		else if (b == btnFillBlue) {
			currentFig = Figure::BLUEFILL;
		}
		else if (b == btnFillOrigin) {
			currentFig = Figure::ORIGINFILL;
		}
		else if (b == btnErase) {
			currentFig = Figure::ERASERECT;
		}
		else if (b == btnAllErase) {
			currentFig = Figure::ERASEALL;
		}
	}
}

// 메뉴 버튼 액션 정해주기
void View::menuActions(Menu *m) {
	if (state == openMenu) {
		if (m == nullptr) {
			return;
		}
		if (m == save) {
			//
		}
		else if (m == open) {
			//
		}
		else if (m == rectSet) {
			currentFig = Figure::RECT;
		}
		else if (m == ellipseSet) {
			currentFig = Figure::ELLIPSE;
		}
		else if (m == lineSet) {
			currentFig = Figure::LINE;
		}
		else if (m == redLineSet) {
			currentFig = Figure::REDLINE;
		}
		else if (m == greenLineSet) {
			currentFig = Figure::GREENLINE;
		}
		else if (m == blueLineSet) {
			currentFig = Figure::BLUELINE;
		}
		else if (m == originLineSet) {
			currentFig = Figure::ORIGINLINE;
		}
		else if (m == redFillSet) {
			currentFig = Figure::REDFILL;
		}
		else if (m == greenFillSet) {
			currentFig = Figure::GREENFILL;
		}
		else if (m == blueFillSet) {
			currentFig = Figure::BLUEFILL;
		}
		else if (m == originFillSet) {
			currentFig = Figure::ORIGINFILL;
		}
		invalidate();
	}
}

// 메뉴바 버튼 액션 정해주기
void View::menubarActions(MenuItem *t) {
	if (state == closeMenu) {
		if (t == nullptr) {
			return;
		}
		if (t == fileButton) {
			currentMenu = Menu::OPENFILEMENU;
		}
		else if (t == figureButton) {
			currentMenu = Menu::OPENSETMENU;
		}
		else if (t == lineButton) {
			currentMenu = Menu::OPENLINEMENU;
		}
		else if (t == fillButton) {
			currentMenu = Menu::OPENFILLMENU;
		}
	}
}

// 라인의 색을 지정하기
void View::setPenColor(COLORREF color)
{
	if (penMap.find(color) != penMap.end()) {
		thePen = penMap.find(color)->second;
	}
	else {
		thePen = CreatePen(PS_SOLID, 1, color);
		penMap[color] = thePen;
	}
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
	if (brushMap.find(color) != brushMap.end()) {
		theBrush = brushMap.find(color)->second;
	}
	else {
		theBrush = CreateSolidBrush(color);
		brushMap[color] = theBrush;
	}
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
	width = this->getWindowWidth();
	height = this->getWindowHeight();
	setPenColor(RGB(230, 230, 230));
	setFillColor(RGB(230, 230, 230));
	drawRectangle(0, 0, width, 32);
	setPenColor(RGB(230, 230, 230));
	setFillColor(RGB(230, 230, 230));
	drawRectangle(32, 0, width, 64);
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
void View::eraseRect(int x, int y, int sizeX, int sizeY) // 좌상귀 x y 그리고 x축 y축 크기
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

int View::getWindowHeight() {
	RECT r;
	GetWindowRect(m_WindowHandle, &r);
	return r.bottom - r.top;
}

void View::addTButton(Component *c) {
	m_List.push_back(c);
	c->setView(this);
}

void View::addMenu(Component *c) {
	m_menuList.push_back(c);
	c->setView(this);
}

void View::addFile(Component *c) {
	m_fileList.push_back(c);
	c->setView2(this);
}

void View::addSet(Component *c) {
	m_setList.push_back(c);
	c->setView2(this);
}

void View::addLineSet(Component *c) {
	m_lineList.push_back(c);
	c->setView2(this);
}

void View::addFillSet(Component *c) {
	m_fillList.push_back(c);
	c->setView2(this);
}

void View::redrawColor(MyEvent e) {
	if (recent_figure == recent_line) {
		addFigure(new CLine(startX, startY, e.x, e.y, line_state, fill_state));
	}
	else if (recent_figure == recent_ellipse) {
		addFigure(new CEllipse(startX, startY, e.x, e.y, line_state, fill_state));
	}
	else if (recent_figure == recent_rect) {
		addFigure(new Rect(startX, startY, e.x, e.y, line_state, fill_state));
	}
}

void View::drawIcon(int x, int y, HICON i) {
	DrawIcon(m_DCHandle, x, y, i);
}