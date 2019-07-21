#include "stdafx.h"
#include "Body.h"


Body::Body()
{

}

Body::Body( BodyType btype, b2Vec2 vec, std::shared_ptr<Texture> textr )
{
	this->btype = btype;

	groundBodyDef.type = b2_staticBody;
	groundBodyDef.position.Set( vec.x , vec.y );

	groundBody = SDL_wrapper::world->CreateBody( &groundBodyDef );
	texture = std::move( textr );
	groundBox.SetAsBox((texture->getWidth() / 2) * PtMratio, (texture->getHeight() / 2) * PtMratio);

	groundBody->CreateFixture( &groundBox, 0.0f );
	
	groundBody->SetUserData( this );
}

Body::Body( BodyType btype, float x, float y, std::shared_ptr<Texture> textr )
{
	groundBodyDef.type = b2_staticBody;
	groundBodyDef.position.Set( x , y );

	groundBody = SDL_wrapper::world->CreateBody( &groundBodyDef );
	texture = std::move( textr );
	groundBox.SetAsBox((texture->getWidth() / 2) * PtMratio, (texture->getHeight() / 2) * PtMratio);

	groundBody->CreateFixture( &groundBox, 0.0f );

	groundBody->SetUserData( this );
}


Body::~Body()
{
	//delete groundBody;
}

void Body::Draw()
{
		//printf( "Pos = %f : %f\n", ( groundBody->GetPosition().x) * MtPratio, (groundBody->GetPosition().y ) * MtPratio );

		//printf("Rotation = %f \n", groundBody->GetAngle() * ( 180.0f / 3.141592653589793238463f) );
	//printf( "Pos = %f : %f\n", ( groundBody->GetPosition().x - ( ( texture->getWidth() / 2 ) * PtMratio ) ) * MtPratio, (groundBody->GetPosition().y - ( texture->getHeight() / 2) * PtMratio ) * MtPratio );
	//printf( "POS = %f, %f\n", getPos().x, getPos().y );
	//printf( "POS Pix = %f, %f\n", MeterToPixel( getPos().x ), MeterToPixel( getPos().y ) );
	
	//texture->render( ( groundBody->GetPosition().x  ) * MtPratio, ( groundBody->GetPosition().y ) * MtPratio );

	texture->render((  groundBody->GetPosition().x - ( ( texture->getWidth() / 2 ) * PtMratio ) ) * MtPratio, (groundBody->GetPosition().y - ( texture->getHeight() / 2) * PtMratio ) * MtPratio, nullptr, groundBody->GetAngle() * RtDratio );
}

BodyType Body::getType()
{
	return btype;
}

b2Vec2 Body::getPos()
{
	return groundBody->GetPosition();
}
