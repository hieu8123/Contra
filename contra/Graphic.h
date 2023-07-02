#ifndef GRAPHIC_H    // Ngăn chặn lỗi trùng lặp trong quá trình biên dịch
#define GRAPHIC_H

#include <d3d9.h>
#include <d3dx9.h>
#include "Global.h"
class CGraphic
{
private:
    LPDIRECT3D9 m_pd3d;    // Con trỏ đến đối tượng Direct3D9
    LPDIRECT3DDEVICE9 m_pd3Device;    // Con trỏ đến đối tượng Direct3D9Device
    IDirect3DSurface9* m_backbuffer;    // Con trỏ đến đối tượng Surface

public:
    CGraphic();    // Constructor của class
    ~CGraphic();    // Destructor của class

    bool initDevice(HWND _hWnd);    // Hàm khởi tạo thiết bị Direct3D9
    LPDIRECT3D9 getPd3d();    // Trả về con trỏ đến đối tượng Direct3D9
    LPDIRECT3DDEVICE9 getPd3Device();    // Trả về con trỏ đến đối tượng Direct3D9Device
    IDirect3DSurface9* getBackbuffer();    // Trả về con trỏ đến đối tượng Surface

    void releaseDevice();    // Hàm giải phóng bộ nhớ của thiết bị Direct3D9
    void beginRender();    // Hàm bắt đầu quá trình vẽ
    void endRender();    // Hàm kết thúc quá trình vẽ
};

#endif    // Kết thúc phần định nghĩa của file header.
