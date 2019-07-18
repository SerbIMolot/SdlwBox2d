#pragma once
class Button
{
	b2Vec2 pos;
	std::shared_ptr< b2AABB > rect;

	bool pressed;

	std::string text;

	static std::unique_ptr< NFont > buttonFont;
	std::unique_ptr< NFont > buttonFont1;
public:
	//Button();
	Button(b2Vec2 vec, float w, float h, std::string text);
	Button(int x, int y, int w, int h, std::string text);
	Button(float x, float y, float w, float h, std::string text);
	~Button();


public:

	std::shared_ptr< b2AABB> getb2AABB();

	void Draw();
	
	void collisionDetected( std::shared_ptr< Object > obj );

	bool isPressed();
};

