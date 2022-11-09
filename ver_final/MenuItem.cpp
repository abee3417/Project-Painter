#include "stdafx.h"
#include "MenuItem.h"
#include "Misc.h"
#include "View.h"

MenuItem::MenuItem(std::string title) : MyButton(title)
{
}


MenuItem::~MenuItem()
{
}

// 리스너를 이용하여 view에서 액션을 정해준다.
void MenuItem::action() {
	debugOutput(m_title);
	for (auto i : m_MenubarLList) {
		i->MenubarPerformed(this);
	}
}

void MenuItem::addMenubarListener(MenubarActionListener *l) {
	m_MenubarLList.push_back(l);
}


