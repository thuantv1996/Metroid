#pragma once
#include <dinput.h>
#define KEY_DOWN(code) ( IsKeyDown(code) )

#define KEYBOARD_BUFFER_SIZE	1024
class InputGame
{
protected:
	BYTE						_KeyStates[256];
	DIDEVICEOBJECTDATA			_KeyEvents[KEYBOARD_BUFFER_SIZE];
	LPDIRECTINPUT8				_DI_Object;
	LPDIRECTINPUTDEVICE8		_DI_Device;
	HRESULT						_hr;
	int IsKeyDown(int KeyCode);

public:
	virtual void OnKeyDown(int KeyCode);
	virtual void OnKeyUp(int KeyCode);
	void _ProcessKeyBoard(HWND _hWnd);
	void InitKeyboard(HINSTANCE _hInstance, HWND _hWnd);
	void CleanUp();
	InputGame();
	~InputGame();
};

