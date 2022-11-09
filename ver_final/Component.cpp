#include "stdafx.h"
#include "Component.h"

LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);  // Prototype to external fun
ATOM Component::MyRegisterClass(HINSTANCE hInstance)		//  용도: 창 클래스를 등록합니다.
{
	WNDCLASSEXW wcex;

	wcex.cbSize = sizeof(WNDCLASSEX);

	wcex.style = CS_HREDRAW | CS_VREDRAW;
	wcex.lpfnWndProc = WndProc;
	wcex.cbClsExtra = 0;
	wcex.cbWndExtra = 0;
	wcex.hInstance = hInstance;
	wcex.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_PROJ2018));
	wcex.hCursor = LoadCursor(nullptr, IDC_ARROW);
	wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
	wcex.lpszMenuName = NULL; //  MAKEINTRESOURCEW(IDC_PROJ2018);
	wcex.lpszClassName = szWindowClass;
	wcex.hIconSm = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

	return RegisterClassExW(&wcex);
}

Component::Component(std::string title)
	:m_title(title)
{
}

Component::Component(View *data)
	:m_view(data)
{
}

Component::Component(HINSTANCE hInstance) : m_InstanceHandle(hInstance) {
	m_InstanceHandle = hInstance;
	LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
	LoadStringW(hInstance, IDC_PROJ2018, szWindowClass, MAX_LOADSTRING);
	MyRegisterClass(hInstance);
}

Component::~Component()
{
}

void Component::drawTButton(int count) {

}
void Component::redrawTButton() {

}
void Component::ccdrawTButton() {

}
void Component::drawMenu(int count) {

}
void Component::redrawMenu() {

}
void Component::ccdrawMenu() {

}
void Component::drawFileMenu(int count) {

}
void Component::redrawFileMenu() {

}
void Component::ccdrawFileMenu() {

}
void Component::drawSetMenu(int count) {

}
void Component::redrawSetMenu() {

}
void Component::ccdrawSetMenu() {

}
void Component::drawLineSetMenu(int count) {

}
void Component::redrawLineSetMenu() {

}
void Component::ccdrawLineSetMenu() {

}
void Component::drawFillSetMenu(int count) {

}
void Component::redrawFillSetMenu() {

}
void Component::ccdrawFillSetMenu() {

}
void Component::setView(View *) {

}
void Component::setView2(View *) {

}
void Component::action() {

}
void Component::makeRectIcon() {

}
void Component::makeEllipseIcon() {

}
void Component::makeLineIcon() {

}
void Component::makeRLIcon() {

}
void Component::makeGLIcon() {

}
void Component::makeBLIcon() {

}
void Component::makeOLIcon() {

}
void Component::makeRFIcon() {

}
void Component::makeGFIcon() {

}
void Component::makeBFIcon() {

}
void Component::makeOFIcon() {

}
void Component::makeEraseIcon() {

}
void Component::makeAllEraseIcon() {

}
bool Component::insideTButton(int x, int y) {
	return (m_x1 <= x && x <= m_xplus1
		&& 32 <= y && y <= 64);
}

bool Component::insideMenu(int x, int y) {
	return (m_x2 <= x && x <= m_xplus2
		&& 0 <= y && y <= 32);
}

bool Component::insideFileMenu(int x, int y) {
	return (0 <= x && x <= 48
		&& m_y1 <= y && y <= m_yplus1);
}

bool Component::insideSetMenu(int x, int y) {
	return (48 <= x && x <= 96
		&& m_y2 <= y && y <= m_yplus2);
}

bool Component::insideLineMenu(int x, int y) {
	return (96 <= x && x <= 144
		&& m_y3 <= y && y <= m_yplus3);
}

bool Component::insideFillMenu(int x, int y) {
	return (144 <= x && x <= 192
		&& m_y4 <= y && y <= m_yplus4);
}

void Component::addToolbarListener(ToolbarActionListener *l) {

}

void Component::addMenuListener(MenuActionListener *l) {

}

void Component::addMenubarListener(MenubarActionListener *l) {

}
