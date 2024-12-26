
#include "balls.h"

balls::balls()
{
}

balls::balls(const float& radius, const Vector2f position) :velocity(200.f,-200.f)
{
	Balls.setRadius(radius);	
	Balls.setFillColor(Color::White);
	Balls.setPosition(position);
}

void balls::update(float deltaTime, const RenderWindow& window)
{
	Balls.move(velocity * deltaTime);
	Vector2f position = Balls.getPosition();

	if (position.x <= 0 || position.x + Balls.getRadius() * 2 >= window.getSize().x)
	{
		reverseVelocityX();
	}
	if (position.y <= 0)
	{
		reverseVelocityY();
	}
	//for ending game
	if (Balls.getPosition().y + Balls.getRadius() * 2 >= window.getSize().y) {
		reverseVelocityY();
	}
}

void balls::draw(RenderWindow& window)
{
	window.draw(Balls);
	
}

Vector2f balls::getPosition() const
{
	return Balls.getPosition();
}

FloatRect balls::getBounds() const
{
	return Balls.getGlobalBounds();
}

void balls::reverseVelocityX()
{
	velocity.x = -velocity.x;
}

void balls::reverseVelocityY()
{
	velocity.y = -velocity.y;
}
