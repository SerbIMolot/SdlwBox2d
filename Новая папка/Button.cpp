#include "stdafx.h"
#include "Button.h"


Button::Button( b2Vec2 vec, float w, float h , std::string text )
{
	pos = std::move( vec );
	buttonFont1 = std::make_unique< NFont >( SDL_wrapper::gRenderer, "Data/FreeSans.ttf", 60, NFont::Color( 0, 0, 0, 255) );

	rect = std::make_shared< b2AABB >( pos, w, h );

	this->text = text;

	pressed = false;
}

Button::Button( int x, int y, int w, int h , std::string text )
{
	pos = std::make_shared< b2Vec2 >( x, y );
	buttonFont1 = std::make_unique< NFont >(SDL_wrapper::gRenderer, "Data/FreeSans.ttf", 60, NFont::Color(0, 0, 0, 255));
	rect = std::make_shared< b2AABB >( pos, w, h );

	this->text = text;
	
	pressed = false;
}

Button::Button( float x, float y, float w, float h , std::string text )
{
	pos = std::make_shared< b2Vec2 >( x, y );
	buttonFont1 = std::make_unique< NFont >(SDL_wrapper::gRenderer, "Data/FreeSans.ttf", 60, NFont::Color(0, 0, 0, 255));
	rect = std::make_shared< b2AABB >( pos, w, h );

	this->text = text;

	pressed = false;
}


Button::~Button()
{
}

std::shared_ptr<b2AABB> Button::getb2AABB()
{
	return rect;
}

b2Vec2 Button::Pos()
{
	return pos;
}

void Button::Draw()
{
	if ( pressed == false )
	{
		
		SDL_SetRenderDrawColor(SDL_wrapper::gRenderer, 169, 169, 169, 255); // the 
		
		

		SDL_RenderFillRect( SDL_wrapper::gRenderer, &rect->convertToSDLRect() );

		buttonFont1->draw(SDL_wrapper::gRenderer, rect.x, rect.y, text.c_str());

	}
}

void Button::collisionDetected(std::shared_ptr<Object> obj)
{
	if ( obj->getType() == tMouse )
	{
		if ( std::static_pointer_cast< Mouse >( obj )->isLMBHold() == true )
		{

			pressed = true;

		}
	}
}

bool Button::isPressed()
{
	return pressed;
}
