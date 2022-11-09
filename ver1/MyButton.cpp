#include "stdafx.h"
#include <string>
#include "View.h"
using namespace std;


MyButton::MyButton(string str, View *data, int x1, int y1, int x2, int y2)
{
	m_str = str;
	m_data = data;
	m_x1 = x1;
	m_y1 = y1;
	m_x2 = x2;
	m_y2 = y2;
}

MyButton::MyButton()
{
	//
}

MyButton::~MyButton()
{
}