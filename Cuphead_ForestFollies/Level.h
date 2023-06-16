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
	void DrawMiddleGround() const;

	void HandleCollision(Point2f& actorLoc, Rectf& actorShape, Vector2f& actorVelocity) const;
	bool IsOnGround(const Rectf& actorShape) const;
	Rectf GetBoundaries() const;

private:
	std::vector <std::vector<Point2f>> m_Vertices;
	Texture* m_pBackgroundTexture;
	Rectf m_Boundaries;




};

