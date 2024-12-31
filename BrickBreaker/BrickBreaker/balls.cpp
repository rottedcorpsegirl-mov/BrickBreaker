
#include "balls.h"
#include "paddle.h"
#include "Bricks.h"


void balls::debugCollision(int hitcount)
{
	cout << "current Hit count: " << hitcount << endl;
	cout << "current Speed: (" << velocity.x << "," << velocity.y << ")\n";
}

balls::balls(const float& radius, const Vector2f position) :velocity(0.f,200.f) //create ball
{
	Balls.setRadius(radius);	
	Balls.setFillColor(Color::White);
	Balls.setPosition(position);
}

void balls::update(float deltaTime, const RenderWindow& window) //update ball based on velocity aswell as keep it in bounds
{
	Balls.move(velocity * deltaTime);
	Vector2f position = Balls.getPosition();

	if (position.x <= 0 || position.x + Balls.getRadius() * 2 >= window.getSize().x)
	{
		reverseVelocityX();
		hitcount++;
		debugCollision(hitcount);
	}
	if (position.y <= 0)
	{
		reverseVelocityY();
		hitcount++;
		debugCollision(hitcount);
	}
	
}

void balls::draw(RenderWindow& window) //draw to window
{
	window.draw(Balls);
	
}

Vector2f balls::getPosition() const //position for collision handling
{
	return Balls.getPosition();
}

FloatRect balls::getBounds() const // also for collisoin handling
{
	return Balls.getGlobalBounds();
}

int balls::getHitcount() const
{
	return hitcount;
}

void balls::increaseHitcount()
{
	hitcount++;
}

void balls::reverseVelocityX() // reverse xvelocity function
{
	velocity.x = -velocity.x;
}

void balls::reverseVelocityY() // reverse yvelocity function
{
	velocity.y = -velocity.y;
	//increasing speed of ball
	float speedIncrease = 10.f;
	velocity.y += (velocity.y > 0 ? speedIncrease : -speedIncrease); //? = absolute value
	
	//capping speed of ball
	float maxSpeed = 500.0f;
	if (std::abs(velocity.x) > maxSpeed)
	{
		velocity.x = (velocity.x > 0 ? 1 : -1) * maxSpeed;
	}
}

void balls::handlePaddleCollision(const paddle& paddle) //handling collision between paddle and ball
{
	Vector2f ballPos = Balls.getPosition(); //need to have the return values as usable values 
	FloatRect ballBounds = Balls.getGlobalBounds();
	FloatRect paddleBounds = paddle.getGlobalBounds();


	if (ballBounds.intersects(paddleBounds))
	{
		reverseVelocityY();
			
		
		
		/*
			this is getting the relative hit position to manipulate the ball based on the position of the hit 
			( hit on the left side of the paddle means moving left)
		*/

		float paddlecenter = paddleBounds.left + paddleBounds.width / 2.0f;
		float ballCenter = ballBounds.left + ballBounds.width / 2.0f;
		float relativeHitPosition = (ballCenter - paddlecenter) / (paddleBounds.width / 2.0f);
		 

		//adjusting ball x velopcity based on the hit position
		velocity.x = relativeHitPosition * 200.0f; // adjust to change angler sensitivity

	
		//this is to change ball with paddle's movement
		Vector2f paddleSpeed = paddle.getPosition() - paddle.lastPaddlePos();
		velocity.x += paddleSpeed.x * 0.5f;
		
		
		hitcount++;
		debugCollision(hitcount);
	}
}

bool balls::isOutOfBounds(const RenderWindow& window) const
{
	return Balls.getPosition().y > window.getSize().y;
}

