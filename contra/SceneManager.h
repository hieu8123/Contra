#ifndef SCENEMANAGER_H
#define SCENEMANAGER_H

#include "SceneID.h" // Khai báo enum SceneType
#include <cstdio>
#include "BaseScene.h" // Khai báo lớp BaseScene
#include "SceneMenu.h" // Khai báo lớp SceneMenu
#include "Input.h" // Khai báo lớp Input
#include "SceneLoading.h" // Khai báo lớp SceneLoading
#include "ScenePlay.h" // Khai báo lớp ScenePlay
#include "ScenePause.h" // Khai báo lớp ScenePause
#include "SceneGameOver.h" // Khai báo lớp SceneGameOver
#include "SceneWin.h" // Khai báo lớp SceneWin

class SceneMenu;
class ScenePlay;
class SceneLoading;
class SceneGameOver;
class ScenePause;
class SceneWin;

class SceneManager
{
private:
	static SceneManager* m_sceneManager; // Con trỏ tĩnh trỏ tới duy nhất một đối tượng của lớp SceneManager
	BaseScene* m_curScene; // Con trỏ trỏ tới đối tượng lớp BaseScene hiện tại
	SceneType m_typeScene; // Biến kiểu SceneType để lưu loại cảnh đang hiển thị
	SceneMenu* m_sceneMenu; // Con trỏ trỏ tới đối tượng lớp SceneMenu
	SceneLoading* m_sceneLoad; // Con trỏ trỏ tới đối tượng lớp SceneLoading
	ScenePlay* m_scenePlay; // Con trỏ trỏ tới đối tượng lớp ScenePlay
	SceneGameOver* m_sceneOver; // Con trỏ trỏ tới đối tượng lớp SceneGameOver
	ScenePause* m_scenePause; // Con trỏ trỏ tới đối tượng lớp ScenePause
	SceneWin* m_sceneWin; // Con trỏ trỏ tới đối tượng lớp SceneWin

	SceneManager(); // Hàm tạo mặc định là private

public:
	~SceneManager(); // Hàm hủy
	static SceneManager* getInstance(); // Phương thức để lấy thể hiện duy nhất của lớp

	// Các phương thức xử lý cảnh chính
	void draw(); // Phương thức vẽ các đối tượng trong cảnh
	void update(float time); // Phương thức cập nhật trạng thái các đối tượng trong cảnh
	void processInput(); // Phương thức xử lý các sự kiện đầu vào từ người chơi

	// Các phương thức để thay đổi cảnh
	void setScene(BaseScene* x); // Thay đổi cảnh bằng cách truyền đối tượng BaseScene vào
	void setScene(SceneType x); // Thay đổi cảnh bằng cách truyền loại cảnh (SceneType) vào
	BaseScene* getCurScene() { return m_curScene; }; // Phương thức trả về đối tượng lớp BaseScene hiện tại
	SceneType getTypeScene() { return m_typeScene; }; // phương thức trả về loại của scene hiện tại(SceneType).

	// Menu
	void createMenuScene(); // Phương thức tạo cảnh Menu
	void loadMenuScene(); // Phương thức tải cảnh Menu
	void destroyMenuScene(); // Phương thức huỷ cảnh Menu

	// Loading
	void createLoadingScene(); // Phương thức tạo cảnh Loading
	void loadLoadingScene(); // Phương thức tải cảnh Loading
	void destroyLoadingScene(); // Phương thức huỷ cảnh Loading

	// Play
	void createPlayScene(); // Phương thức tạo cảnh Play
	void loadPlayScene(); // Phương thức tải cảnh Play
	void destroyPlayScene(); // Phương thức huỷ cảnh Play

	// Pause
	void createPauseScene(); // Phương thức tạo cảnh Pause
	void loadPauseScene(); // Phương thức tải cảnh Pause
	void destroyPauseScene(); // Phương thức huỷ cảnh Pause

	// GameOver
	void createOverScene(); // Phương thức tạo cảnh GameOver
	void loadOverScene(); // Phương thức tải cảnh GameOver
	void destroyOverScene(); // Phương thức huỷ cảnh GameOver

	// Win
	void createWinScene(); // Phương thức tạo cảnh Win
	void loadWinScene(); // Phương thức tải cảnh Win
	void destroyWinScene(); // Phương thức huỷ cảnh Win
};

#endif