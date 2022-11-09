#pragma once
#include "stdafx.h"
//#include "Proj2018.h"
// 잡다한 것들을 넣기 위한 헤더 파일
#include <string>
void debugOutput(int n);
void debugOutput(const char *s);
void debugOutput(const std::string &s);
class MyEvent {
public:
	MyEvent(WPARAM wParam, LPARAM lParam);
	bool ctrl();
	bool alt();
	bool shift();
	int x, y;
	WPARAM m_wParam;
};