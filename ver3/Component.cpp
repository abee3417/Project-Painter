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

void Component::draw(int count) {

}
void Component::redraw() {

}
void Component::tempDraw() {

}
void Component::setView(View *) {

}
void Component::action() {

}

bool Component::inside(int x, int y) {
	return (m_x <= x && x <= m_xplus
		&& 0 <= y && y <= 32);
}