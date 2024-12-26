#include "GameOver.h"

GameOver::GameOver(const Font& font, const Vector2f& windowSize)
{
	gameOverText.setFont(font);
	gameOverText.setString("Game Over!");
	gameOverText.setCharacterSize(50);
	gameOverText.setFillColor(Color::Red);
	gameOverText.setPosition(windowSize.x / 2.f - 100.f, windowSize.y / 2.f - 100.f);

	restartPrompt.setFont(font);
	restartPrompt.setString("Press R to Restart");
	restartPrompt.setCharacterSize(30);
	restartPrompt.setFillColor(Color::Red);
	restartPrompt.setPosition(windowSize.x / 2.f - 120.f, windowSize.y / 2.f );
}


void GameOver::draw(RenderWindow& window)
{
	window.draw(gameOverText);
	window.draw(restartPrompt);
}

bool GameOver::handleInput(Event event)
{
	if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::R) {
		return true; // signals to restart game
	}
	return false;
}

void GameOver::reset()
{
	// add stuff here
}
