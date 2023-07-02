#ifndef __UTILS_H_
#define __UTILS_H_

#include <d3d9.h>
#include <string>
#include "Global.h"

using namespace std;

//LPDIRECT3DSURFACE9 CreateSurfaceFromFile(LPDIRECT3DDEVICE9 d3ddv, string FilePath);
void DisplayText(string text);
void GLMessage(string text);
void GLMessage(string text);
LPCWSTR ConvertStringToLPCWSTR(const std::string& str); // convert std::string to LPCWSTR in C++ (Unicode)
LPWSTR ConvertStringToLPWSTR(const std::string& str); // convert std::string to LPWSTR in C++ (Unicode)
#endif