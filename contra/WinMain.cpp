//#include "GameContra.h"
#include <ctime>
#include <Windows.h>
#include "GameContra.h"
int WINAPI WinMain(HINSTANCE hInstance,        // Tham số chứa handle của ứng dụng
    HINSTANCE hPrevInstance,    // Tham số chứa handle của ứng dụng trước đó
    LPSTR lpCmdLine,            // Tham số chứa các tham số dòng lệnh truyền vào cho ứng dụng
    int nCmdShow) {             // Tham số chứa các thông tin hiển thị cho cửa sổ

	srand((unsigned int)time(NULL));
	GameContra *m_game;
	m_game = new GameContra();
	if (!m_game->initGame(hInstance))
	{
		return 0;
	}

	m_game->runGame();
	m_game->endGame();
	return 1;	
}

