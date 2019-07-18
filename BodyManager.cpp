#include "stdafx.h"
#include "BodyManager.h"

std::shared_ptr< BodyManager > BodyManager::objInstance = nullptr;

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
