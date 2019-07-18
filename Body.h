#pragma once
class Body
{

	b2Vec2 pos;

	b2BodyDef groundBodyDef;

	b2Body* groundBody;

	b2PolygonShape groundBox;

	std::shared_ptr< Texture > texture;

public:
	Body();
	~Body();
	void Draw();

	friend class dynBody;
};

