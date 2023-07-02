#ifndef CONTRA_H
#define CONTRA_H

#include "Register.h"
#include "Graphic.h"
#include "Timer.h"
#include "Input.h"
#include "Text.h"
#include "CResourcesManager.h"
#include "SceneManager.h"
#include "Audio.h"

class GameContra
{
private:
    CRegister* m_register;          // Con trỏ đến đối tượng CRegister
    CGraphic* m_graphic;            // Con trỏ đến đối tượng CGraphic
    CTimer* m_timer;                // Con trỏ đến đối tượng CTimer
    CInput* m_input;                // Con trỏ đến đối tượng CInput
    CText* m_text;                  // Con trỏ đến đối tượng CText
    CAudio* m_audio;                // Con trỏ đến đối tượng CAudio
    SceneManager* m_sceneManager;   // Con trỏ đến đối tượng SceneManager

public:
    LPD3DXSPRITE m_spriteHandler;    // Con trỏ đến đối tượng sprite handler
    LPD3DXFONT m_pFont;             // Con trỏ đến đối tượng font

    GameContra();                   // Constructor
    ~GameContra();                  // Destructor

    int initGame(HINSTANCE hInstance);   // Khởi tạo trò chơi
    int runGame();                       // Chạy trò chơi
    int endGame();                       // Kết thúc trò chơi

private:
    void updateWorld(int time);     // Cập nhật thế giới
    void drawWorld();               // Vẽ thế giới
};

#endif 
