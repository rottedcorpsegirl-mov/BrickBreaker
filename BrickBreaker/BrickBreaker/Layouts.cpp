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
	bricks.push_back(Bricks(Vector2f(80.f, 30.f), Vector2f(300.f, 100.f)));
	bricks.push_back(Bricks(Vector2f(80.f, 30.f), Vector2f(400.f, 100.f)));
	bricks.push_back(Bricks(Vector2f(80.f, 30.f), Vector2f(125.f, 200.f)));
	bricks.push_back(Bricks(Vector2f(80.f, 30.f), Vector2f(225.f, 200.f)));
	bricks.push_back(Bricks(Vector2f(80.f, 30.f), Vector2f(325.f, 200.f)));
	bricks.push_back(Bricks(Vector2f(80.f, 30.f), Vector2f(425.f, 200.f)));
	bricks.push_back(Bricks(Vector2f(30.f, 80.f), Vector2f(525.f, 200.f)));
	bricks.push_back(Bricks(Vector2f(30.f, 80.f), Vector2f(25.f, 200.f)));
}


void Layouts::handleCollision(balls& ball)
{
	for (auto it = bricks.begin(); it !=bricks.end(); )
	{
		if (ball.getBounds().intersects(it->getBounds()))
		{
			ball.reverseVelocityY();
			ball.increaseHitcount();
			ball.debugCollision(ball.getHitcount());
			it = bricks.erase(it);
		}
		else
		{
			++it;
		}

	}
}
