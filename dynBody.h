#pragma once
class dynBody : public Body
{
	b2PolygonShape dynamicBox;

	b2FixtureDef fixtureDef;
	b2Fixture* fixture;
public:
	dynBody();
	dynBody( b2Vec2 vec, std::shared_ptr< Texture > textr, float dencity, float friction );
	dynBody(float x, float y, std::shared_ptr<Texture> textr, float dencity, float friction);
	~dynBody();

	
};

