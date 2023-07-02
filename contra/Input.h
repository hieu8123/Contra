#pragma once
#ifndef INPUT_H_
#define INPUT_H_

#include <dinput.h>

#define KEYBOARD_BUFFER_SIZE 1024 // Kích thước của buffer cho bàn phím
#define BUTTON_DOWN(obj, button) (obj.rgbButtons[button] & 0x80) //Kiểm tra trạng thái của button trên chuột

#define DIRECTINPUT_VERSION 0x0800 // Phiên bản DirectInput

class CInput
{
private:
	LPDIRECTINPUTDEVICE8 m_dinputkeyboard; // Đối tượng thiết bị nhập liệu cho bàn phím
	DIDEVICEOBJECTDATA m_keyEvents[KEYBOARD_BUFFER_SIZE]; // Dữ liệu nhận từ bàn phím
	BYTE m_keystate[256]; // Trạng thái phím hiện tại
	int m_keyDown; // Số lần nhấn phím
	int m_keyUp; // Số lần thả phím
	BYTE m_lastState[256]; // Trạng thái phím trước đó
	LPDIRECTINPUT8 m_dinput; // Đối tượng DirectInput
public:
	CInput(void);
	CInput(HINSTANCE hInstance);
	~CInput(void);
	int initInput(HINSTANCE hInstance); // Khởi tạo đối tượng DirectInput
	int initKeyboard(HWND); // Khởi tạo đối tượng thiết bị nhập liệu cho bàn phím
	void pollKeyBoard(); // Lấy dữ liệu từ bàn phím
	void killKeyboard(); // Huỷ thiết bị nhập liệu cho bàn phím
	int KeyDown(int); // Đếm số lần nhấn phím
	void processKeyBoard(); // Xử lý dữ liệu từ bàn phím
	bool onKeyDown(int); // Kiểm tra xem có phím nào đang được nhấn xuống không
	bool onKeyUp(int); // Kiểm tra xem có phím nào được thả ra không
	LPDIRECTINPUTDEVICE8 getKeyBoard(); // Lấy đối tượng thiết bị nhập liệu cho bàn phím
};

#endif // INPUT_H_