#ifndef CSNIPERBLOCK_H
#define CSNIPERBLOCK_H

#include "CEnemyUseGun.h"

class CSniperBlock
	:public CEnemyUseGun
{
private:

public:
	CSniperBlock(int id, SpecificType specific_type, D3DXVECTOR3 pos, int width, int height);
	~CSniperBlock();

	void LoadResources();
	void Draw();
	void Update(int delta_time);
	void SetTarget(float x, float y);

	void DrawWhenAttack(D3DXVECTOR3 pos);
	void DrawWhenWait(D3DXVECTOR3 pos);
	void DrawWhenDie(D3DXVECTOR3 pos);
	void Attacking();


};



#endif