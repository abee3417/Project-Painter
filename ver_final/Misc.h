#pragma once
#include "stdafx.h"
//#include "Proj2018.h"
// 잡다한 것들을 넣기 위한 헤더 파일
#include <string>
void debugOutput(int n);
void debugOutput(const char *s);
void debugOutput(const std::string &s);
class MyView;
class Menu;
class MenuItem;
class TButton;
class MyEvent {
public:
	MyEvent(WPARAM wParam, LPARAM lParam);
	bool ctrl();
	bool shift();
	int x, y;
	WPARAM m_wParam;
};

class MenuActionListener {
public:
	virtual void MenuPerformed(Menu *m) = 0;
};

class ToolbarActionListener {
public:
	virtual void TButtonPerformed(TButton * b) = 0;
};

class MenubarActionListener {
public:
	virtual void MenubarPerformed(MenuItem * t) = 0;
};

class MenuListener : public MenuActionListener{
public:
	MenuListener(MyView * data);
	void MenuPerformed(Menu * m);
private:
	MyView * v;
};

class ToolbarListener : public ToolbarActionListener {
public:
	ToolbarListener(MyView * data);
	void TButtonPerformed(TButton * b);
private:
	MyView * v;
};

class MenubarListener : public MenubarActionListener {
public:
	MenubarListener(MyView * data);
	void MenubarPerformed(MenuItem * t);
private:
	MyView * v;
};