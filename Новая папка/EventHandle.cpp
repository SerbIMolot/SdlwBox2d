#include "stdafx.h"


EventHandle::EventHandle()
{
	memset( &KEYS, false, sizeof( bool ) * 322 );
	
}


EventHandle::~EventHandle()
{
}

void EventHandle::Update()
{
	while (SDL_PollEvent(&e) != 0)
	{

		//uset request quit
		if (e.type == SDL_QUIT)
		{

			SDL_wrapper::Instance()->quit = true;
			
		}
		
		if (e.type == SDL_MOUSEMOTION || e.type == SDL_MOUSEBUTTONDOWN || e.type == SDL_MOUSEBUTTONUP)
		{
			bool isReleased = false;

			if ( e.type == SDL_MOUSEBUTTONDOWN )
			{
				isReleased = false;
				
			}
			else if ( e.type == SDL_MOUSEBUTTONUP )
			{
				isReleased = true;
			}

			SDL_wrapper::Instance()->onMouseButtonEvent(e.motion.x, e.motion.y, isReleased, e.button.button);
		}

		const Uint8* currentKeyState = SDL_GetKeyboardState(NULL);
	//	SDL_Log("currentstate %d", currentKeyState);
		if (currentKeyState[SDL_SCANCODE_LEFT])
		{
			
		}

		if (currentKeyState[SDL_SCANCODE_RIGHT])
		{
		}
		
		if ( e.type == SDL_KEYDOWN && e.key.repeat == 0 ) 
		{

			KEYS[ e.key.keysym.scancode ] = true;
			SDL_wrapper::Instance()->onKeyPress( e.key.keysym.scancode );
		
		}
		if ( e.type == SDL_KEYUP && e.key.repeat == 0 ) 
		{

			KEYS[ e.key.keysym.scancode ] = false;
			SDL_wrapper::Instance()->onKeyRelease( e.key.keysym.scancode );
			break;
		
		}


	}
	handleInput();
}

void EventHandle::handleInput()
{

	if ( KEYS[ SDL_SCANCODE_LEFT ] )
	{
		BodyManager::Instance()->getPlayer()->move( b2Vec2( 0, 1 ) );
	}
	//if ( !KEYS[ SDL_SCANCODE_LEFT ] )
	//{
	//	SDL_wrapper::Instance()->pl->move( b2Vec2( 0, 1 ) );
	//}
	if ( KEYS[ SDL_SCANCODE_RIGHT ] )
	{
		BodyManager::Instance()->getPlayer()->move( b2Vec2( 0, -1 ) );
	}
	if ( KEYS[ SDL_SCANCODE_SPACE ] )
	{
		BodyManager::Instance()->getPlayer()->jump( );
	}


	/*
	int a = SDL_SCANCODE_TO_KEYCODE(SDLK_LEFT);
	SDL_Log(" SDLKLEFT %d", SDL_SCANCODE_TO_KEYCODE(SDLK_LEFT) );
	SDL_Log(" SDLKLEFT %d", SDLK_LEFT );
	SDL_Log(" SDLKLEFT %d", SDLK_SCANCODE_MASK | SDLK_LEFT );
	if( KEYS[ SDL_SCANCODE_TO_KEYCODE( SDLK_LEFT ) ] == true )
	{
		SDL_wrapper::Instance()->pl->move( b2Vec2( 0, 1 ) );
	}
	if  (KEYS[ SDL_SCANCODE_TO_KEYCODE( SDLK_RIGHT ) ] == true)
	{
		SDL_wrapper::Instance()->pl->move( b2Vec2( 0, -1 ) );
	}

	if( KEYS[ SDL_SCANCODE_TO_KEYCODE( SDLK_LEFT ) ] == false )
	{
		SDL_wrapper::Instance()->pl->move( b2Vec2( 0, 1 ) );
	}
	if ( KEYS[ SDL_SCANCODE_TO_KEYCODE( SDLK_RIGHT ) ] == false )
	{
		SDL_wrapper::Instance()->pl->move( b2Vec2( 0, -1 ) );
	}
	*/
}
