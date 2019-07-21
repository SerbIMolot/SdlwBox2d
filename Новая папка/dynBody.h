#pragma once
class dynBody : public Body
{
	b2PolygonShape dynamicBox;

	b2FixtureDef fixtureDef;
	b2Fixture* fixture;
public:
	dynBody();
	dynBody( BodyType btype, b2Vec2 vec, std::shared_ptr< Texture > textr, float dencity, float friction );
	dynBody( BodyType btype, float x, float y, std::shared_ptr<Texture> textr, float dencity, float friction );
	~dynBody();

	void applyForce( b2Vec2 force );

	b2Vec2 getVelocity();

	friend class Entity;
	
};

