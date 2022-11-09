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
	//debugOutput("Click\n");  // IDE�� '���' â�� ���´�.
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
		// �� ���� ��ư�� ���� �� �̵��Ͽ� ĵ�������� �� ����̴�. 
		return;
	}
	if (state == closeMenu) {
		if (currentFig == Figure::LINE) { // ����
			addFigure(new CLine(startX, startY, e.x, e.y, line_state, fill_state));
			recent_figure = recent_line;
		}
		else if (currentFig == Figure::ELLIPSE) {  // Ÿ��
			addFigure(new CEllipse(startX, startY, e.x, e.y, line_state, fill_state));
			recent_figure = recent_ellipse;
		}
		else if (currentFig == Figure::RECT) {  // �簢��
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
	// ���α׷� ���� ����� �����ϱ� ���� ���� ��ư Ŭ���� �Ʒ� ���� ȣ���ϰ� ��������ϴ�.
	// eraseRect(e.x - 50, e.y - 50, e.x + 50, e.y + 50);
	//::PostMessage(m_WindowHandle, WM_CLOSE, NULL, NULL);
}

void View::OnRButtonUp(MyEvent e)
{
	
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

// ���� ��ư �׼� �����ֱ�
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

// �޴� ��ư �׼� �����ֱ�
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

// �޴��� ��ư �׼� �����ֱ�
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

// ������ ���� �����ϱ�
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

// ���� ���� �β��� ���ÿ� �����ϱ�
void View::setPen(COLORREF color, int width)
{
	thePen = CreatePen(PS_SOLID, width, color);
	SelectObject(m_DCHandle, thePen);
}

// ä�� ���� �����ϴ� �Լ�.
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
	width = this->getWindowWidth();
	height = this->getWindowHeight();
	setPenColor(RGB(230, 230, 230));
	setFillColor(RGB(230, 230, 230));
	drawRectangle(0, 0, width, 32);
	setPenColor(RGB(230, 230, 230));
	setFillColor(RGB(230, 230, 230));
	drawRectangle(32, 0, width, 64);
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
void View::eraseRect(int x, int y, int sizeX, int sizeY) // �»�� x y �׸��� x�� y�� ũ��
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