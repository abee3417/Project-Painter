#pragma once
#include "Component.h"
#include "list"
using namespace std;
class View;
class Container : public Component
{
public:
	Container(View *data);
	Container(HINSTANCE hInstance);
	~Container();
	void addComponent(Component *c);
	void draw();
	Component * findButton(int x, int y);
protected:
	std::list<Component *> m_List;
};