#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;

class Bricks
{
public:
	Bricks();
	Bricks(const Vector2f&, const Vector2f& position);

	
	void draw(RenderWindow& window) const;


private:
	RectangleShape bricks;

};

