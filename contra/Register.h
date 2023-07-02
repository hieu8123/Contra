#ifndef REGISTER_H // Tránh trùng lặp thư viện
#define REGISTER_H

#include <d3d9.h> // Thư viện DirectX
#include <d3dx9.h>
#include <Windows.h> // Thư viện Windows
#include "Utils.h"
#define NameClass "Contra Game" // Tên lớp cửa sổ

// Kích thước màn hình
#define SCREEN_WIDTH kScreenWidth
#define SCREEN_HEIGHT kScreenHeight
// Tọa độ của cửa sổ so với màn hình
#define SCREENX (GetSystemMetrics(SM_CXSCREEN) - SCREEN_WIDTH) / 2
#define SCREENY (GetSystemMetrics(SM_CYSCREEN) - SCREEN_HEIGHT) / 2

class CRegister
{
private:
	HINSTANCE m_Hinst; // Thể hiện của chương trình
	HWND m_Hwnd; // Cửa sổ

public:
	CRegister(HINSTANCE hInstance); // Hàm tạo
	CRegister(); // Hàm tạo mặc định
	~CRegister(); // Hàm hủy
	bool initWindow(HINSTANCE hInstance); // Khởi tạo cửa sổ
	//ATOM MyRegisterClass(HINSTANCE hInstance);
	HINSTANCE gethInstance(); // Lấy thể hiện của chương trình
	HWND getHandle(); // Lấy cửa sổ
	static LRESULT WINAPI WinProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam); // Hàm xử lý sự kiện của cửa sổ
};

#endif