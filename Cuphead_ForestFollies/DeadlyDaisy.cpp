#include "pch.h"
#include "DeadlyDaisy.h"
#include "Sprite.h"

DeadlyDaisy::DeadlyDaisy()
{

}

DeadlyDaisy::~DeadlyDaisy()
{
	for (size_t i{ 0 }; i < m_pDeadlyDaisySprites.size(); i++)
	{
		delete m_pDeadlyDaisySprites[i];
		m_pDeadlyDaisySprites[i] = nullptr;
	}

	m_pDeadlyDaisySprites.clear();

}

void DeadlyDaisy::InitTextures()
{
	m_pDeadlyDaisySprites.push_back(new Sprite{ "enemies/deadlyDaisy/daisyFall.png",15,4,1/20.f });
	m_pDeadlyDaisySprites.push_back(new Sprite{ "enemies/deadlyDaisy/daisyStart.png",8,2,1/20.f });
	m_pDeadlyDaisySprites.push_back(new Sprite{ "enemies/deadlyDaisy/daisyFloat.png",21,5,1/20.f });
	//m_pDeadlyDaisySprites.push_back(new Sprite{ "enemies/deadlyDaisy/daisyLand.png" });

}