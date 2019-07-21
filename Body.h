#pragma once

enum BodyType
{
	btUnknown,
	btWall,
	btBox,
	btPlayer
};


class Body
{

	//b2Vec2 pos;
	BodyType btype;

	b2BodyDef groundBodyDef;

	b2Body* groundBody;

	b2PolygonShape groundBox;

	std::shared_ptr< Texture > texture;

public:
	Body();
	Body( BodyType btype, b2Vec2 vec, std::shared_ptr<Texture> textr );
	Body( BodyType btype, float x, float y, std::shared_ptr<Texture> textr );
	~Body();
	b2Vec2 getPos();
	void Draw();

	BodyType getType();


	friend class dynBody;
	friend class Entity;
	friend class Player;
};

