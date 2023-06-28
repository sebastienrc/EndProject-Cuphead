#pragma once

#include <vector>
class Sprite;

class Enemies
{
public:
	enum class ennemyType
	{
		acornMachine,
		aggravatingAcorn,
		bothersomeBlueberry,
		deadlyDaisy,
		murderousMushroom,
		terribleTullip,
		spikyBulb,
		toothyTerror
	};




	Enemies();
	~Enemies();
	void virtual Draw() const = 0;
	void Update(float elapsedSec);
	void virtual InitTextures();




private:

	std::vector<Sprite*> m_pEnemiesTextures;
	Point2f m_Pos;
	Rectf	m_Shape;




};

