#pragma once

#include <vector>
#include "utils.h"

class Texture;

class Level
{
public:
	Level();
	~Level();

	void DrawBackground() const;

	void HandleCollision(Point2f& actorLoc, Rectf& actorShape, Vector2f& actorVelocity) const;
	bool IsOnGround(const Rectf& actorShape) const;
	Rectf GetBoundaries() const;

private:
	std::vector <std::vector<Point2f>> m_Vertices;
	std::vector <Texture*> m_pMiddlegroundTexture;
	std::vector <Texture*> m_pBackgroundTexture;
	std::vector <Texture*> m_pForegroundTexture;


	Rectf m_Boundaries;

	void InitTextures();
	
	void DrawMiddleGround() const;
	void DrawForeGround() const;
	void DrawBackgroundClose() const;
	void DrawBackgroundFar() const;
	void DrawSky() const;


};

