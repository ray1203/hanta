#pragma once
class Window
{
public:
	Window();
	~Window();
	void createWindow(const wchar_t* title, int width, int height);
	static LRESULT CALLBACK WndProc(HWND hWnd, UINT iMessagem, WPARAM wParam, LPARAM lParam);
};