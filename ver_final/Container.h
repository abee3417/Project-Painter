#pragma once
#include "Component.h"
#include "list"
using namespace std;
class View;
class Container : public Component
{
public:
	Container(View *data);
	Container(std::string title);
	Container(HINSTANCE hInstance);
	~Container();
	virtual void addTButton(Component *c);
	virtual void addMenu(Component *c);
	virtual void addFile(Component *c);
	virtual void addSet(Component *c);
	virtual void addLineSet(Component *c);
	virtual void addFillSet(Component *c);
	virtual void drawFileMenu(int count);
	virtual void redrawFileMenu();
	virtual void ccdrawFileMenu();
	virtual void drawSetMenu(int count);
	virtual void redrawSetMenu();
	virtual void ccdrawSetMenu();
	virtual void drawLineSetMenu(int count);
	virtual void redrawLineSetMenu();
	virtual void ccdrawLineSetMenu();
	virtual void drawFillSetMenu(int count);
	virtual void redrawFillSetMenu();
	virtual void ccdrawFillSetMenu();
	virtual void setView2(View *);
	virtual void action();
	virtual void addMenuListener(MenuActionListener *l);
	void drawTButton();
	void drawMenu();
	void drawFile();
	void drawSet();
	void drawLineSet();
	void drawFillSet();

	Component * findButton(int x, int y, int &whatType);
protected:
	std::list<Component *> m_List;
	std::list<Component *> m_menuList;
	std::list<Component *> m_fileList;
	std::list<Component *> m_setList;
	std::list<Component *> m_lineList;
	std::list<Component *> m_fillList;
};