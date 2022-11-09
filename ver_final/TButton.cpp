#include "stdafx.h"
#include "TButton.h"
#include "Misc.h"
#include "View.h"
#include "list"

TButton::TButton(std::string title) : MyButton(title)
{
}


TButton::~TButton()
{
}

// 리스너를 이용하여 view에서 액션을 정해준다.
void TButton::action() {
	debugOutput(m_title);
	for (auto i : m_ToolbarLList) {
		i->TButtonPerformed(this);
	}
}

void TButton::addToolbarListener(ToolbarActionListener *l) {
	m_ToolbarLList.push_back(l);
}