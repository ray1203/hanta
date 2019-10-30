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
	WndClass.cbClsExtra = 0;//Ư���������� ����ϴ� ������ ����(0)
	WndClass.cbWndExtra = 0;//Ư���������� ����ϴ� ������ ����(0)
	WndClass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);//��� ������ ä���� �귯�� ����(�Ͼ��)
	WndClass.hCursor = LoadCursor(NULL, IDC_ARROW);//���콺 Ŀ�� ����(�⺻ Ŀ��)
	WndClass.hIcon = LoadIcon(NULL, IDI_APPLICATION);//������ ������ ����(�⺻ ������)
	WndClass.style = CS_HREDRAW | CS_VREDRAW;//ȭ�� ũ�� ���� �ø��� ����, ���� �ٽ� �׸�
	WndClass.lpszClassName = title;//������ Ŭ���� �̸� ����
	WndClass.lpszMenuName = NULL;//�޴� ���� X
	WndClass.hInstance = GetModuleHandle(NULL);//������ �ڵ� �޾ƿ�
	WndClass.lpfnWndProc = WndProc;//������ �ݹ� �Լ� ���

	if (!RegisterClass(&WndClass)) {
		printf("������ Ŭ���� ��� ����!\n");
		return;
	}
	int wx = (GetSystemMetrics(SM_CXSCREEN) - width) / 2;
	int wy = (GetSystemMetrics(SM_CYSCREEN) - height) / 2;
	hWnd = CreateWindow(title, title, WS_OVERLAPPEDWINDOW,
		wx, wy, width, height,
		0, 0, WndClass.hInstance, 0);
	//������ Ŭ���� �̸� ����, ������ Ÿ��Ʋ �̸�, �������� ����
	//������ġ(ȭ�� �߾�), ������ġ(ȭ�� �߾�), ����ũ��, ����ũ��
	//�θ� ������ �ڵ� ����, �޴� �ڵ� ����, ���α׷� �ڵ� ����, NULL

	ShowWindow(hWnd, SW_SHOWNORMAL);//HWND, ȭ�� ��� ���
}