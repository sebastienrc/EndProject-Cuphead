#include "pch.h"
#include "Sprite.h"
#include "Texture.h"
#include <iostream>

Sprite::Sprite(std::string path,int frames, int cols, float animationTime) :
	  m_pSpriteTexture	{nullptr}
	, m_Frames			{frames}
	, m_Cols			{cols}
	, m_FrameTime		{animationTime}
	, m_CurrentFrame	{0}
	, m_AccumulatedTime	{0}
	, m_Scale			{1.f}
	, m_SrcRect			{0,0,0,0}
{
	m_pSpriteTexture = new Texture{ path };
	if (m_pSpriteTexture == nullptr)
		throw "couldn t load sprite";

	m_SrcRect.width = m_pSpriteTexture->GetWidth() / m_Cols;
	m_SrcRect.height = m_pSpriteTexture->GetHeight() / (m_Frames / m_Cols);
	m_SrcRect.bottom = (m_CurrentFrame / m_Cols + 1) * m_SrcRect.height;
	m_SrcRect.left = (m_CurrentFrame % m_Cols) * m_SrcRect.width;
}

void Sprite::DrawSprite(bool isMirrored) const
{
	Rectf srcRect{};
	srcRect.width	= m_pSpriteTexture->GetWidth() / m_Cols;
	srcRect.height	= m_pSpriteTexture->GetHeight() / (m_Frames / m_Cols);
	srcRect.bottom  = (m_CurrentFrame / m_Cols + 1) * srcRect.height;
	srcRect.left	= (m_CurrentFrame % m_Cols) * srcRect.width;

	Rectf dstRect{};

	dstRect.left	= 0;
	dstRect.bottom	= 0;
	dstRect.width	= srcRect.width	* m_Scale;
	dstRect.height  = srcRect.height	* m_Scale;

	if(isMirrored)
	{
		glPushMatrix();
		{
			glScalef(-1, 1, 1);
			dstRect.left -= dstRect.width / 2;
			m_pSpriteTexture->Draw(dstRect, srcRect);
		}
		glPopMatrix();
		return;
	}

	m_pSpriteTexture->Draw(dstRect, srcRect);
}


void Sprite::UpdateSprite(float elapsedSec)
{
	m_AccumulatedTime += elapsedSec;
	//std::cout<<m_CurrentFrame<<std::endl;

	if (m_AccumulatedTime > m_FrameTime)
	{
		++m_CurrentFrame	%= m_Frames;
		m_AccumulatedTime	-= m_FrameTime;	
	}

	
}

Sprite::~Sprite() 
{
	delete m_pSpriteTexture;
}


Rectf Sprite::GetShape()
{
	Rectf shape{0,0,0,0};

	shape		= m_SrcRect;

	shape.width	= m_SrcRect.width * m_Scale;
	shape.height= m_SrcRect.height * m_Scale;

	return shape;

	
}