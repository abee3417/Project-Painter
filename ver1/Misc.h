#pragma once
#include "stdafx.h"
//#include "Proj2018.h"
// ����� �͵��� �ֱ� ���� ��� ����
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