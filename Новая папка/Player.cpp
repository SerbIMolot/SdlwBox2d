#include "stdafx.h"
#include "Player.h"


Player::Player()
	: Entity( btPlayer, PixelToMeter( SCREEN_WIDTH / 2), PixelToMeter(SCREEN_HEIGHT / 2), TextureManager::getTexture("plStand.png"), 0.20f, 0.30f )
{
	maxSpeed = 2.0f;
	groundBody->SetFixedRotation( true );
}

Player::Player( b2Vec2 vec )
	: Entity( btPlayer, vec, TextureManager::getTexture("plStand.png"), 0.20f, 0.30f)
{
	maxSpeed = 2.0f;
	groundBody->SetFixedRotation(true);
}

Player::Player( float x, float y )
	: Entity( btPlayer, x, y, TextureManager::getTexture("plStand.png"), 0.20f, 0.30f)
{
	maxSpeed = 2.0f;
	groundBody->SetFixedRotation(true);
}


Player::~Player()
{
}

void Player::jump()
{
	applyForce( b2Vec2( 0, -10 ) );
}


void Player::move( b2Vec2 dir )
{

	groundBody->SetLinearVelocity( b2Cross( dir, getMaxSpeed() ) );
	//applyForce( b2Cross( dir, getMaxSpeed() ) );

}