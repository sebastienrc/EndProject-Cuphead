#pragma once
class Texture;


class Sprite
{
	
public:

	Sprite(std::string path, int frames, int cols, float animationTime);
	~Sprite();

	void DrawSprite(bool isMirrored) const;
	void UpdateSprite(float elapsedSec);

	Rectf GetShape() ;

private:
	Texture* m_pSpriteTexture;
	int		m_Frames;
	int		m_Cols;
	float	m_FrameTime;
	int		m_CurrentFrame;
	float	m_AccumulatedTime;
	float	m_Scale;

	Rectf m_SrcRect;
;





};

