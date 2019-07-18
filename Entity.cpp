#include "stdafx.h"
#include "Entity.h"


Entity::Entity() : Object()
{
	movable = true;
}


Entity::~Entity()
{
}

void Entity::setMoveBounds(b2Vec2 bounds)
{
	this->moveBounds = bounds;
}

void Entity::setMoveBounds(float x, float y)
{
	this->moveBounds = std::make_shared< b2Vec2 >( x, y );
}

void Entity::setVelocity(
	
	
	
	velocity)
{
	this->velocity = velocity;
}

void Entity::setVelocity(float x, float y)
{
	this->velocity = std::make_shared< b2Vec2 >( x, y );
}

b2Vec2 Entity::getMoveBounds()
{
	return moveBounds;
}

b2Vec2 Entity::getVelocity()
{
	return velocity;
}

void Entity::move()
{
}

void Entity::Update(std::shared_ptr< Object > obj)
{
}

void Entity::collisionDetected(std::shared_ptr< Object > obj)
{
}
