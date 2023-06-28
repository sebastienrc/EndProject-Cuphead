#include "pch.h"
#include "Game.h"

Game::Game( const Window& window ) 
	: BaseGame	{window}
	, m_Window{ window }
	, m_Camera{window.width,window.height}
{
	Initialize();
}

Game::~Game( )
{
	Cleanup( );

}

void Game::Initialize( )
{
	m_pCurrentPlayer = new Avatar{};
	m_pLevel = new Level{};
	m_pCurrentPlayer->InitTextures();
	m_Camera.SetLevelBoundaries(m_pLevel->GetBoundaries());
	
}

void Game::Cleanup( )
{
	delete m_pCurrentPlayer;
	m_pCurrentPlayer = nullptr;
	delete m_pLevel;
	m_pLevel = nullptr;
}

void Game::Update( float elapsedSec )
{
	// Check keyboard state
	//const Uint8 *pStates = SDL_GetKeyboardState( nullptr );
	//if ( pStates[SDL_SCANCODE_RIGHT] )
	//{
	//	std::cout << "Right arrow key is down\n";
	//}
	//if ( pStates[SDL_SCANCODE_LEFT] && pStates[SDL_SCANCODE_UP])
	//{
	//	std::cout << "Left and up arrow keys are down\n";
	//}

	m_pCurrentPlayer->Update(elapsedSec,*m_pLevel);

}

void Game::Draw( ) const
{
	ClearBackground( );
	glPushMatrix();
	{
		m_Camera.Transform(m_pCurrentPlayer->GetShape());
		m_pLevel->DrawBackground();
		m_pCurrentPlayer->Draw();
	}
	glPopMatrix();
	
	

	
}

void Game::ProcessKeyDownEvent( const SDL_KeyboardEvent & e )
{
	//std::cout << "KEYDOWN event: " << e.keysym.sym << std::endl;

	//switch (e.keysym.sym)
	//{
	//case SDLK_DOWN:
	//	//m_pCurrentPlayer->SpriteIdx(3);
	//	m_CurrentMovement = Avatar::movement::crouch;
	//	break;
	///*case SDLK_RIGHT:
	//	m_pCurrentPlayer->SpriteIdx(1);
	//	m_CurrentMovement	= Avatar::movement::right;

	//	break;
	//case SDLK_LEFT:
	//	m_pCurrentPlayer->SpriteIdx(1);
	//	m_CurrentMovement = Avatar::movement::left;
	//	break;*/
	//case SDLK_UP:
	//	//m_pCurrentPlayer->SpriteIdx(4);
	//	m_CurrentMovement = Avatar::movement::jump;
	//	break;
	//default:
	//	break;
	//}
}

void Game::ProcessKeyUpEvent( const SDL_KeyboardEvent& e )
{
	switch ( e.keysym.sym )
	{

	case SDLK_1:
	case SDLK_KP_1:
		//std::cout << "Key 1 released\n";
		break;
	default:
		//m_CurrentMovement = Avatar::movement::idle;
		//m_pCurrentPlayer->SpriteIdx(0);
		break;
	}
}

void Game::ProcessMouseMotionEvent( const SDL_MouseMotionEvent& e )
{
	//std::cout << "MOUSEMOTION event: " << e.x << ", " << e.y << std::endl;
}

void Game::ProcessMouseDownEvent( const SDL_MouseButtonEvent& e )
{
	//std::cout << "MOUSEBUTTONDOWN event: ";
	//switch ( e.button )
	//{
	//case SDL_BUTTON_LEFT:
	//	std::cout << " left button " << std::endl;
	//	break;
	//case SDL_BUTTON_RIGHT:
	//	std::cout << " right button " << std::endl;
	//	break;
	//case SDL_BUTTON_MIDDLE:
	//	std::cout << " middle button " << std::endl;
	//	break;
	//}
	
}

void Game::ProcessMouseUpEvent( const SDL_MouseButtonEvent& e )
{
	//std::cout << "MOUSEBUTTONUP event: ";
	//switch ( e.button )
	//{
	//case SDL_BUTTON_LEFT:
	//	std::cout << " left button " << std::endl;
	//	break;
	//case SDL_BUTTON_RIGHT:
	//	std::cout << " right button " << std::endl;
	//	break;
	//case SDL_BUTTON_MIDDLE:
	//	std::cout << " middle button " << std::endl;
	//	break;
	//}
}

void Game::ClearBackground( ) const
{
	glClearColor( 0.0f, 0.0f, 0.3f, 1.0f );
	glClear( GL_COLOR_BUFFER_BIT );
}
