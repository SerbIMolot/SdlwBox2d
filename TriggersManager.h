#pragma once
class TriggersManager
{
	//static std::shared_ptr< TriggersManager > trmInstance;
	static TriggersManager* trmInstance;

	std::shared_ptr< Trigger > playerGoal;
	std::shared_ptr< Trigger > aiGoal;

	TriggersManager();
	

public:
	~TriggersManager();

	 std::vector< std::shared_ptr< Trigger > > trigers;


	static TriggersManager* Instance();

	void addTrigger( int x, int y, int w, int h, std::string name );
	void addTrigger( b2Vec2 vec, int w, int h, std::string name );

	void Init();


	void collisionDetected( std::shared_ptr< Body > obj );

};

