#include<Windows.h>
#include"framework\GraphicsDevice.h"
#include"framework\GameSprite.h"
#include"object\Player.h"
#include"framework\GameTime.h"
/*prototype function*/
bool GenerateWindow(HINSTANCE hInstance, int nCmdShow, LPCSTR className, LPCSTR windowTitle, int width, int height,HWND& hWnd);
bool GenerateWindow(HINSTANCE hInstance, int nCmdShow, LPCSTR className, LPCSTR windowTitle, int x, int y, int width, int height, HWND& hWnd);
LRESULT CALLBACK WinProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);

/* WinMain */
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	HWND hWnd;
	if (GenerateWindow(hInstance, nCmdShow, "MyWindow", "MyGame", 550, 550,hWnd))
	{
		MSG msg;
		ZeroMemory(&msg, sizeof(msg));
		float tickPerFrame = 1.0f / 60, delta = 0;
		GraphicsDevice::GetInstance()->Init(hWnd, true);
		GameSprite::getInstance()->Init(GraphicsDevice::GetInstance()->device);
		Player::getInstance()->Init();
			while (msg.message != WM_QUIT)
			{
				GameTime::GetInstance()->StartCounter();

				if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
				{
					TranslateMessage(&msg);
					DispatchMessage(&msg);
				}
				delta += GameTime::GetInstance()->GetCouter();

				if (delta >= tickPerFrame)
				{
					Player::getInstance()->Update(delta);

					GraphicsDevice::GetInstance()->Clear(D3DCOLOR_XRGB(0,0,0));
					GraphicsDevice::GetInstance()->Begin();
					GameSprite::getInstance()->Begin();

					Player::getInstance()->Render(delta);

					GameSprite::getInstance()->End();
					GraphicsDevice::GetInstance()->End();
					GraphicsDevice::GetInstance()->Present();
					delta = 0;
				}
				else
				{
					Sleep(tickPerFrame - delta);
					delta = tickPerFrame;
				}
			
			
			
		}
	}
	return 1;
}

bool GenerateWindow(HINSTANCE hInstance, int nCmdShow, LPCSTR className, LPCSTR windowTitle, int x, int y, int width, int height, HWND& hWnd)
{
	WNDCLASSEX wc;
	ZeroMemory(&wc, sizeof(wc));
	wc.cbSize = sizeof(WNDCLASSEX);
	wc.lpfnWndProc = WinProc;
	wc.hInstance = hInstance;
	wc.lpszClassName = className;
	wc.style = CS_HREDRAW | CS_VREDRAW;
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);
	wc.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	wc.hIconSm = NULL;
	wc.lpszMenuName = NULL;
	wc.cbClsExtra = 0;
	wc.cbWndExtra = 0;
	wc.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH);
	if (!RegisterClassEx(&wc))
	{
		return false;
	}
	hWnd = CreateWindowEx(NULL, className, windowTitle, WS_OVERLAPPEDWINDOW, x, y, width, height, NULL, NULL, hInstance, NULL);
	ShowWindow(hWnd, nCmdShow);
	UpdateWindow(hWnd);
	return true;
}
bool GenerateWindow(HINSTANCE hInstance, int nCmdShow, LPCSTR className, LPCSTR windowTitle, int width, int height, HWND& hWnd)
{
	return GenerateWindow(hInstance, nCmdShow, className, windowTitle, GetSystemMetrics(SM_CXSCREEN) / 2 - width / 2,
		GetSystemMetrics(SM_CYSCREEN) / 2 - height / 2, width, height,hWnd);
}

LRESULT CALLBACK WinProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{
	case WM_DESTROY:
	{
					   PostQuitMessage(0);
					   return 0;
	}
	default:
		break;
	}
	return DefWindowProc(hWnd, message, wParam, lParam);
}



