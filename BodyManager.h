#pragma once
class BodyManager
{
	static std::shared_ptr< BodyManager > objInstance;
public:
	BodyManager();
	~BodyManager();

	static std::shared_ptr< BodyManager > Instance();

	//static addBody();
};

