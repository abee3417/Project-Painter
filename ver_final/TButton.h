#pragma once
#include "MyButton.h"
class TButton : public MyButton
{
public:
	TButton(std::string title);
	~TButton();
	void action();
	void addToolbarListener(ToolbarActionListener *l);
};

