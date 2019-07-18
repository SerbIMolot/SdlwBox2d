#pragma once
class Entity : public Object
{
	

	
	b2Vec2 moveBounds;
	
	
	
	
	b2Vec2 velocity;

public:
	Entity();
	~Entity();

	void setMoveBounds( b2Vec2 bounds );
	void setMoveBounds( float x, float y );
	void setVelocity( b2Vec2 velocity );
	void setVelocity( float x, float y );

	b2Vec2 getMoveBounds();
	
	b2Vec2 getVelocity();


	virtual void move() = 0;

	virtual void Update( std::shared_ptr< Object > obj ) = 0;

	virtual void collisionDetected( std::shared_ptr< Object > obj ) = 0;
	friend class Puck;
};

