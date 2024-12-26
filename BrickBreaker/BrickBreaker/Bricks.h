#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;

class Bricks
{
public:
	Bricks();
	Bricks(const Vector2f& size, const Vector2f& position);
	
	void draw(RenderWindow& window) const;
	FloatRect getBounds() const;

private:
	RectangleShape bricks;

};

