#include "stdafx.h"
#include "MyButton.h"
#include "View.h"
#include "Menu.h"

MyButton::MyButton(std::string title)
	:Component(title)
{
}


MyButton::~MyButton()
{
}

// ó���� ��ư�� �׸��� �Լ� drawTButton
void MyButton::drawTButton(int count)
{
	m_view->drawIcon(count, 32, m_icon);
	m_x1 = count;
	m_xplus1 = count + 32;
}

// ��ư�� ������� �׸��� �Լ� redrawTButton
void MyButton::redrawTButton()
{
	m_view->drawIcon(m_x1, 32, m_icon);
}

// ���콺�� ��ư�� �÷��� �� ������ �ٲٴ� �Լ� ccdrawTButton
void MyButton::ccdrawTButton()
{
	m_view->drawIcon(m_x1, 32, m_icon_change);
}

// ó���� �޴��� �׸��� �Լ� drawMenu
void MyButton::drawMenu(int count)
{
	m_view->setPenColor(m_line_color);
	m_view->setFillColor(m_normal_bg_color);
	m_view->drawRectangle(count, 0, count + 48, 32);
	m_x2 = count;
	m_xplus2 = count + 48;
	SIZE s = m_view->textSize(m_title);
	int xoff = (48 - s.cx) / 2;
	int yoff = (32 - s.cy) / 2;
	m_view->setTextBkColor(m_normal_bg_color);
	m_view->drawText(m_title, m_x2 + xoff, yoff);
}

// �޴��� ������� �׸��� �Լ� redrawMenu
void MyButton::redrawMenu()
{
	m_view->setPenColor(m_line_color);
	m_view->setFillColor(m_normal_bg_color);
	m_view->drawRectangle(m_x2, 0, m_x2 + 48, 32);
	SIZE s = m_view->textSize(m_title);
	int xoff = (48 - s.cx) / 2;
	int yoff = (32 - s.cy) / 2;
	m_view->setTextBkColor(m_normal_bg_color);
	m_view->drawText(m_title, m_x2 + xoff, yoff);
}

// ���콺�� �޴��� �÷��� �� ������ �ٲٴ� �Լ� ccdrawMenu
void MyButton::ccdrawMenu() {
	m_view->setPenColor(m_temp_line_color);
	m_view->setFillColor(m_temp_bg_color);
	m_view->drawRectangle(m_x2, 0, m_x2 + 48, 32);
	SIZE s = m_view->textSize(m_title);
	int xoff = (48 - s.cx) / 2;
	int yoff = (32 - s.cy) / 2;
	m_view->setTextBkColor(m_temp_bg_color);
	m_view->drawText(m_title, m_x2 + xoff, yoff);
}

// ���콺�� ��ư ��ġ�� �ִ��� �Ǻ��ϴ� �Լ�
void MyButton::action() {
	//
}
void MyButton::setView(View *v) {
	m_view = v;
}

