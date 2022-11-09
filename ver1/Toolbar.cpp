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
	// ���콺 �������� ��ġ�� ��Ȳ���� �ٸ��� ����Ѵ�.
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
	// ���� ���� ���콺 �����Ϳ� ���� ���콺 �������� ��ġ�� �ٸ� ���
	if (move_type != move_data) {
		// �ٲ� ���콺 �����Ͱ� ��ư�� ����ų ��� ���� �ٲ� ��ư�� ���� �׷��ش�.
		if (move_type == type_square) {
			square->push_redraw();
		}
		else if (move_type == type_circle) {
			circle->push_redraw();
		}
		else if (move_type == type_line) {
			line->push_redraw();
		}
		// �ٲ� ���콺 �����Ͱ� ����� ����ų ��� ��ư�� ������� �ٽ� �׷��ش�.
		else if (move_type == type_none) {
			square->button_draw();
			circle->button_draw();
			line->button_draw();
		}
	}
	move_data = move_type; // ���콺 �������� ��ġ�� �����Ѵ�.
}

void Toolbar::downButton(Event e) {
	m_startx = e.x;
	m_starty = e.y;

	// x �� y �� ���콺�� ��ġ�� ��Ÿ����.
	// control key�� shift key� ���� �ٸ��� �Ϸ���

	// ��ư�� ������ �ʾ��� ���� ������ ���� ��� ��� �׸���.

	if (e.ctrlPressed() == true) {	// Ctrl Ű�� ���� �������� ����
		type = type_line;
	}
	else if (e.shiftPressed() == true) { // Shift Ű�� ���� �������� ����
		type = type_circle;
	}


	if ((0 < e.x && e.x < 32) && (0 < e.y && e.y < 32)) {
		debugOutput("�簢�� ");
		draw_type = draw_prepare;
	}
	else if ((32 < e.x && e.x < 64) && (0 < e.y && e.y < 32)) {
		debugOutput("Ÿ�� ");
		draw_type = draw_prepare;
	}
	else if ((64 < e.x && e.x < 96) && (0 < e.y && e.y < 32)) {
		debugOutput("���� ");
		draw_type = draw_prepare;
	}
	else {
		draw_type = draw_pass;
	}
}

void Toolbar::upButton(Event e) {
	m_endx = e.x;
	m_endy = e.y; // ������ ��ġ ����

	if (draw_type == draw_pass) { // ��ư�� �ȴ����� ��

		if (type == type_line) { // ��� Ÿ���� ������ ���
			f = new CLine(m_startx, m_starty, m_endx, m_endy, m_data);
		}
		else if (type == type_circle) { // ��� Ÿ���� Ÿ���� ���
			f = new CEllipse(m_startx, m_starty, m_endx, m_endy, m_data);
		}
		else if (type == type_square) { // ��� Ÿ���� �簢���� ���
			f = new CRect(m_startx, m_starty, m_endx, m_endy, m_data);
		}
		else { // �ƹ��͵� �ȴ����� ���
			return;
		}
		make.push_back(f);
		m_data->invalidate();
	}
	else if (draw_type == draw_prepare) { // ��ư�� ������ ��
		square->button_draw();
		circle->button_draw();
		line->button_draw();
		if ((0 < e.x && e.x < 31) && (0 < e.y && e.y < 32)) {
			type = type_square; // ��� Ÿ���� �簢������ ����
		}
		else if ((32 < e.x && e.x < 63) && (0 < e.y && e.y < 32)) {
			type = type_circle; // ��� Ÿ���� Ÿ������ ����
		}
		else if ((64 < e.x && e.x < 96) && (0 < e.y && e.y < 32)) {
			type = type_line; // ��� Ÿ���� �������� ����
		}
	}
	//drawText("������", x - (x - plus_x) / 1.75, y - (y - plus_y) / 1.75);
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