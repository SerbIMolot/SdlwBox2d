#include "stdafx.h"
#include "Body.h"


Body::Body()
{
	texture = TextureManager::getTexture("wall.png");
	groundBodyDef.position.Set( ( SCREEN_WIDTH / 2.0f ) * PtMratio , ( SCREEN_HEIGHT - ( texture->getHeight() / 2.0f ) ) * PtMratio );
	groundBody = SDL_wrapper::world->CreateBody( &groundBodyDef );
	groundBox.SetAsBox( ( texture->getWidth() / 2 ) * PtMratio, ( texture->getHeight() / 2 ) * PtMratio );
	groundBody->CreateFixture( &groundBox, 0.0f );
}


Body::~Body()
{
	//delete groundBody;
}

void Body::Draw()
{
		printf( "Pos = %f : %f\n", ( groundBody->GetPosition().x) * MtPratio, (groundBody->GetPosition().y ) * MtPratio );

		printf("Rotation = %f \n", groundBody->GetAngle() * ( 180.0f / 3.141592653589793238463f) );
	//printf( "Pos = %f : %f\n", ( groundBody->GetPosition().x - ( ( texture->getWidth() / 2 ) * PtMratio ) ) * MtPratio, (groundBody->GetPosition().y - ( texture->getHeight() / 2) * PtMratio ) * MtPratio );

	//texture->render( ( groundBody->GetPosition().x  ) * MtPratio, ( groundBody->GetPosition().y ) * MtPratio );

	texture->render((  groundBody->GetPosition().x - ( ( texture->getWidth() / 2 ) * PtMratio ) ) * MtPratio, (groundBody->GetPosition().y - ( texture->getHeight() / 2) * PtMratio ) * MtPratio, nullptr, groundBody->GetAngle() * RtDratio );
}
