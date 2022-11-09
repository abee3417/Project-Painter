#include "stdafx.h"
#include "Menu.h"
#include "Component.h"
#include "View.h"

Menu::Menu(std::string title) : Container(title)
{
}
// 파일 메뉴 그리기
void Menu::drawFileMenu(int count)
{
	m_view->setPenColor(m_line_color);
	m_view->setFillColor(m_normal_bg_color);
	m_view->drawRectangle(0, count, 48, count + 32);
	m_y1 = count;
	m_yplus1 = count + 48;
	SIZE s = m_view->textSize(m_title);
	int xoff = (48 - s.cx) / 2;
	int yoff = (32 - s.cy) / 2;
	m_view->setTextBkColor(m_normal_bg_color);
	m_view->drawText(m_title, xoff, m_y1 + yoff);
}
void Menu::redrawFileMenu()
{
	m_view->setPenColor(m_line_color);
	m_view->setFillColor(m_normal_bg_color);
	m_view->drawRectangle(0, m_y1, 48, m_y1 + 32);
	SIZE s = m_view->textSize(m_title);
	int xoff = (48 - s.cx) / 2;
	int yoff = (32 - s.cy) / 2;
	m_view->setTextBkColor(m_normal_bg_color);
	m_view->drawText(m_title, xoff, m_y1 + yoff);
}
void Menu::ccdrawFileMenu() {
	m_view->setPenColor(m_temp_line_color);
	m_view->setFillColor(m_temp_bg_color);
	m_view->drawRectangle(0, m_y1, 48, m_y1 + 32);
	SIZE s = m_view->textSize(m_title);
	int xoff = (48 - s.cx) / 2;
	int yoff = (32 - s.cy) / 2;
	m_view->setTextBkColor(m_temp_bg_color);
	m_view->drawText(m_title, xoff, m_y1 + yoff);
}
// 도형 메뉴 그리기
void Menu::drawSetMenu(int count)
{
	m_view->setPenColor(m_line_color);
	m_view->setFillColor(m_normal_bg_color);
	m_view->drawRectangle(48, count, 96, count + 32);
	m_y2 = count;
	m_yplus2 = count + 48;
	SIZE s = m_view->textSize(m_title);
	int xoff = (144 - s.cx) / 2;
	int yoff = (32 - s.cy) / 2;
	m_view->setTextBkColor(m_normal_bg_color);
	m_view->drawText(m_title, xoff, m_y2 + yoff);
}
void Menu::redrawSetMenu()
{
	m_view->setPenColor(m_line_color);
	m_view->setFillColor(m_normal_bg_color);
	m_view->drawRectangle(48, m_y2, 96, m_y2 + 32);
	SIZE s = m_view->textSize(m_title);
	int xoff = (144 - s.cx) / 2;
	int yoff = (32 - s.cy) / 2;
	m_view->setTextBkColor(m_normal_bg_color);
	m_view->drawText(m_title, xoff, m_y2 + yoff);
}
void Menu::ccdrawSetMenu() {
	m_view->setPenColor(m_temp_line_color);
	m_view->setFillColor(m_temp_bg_color);
	m_view->drawRectangle(48, m_y2, 96, m_y2 + 32);
	SIZE s = m_view->textSize(m_title);
	int xoff = (144 - s.cx) / 2;
	int yoff = (32 - s.cy) / 2;
	m_view->setTextBkColor(m_temp_bg_color);
	m_view->drawText(m_title, xoff, m_y2 + yoff);
}
// 선색 메뉴 그리기
void Menu::drawLineSetMenu(int count) {
	m_view->setPenColor(m_line_color);
	m_view->setFillColor(m_normal_bg_color);
	m_view->drawRectangle(96, count, 144, count + 32);
	m_y3 = count;
	m_yplus3 = count + 48;
	SIZE s = m_view->textSize(m_title);
	int xoff = (240 - s.cx) / 2;
	int yoff = (32 - s.cy) / 2;
	m_view->setTextBkColor(m_normal_bg_color);
	m_view->drawText(m_title, xoff, m_y3 + yoff);
}
void Menu::redrawLineSetMenu() {
	m_view->setPenColor(m_line_color);
	m_view->setFillColor(m_normal_bg_color);
	m_view->drawRectangle(96, m_y3, 144, m_y3 + 32);
	SIZE s = m_view->textSize(m_title);
	int xoff = (240 - s.cx) / 2;
	int yoff = (32 - s.cy) / 2;
	m_view->setTextBkColor(m_normal_bg_color);
	m_view->drawText(m_title, xoff, m_y3 + yoff);
}
void Menu::ccdrawLineSetMenu() {
	m_view->setPenColor(m_line_color);
	m_view->setFillColor(m_normal_bg_color);
	m_view->drawRectangle(96, m_y3, 144, m_y3 + 32);
	SIZE s = m_view->textSize(m_title);
	int xoff = (240 - s.cx) / 2;
	int yoff = (32 - s.cy) / 2;
	m_view->setTextBkColor(m_normal_bg_color);
	m_view->drawText(m_title, xoff, m_y3 + yoff);
}
// 채움색 메뉴 그리기
void Menu::drawFillSetMenu(int count) {
	m_view->setPenColor(m_line_color);
	m_view->setFillColor(m_normal_bg_color);
	m_view->drawRectangle(144, count, 192, count + 32);
	m_y4 = count;
	m_yplus4 = count + 48;
	SIZE s = m_view->textSize(m_title);
	int xoff = (336 - s.cx) / 2;
	int yoff = (32 - s.cy) / 2;
	m_view->setTextBkColor(m_normal_bg_color);
	m_view->drawText(m_title, xoff, m_y4 + yoff);
}
void Menu::redrawFillSetMenu() {
	m_view->setPenColor(m_line_color);
	m_view->setFillColor(m_normal_bg_color);
	m_view->drawRectangle(144, m_y4, 192, m_y4 + 32);
	SIZE s = m_view->textSize(m_title);
	int xoff = (336 - s.cx) / 2;
	int yoff = (32 - s.cy) / 2;
	m_view->setTextBkColor(m_normal_bg_color);
	m_view->drawText(m_title, xoff, m_y4 + yoff);
}
void Menu::ccdrawFillSetMenu() {
	m_view->setPenColor(m_line_color);
	m_view->setFillColor(m_normal_bg_color);
	m_view->drawRectangle(144, m_y4, 192, m_y4 + 32);
	SIZE s = m_view->textSize(m_title);
	int xoff = (336 - s.cx) / 2;
	int yoff = (32 - s.cy) / 2;
	m_view->setTextBkColor(m_normal_bg_color);
	m_view->drawText(m_title, xoff, m_y4 + yoff);
}
void Menu::setView2(View *v) {
	m_view = v;
}

// 리스너를 이용하여 view에서 액션을 정해준다.
void Menu::action() {
	debugOutput(m_title);
	for (auto i : m_MenuLList) {
		i->MenuPerformed(this);
	}
}

void Menu::addMenuListener(MenuActionListener *l) {
	m_MenuLList.push_back(l);
}
