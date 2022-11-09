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

// �����ʸ� �̿��Ͽ� view���� �׼��� �����ش�.
void TButton::action() {
	debugOutput(m_title);
	for (auto i : m_ToolbarLList) {
		i->TButtonPerformed(this);
	}
}

void TButton::addToolbarListener(ToolbarActionListener *l) {
	m_ToolbarLList.push_back(l);
}