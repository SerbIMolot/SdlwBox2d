#include "stdafx.h"
#include "dynBody.h"


dynBody::dynBody()
{
	groundBodyDef.type = b2_dynamicBody;
	groundBodyDef.position.Set( 1.0f, 1.0f );
	
	groundBody = SDL_wrapper::world->CreateBody( &groundBodyDef );
	texture = TextureManager::getTexture("box.jpg");
	groundBox.SetAsBox( ( texture->getWidth() / 2 ) * PtMratio, ( texture->getHeight() / 2 ) * PtMratio );

	fixtureDef.shape = &groundBox;
	fixtureDef.density = 0.65f;
	fixtureDef.friction = 0.3f;

	fixture = groundBody->CreateFixture( &fixtureDef );
}

dynBody::dynBody( BodyType btype, b2Vec2 vec, std::shared_ptr<Texture> textr, float dencity, float friction)
	: Body( btype, vec, textr )
{
	groundBodyDef.type = b2_dynamicBody;
	//groundBodyDef.position.Set( vec.x , vec.y );

	//groundBody = SDL_wrapper::world->CreateBody( &groundBodyDef );
	//texture = textr;
	groundBox.SetAsBox( ( texture->getWidth() / 2 ) * PtMratio, ( texture->getHeight() / 2 ) * PtMratio );

	fixtureDef.shape = &groundBox;
	fixtureDef.density = dencity;
	fixtureDef.friction = friction;

	fixture = groundBody->CreateFixture( &fixtureDef );
}

dynBody::dynBody( BodyType btype, float x, float y, std::shared_ptr<Texture> textr, float dencity, float friction)
	: Body( btype, x, y, textr )
{
	groundBodyDef.type = b2_dynamicBody;
	//groundBodyDef.position.Set( x, y );

	//groundBody = SDL_wrapper::world->CreateBody(&groundBodyDef);
	//texture = textr;
	groundBox.SetAsBox( ( texture->getWidth() / 2 ) * PtMratio, ( texture->getHeight() / 2 ) * PtMratio );

	fixtureDef.shape = &groundBox;
	fixtureDef.density = dencity;
	fixtureDef.friction = friction;

	fixture = groundBody->CreateFixture(&fixtureDef);
}



dynBody::~dynBody()
{
}

void dynBody::applyForce( b2Vec2 force )
{
	b2Vec2 pos = groundBody->GetWorldCenter();
	groundBody->ApplyForce( force, pos, true );
}

b2Vec2 dynBody::getVelocity()
{
	return groundBody->GetLinearVelocity();
}
