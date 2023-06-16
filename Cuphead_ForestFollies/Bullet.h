#pragma once
#include "vector2f.h"


class Texture;

class Bullet 
{
public:
	enum class Type
	{
		pea,
		spread
	};


	Bullet(Bullet::Type type);
	~Bullet();


	void Update(float elapsedSec);
	void Draw() const;

	void Shoot();

	bool IsOverlapping(const Rectf& rect) const;

private:


	const Texture* m_pTexture;
	Rectf m_Shape;
	Vector2f m_Velocity;
	Point2f m_Pos;

	bool m_IsActive;

};

