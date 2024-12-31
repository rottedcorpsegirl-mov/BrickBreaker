#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>


using namespace std;
using namespace sf;

class paddle;

class bricks;


class balls
{
public:
	void debugCollision(int hitcount);
	balls(const float& radius, const Vector2f position);

	void update(float deltaTime, const RenderWindow& window);
	void draw(RenderWindow& window);

	Vector2f getPosition() const;
	FloatRect getBounds() const;
	int getHitcount() const;
	
	void increaseHitcount();
	void reverseVelocityX();
	void reverseVelocityY();
	void handlePaddleCollision(const paddle& paddle);

	bool isOutOfBounds(const RenderWindow& window)const;

private:
	int hitcount = 0;
	CircleShape Balls;

	Vector2f velocity;

};

