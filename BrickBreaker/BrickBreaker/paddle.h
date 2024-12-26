#pragma once
#include "SFML/Graphics.hpp"

using namespace std;
using namespace sf;

class paddle
{
public:
	paddle(const Vector2f& size, const Vector2f& position);
	void update(float deltaTime);
	void draw(RenderWindow& window);
	FloatRect getGlobalBounds() const;
	Vector2f getPosition() const;
	Vector2f getSpeed() const;
	Vector2f lastPaddlePos() const;
	Vector2f previousPosition;
private:
	RectangleShape Paddle;
	float speed;
	int direction;

	


};

