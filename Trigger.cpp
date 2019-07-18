#include "stdafx.h"
#include "Trigger.h"


Trigger::Trigger(b2Vec2 vec, int w, int h)
{

	this->pos = std::move( vec );
	rect = std::make_shared< b2AABB >( );
	rect->lowerBound = b2Vec2(vec.x, vec.y);
	rect->upperBound = b2Vec2(w, h);
}

Trigger::Trigger(b2Vec2 vec, std::shared_ptr<b2AABB> rect)
{

	this->pos = std::move( vec );
	rect = std::move( rect );

}

Trigger::Trigger(int x, int y, int w, int h)
{

	this->pos =  b2Vec2 ( x, y );
	rect = std::make_shared< b2AABB>(  );

	rect->lowerBound = b2Vec2( x, y );
	rect->upperBound = b2Vec2( w, h );
}

void Trigger::setName(std::string str)
{
	name = str;
}

std::string Trigger::getName()
{
	return name;
}

std::shared_ptr<b2AABB> Trigger::getRect()
{
	return rect;
}

Trigger::~Trigger()
{
}

bool Trigger::isTrigered()
{
	return triggered;
}

void Trigger::trigger()
{
	triggered = true;
}

void Trigger::reset()
{
	triggered = false;
}
