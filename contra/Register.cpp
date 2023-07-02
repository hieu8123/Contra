#include "Register.h"

CRegister::CRegister()
{

};

CRegister::CRegister(HINSTANCE hInstance)
{
	this->m_Hinst = hInstance;
}


bool CRegister::initWindow(HINSTANCE hInstance)
{
	WNDCLASSEX wc;
	wc.cbSize = sizeof(WNDCLASSEX); // Đặt kích thước của WNDCLASSEX
	wc.style = CS_HREDRAW | CS_VREDRAW; // Đặt kiểu lớp cửa sổ để xử lý sự kiện vẽ lại khi kích thước hoặc vị trí của cửa sổ thay đổi
	wc.lpfnWndProc = (WNDPROC)WinProc; // Con trỏ đến hàm xử lý sự kiện cho cửa sổ
	wc.cbClsExtra = 0; // Không sử dụng bộ nhớ dự phòng lớp
	wc.cbWndExtra = 0; // Không sử dụng bộ nhớ dự phòng cửa sổ
	wc.hInstance = hInstance; // Con trỏ đến instance của chương trình
	wc.hIcon = NULL; // Không sử dụng biểu tượng
	wc.hCursor = LoadCursor(NULL, IDC_ARROW); // Sử dụng con trỏ chuột mặc định
	wc.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH); // Đặt màu nền của cửa sổ
	wc.lpszMenuName = NULL; // Không sử dụng menu
	wc.lpszClassName = ConvertStringToLPCWSTR(NameClass); // Đặt tên lớp cửa sổ
	wc.hIconSm = NULL; // Không sử dụng biểu tượng nhỏ
	RegisterClassEx(&wc);
	this->m_Hwnd = CreateWindowEx(
		0, // dwExStyle: Thông số mở rộng của cửa sổ, trong trường hợp này không có
		ConvertStringToLPCWSTR(NameClass), // lpClassName: Tên lớp cửa sổ được đăng ký trước đó
		ConvertStringToLPCWSTR(NameClass), // lpWindowName: Tiêu đề của cửa sổ
		WS_OVERLAPPEDWINDOW, // dwStyle: Kiểu của cửa sổ, gồm WS_OVERLAPPED, WS_SYSMENU và WS_MINIMIZEBOX
		SCREENX, // X: Vị trí của cửa sổ trên trục x
		SCREENY, // Y: Vị trí của cửa sổ trên trục y
		SCREEN_WIDTH, // nWidth: Độ rộng của cửa sổ
		SCREEN_HEIGHT, // nHeight: Chiều cao của cửa sổ
		NULL, // hWndParent: Handle của cửa sổ cha, trong trường hợp này không có
		NULL, // hMenu: Handle của menu, trong trường hợp này không có
		hInstance, // hInstance: Handle của chương trình đang chạy
		NULL); // lpParam: Con trỏ tùy chọn, trong trường hợp này không có
	if (!this->m_Hwnd)
		return false;
	ShowWindow(this->m_Hwnd, SW_SHOW);
	UpdateWindow(this->m_Hwnd);
	return true;
}

HINSTANCE CRegister::gethInstance()
{
	return this->m_Hinst;
}

HWND CRegister::getHandle()
{
	return this->m_Hwnd;
}

LRESULT WINAPI CRegister::WinProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	}

	return DefWindowProc(hWnd, message, wParam, lParam);
}

CRegister::~CRegister()
{
}