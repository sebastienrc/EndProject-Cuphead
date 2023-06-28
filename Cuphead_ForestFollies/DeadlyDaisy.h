#pragma once

#include "Enemies.h"
#include <vector>


class Sprite;

class DeadlyDaisy	
{
public:
	enum class enemyState
	{
		fall,
		land,
		run,
		turn,
		jump
	};
	DeadlyDaisy();
	~DeadlyDaisy();
	void  Draw() const ;
	void InitTextures();


private:

	std::vector<Sprite*> m_pDeadlyDaisySprites;





};

