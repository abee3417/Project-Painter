#include "stdafx.h"
#include "MyView.h"
#include "Figure.h"
#include "Menu.h"
#include "Container.h"
#include "MenuItem.h"
#include "CLine.h"
#include "Rect.h"
#include "Ellipse.h"
#include "Misc.h"

MyView::MyView(HINSTANCE hInstance) : View(hInstance)
{
}


MyView::~MyView()
{
}

void MyView::redrawAll() {
	View::redrawAll();
	this->drawTButton();
	this->drawMenu();
	// 다른 아이콘 변수도 설정 아이콘 ID 가 IDI_ICON3 라고 가정하고,
	//drawIcon(32, 32, rectIcon);
	state = closeMenu;
	stateMenu = closeMenu;
	for (auto r : m_rectList) {
		r->draw();
	}
}
// 모든 윈도들을 onInitialize 함수에서 초기화하자.
void MyView::onInitialize()
{
	// 툴바 버튼 추가
	btnRect = new TButton("Rect");
	btnEllipse = new TButton("Ellipse");
	btnLine = new TButton("Line");
	btnLineRed = new TButton("Red /");
	btnLineGreen = new TButton("Green /");
	btnLineBlue = new TButton("Blue /");
	btnLineOrigin = new TButton("Origin /");
	btnFillRed = new TButton("Red");
	btnFillGreen = new TButton("Green");
	btnFillBlue = new TButton("Blue");
	btnFillOrigin = new TButton("Origin");
	btnErase = new TButton("erase");
	btnAllErase = new TButton("ALLerase");
	// 메뉴 목록 추가
	fileButton = new MenuItem("파일");
	figureButton = new MenuItem("도형");
	lineButton = new MenuItem("선색");
	fillButton = new MenuItem("채움색");
	// 메뉴 버튼 추가
	save = new Menu("저장");
	open = new Menu("열기");
	rectSet = new Menu("사각형");
	ellipseSet = new Menu("타원");
	lineSet = new Menu("선분");
	redLineSet = new Menu("빨강");
	greenLineSet = new Menu("초록");
	blueLineSet = new Menu("파랑");
	originLineSet = new Menu("초기화");
	redFillSet = new Menu("빨강");
	greenFillSet = new Menu("초록");
	blueFillSet = new Menu("파랑");
	originFillSet = new Menu("초기화");
	// 각 리스트에 집어넣기
	this->addTButton(btnRect);
	this->addTButton(btnEllipse);
	this->addTButton(btnLine);
	this->addTButton(btnLineRed);
	this->addTButton(btnLineGreen);
	this->addTButton(btnLineBlue);
	this->addTButton(btnLineOrigin);
	this->addTButton(btnFillRed);
	this->addTButton(btnFillGreen);
	this->addTButton(btnFillBlue);
	this->addTButton(btnFillOrigin);
	this->addTButton(btnErase);
	this->addTButton(btnAllErase);
	this->addMenu(fileButton);
	this->addMenu(figureButton);
	this->addMenu(lineButton);
	this->addMenu(fillButton);
	this->addFile(save);
	this->addFile(open);
	this->addSet(rectSet);
	this->addSet(ellipseSet);
	this->addSet(lineSet);
	this->addLineSet(redLineSet);
	this->addLineSet(greenLineSet);
	this->addLineSet(blueLineSet);
	this->addLineSet(originLineSet);
	this->addFillSet(redFillSet);
	this->addFillSet(greenFillSet);
	this->addFillSet(blueFillSet);
	this->addFillSet(originFillSet);
	// 각 리스너를 추가하기
	btnRect->addToolbarListener(new ToolbarListener(this));
	btnEllipse->addToolbarListener(new ToolbarListener(this));
	btnLine->addToolbarListener(new ToolbarListener(this));
	btnLineRed->addToolbarListener(new ToolbarListener(this));
	btnLineGreen->addToolbarListener(new ToolbarListener(this));
	btnLineBlue->addToolbarListener(new ToolbarListener(this));
	btnLineOrigin->addToolbarListener(new ToolbarListener(this));
	btnFillRed->addToolbarListener(new ToolbarListener(this));
	btnFillGreen->addToolbarListener(new ToolbarListener(this));
	btnFillBlue->addToolbarListener(new ToolbarListener(this));
	btnFillOrigin->addToolbarListener(new ToolbarListener(this));
	btnErase->addToolbarListener(new ToolbarListener(this));
	btnAllErase->addToolbarListener(new ToolbarListener(this));
	fileButton->addMenubarListener(new MenubarListener(this));
	figureButton->addMenubarListener(new MenubarListener(this));
	lineButton->addMenubarListener(new MenubarListener(this));
	fillButton->addMenubarListener(new MenubarListener(this));
	save->addMenuListener(new MenuListener(this));
	open->addMenuListener(new MenuListener(this));
	rectSet->addMenuListener(new MenuListener(this));
	ellipseSet->addMenuListener(new MenuListener(this));
	lineSet->addMenuListener(new MenuListener(this));
	redLineSet->addMenuListener(new MenuListener(this));
	greenLineSet->addMenuListener(new MenuListener(this));
	blueLineSet->addMenuListener(new MenuListener(this));
	originLineSet->addMenuListener(new MenuListener(this));
	redFillSet->addMenuListener(new MenuListener(this));
	greenFillSet->addMenuListener(new MenuListener(this));
	blueFillSet->addMenuListener(new MenuListener(this));
	originFillSet->addMenuListener(new MenuListener(this));
	// 아이콘 추가하기
	btnRect->makeRectIcon();
	btnEllipse->makeEllipseIcon();
	btnLine->makeLineIcon();
	btnLineRed->makeRLIcon();
	btnLineGreen->makeGLIcon();
	btnLineBlue->makeBLIcon();
	btnLineOrigin->makeOLIcon();
	btnFillRed->makeRFIcon();
	btnFillGreen->makeGFIcon();
	btnFillBlue->makeBFIcon();
	btnFillOrigin->makeOFIcon();
	btnErase->makeEraseIcon();
	btnAllErase->makeAllEraseIcon();
	//
	invalidate();
}

void MyView::OnMouseMove(MyEvent e)
{
	View::OnMouseMove(e);
}

void MyView::OnLButtonDown(MyEvent e)
{
	View::OnLButtonDown(e);
}

void MyView::OnLButtonUp(MyEvent e)
{
	View::OnLButtonUp(e);
}

void MyView::OnRButtonDown(MyEvent e)
{
	View::OnRButtonDown(e);
}

void MyView::OnRButtonUp(MyEvent e)
{
	View::OnRButtonUp(e);
}


void MyView::OnChar(long ch)
{
	View::OnChar(ch);
}

void MyView::addFigure(Figure *r) {
	View::addFigure(r);
}

void MyView::buttonActions(TButton *b) {
	View::buttonActions(b);
}