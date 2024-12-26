#pragma once
#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;

class GameOver
{
public:
	GameOver(const Font& font, const Vector2f& windowSize);

	void draw(RenderWindow& window);
	bool handleInput(Event event);
	void reset();
	
private:
	Text gameOverText;
	Text restartPrompt;

};

