#include <iostream>
#include <SFML/Graphics.hpp>

#include "Layouts.h"
#include "balls.h"
#include "Bricks.h"
#include "GameOver.h"
#include "paddle.h"

using namespace std;
using namespace sf;

enum GameState { Playing, GameOverState }; // Game states
GameState gameState = Playing;

int main() {

	RenderWindow window(VideoMode(600, 900), "Brick Breaker");
	window.setFramerateLimit(60);

	Texture backgroundTexture;
	if (!backgroundTexture.loadFromFile("C:/Users/matterviola/Documents/code/BrickBreaker/BrickBreaker/src/BackGround.jpg")) {
		cout << "background not working!";
	}
	Sprite backgroundSprite;
	backgroundSprite.setTexture(backgroundTexture);
	paddle player(Vector2f(100,20), Vector2f(250,800));
	

	Font font;
	if (!font.loadFromFile("C:/Users/matterviola/Documents/code/BrickBreaker/BrickBreaker/src/POSTHAND.ttf")) {
		cout << "failed to load font! \n";

	}

	GameOver gameOver(font, Vector2f(window.getSize()));

	Layouts layout;
	

	balls ball(10.f, Vector2f(300.f, 460.f));

	float speed = 300.0f;
	Clock clock;

	while (window.isOpen()) {
		float deltaTime = clock.restart().asSeconds();
		
		Event events;

		//while event loop
		while (window.pollEvent(events)) {
			
			Vector2f ballPos = ball.getPosition();
			switch (events.type)
			{
			case Event::Closed():
				window.close();
				break;
			case Event::KeyPressed:
				switch (events.key.code)
				{
				case Keyboard::Escape:
					window.close();
					break;
					
				case Keyboard::P:
					//cout << "Paddle X Postion: " << paddle<< endl<< "Paddle Y position: "<< paddlePos.y<< endl;
					cout << "ball X Position: " << ballPos.x << endl << "Paddle Y position: " << ballPos.y << endl;
					gameState = GameOverState;
					cout << gameState;
					break;
				case Keyboard::R:
					if (gameState == GameOverState) {
						//restarting game
						gameState = Playing;
						ball = balls(10.f, Vector2f(300.f, 460.f));
						balls ball(10.f, Vector2f(300.f, 460.f));
						layout = Layouts();

					}
					break;
				default:
					break;
				}
			default:
				break;
			}
		}
		
		//paddle movement
		if (gameState == Playing)
		{
			player.update(deltaTime);
			// update ball
			ball.update(deltaTime, window);
			ball.handlePaddleCollision(player);
			
			
		}
		
	
		
		window.clear();
		window.draw(backgroundSprite);
		ball.draw(window);
		player.draw(window);
		layout.draw(window);
		if (gameState == GameOverState) {
			gameOver.draw(window);
		}
		
		window.display();


	}
	cout << "Application Closed!\n";

	return 0;
}