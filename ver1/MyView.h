#pragma once
#include "Figure.h"
#include "iostream"
#include "Proj2018.h"
#include "CRect.h"
#include "CEllipse.h"
#include "TButton.h"
#include "CLine.h"
#include "MyButton.h"
#include "View.h"
#include "Toolbar.h"
#include <list>
#include <string>
#define MAX_LOADSTRING 100
using namespace std;
class MyView : public View
{
public:
	MyView(HINSTANCE hInstance);
	MyView(HWND w);
	~MyView();
};

