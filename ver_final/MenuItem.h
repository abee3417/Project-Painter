#pragma once
#include "MyButton.h"
class MenuItem : public MyButton
{
public:
	MenuItem(std::string title);
	~MenuItem();
	void action();
	void addMenubarListener(MenubarActionListener *l);
};

