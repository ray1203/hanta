#include "pch.h"
#include "Window.h"


Window::Window()
{
}


Window::~Window()
{
}

LRESULT Window::WndProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam) {
	switch (iMessage) {
	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
	}
	return(DefWindowProc(hWnd, iMessage, wParam, lParam));
}

void Window::createWindow(const wchar_t* title, int width, int height) {
	HWND hWnd;
	WNDCLASS WndClass;
	ZeroMemory(&WndClass, sizeof(WNDCLASS));
	WndClass.cbClsExtra = 0;//특수목적으로 사용하는 여분의 공간(0)
	WndClass.cbWndExtra = 0;//특수목적으로 사용하는 여분의 공간(0)
	WndClass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);//배경 색상을 채색할 브러시 지정(하얀색)
	WndClass.hCursor = LoadCursor(NULL, IDC_ARROW);//마우스 커서 지정(기본 커서)
	WndClass.hIcon = LoadIcon(NULL, IDI_APPLICATION);//윈도우 아이콘 지정(기본 아이콘)
	WndClass.style = CS_HREDRAW | CS_VREDRAW;//화면 크기 변경 시마다 가로, 세로 다시 그림
	WndClass.lpszClassName = title;//윈도우 클래스 이름 지정
	WndClass.lpszMenuName = NULL;//메뉴 지정 X
	WndClass.hInstance = GetModuleHandle(NULL);//윈도우 핸들 받아옴
	WndClass.lpfnWndProc = WndProc;//윈도우 콜백 함수 등록

	if (!RegisterClass(&WndClass)) {
		printf("윈도우 클래스 등록 실패!\n");
		return;
	}
	int wx = (GetSystemMetrics(SM_CXSCREEN) - width) / 2;
	int wy = (GetSystemMetrics(SM_CYSCREEN) - height) / 2;
	hWnd = CreateWindow(title, title, WS_OVERLAPPEDWINDOW,
		wx, wy, width, height,
		0, 0, WndClass.hInstance, 0);
	//윈도우 클래스 이름 지정, 윈도우 타이틀 이름, 윈도우의 형태
	//가로위치(화면 중앙), 세로위치(화면 중앙), 가로크기, 세로크기
	//부모 윈도우 핸들 지정, 메뉴 핸들 지정, 프로그램 핸들 지정, NULL

	ShowWindow(hWnd, SW_SHOWNORMAL);//HWND, 화면 출력 방법
}