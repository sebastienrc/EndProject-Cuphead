#include "pch.h"
#include "Camera.h"
#include <iostream>


Camera::Camera(float width, float height)
	: m_Width(width)
	, m_Height(height)
	, m_LevelBoundaries{ 0,0,0,0 }
{

}


void Camera::Transform(const Rectf& target) const
{
	glPushMatrix();
	{
		Point2f pos{ Track(target) };
		Clamp(pos);
		glTranslatef(-pos.x, -pos.y, 0);
	}
	glPopMatrix();
}


void Camera::SetLevelBoundaries(const Rectf& levelBoundaries)
{
	m_LevelBoundaries = levelBoundaries;
}

Point2f Camera::Track(const Rectf& target) const
{

	Point2f track(target.left + target.width / 2 - m_Width / 2,
		target.bottom + target.height / 2 - m_Height / 2);

	

	return track;

}


void Camera::Clamp(Point2f& bottomLeftPos) const
{
	if (bottomLeftPos.x < m_LevelBoundaries.left)
	{
		bottomLeftPos.x = m_LevelBoundaries.left;
	}
	else if (bottomLeftPos.x + m_Width > m_LevelBoundaries.left + m_LevelBoundaries.width)
	{
		bottomLeftPos.x = m_LevelBoundaries.left + m_LevelBoundaries.width - m_Width;
	}
	if (bottomLeftPos.y < m_LevelBoundaries.bottom)
	{
		bottomLeftPos.y = m_LevelBoundaries.bottom;
	}
	else if (bottomLeftPos.y + m_Height > m_LevelBoundaries.bottom + m_LevelBoundaries.height)
	{
		bottomLeftPos.y = m_LevelBoundaries.bottom + m_LevelBoundaries.height - m_Height;
	}
}
