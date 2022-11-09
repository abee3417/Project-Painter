#include "stdafx.h"
#include "Misc.h"
#include <cstdio>

Event::Event() {
	//
}
Event::~Event() {
	//
}
bool Event::ctrlPressed() {
	if (wParam & MK_CONTROL) {
		return true;
	}
	else {
		return false;
	}
}
bool Event::shiftPressed() {
	if (wParam & MK_SHIFT) {
		return true;
	}
	else {
		return false;
	}
}
void debugOutput(int n) {
	char buf[100];
	sprintf_s(buf, " %d ", n);
	OutputDebugStringA(buf);
}

void debugOutput(const char *s) {
	OutputDebugStringA(s);
}