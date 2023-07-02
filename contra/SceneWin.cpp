#include "SceneWin.h"

SceneWin::SceneWin()
{
	m_count = 0;
	m_pos = D3DXVECTOR2(130, 240);
	init();
}

SceneWin::~SceneWin()
{

}

void SceneWin::processInput()
{
	if (m_input->onKeyDown(DIK_RETURN))
	{
		if (m_count == 0)
		{
			m_pos.y = 30;
		}
		else if (m_count == 1)
		{
			m_nextScene = true;
		}
	}
}

void SceneWin::init()
{
	m_spCongru = new CSprite(CResourcesManager::GetInstance()->win_congra);
	m_spVictory = new CSprite(CResourcesManager::GetInstance()->win_victory);
	m_music_bg = m_resource->music_win_bg;
	m_audio->playSound(m_music_bg);

}

void SceneWin::draw()
{
	drawBackground(m_pos);
}

void SceneWin::drawBackground(D3DXVECTOR2 pos)
{
	D3DXVECTOR2 posCongru = D3DXVECTOR2(pos.x - 60, pos.y);
	m_spCongru->setPostion(posCongru);
	m_spCongru->Draw(m_spCongru->_pos);

	D3DXVECTOR2 posVictory = D3DXVECTOR2(pos.x - 40, pos.y + 40);
	m_spVictory->setPostion(posVictory);
	m_spVictory->Draw(m_spVictory->_pos);
}

void SceneWin::update(float time)
{
	if (m_nextScene)
	{
		m_audio->stopSound(m_music_bg);
		m_resource->readFileConfiDefault();
		SceneManager::getInstance()->createMenuScene();
	}

	if (m_count == 0)
	{
		if (m_pos.y > 30)
		{
			m_pos.y -= 1;
		}
		else
		{
			m_pos.y = 30;
			m_count = 1;
		}
	}


}

void SceneWin::destroy()
{

}