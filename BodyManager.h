#pragma once
class BodyManager
{
	static std::shared_ptr< BodyManager > objInstance;

	static std::unique_ptr< Player > player;

	static std::vector< std::shared_ptr< Body > > bodys;


	std::map< std::string, std::shared_ptr< Body > > mBodies;
	BodyManager();
	~BodyManager();



public:

	static std::shared_ptr< BodyManager > Instance();

	void createBody( BodyType btype );

	void createBody( BodyType btype, b2Vec2 pos, std::shared_ptr< Texture > textr = nullptr );
	void createBody( BodyType btype, float x, float y, std::shared_ptr< Texture > textr = nullptr );
	

	std::shared_ptr< Body > getFirst();

	std::vector< std::shared_ptr< Body > > getBodys();

	Player* getPlayer();

	std::vector<std::shared_ptr< dynBody > > getBoxes();

	std::vector<std::shared_ptr<dynBody>> getDynBodies();

	std::vector<std::shared_ptr<dynBody>> getWalls();

	//static addBody();
};

