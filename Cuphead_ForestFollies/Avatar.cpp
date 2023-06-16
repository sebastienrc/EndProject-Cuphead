#include "pch.h"
#include "Avatar.h"
#include "Sprite.h"
#include "Level.h"
#include <iostream>

int Avatar::m_SpriteIdx{ 0 };

Avatar::Avatar() :
	  m_Pos				{Point2f{ 0,650.f }}
	, m_IsCrouching		{false}
	, m_Velocity		{0,0}
	, m_JumpSpeed		{600.f}
	, m_RunSpeed		{400.f}
	, m_Acceleration	{ 0, 0 }
	, m_CurrentMovement	{movement::idle}
	, m_IsShooting		{false}
	, m_IsMirrored		{false}
	, m_IsAiming		{false}
	, m_Shape			{0,0,0,0}

{
	
}

Avatar::~Avatar()
{
	for (size_t i{ 0 }; i < m_pMainCharSprites.size(); i++)
	{
		delete m_pMainCharSprites[i];
		m_pMainCharSprites[i] = nullptr;
	}

	m_pMainCharSprites.clear();
}



void Avatar::Draw() const
{
	glPushMatrix();
	{
		glTranslatef(m_Pos.x, m_Pos.y, 0);

		/*switch (m_CurrentMovement)
		{
		case Avatar::movement::idle:
			if (m_IsAiming)
				m_pMainCharSprites[5]->DrawSprite(m_IsMirrored);
			else if (m_IsShooting)
				m_pMainCharSprites[10]->DrawSprite(m_IsMirrored);
			else
					m_pMainCharSprites[0]->DrawSprite(m_IsMirrored);
			break;
		case Avatar::movement::left:
			if (m_IsAiming)
				m_pMainCharSprites[5]->DrawSprite(m_IsMirrored);
			else if (m_IsShooting)
					m_pMainCharSprites[2]->DrawSprite(m_IsMirrored);
				else
					m_pMainCharSprites[1]->DrawSprite(m_IsMirrored);
			break;
		case Avatar::movement::right:
			if (m_IsAiming)
				m_pMainCharSprites[5]->DrawSprite(m_IsMirrored);
			else if (m_IsShooting)
					m_pMainCharSprites[2]->DrawSprite(m_IsMirrored);
			else
					m_pMainCharSprites[1]->DrawSprite(m_IsMirrored);
			
			break;
		case Avatar::movement::down:
			if (m_IsAiming)
				m_pMainCharSprites[6]->DrawSprite(m_IsMirrored);
			else
					m_pMainCharSprites[3]->DrawSprite(m_IsMirrored);
			break;
		case Avatar::movement::jump:
					m_pMainCharSprites[4]->DrawSprite(m_IsMirrored);
			break;
		default:
			break;
		}*/
		m_pMainCharSprites[m_SpriteIdx]->DrawSprite(m_IsMirrored);
	}
	glPopMatrix();
	}


	

void Avatar::Update(float elapsedSec, const Level& level)
{
	//bool onGround{ level.IsOnGround(GetShape())};

	m_CurrentMovement = movement::idle;

	//RESET -- IDLE --
	/*if (onGround) {
		m_CurrentMovement = movement::idle;

		
	}
	else
	{
		m_Velocity += m_Acceleration * elapsedSec;
	}*/
	KeyboardFunctionality(elapsedSec);
	UpdateMovement(elapsedSec);
	
	
	//MOVEMENT
	if (!m_IsAiming )
	{
		m_Pos.y += m_Velocity.y * elapsedSec;
		m_Pos.x += m_Velocity.x;
	}
	level.HandleCollision(m_Pos, m_Shape, m_Velocity);


	//SPRITE	ANIMATION
	m_pMainCharSprites[m_SpriteIdx]->UpdateSprite(elapsedSec);

}


