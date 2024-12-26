
#include "balls.h"
#include "paddle.h"


balls::balls(const float& radius, const Vector2f position) :velocity(0.f,200.f)
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

void balls::handlePaddleCollision(const paddle& paddle)
{
	Vector2f ballPos = Balls.getPosition();
	FloatRect ballBounds = Balls.getGlobalBounds();
	FloatRect paddleBounds = paddle.getGlobalBounds();


	if (ballBounds.intersects(paddleBounds))
	{
		reverseVelocityY();
		Vector2f paddleSpeed = paddle.getPosition() - paddle.lastPaddlePos();
		velocity.x += paddleSpeed.x * 0.1f;
	}
}
