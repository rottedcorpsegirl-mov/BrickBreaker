#include "Bricks.h"

Bricks::Bricks()
{
}

Bricks::Bricks(const Vector2f& size, const Vector2f& position)
{
	bricks.setSize(size);
	bricks.setPosition(position);
	bricks.setFillColor(sf::Color::Yellow);
}



void Bricks::draw(RenderWindow& window) const
{
	window.draw(bricks);
}

FloatRect Bricks::getBounds() const
{
	return bricks.getGlobalBounds();
}
