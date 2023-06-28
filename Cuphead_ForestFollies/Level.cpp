#include "pch.h"
#include "Level.h"
#include "Texture.h"
#include "Camera.h"
#include "SVGParser.h"
#include <iostream>



Level::Level()
	:m_Vertices{}
	, m_pMiddlegroundTexture{}
	, m_Boundaries{ 0,50, 23500.f,1200.f}
{
	InitTextures();
	SVGParser::GetVerticesFromSvgFile("levels/runAndGun/mg/mg.svg", m_Vertices);
}

Level::~Level()
{

	for (size_t i{ 0 }; i < m_pMiddlegroundTexture.size(); i++)
	{
		delete m_pMiddlegroundTexture[i];
		m_pMiddlegroundTexture[i] = nullptr;
	}
	m_pMiddlegroundTexture.clear();

	for (size_t i{ 0 }; i < m_pBackgroundTexture.size(); i++)
	{
		delete m_pBackgroundTexture[i];
		m_pBackgroundTexture[i] = nullptr;
	}
	m_pBackgroundTexture.clear();

}

void Level::DrawBackground() const
{
	/*if (m_pBackgroundTexture == nullptr)
		std::cout<< "invalid texture path";*/

	DrawSky();
	DrawBackgroundFar();
	DrawBackgroundClose();
	DrawMiddleGround();
	DrawForeGround();
	
}

void Level::InitTextures()
{
	//Background
		//Sky
	m_pBackgroundTexture.push_back(new Texture{ "levels/runAndGun/sky/bg_sky_1.png" });
	m_pBackgroundTexture.push_back(new Texture{ "levels/runAndGun/sky/bg_sky_2.png" });
		//furthest
	m_pBackgroundTexture.push_back(new Texture{ "levels/runAndGun/BgFurthest/part1.png" });




	//Middleground -- Platform
	m_pMiddlegroundTexture.push_back(new Texture{ "levels/runAndGun/mg/part1.png" });
	m_pMiddlegroundTexture.push_back(new Texture{ "levels/runAndGun/mg/part2.png" });
	m_pMiddlegroundTexture.push_back(new Texture{ "levels/runAndGun/mg/part3.png" });
	m_pMiddlegroundTexture.push_back(new Texture{ "levels/runAndGun/mg/part4.png" });
	m_pMiddlegroundTexture.push_back(new Texture{ "levels/runAndGun/mg/part5.png" });
	m_pMiddlegroundTexture.push_back(new Texture{ "levels/runAndGun/mg/part6.png" });
	m_pMiddlegroundTexture.push_back(new Texture{ "levels/runAndGun/mg/part7.png" });
	m_pMiddlegroundTexture.push_back(new Texture{ "levels/runAndGun/mg/part8.png" });
	m_pMiddlegroundTexture.push_back(new Texture{ "levels/runAndGun/mg/part9.png" });
	m_pMiddlegroundTexture.push_back(new Texture{ "levels/runAndGun/mg/part10.png" });

	

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

void Level::DrawMiddleGround() const
{
	glPushMatrix();
	{
		//Scaling

		glScalef(0.75f, 0.75f, 1);


		//Middleground -- Platform

		m_pMiddlegroundTexture[0]->Draw(Point2f{ 0,0 });
		m_pMiddlegroundTexture[1]->Draw(Point2f{ 2800,220 });
		m_pMiddlegroundTexture[2]->Draw(Point2f{ 5800,-300.f });
		m_pMiddlegroundTexture[3]->Draw(Point2f{ 10600,-200.f });
		m_pMiddlegroundTexture[4]->Draw(Point2f{ 12550,-300.f });
		m_pMiddlegroundTexture[5]->Draw(Point2f{ 15450,-175 });
		m_pMiddlegroundTexture[6]->Draw(Point2f{ 16450,-130 });
		m_pMiddlegroundTexture[7]->Draw(Point2f{ 21500,-600 });
		m_pMiddlegroundTexture[8]->Draw(Point2f{ 25800,-520 });
		m_pMiddlegroundTexture[9]->Draw(Point2f{ 27800,-600 });
	}
	glPopMatrix();
}

void Level::DrawForeGround() const
{

}

void Level::DrawBackgroundClose() const
{

}

void Level::DrawBackgroundFar() const
{
	glPushMatrix();
	{
		glScalef(0.6f, 0.6f, 1);
		m_pBackgroundTexture[2]->Draw(Point2f{ 2400.f , 600.f });

	}
	glPopMatrix();
	}

void Level::DrawSky() const
{

	glPushMatrix();
	{
		glScalef(4, 1, 1);
		m_pBackgroundTexture[0]->Draw(Point2f{-100.f,0});
	}
	glPopMatrix();

	
}

