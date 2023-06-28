#pragma once
#include <vector>
#include "vector2f.h"

class Sprite;
class Level;


class Avatar
{
public:
	enum class playerState
	{
		idle,
		run,
		jump,
		shoot
	};

	enum class aimDirection
	{
		straight,
		up,
		down,
		diagonalUp,
		diagonalDown
	};

	enum class movement
	{
		idle,
		left,
		right,
		down,
		jump
	};

	Avatar();
	~Avatar();

	void Draw() const;
	void Update(float elapsedSec, const Level& level);
	void InitTextures();


	Rectf GetShape() ;

private:
	std::vector<Sprite*> m_pMainCharSprites;

	static int m_SpriteIdx;
	static int m_TimesJumped;

	bool m_IsCrouching;
	bool m_IsShooting;
	bool m_IsMirrored;
	bool m_IsAiming;


	
	movement m_CurrentMovement;
	Point2f m_Pos;
	Vector2f m_Velocity;
	Vector2f m_Acceleration;
	Rectf m_Shape;


	float m_JumpSpeed;
	float m_RunSpeed;


	void KeyboardFunctionality(float elapsedSec);

	void UpdateMovement(float elapsedSec);


};

