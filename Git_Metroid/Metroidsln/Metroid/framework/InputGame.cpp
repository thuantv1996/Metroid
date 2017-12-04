#include "InputGame.h"

InputGame::InputGame()
{
	_DI_Object = NULL;
	_DI_Device = NULL;
}

void InputGame::InitKeyboard(HINSTANCE _hInstance, HWND _hWnd)
{
	HRESULT hr;
	hr = DirectInput8Create
		(
		_hInstance,
		DIRECTINPUT_VERSION,
		IID_IDirectInput8, (VOID**)&_DI_Object, NULL
		);
	if (hr != DI_OK) return;

	hr = _DI_Object->CreateDevice(GUID_SysKeyboard, &_DI_Device, NULL);
	if (hr != DI_OK) return;

	hr = _DI_Device->SetDataFormat(&c_dfDIKeyboard);
	if (hr != DI_OK) return;

	hr = _DI_Device->SetCooperativeLevel(_hWnd, DISCL_FOREGROUND | DISCL_NONEXCLUSIVE);
	if (hr != DI_OK) return;

	DIPROPDWORD dipdw;

	dipdw.diph.dwSize = sizeof(DIPROPDWORD);
	dipdw.diph.dwHeaderSize = sizeof(DIPROPHEADER);
	dipdw.diph.dwObj = 0;
	dipdw.diph.dwHow = DIPH_DEVICE;
	dipdw.dwData = KEYBOARD_BUFFER_SIZE; // Arbitary buffer size

	hr = _DI_Device->SetProperty(DIPROP_BUFFERSIZE, &dipdw.diph);
	if (hr != DI_OK) return;

	hr = _DI_Device->Acquire();
	if (hr != DI_OK) return;
}

InputGame::~InputGame()
{
}

void InputGame::_ProcessKeyBoard(HWND _hWnd)
{

	// Collect all key states first
	_DI_Device->GetDeviceState(sizeof(_KeyStates), _KeyStates);


	if (IsKeyDown(DIK_ESCAPE))
	{
		PostMessage(_hWnd, WM_QUIT, 0, 0);
	}

	// Collect all buffered events
	DWORD dwElements = KEYBOARD_BUFFER_SIZE;
	HRESULT hr = _DI_Device->GetDeviceData(sizeof(DIDEVICEOBJECTDATA), _KeyEvents, &dwElements, 0);

	// Scan through all data, check if the key is pressed or released
	for (DWORD i = 0; i < dwElements; i++)
	{
		int KeyCode = _KeyEvents[i].dwOfs;
		int KeyState = _KeyEvents[i].dwData;
		if ((KeyState & 0x80) > 0)
			OnKeyDown(KeyCode);
		else
			OnKeyUp(KeyCode);
	}
}

int InputGame::IsKeyDown(int KeyCode)
{
	return (_KeyStates[KeyCode] & 0x80) > 0;
}

void  InputGame::OnKeyUp(int KeyCode) {  }

void InputGame::OnKeyDown(int KeyCode) { }

void InputGame::CleanUp()
{

	if (_DI_Device != NULL)
	{
		_DI_Device->Release();
	}

	if (_DI_Object != NULL)
	{
		_DI_Object->Release();
	}

	if (_DI_Device)
	{
		_DI_Device->Unacquire();
		_DI_Device->Release();
	}
}

