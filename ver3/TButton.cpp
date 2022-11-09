#include "stdafx.h"
#include "TButton.h"
#include "Misc.h"
#include "View.h"

TButton::TButton(std::string title) : MyButton(title)
{
}


TButton::~TButton()
{
}

void TButton::action() {
	debugOutput(m_title);
	m_view->buttonActions(this);
}
