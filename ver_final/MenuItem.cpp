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

// �����ʸ� �̿��Ͽ� view���� �׼��� �����ش�.
void MenuItem::action() {
	debugOutput(m_title);
	for (auto i : m_MenubarLList) {
		i->MenubarPerformed(this);
	}
}

void MenuItem::addMenubarListener(MenubarActionListener *l) {
	m_MenubarLList.push_back(l);
}


