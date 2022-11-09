#include "stdafx.h"
#include "Container.h"


Container::Container(View *data)
	:Component(data)
{
}

Container::Container(HINSTANCE hInstance) : Component(hInstance) {

}

Container::~Container()
{
}

void Container::addComponent(Component *c) {
	m_List.push_back(c);
	c->setView(m_view);
}

Component * Container::findButton(int x, int y)
{
	// TODO: 여기에 구현 코드 추가.

	for (auto b : m_List) {
		if (b->inside(x, y)) return b;
	}
	return nullptr;
}

void Container::draw() {
	int count = 0;
	for (std::list<Component*>::iterator i = m_List.begin(); i != m_List.end(); i++) {
		(*i)->draw(count * 32);
		count++;
	}
	count = 0;
}