void Avatar::KeyboardFunctionality(float elapsedSec)
{
	const Uint8* pStates = SDL_GetKeyboardState(nullptr);

	

	// CHECK KEYBOARD STATE  & CHANGING VALUES ACCORDINGLY
	if (pStates[SDL_SCANCODE_X])
	{
		m_IsShooting = true;
		m_SpriteIdx = 10;
	}

	if (pStates[SDL_SCANCODE_C])
	{
		m_IsAiming = true;
		m_SpriteIdx = 5;
	}



	if (pStates[SDL_SCANCODE_DOWN])
	{
		if (m_IsAiming)
		{
			/*if (m_IsShooting)
				m_SpriteIdx = 11;
			else*/
				m_SpriteIdx = 6;
		}
		else if (m_IsShooting)
		{
			m_SpriteIdx = 15;

		}
		else
			m_SpriteIdx = 3;

		m_IsCrouching = true;
		m_CurrentMovement = movement::down;
	}

	

	if (!m_IsCrouching)
	{
		if (pStates[SDL_SCANCODE_UP])
		{
			if (pStates[SDL_SCANCODE_RIGHT])
			{
				m_CurrentMovement = movement::right;
				if (m_IsAiming)
				{
					if (m_IsShooting)
						m_SpriteIdx = 14;
					else
						m_SpriteIdx = 9;
				}
				else if (m_IsShooting)
					m_SpriteIdx = 16;
				else
					m_SpriteIdx = 1;
			}
			else if (pStates[SDL_SCANCODE_LEFT])
			{
				m_CurrentMovement = movement::left;

				if (m_IsAiming)
				{
					if (m_IsShooting)
						m_SpriteIdx = 14;
					else
						m_SpriteIdx = 9;
				}
				else if (m_IsShooting)
					m_SpriteIdx = 16;
				else
					m_SpriteIdx = 1;

			}
			else
				m_CurrentMovement = movement::idle;


			if (m_CurrentMovement == movement::idle) {
				if (m_IsAiming)
				{
					if (m_IsShooting)
						m_SpriteIdx = 12;
					else
						m_SpriteIdx = 7;
				}
				else if (m_IsShooting)
					m_SpriteIdx = 12;
				else
					m_SpriteIdx = 0;
			}			
		}


		else if (pStates[SDL_SCANCODE_RIGHT])
		{

			if (m_IsAiming)
				m_SpriteIdx = 5;
			else if (m_IsShooting)
				m_SpriteIdx = 2;
			else
				m_SpriteIdx = 1;

			m_CurrentMovement = movement::right;


		}
		else if (pStates[SDL_SCANCODE_LEFT])
		{
			
		
				if (m_IsAiming)
					m_SpriteIdx = 5;
				else if (m_IsShooting)
					m_SpriteIdx = 2;
				else
					m_SpriteIdx = 1;
			
			m_CurrentMovement = movement::left;
		}

		else if (pStates[SDL_SCANCODE_SPACE])
		{
			m_CurrentMovement = movement::jump;
			m_SpriteIdx = 4;

		}
	}
		


}


void Avatar::InitTextures()
{

	m_pMainCharSprites.push_back(new Sprite{ "avatar/cuphead_idle.png",5,5,1 / 10.f });
	m_pMainCharSprites.push_back(new Sprite{ "avatar/cuphead_run.png" , 16, 4, 1 / 20.f });
	m_pMainCharSprites.push_back(new Sprite{ "avatar/cuphead_run_shoot.png",16,4,1 / 20.f });
	//m_pMainCharSprites.push_back(new Sprite{ "avatar/crouch_animation.png",7,7,1 / 20.f });
	m_pMainCharSprites.push_back(new Sprite{ "avatar/crouch_idle.png",5,5,1 / 10.f });
	m_pMainCharSprites.push_back(new Sprite{ "avatar/cuphead_jump.png",8,8,1 / 10.f });

	//AIM 5

	m_pMainCharSprites.push_back(new Sprite{ "avatar/aim/aim_straight.png",5,5,1 / 10.f });
	m_pMainCharSprites.push_back(new Sprite{ "avatar/aim/aim_down.png",5,5,1 / 10.f });
	m_pMainCharSprites.push_back(new Sprite{ "avatar/aim/aim_up.png",5,5,1 / 10.f });
	m_pMainCharSprites.push_back(new Sprite{ "avatar/aim/aim_diagonal_down.png",5,5,1 / 10.f });
	m_pMainCharSprites.push_back(new Sprite{ "avatar/aim/aim_diagonal_up.png",5,5,1 / 10.f });

	//SHOOT 10

	m_pMainCharSprites.push_back(new Sprite{ "avatar/shoot/shoot_straight.png",3,3,1 / 10.f });
	m_pMainCharSprites.push_back(new Sprite{ "avatar/shoot/shoot_down.png",3,3,1 / 10.f });
	m_pMainCharSprites.push_back(new Sprite{ "avatar/shoot/shoot_up.png",3,3,1 / 10.f });
	m_pMainCharSprites.push_back(new Sprite{ "avatar/shoot/shoot_diagonal_down.png",3,3,1 / 10.f });
	m_pMainCharSprites.push_back(new Sprite{ "avatar/shoot/shoot_diagonal_up.png",3,3,1 / 10.f });

	//15

	m_pMainCharSprites.push_back(new Sprite{ "avatar/crouch_shoot.png",3,3,1 / 10.f });

	m_pMainCharSprites.push_back(new Sprite{ "avatar/shoot_run_diagonal_up.png",16,4,1 / 20.f });
}

void Avatar::UpdateMovement(float elapsedSec)
{

		switch (m_CurrentMovement)
		{
		case Avatar::movement::idle:
			m_Velocity = Vector2f{ 0,0 };
			m_SpriteIdx = 0;
			m_IsCrouching = false;
			m_IsShooting = false;
			m_IsAiming = false;
			break;

		case Avatar::movement::left:
			m_IsMirrored = true;
			m_Velocity.x = -m_RunSpeed * elapsedSec;
			break;

		case Avatar::movement::right:
			m_IsMirrored = false;
			m_Velocity.x = m_RunSpeed * elapsedSec;
			break;

		case Avatar::movement::jump:
			m_Velocity.y = m_JumpSpeed;
			break;
		default:
			break;
		}
		m_Velocity += m_Acceleration * elapsedSec;
		
		//std::cout << "(" << m_Shape.left << ", " << m_Shape.bottom << ")" << std::endl;
		
	
}


Rectf Avatar::GetShape() 
{
	Rectf shape{ m_pMainCharSprites[m_SpriteIdx]->GetShape()};

	shape.bottom = m_Pos.y;
	shape.left = m_Pos.x;

	m_Shape = shape;


	return shape;
}