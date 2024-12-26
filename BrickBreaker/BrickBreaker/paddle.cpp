#include "paddle.h"
#include "balls.h"
paddle::paddle(const Vector2f& size, const Vector2f& position): speed(300.0f), direction(0), previousPosition(position)
{
	Paddle.setSize(size);
	Paddle.setPosition(position);
	Paddle.setFillColor(Color::Green);
}


void paddle::update(float deltaTime)
{
	direction =0;
	previousPosition = Paddle.getPosition();
	if (Keyboard::isKeyPressed(Keyboard::A))
	{
		direction = -1;

	}
	else if (Keyboard::isKeyPressed(Keyboard::D))
	{
		direction = 1;
	}
	Paddle.move(direction * speed * deltaTime, 0);

	if (Paddle.getPosition().x + Paddle.getSize().x < 0)
	{
		Paddle.setPosition(Vector2f(600, Paddle.getPosition().y));
	}
	if (Paddle.getPosition().x > 600)
	{
		Paddle.setPosition(Vector2f(-Paddle.getSize().x, Paddle.getPosition().y));
	}
	else
	{
		direction = 0;
	}
}

void paddle::draw(RenderWindow& window)
{
	window.draw(Paddle);
}

FloatRect paddle::getGlobalBounds() const
{
	return Paddle.getGlobalBounds();
}

Vector2f paddle::getPosition() const
{
	return Paddle.getPosition();
}

Vector2f paddle::getSpeed() const
{
	return Vector2f(direction *speed ,0 );
}

Vector2f paddle::lastPaddlePos() const
{
	return previousPosition;
}