// ��Ȳ���� �������� ����� �Լ�
void MyButton::makeRectIcon() {
	m_icon = (HICON)LoadImage(m_view->m_InstanceHandle, MAKEINTRESOURCE(IDI_ICON1), IMAGE_ICON, 32, 32, LR_DEFAULTCOLOR);
	m_icon_change = (HICON)LoadImage(m_view->m_InstanceHandle, MAKEINTRESOURCE(IDI_ICON2), IMAGE_ICON, 32, 32, LR_DEFAULTCOLOR);
}
void MyButton::makeEllipseIcon() {
	m_icon = (HICON)LoadImage(m_view->m_InstanceHandle, MAKEINTRESOURCE(IDI_ICON3), IMAGE_ICON, 32, 32, LR_DEFAULTCOLOR);
	m_icon_change = (HICON)LoadImage(m_view->m_InstanceHandle, MAKEINTRESOURCE(IDI_ICON4), IMAGE_ICON, 32, 32, LR_DEFAULTCOLOR);
}
void MyButton::makeLineIcon() {
	m_icon = (HICON)LoadImage(m_view->m_InstanceHandle, MAKEINTRESOURCE(IDI_ICON5), IMAGE_ICON, 32, 32, LR_DEFAULTCOLOR);
	m_icon_change = (HICON)LoadImage(m_view->m_InstanceHandle, MAKEINTRESOURCE(IDI_ICON6), IMAGE_ICON, 32, 32, LR_DEFAULTCOLOR);
}
void MyButton::makeRLIcon() {
	m_icon = (HICON)LoadImage(m_view->m_InstanceHandle, MAKEINTRESOURCE(IDI_ICON15), IMAGE_ICON, 32, 32, LR_DEFAULTCOLOR);
	m_icon_change = (HICON)LoadImage(m_view->m_InstanceHandle, MAKEINTRESOURCE(IDI_ICON16), IMAGE_ICON, 32, 32, LR_DEFAULTCOLOR);
}
void MyButton::makeGLIcon() {
	m_icon = (HICON)LoadImage(m_view->m_InstanceHandle, MAKEINTRESOURCE(IDI_ICON17), IMAGE_ICON, 32, 32, LR_DEFAULTCOLOR);
	m_icon_change = (HICON)LoadImage(m_view->m_InstanceHandle, MAKEINTRESOURCE(IDI_ICON18), IMAGE_ICON, 32, 32, LR_DEFAULTCOLOR);
}
void MyButton::makeBLIcon() {
	m_icon = (HICON)LoadImage(m_view->m_InstanceHandle, MAKEINTRESOURCE(IDI_ICON19), IMAGE_ICON, 32, 32, LR_DEFAULTCOLOR);
	m_icon_change = (HICON)LoadImage(m_view->m_InstanceHandle, MAKEINTRESOURCE(IDI_ICON20), IMAGE_ICON, 32, 32, LR_DEFAULTCOLOR);
}
void MyButton::makeOLIcon() {
	m_icon = (HICON)LoadImage(m_view->m_InstanceHandle, MAKEINTRESOURCE(IDI_ICON21), IMAGE_ICON, 32, 32, LR_DEFAULTCOLOR);
	m_icon_change = (HICON)LoadImage(m_view->m_InstanceHandle, MAKEINTRESOURCE(IDI_ICON22), IMAGE_ICON, 32, 32, LR_DEFAULTCOLOR);
}
void MyButton::makeRFIcon() {
	m_icon = (HICON)LoadImage(m_view->m_InstanceHandle, MAKEINTRESOURCE(IDI_ICON7), IMAGE_ICON, 32, 32, LR_DEFAULTCOLOR);
	m_icon_change = (HICON)LoadImage(m_view->m_InstanceHandle, MAKEINTRESOURCE(IDI_ICON8), IMAGE_ICON, 32, 32, LR_DEFAULTCOLOR);
}
void MyButton::makeGFIcon() {
	m_icon = (HICON)LoadImage(m_view->m_InstanceHandle, MAKEINTRESOURCE(IDI_ICON9), IMAGE_ICON, 32, 32, LR_DEFAULTCOLOR);
	m_icon_change = (HICON)LoadImage(m_view->m_InstanceHandle, MAKEINTRESOURCE(IDI_ICON10), IMAGE_ICON, 32, 32, LR_DEFAULTCOLOR);
}
void MyButton::makeBFIcon() {
	m_icon = (HICON)LoadImage(m_view->m_InstanceHandle, MAKEINTRESOURCE(IDI_ICON11), IMAGE_ICON, 32, 32, LR_DEFAULTCOLOR);
	m_icon_change = (HICON)LoadImage(m_view->m_InstanceHandle, MAKEINTRESOURCE(IDI_ICON12), IMAGE_ICON, 32, 32, LR_DEFAULTCOLOR);
}
void MyButton::makeOFIcon() {
	m_icon = (HICON)LoadImage(m_view->m_InstanceHandle, MAKEINTRESOURCE(IDI_ICON13), IMAGE_ICON, 32, 32, LR_DEFAULTCOLOR);
	m_icon_change = (HICON)LoadImage(m_view->m_InstanceHandle, MAKEINTRESOURCE(IDI_ICON14), IMAGE_ICON, 32, 32, LR_DEFAULTCOLOR);
}
void MyButton::makeEraseIcon() {
	m_icon = (HICON)LoadImage(m_view->m_InstanceHandle, MAKEINTRESOURCE(IDI_ICON23), IMAGE_ICON, 32, 32, LR_DEFAULTCOLOR);
	m_icon_change = (HICON)LoadImage(m_view->m_InstanceHandle, MAKEINTRESOURCE(IDI_ICON24), IMAGE_ICON, 32, 32, LR_DEFAULTCOLOR);
}
void MyButton::makeAllEraseIcon() {
	m_icon = (HICON)LoadImage(m_view->m_InstanceHandle, MAKEINTRESOURCE(IDI_ICON25), IMAGE_ICON, 32, 32, LR_DEFAULTCOLOR);
	m_icon_change = (HICON)LoadImage(m_view->m_InstanceHandle, MAKEINTRESOURCE(IDI_ICON26), IMAGE_ICON, 32, 32, LR_DEFAULTCOLOR);
}