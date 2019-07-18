#include "stdafx.h"
#include "TriggersManager.h"


TriggersManager* TriggersManager::trmInstance = nullptr;

TriggersManager::TriggersManager()
{
}


TriggersManager::~TriggersManager()
{
	trigers.clear();

	delete trmInstance;
	
}

TriggersManager* TriggersManager::Instance()
{
	if( trmInstance == nullptr )
	{
		trmInstance = new TriggersManager();

		trmInstance->Init();
	}
	return trmInstance;
}

void TriggersManager::addTrigger(int x, int y, int w, int h, std::string name)
{

	std::shared_ptr< Trigger > tr = std::make_shared< Trigger >( x, y, w, h );

	tr->setName( name );

	trigers.push_back( tr );



}

void TriggersManager::addTrigger( b2Vec2 vec, int w, int h, std::string name)
{
	std::shared_ptr< Trigger > tr = std::make_shared< Trigger >( vec, w, h );

	tr->setName( name );

	trigers.push_back( tr );
}

void TriggersManager::Init()
{
}

void TriggersManager::collisionDetected( std::shared_ptr< Body > obj )
{

	for ( auto tr : trigers )
	{



	}


}
