// Đây là một header guard, ngăn chặn tệp header bị bao gồm nhiều lần
#ifndef TILED_H
#define TILED_H

// Bao gồm các tệp header cần thiết
#include "CResourcesManager.h"
#include "Sprite.h"
#include "Config.h"

// Khai báo lớp Tiled
class Tiled
{
private:
	// Các biến thành viên riêng tư của lớp Tiled
	CSprite* m_sprite; // Con trỏ đến đối tượng Sprite
	CCamera* m_camera; // Con trỏ đến đối tượng Camera
	LPD3DXSPRITE m_spriteHandler; // Con trỏ đến đối tượng Direct3D Sprite
	float m_posX; // Vị trí X của đối tượng Tiled
	float m_posY; // Vị trí Y của đối tượng Tiled
	int m_width; // Chiều rộng của đối tượng Tiled
	int m_height; // Chiều cao của đối tượng Tiled
	int m_id; // ID của đối tượng Tiled
	int m_level; // Cấp độ của bản đồ
	int m_index; // Chỉ số của đối tượng Tiled
public:
	// Các phương thức công khai của lớp Tiled
	Tiled(); // Constructor mặc định
	Tiled(int index, int id, float posX, float posY); // Constructor với tham số
	~Tiled(); 	// Phương thức hủy của lớp Tiled
	// Các phương thức của lớp Tiled
	void update(int time); // Cập nhật đối tượng Tiled
	void draw(); // Vẽ đối tượng Tiled
	void init(); // Khởi tạo đối tượng Tiled

	// Các phương thức thiết lập và trả về giá trị của các biến thành viên
	void setID(int x) { m_id = x; }
	int getID() { return m_id; }
	void setWidth(int x) { m_width = x; }
	int getWidth() { return m_width; }
	void setHeight(int x) { m_height = x; }
	int getHeight() { return  m_height; }
	void setPosX(float x) { m_posX = x; }
	float getPosX() { return m_posX; }
	void setPosY(float x) { m_posY = x; }
	float getPosY() { return m_posY; }
};

// Kết thúc header guard
#endif