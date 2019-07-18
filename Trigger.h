#pragma once
class Trigger
{
	static int triggerCount;
	int id;

	std::string name;

	b2Vec2 pos;

	std::shared_ptr< b2AABB> rect;

	bool triggered;

public:
	Trigger( b2Vec2 vec, int w, int h );
	Trigger( b2Vec2 vec, std::shared_ptr< b2AABB > rect );
	Trigger( int x, int y, int w, int h );

	void setName( std::string str );
	std::string getName(  );

	std::shared_ptr< b2AABB > getRect();


	~Trigger();

	bool isTrigered();
	void trigger();

	void reset();


};



