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
	// �ٸ� ������ ������ ���� ������ ID �� IDI_ICON3 ��� �����ϰ�,
	//drawIcon(32, 32, rectIcon);
	state = closeMenu;
	stateMenu = closeMenu;
	for (auto r : m_rectList) {
		r->draw();
	}
}
// ��� �������� onInitialize �Լ����� �ʱ�ȭ����.
void MyView::onInitialize()
{
	// ���� ��ư �߰�
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
	// �޴� ��� �߰�
	fileButton = new MenuItem("����");
	figureButton = new MenuItem("����");
	lineButton = new MenuItem("����");
	fillButton = new MenuItem("ä���");
	// �޴� ��ư �߰�
	save = new Menu("����");
	open = new Menu("����");
	rectSet = new Menu("�簢��");
	ellipseSet = new Menu("Ÿ��");
	lineSet = new Menu("����");
	redLineSet = new Menu("����");
	greenLineSet = new Menu("�ʷ�");
	blueLineSet = new Menu("�Ķ�");
	originLineSet = new Menu("�ʱ�ȭ");
	redFillSet = new Menu("����");
	greenFillSet = new Menu("�ʷ�");
	blueFillSet = new Menu("�Ķ�");
	originFillSet = new Menu("�ʱ�ȭ");
	// �� ����Ʈ�� ����ֱ�
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
	// �� �����ʸ� �߰��ϱ�
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
	// ������ �߰��ϱ�
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