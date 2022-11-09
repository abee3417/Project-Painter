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

// MyEvent Ŭ������ ����Լ���
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

// MenuListener Ŭ������ ����Լ���
MenuListener::MenuListener(MyView * data) {
	v = data;
}
void MenuListener::MenuPerformed(Menu * m) {
	v->menuActions(m);
}

// ToolbarListener Ŭ������ ����Լ���
ToolbarListener::ToolbarListener(MyView * data) {
	v = data;
}
void ToolbarListener::TButtonPerformed(TButton * b) {
	v->buttonActions(b);
}

// MenubarListener Ŭ������ ����Լ���
MenubarListener::MenubarListener(MyView * data) {
	v = data;
}
void MenubarListener::MenubarPerformed(MenuItem * t) {
	v->menubarActions(t);
}