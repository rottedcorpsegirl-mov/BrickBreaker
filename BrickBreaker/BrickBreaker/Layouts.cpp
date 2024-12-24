#include "Layouts.h"



Layouts::Layouts()
{
	createLayout1();
}

void Layouts::draw(RenderWindow& window) const
{

	for (const auto& brick : bricks)
	{
		brick.draw(window);
	}

}


void Layouts::createLayout1()
{
	

	bricks.push_back(Bricks(Vector2f(80.f, 30.f), Vector2f(100.f, 100.f)));
	bricks.push_back(Bricks(Vector2f(80.f, 30.f), Vector2f(200.f, 100.f)));
	
	
	
}


void Layouts::handleCollision(balls& ball)
{
	for (auto it = bricks.begin(); it !=bricks.end(); )
	{
		if (ball.getBounds().intersects(it->getBounds()))
		{
			ball.reverseVelocityY();
			it = bricks.erase(it);
		}
		else
		{
			++it;
		}

	}
}
