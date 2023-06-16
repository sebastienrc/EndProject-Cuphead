#pragma once
#include "Bullet.h"
#include <vector>
#include "structs.h"


class BulletManager
{
public:

	BulletManager();
	~BulletManager();

	void Draw() const;
	void Update(float elapsedSec);
	
	size_t Size();
	Bullet* AddItem(Bullet::Type type);
	bool HitItem(const Rectf& shape);

private:

	std::vector<Bullet*> m_pItems;



};

