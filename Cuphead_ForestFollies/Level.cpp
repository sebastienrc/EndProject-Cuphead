#include "pch.h"
#include "Level.h"
#include "Texture.h"
#include "Camera.h"
#include "SVGParser.h"
#include <iostream>



Level::Level()
	:m_Vertices{}
	, m_pBackgroundTexture{ new Texture{ "levels/runAndGun/mg/mg.png" } }
	, m_Boundaries{ 0,0, 1280.f,800.f}
{

	
	SVGParser::GetVerticesFromSvgFile("levels/runAndGun/mg/mg.svg", m_Vertices);
}

Level::~Level()
{
	delete m_pBackgroundTexture;
	m_pBackgroundTexture = nullptr;
}

void Level::DrawBackground() const
{
	if (m_pBackgroundTexture == nullptr)
		std::cout<< "invalid texture path";


	m_pBackgroundTexture->Draw();
}

void Level::HandleCollision(Point2f& actorLoc, Rectf& actorShape, Vector2f& actorVelocity) const
{
	utils::HitInfo hitInfo{};
	Point2f p1{ actorLoc.x + actorShape.width / 2 ,
				actorLoc.y + actorShape.height };

	Point2f p2{ actorLoc.x + actorShape.width / 2, actorLoc.y };

	if (utils::Raycast(m_Vertices[0], p1, p2, hitInfo))
	{
		actorLoc.y = hitInfo.intersectPoint.y;
		actorVelocity.y = 0;
	}
}


bool Level::IsOnGround(const Rectf& actorShape) const
{
	utils::HitInfo hitInfo{};

	Point2f p1{ actorShape.left + actorShape.width / 2 , actorShape.bottom + actorShape.height };
	Point2f p2{ actorShape.left + actorShape.width / 2 , actorShape.bottom - 1 };

	return (utils::Raycast(m_Vertices[0], p1, p2, hitInfo));

}

Rectf Level::GetBoundaries() const
{
	return m_Boundaries;
}