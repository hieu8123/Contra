#include <d3dx9.h>
#include "Utils.h"

void DisplayText(string text)
{
	D3DCOLOR fontColor = D3DCOLOR_ARGB(255, 0, 0, 255);

	RECT rct;
	rct.left = 2;
	rct.right = kScreenWidth;
	rct.top = 10;
	rct.bottom = rct.top + 20;

	// Draw some text
	kFont->DrawText(NULL, ConvertStringToLPCWSTR(text), -1, &rct, 0, fontColor);
}

void GLMessage(string text)
{
	MessageBox(kHWND, ConvertStringToLPCWSTR(text), ConvertStringToLPCWSTR("Voice"), MB_OK);
}

LPCWSTR ConvertStringToLPCWSTR(const std::string& str) {
	int wstr_size = MultiByteToWideChar(CP_UTF8, 0, str.c_str(), -1, NULL, 0); // tính toán số lượng ký tự cần để lưu chuỗi ký tự rộng
	wchar_t* wstr = new wchar_t[wstr_size]; // cấp phát bộ nhớ để lưu chuỗi ký tự rộng
	MultiByteToWideChar(CP_UTF8, 0, str.c_str(), -1, wstr, wstr_size); // chuyển đổi chuỗi ký tự sang chuỗi ký tự rộng
	return wstr; // trả về con trỏ đến chuỗi ký tự rộng
}
LPWSTR ConvertStringToLPWSTR(const std::string& str) {
	int size = MultiByteToWideChar(CP_UTF8, 0, str.c_str(), -1, NULL, 0);
	LPWSTR result = new WCHAR[size];
	MultiByteToWideChar(CP_UTF8, 0, str.c_str(), -1, result, size);
	return result;
}
