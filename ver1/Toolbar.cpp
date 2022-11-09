#include "stdafx.h"
#include "Toolbar.h"
#include "View.h"
#include "Figure.h"
#include "CRect.h"
#include "CEllipse.h"
#include "CLine.h"
#include "MyButton.h"
#include "TButton.h"
#include "Misc.h"
#include <list>
#include <string>


Toolbar::Toolbar(View *data)
{
	m_data = data;
}

Toolbar::~Toolbar()
{
}

void Toolbar::checkButton(Event e) {
	// 마우스 포인터의 위치를 상황별로 다르게 기억한다.
	if ((0 < e.x && e.x < 31) && (0 < e.y && e.y < 32)) {
		move_type = type_square;
	}
	else if ((32 < e.x && e.x < 63) && (0 < e.y && e.y < 32)) {
		move_type = type_circle;
	}
	else if ((64 < e.x && e.x < 96) && (0 < e.y && e.y < 32)) {
		move_type = type_line;
	}
	else {
		move_type = type_none;
	}
	// 만약 현재 마우스 포인터와 이전 마우스 포인터의 위치가 다를 경우
	if (move_type != move_data) {
		// 바뀐 마우스 포인터가 버튼을 가르킬 경우 색을 바꾼 버튼을 새로 그려준다.
		if (move_type == type_square) {
			square->push_redraw();
		}
		else if (move_type == type_circle) {
			circle->push_redraw();
		}
		else if (move_type == type_line) {
			line->push_redraw();
		}
		// 바뀐 마우스 포인터가 허공을 가르킬 경우 버튼을 원래대로 다시 그려준다.
		else if (move_type == type_none) {
			square->button_draw();
			circle->button_draw();
			line->button_draw();
		}
	}
	move_data = move_type; // 마우스 포인터의 위치를 저장한다.
}

void Toolbar::downButton(Event e) {
	m_startx = e.x;
	m_starty = e.y;

	// x 와 y 는 마우스의 위치를 나타낸다.
	// control key나 shift key등에 따라 다르게 하려면

	// 버튼이 눌리지 않았을 때만 도형을 이전 방식 대로 그린다.

	if (e.ctrlPressed() == true) {	// Ctrl 키를 누른 상태인지 여부
		type = type_line;
	}
	else if (e.shiftPressed() == true) { // Shift 키를 누른 상태인지 여부
		type = type_circle;
	}


	if ((0 < e.x && e.x < 32) && (0 < e.y && e.y < 32)) {
		debugOutput("사각형 ");
		draw_type = draw_prepare;
	}
	else if ((32 < e.x && e.x < 64) && (0 < e.y && e.y < 32)) {
		debugOutput("타원 ");
		draw_type = draw_prepare;
	}
	else if ((64 < e.x && e.x < 96) && (0 < e.y && e.y < 32)) {
		debugOutput("선분 ");
		draw_type = draw_prepare;
	}
	else {
		draw_type = draw_pass;
	}
}

void Toolbar::upButton(Event e) {
	m_endx = e.x;
	m_endy = e.y; // 마지막 위치 저장

	if (draw_type == draw_pass) { // 버튼을 안눌렀을 때

		if (type == type_line) { // 출력 타입이 선분일 경우
			f = new CLine(m_startx, m_starty, m_endx, m_endy, m_data);
		}
		else if (type == type_circle) { // 출력 타입이 타원일 경우
			f = new CEllipse(m_startx, m_starty, m_endx, m_endy, m_data);
		}
		else if (type == type_square) { // 출력 타입이 사각형일 경우
			f = new CRect(m_startx, m_starty, m_endx, m_endy, m_data);
		}
		else { // 아무것도 안눌렀을 경우
			return;
		}
		make.push_back(f);
		m_data->invalidate();
	}
	else if (draw_type == draw_prepare) { // 버튼을 눌렀을 때
		square->button_draw();
		circle->button_draw();
		line->button_draw();
		if ((0 < e.x && e.x < 31) && (0 < e.y && e.y < 32)) {
			type = type_square; // 출력 타입을 사각형으로 설정
		}
		else if ((32 < e.x && e.x < 63) && (0 < e.y && e.y < 32)) {
			type = type_circle; // 출력 타입을 타원으로 설정
		}
		else if ((64 < e.x && e.x < 96) && (0 < e.y && e.y < 32)) {
			type = type_line; // 출력 타입을 선분으로 설정
		}
	}
	//drawText("양윤성", x - (x - plus_x) / 1.75, y - (y - plus_y) / 1.75);
}

void Toolbar::addButton(TButton *data) {

}

void Toolbar::checkInitialize() {
	square = new TButton("R", m_data, 0, 0, 32, 32);
	button.push_back(square);
	m_data->invalidate();
	circle = new TButton("E", m_data, 32, 0, 64, 32);
	button.push_back(circle);
	m_data->invalidate();
	line = new TButton("L", m_data, 64, 0, 96, 32);
	button.push_back(line);
	m_data->invalidate();
}

void Toolbar::allDraw() {
	width = m_data->getWindowWidth();
	m_data->setPenColor(RGB(220, 220, 220));
	m_data->setFillColor(RGB(220, 220, 220));
	m_data->drawRectangle(0, 0, width, 32);
	for (list<MyButton*>::iterator i = button.begin(); i != button.end(); i++) {
		(*i)->button_draw();
	}
	for (list<Figure*>::iterator i = make.begin(); i != make.end(); i++) {
		(*i)->draw();
	}
}