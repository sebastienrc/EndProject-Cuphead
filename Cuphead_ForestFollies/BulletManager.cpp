#include "pch.h"
#include "BulletManager.h"
#include "utils.h"





BulletManager::BulletManager()
	: m_pItems{}
{

}

BulletManager::~BulletManager()
{
	for (size_t i{}; i < m_pItems.size(); i++)
	{
		delete m_pItems[i];
		m_pItems[i] = nullptr;
	}

	m_pItems.clear();
}


void BulletManager::Draw() const
{
	for (size_t i { 0 }; i  < m_pItems.size(); i++)
	{
		m_pItems[i]->Draw();
	}

}

void BulletManager::Update(float elapsedSec)
{
	for (size_t i{ 0 }; i < m_pItems.size(); i++)
	{
		m_pItems[i]->Update(elapsedSec);
	}

}


size_t BulletManager::Size()
{
	return m_pItems.size();

}


//Bullet* BulletManager::AddItem(Bullet::Type type)
//{
//	Bullet* p{ new Bullet{type} };
//	m_pItems.push_back(p);
//	return p;
//}

bool BulletManager::HitItem(const Rectf& shape)
{
	for (size_t i{ 0 }; i < m_pItems.size(); i++)
	{
		if (m_pItems[i]->IsOverlapping(shape))
		{
			delete m_pItems[i];
			m_pItems[i] = m_pItems.back();
			m_pItems.pop_back();
			return true;
		}
	}

	return false;
}