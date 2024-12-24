#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;


class balls
{
public:
	balls();
	balls(const float& radius, const Vector2f position);

	void update(float deltaTime, const RenderWindow& window);
	void draw(RenderWindow& window);

	Vector2f getPosition() const;
	FloatRect getBounds() const;

	void reverseVelocityX();
	void reverseVelocityY();


private:

	CircleShape Balls;

	Vector2f velocity;

};

