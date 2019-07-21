#pragma once
class Camera {
	static Camera* cInstance;

	b2Vec2* pos;

	int mapX, mapY;
	int screenW, screenH;

	b2AABB* box;

	Object* pivot;

	Type type;

	Camera(int mapX, int mapY, Object* player);
	Camera();
	~Camera();
public:

	void Init();
	void setMap();
	static Camera* Instance();

	static void Release();

	void setPlayer(Object * player);

	b2AABB* getBox();
	Type* getType();

	b2Vec2& Pos();

	void updateBox();

	void Update();

};

