#include "pch.h"
#include "Bullet.h"
#include "utils.h"
#include "texture.h"


Bullet::Bullet(Bullet::Type type)
	: m_pTexture	{ nullptr}
	, m_Shape		{}
	, m_Velocity	{0,0}
	, m_IsActive	{}
{



}

Bullet::~Bullet()
{
	delete m_pTexture;
	m_pTexture = nullptr;
}


void Bullet::Draw() const
{
	glPushMatrix();
	{
		glTranslatef(m_Pos.x, m_Pos.y, 0);
		m_Shape;
		//m_pTexture->Draw();
	}
	glPopMatrix();

}


void Bullet::Update(float elapsedSec)
{

	if (m_IsActive)
	{

	}
	m_Pos.x += m_Velocity.x;
	m_Pos.y += m_Velocity.y;

}

bool Bullet::IsOverlapping(const Rectf& rect) const
{
	
	return utils::IsOverlapping(rect, m_Shape);

}

void Bullet::Shoot()
{
	m_IsActive = true;

}
