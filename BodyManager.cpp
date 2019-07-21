#include "stdafx.h"
#include "BodyManager.h"

std::shared_ptr< BodyManager > BodyManager::objInstance = nullptr;

std::vector< std::shared_ptr< Body > > BodyManager::bodys = std::vector< std::shared_ptr< Body > >();

BodyManager::BodyManager()
{
}

BodyManager::~BodyManager()
{
}

std::shared_ptr<BodyManager> BodyManager::Instance()
{
	if ( objInstance == nullptr )
	{
		objInstance = std::make_shared< BodyManager >();
	}

	return objInstance;

}

void BodyManager::createBody( BodyType btype )
{
	if ( btype == btPlayer )
	{
		player = std::make_unique< Player >();
	}
}



void BodyManager::createBody(BodyType btype, b2Vec2 pos, std::shared_ptr<Texture> textr)
{
	if ( btype == btWall )
	{
		std::shared_ptr< Body > temp = std::make_shared< Body >( btype, pos, textr );
		bodys.push_back( temp );
	}
	if ( btype == btBox )
	{
		std::shared_ptr< dynBody > temp = std::make_shared< dynBody >(btype, pos, textr, 0.65f, 0.35f );
		bodys.push_back( temp );
	}
	if ( btype == btPlayer )
	{
		player = std::make_unique< Player >( pos );
	}
}

void BodyManager::createBody( BodyType btype, float x, float y, std::shared_ptr<Texture> textr )
{
		if ( btype == btWall )
	{
		std::shared_ptr< Body > temp = std::make_shared< Body >( btype, x, y, textr );
		bodys.push_back( temp );
	}
	if ( btype == btBox )
	{
		std::shared_ptr< dynBody > temp = std::make_shared< dynBody >(btype, x, y, textr, 0.65f, 0.35f );
		bodys.push_back( temp );
	}
	if ( btype == btPlayer )
	{
		player = std::make_unique< Player >( x, y );
	}
}

std::shared_ptr< Body > BodyManager::getFirst()
{
	return bodys.front() ;
}

std::vector< std::shared_ptr< Body > > BodyManager::getBodys()
{
	return bodys;
}

Player* BodyManager::getPlayer()
{
	return player.get();
}

std::vector< std::shared_ptr< dynBody > > BodyManager::getBoxes()
{
	std::shared_ptr< dynBody > box;

	std::vector< std::shared_ptr< dynBody > > boxes;

	for ( auto body : bodys )
	{

		box = std::static_pointer_cast< dynBody > ( body );

		if ( box != nullptr && box->getType() == btBox )
		{
			boxes.push_back( box );
		}

	}

	return boxes;

}

std::vector< std::shared_ptr< dynBody > > BodyManager::getDynBodies()
{
	std::shared_ptr< dynBody > tempDynBod;

	std::vector< std::shared_ptr< dynBody > > dynBodies;

	for ( auto body : bodys )
	{

		tempDynBod = std::static_pointer_cast< dynBody > ( body );

		if ( tempDynBod != nullptr )
		{
			dynBodies.push_back( tempDynBod );
		}

	}

	return dynBodies;

}

std::vector< std::shared_ptr< dynBody > > BodyManager::getWalls()
{
	std::shared_ptr< dynBody > wall;

	std::vector< std::shared_ptr< dynBody > > walls;

	for ( auto body : bodys )
	{

		wall = std::static_pointer_cast< Body > ( body );

		if ( wall != nullptr && body->getType() == btWall )
		{
			walls.push_back( wall );
		}

	}

	return walls;

}

// find object by type
/*	
	std::shared_ptr< Player > pl;

	for ( auto body : bodys )
	{
		 
		pl = std::static_pointer_cast< Player > ( body );

		if ( pl != nullptr )
		{
			return pl;
		}
	
	}

	return nullptr;
*/