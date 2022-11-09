#include "stdafx.h"
#include "Container.h"
#include "list"
#include "Menu.h"


Container::Container(View *data)
	:Component(data)
{
}

Container::Container(std::string title)
	: Component(title)
{
}

Container::Container(HINSTANCE hInstance) : Component(hInstance) {

}

Container::~Container()
{
}

void Container::addTButton(Component *c) {

}

void Container::addMenu(Component *c) {

}

void Container::addFile(Component *c) {

}

void Container::addSet(Component *c) {

}

void Container::addLineSet(Component *c) {

}

void Container::addFillSet(Component *c) {

}

void Container::drawFileMenu(int count) {

}
void Container::redrawFileMenu() {

}
void Container::ccdrawFileMenu() {

}
void Container::drawSetMenu(int count) {

}
void Container::redrawSetMenu() {

}
void Container::ccdrawSetMenu() {

}
void Container::setView2(View *) {

}
void Container::action() {

}
void Container::drawLineSetMenu(int count) {

}
void Container::redrawLineSetMenu() {

}
void Container::ccdrawLineSetMenu() {

}
void Container::drawFillSetMenu(int count) {

}
void Container::redrawFillSetMenu() {

}
void Container::ccdrawFillSetMenu() {

}
void Container::addMenuListener(MenuActionListener *l) {

}
Component * Container::findButton(int x, int y, int &whatType)
{
	// TODO: 여기에 구현 코드 추가.
	if (state == closeMenu) { // 메뉴를 닫은 상태에서는 툴바만 작동
		for (auto a : m_List) {
			if (a->insideTButton(x, y)) {
				whatType = typeTButton;
				return a;
			}
		}
		for (auto b : m_menuList) {
			if (b->insideMenu(x, y)) {
				whatType = typeMenu;
				return b;
			}
		}
	}
	else if (state == openMenu) { // 메뉴를 오픈한 상태에서는 메뉴바만 작동
		for (auto c : m_fileList) {
			if (c->insideFileMenu(x, y)) {
				//whatType = typeTButton;
				return c;
			}
		}
		for (auto d : m_setList) {
			if (d->insideSetMenu(x, y)) {
				return d;
			}
		}
		for (auto e : m_lineList) {
			if (e->insideLineMenu(x, y)) {
				return e;
			}
		}
		for (auto f : m_fillList) {
			if (f->insideFillMenu(x, y)) {
				return f;
			}
		}
	}
	return nullptr;
}

void Container::drawTButton() {
	int countTButton = 0;
	for (std::list<Component*>::iterator i = m_List.begin(); i != m_List.end(); i++) {
		(*i)->drawTButton(countTButton * 32);
		countTButton++;
	}
	countTButton = 0;
}

void Container::drawMenu() {
	int countMenu = 0;
	for (std::list<Component*>::iterator i = m_menuList.begin(); i != m_menuList.end(); i++) {
		(*i)->drawMenu(countMenu * 48);
		countMenu++;
	}
	countMenu = 0;
}

void Container::drawFile() {
	int countFile = 1;
	for (std::list<Component*>::iterator i = m_fileList.begin(); i != m_fileList.end(); i++) {
		(*i)->drawFileMenu(countFile * 32);
		countFile++;
	}
	countFile = 1;
}

void Container::drawSet() {
	int countSet = 1;
	for (std::list<Component*>::iterator i = m_setList.begin(); i != m_setList.end(); i++) {
		(*i)->drawSetMenu(countSet * 32);
		countSet++;
	}
	countSet = 1;
}

void Container::drawLineSet() {
	int countLineSet = 1;
	for (std::list<Component*>::iterator i = m_lineList.begin(); i != m_lineList.end(); i++) {
		(*i)->drawLineSetMenu(countLineSet * 32);
		countLineSet++;
	}
	countLineSet = 1;
}

void Container::drawFillSet() {
	int countFillSet = 1;
	for (std::list<Component*>::iterator i = m_fillList.begin(); i != m_fillList.end(); i++) {
		(*i)->drawFillSetMenu(countFillSet * 32);
		countFillSet++;
	}
	countFillSet = 1;
}