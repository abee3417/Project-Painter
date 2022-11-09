#pragma once
#include "Container.h"
class Menu : public Container
{
public:
	static const int OPENFILEMENU = 201, OPENSETMENU = 202, OPENLINEMENU = 203, OPENFILLMENU = 204;
	Menu(std::string title);
	void drawFileMenu(int count);
	void redrawFileMenu();
	void ccdrawFileMenu();
	void drawSetMenu(int count);
	void redrawSetMenu();
	void ccdrawSetMenu();
	void drawLineSetMenu(int count);
	void redrawLineSetMenu();
	void ccdrawLineSetMenu();
	void drawFillSetMenu(int count);
	void redrawFillSetMenu();
	void ccdrawFillSetMenu();
	void setView2(View *v);
	void action();
	void addMenuListener(MenuActionListener *l);
};

