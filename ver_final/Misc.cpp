#include "stdafx.h"
#include "Misc.h"
#include "MyView.h"
#include <cstdio>
#include <string>
void debugOutput(int n) {
	char buf[100];
	sprintf_s(buf, " %d ", n);
	OutputDebugStringA(buf);
}

void debugOutput(const char *s) {
	OutputDebugStringA(s);
}


void debugOutput(const std::string &s) {
	OutputDebugStringA(s.c_str());
}

// MyEvent 클래스의 멤버함수들
MyEvent::MyEvent(WPARAM wp, LPARAM lp)
:m_wParam(wp), x(LOWORD(lp)), y(HIWORD(lp)){
	//
}
bool MyEvent::ctrl() {
	return (m_wParam & MK_CONTROL);
}

bool MyEvent::shift() {
	return (m_wParam & MK_SHIFT);
}

// MenuListener 클래스의 멤버함수들
MenuListener::MenuListener(MyView * data) {
	v = data;
}
void MenuListener::MenuPerformed(Menu * m) {
	v->menuActions(m);
}

// ToolbarListener 클래스의 멤버함수들
ToolbarListener::ToolbarListener(MyView * data) {
	v = data;
}
void ToolbarListener::TButtonPerformed(TButton * b) {
	v->buttonActions(b);
}

// MenubarListener 클래스의 멤버함수들
MenubarListener::MenubarListener(MyView * data) {
	v = data;
}
void MenubarListener::MenubarPerformed(MenuItem * t) {
	v->menubarActions(t);
}