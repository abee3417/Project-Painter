#pragma once
#include "stdafx.h"
//#include "Proj2018.h"
// 잡다한 것들을 넣기 위한 헤더 파일
class Event {
private:
public:
	int x, y;
	long wParam;
	Event();
	~Event();
	bool ctrlPressed();
	bool shiftPressed();

};
void debugOutput(int n);
void debugOutput(const char *s);