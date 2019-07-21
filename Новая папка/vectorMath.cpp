#include "stdafx.h"
#include "Vector2d.h"



float magnitude( b2Vec2 vec ) {
	return sqrt( ( vec.x * vec.x ) + ( vec.y * vec.y ) );
}

float lengthSqr( b2Vec2 vec ) {
	return ( vec.x * vec.x ) + ( vec.y * vec.y );
}

b2Vec2 normalise( b2Vec2 vec ) {
	float magn = magnitude( vec );
	if (magn > 0) {
		vec /= magnitude;
	}
}

b2Vec2 rightHNormal( b2Vec2 vec )
{
	b2Vec2 bufVect = b2Vec2(-vec.y, getX());

	return bufVect;

}

b2Vec2 leftHNormal()
{
	b2Vec2 bufVect = b2Vec2(getY(), -getX());

	return bufVect;

}

float clamp(float n, float lower, float upper)
{
	return std::max(lower, std::min(n, upper));
}

Vector2d RotateVector(b2Vec2 vec, float angle)
{
	float radAngle = (float)(angle*DEG_TO_RAD);

	return Vector2d((float)(vec.getX() * cos(radAngle) - vec.getY() * sin(radAngle)), (float)(vec.getX() * sin(radAngle) + vec.getY() * cos(radAngle)));
}

Vector2d operator+(b2Vec2 r)
{
	return Vector2d(this->x + r.x, this->y + r.y);
}

Vector2d operator-(b2Vec2 r)
{
	return Vector2d(this->x - r.x, this->y - r.y);
}

b2Vec2 operator+=(b2Vec2 r)
{
	this->x += r.x;
	this->y += r.y;

	return *this;
}

b2Vec2 operator-=(b2Vec2 r) {
	this->x -= r.x;
	this->y -= r.y;

	return *this;
}
/**/
b2Vec2 operator+(b2Vec2& r)
{
	b2Vec2 buffer = b2Vec2(this->getX() + r->getX(), this->getY() + r->getY());
	return buffer;
}

b2Vec2 operator-(b2Vec2& r)
{
	b2Vec2 buffer = b2Vec2(this->getX() - r->getX(), this->getY() - r->getY());
	return buffer;
}

void operator+=(b2Vec2 r)
{
	setX(getX() + r->getX());

	setY(getY() + r->getY());

}

void operator-=(b2Vec2 r)
{
	setX(getX() - r->getX());

	setY(getY() - r->getY());

}

Vector2d operator+(const b2Vec2 r) {
	return Vector2d(this->x + r.x, this->y + r.y);
}

Vector2d operator-(const b2Vec2 r) {
	return Vector2d(this->x - r.x, this->y - r.y);
}

b2Vec2 operator+=(const b2Vec2 r) {
	this->x += r.x;
	this->y += r.y;

	return *this;
}

b2Vec2 operator-=(const b2Vec2 r) {
	this->x -= r.x;
	this->y -= r.y;

	return *this;
}

b2Vec2 operator*(float scalar)
{
	return b2Vec2(x*scalar, y*scalar);
}

void operator*=(float scalar)
{
	setX(getX() * scalar);

	setY(getY() * scalar);

}
b2Vec2 operator/(float scalar)
{
	return b2Vec2(x / scalar, y / scalar);
}

void operator/=(float scalar)
{
	setX(getX() / scalar);

	setY(getY() / scalar);

}

std::ostream & operator<<(std::ostream & out, const Vector2d & vec) {
	out << "(" << vec.x << "," << vec.y << ")";
	return out;
}

std::ostream & operator<<(std::ostream & out, b2Vec2 vec) {
	out << "(" << vec->getX() << "," << vec->getY() << ")";
	return out;
}

float distance(b2Vec2 vec1, b2Vec2 vec2)
{
	return distance(vec1->getX(), vec1->getY(), vec2->getX(), vec2->getY());
}
float distanceSquared(b2Vec2 vec1, b2Vec2 vec2)
{
	return distanceSquared(vec1->getX(), vec1->getY(), vec2->getX(), vec2->getY());
}

float distanceSquared(b2Vec2 vec1, b2Vec2 vec2)
{
	return distanceSquared(vec1.getX(), vec1.getY(), vec2.getX(), vec2.getY());
}

float distance(int x1, int y1, int x2, int y2)
{
	return static_cast<float>(sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2)));
}

float distance(float x1, float y1, float x2, float y2)
{
	return sqrtf((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

float distanceSquared(int x1, int y1, int x2, int y2)
{
	return static_cast<float>((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

float distanceSquared(float x1, float y1, float x2, float y2)
{
	return (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
}

float dotProduct(Vector2d & vec1, Vector2d & vec2)
{
	return vec1.getX() * vec2.getX() + vec1.getY() * vec2.getY();
}

float dotProduct(b2Vec2 vec1, b2Vec2 vec2)
{
	return vec1->getX() * vec2->getX() + vec1->getY() * vec2->getY();
}

float dotProduct(int x1, int y1, int x2, int y2)
{
	return static_cast<float>(x1 * x2 + y1 * y2);
}

float dotProduct(float x1, float y1, float x2, float y2)
{
	return x1 * x2 + y1 * y2;
}

float crossProduct(b2Vec2 vec1, b2Vec2 vec2)
{
	return;
}

b2Vec2 projection(b2Vec2 vec1, b2Vec2 vec2)
{
	float v2Len = vec2->lengthSqr();
	return *vec2 * (dotProduct(vec2, vec1) / v2Len);
}