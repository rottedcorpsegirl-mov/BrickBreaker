#include <iostream>
#include <SFML/Graphics.hpp>

#include "Layouts.h"
#include "balls.h"
#include "Bricks.h"
#include "GameOver.h"

using namespace std;
using namespace sf;

enum GameState { Playing, GameOverState }; // Game states
GameState gameState = Playing;

int main() {

	RenderWindow window(VideoMode(600, 900), "Brick Breaker");
	window.setFramerateLimit(60);

	Texture backgroundTexture;
	if (!backgroundTexture.loadFromFile("H:/code/platformer/BrickBreaker/BrickBreaker/src/BackGround.jpg")) {
		cout << "background not working!";
	}
	Sprite backgroundSprite;
	backgroundSprite.setTexture(backgroundTexture);
	RectangleShape paddle(Vector2f(100, 20));
	paddle.setPosition(sf::Vector2f(250, 800));

	Font font;
	if (!font.loadFromFile("H:/code/platformer/BrickBreaker/BrickBreaker/src/POSTHAND.ttf")) {
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
			Vector2f paddlePos = paddle.getPosition(); //need this in game loop instead of out of it
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
					cout << "Paddle X Postion: " << paddlePos.x<< endl<< "Paddle Y position: "<< paddlePos.y<< endl;
					cout << "ball X Position: " << ballPos.x << endl << "Paddle Y position: " << ballPos.y << endl;
					break;
				case Keyboard::R:
					if (gameState == GameOverState) {
						//restarting game
						gameState - Playing;
						ball = balls(10.f, Vector2f(300.f, 460.f));
						paddle.setPosition(Vector2f(300.f, 800.f));
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
			if (Keyboard::isKeyPressed(Keyboard::A)) {

				paddle.move(-speed * deltaTime, 0);

			}

			if (Keyboard::isKeyPressed(Keyboard::D)) {

				paddle.move(speed * deltaTime, 0);
			}

			//wrapping function
			if (paddle.getPosition().x + paddle.getSize().x < 0) {
				paddle.setPosition(Vector2f(window.getSize().x, paddle.getPosition().y));  // Wrap to the right
			}

			if (paddle.getPosition().x > window.getSize().x) {
				paddle.setPosition(Vector2f(-paddle.getSize().x, paddle.getPosition().y));  // Wrap to the left
			}

			// update ball
			ball.update(deltaTime, window);

			//ball with paddle collison
			if (ball.getBounds().intersects(paddle.getGlobalBounds())) {
				ball.reverseVelocityY();
			}
			layout.handleCollision(ball);
			if (ball.getBounds().top + ball.getBounds().height >= window.getSize().y) {
				gameState = GameOverState;
			}
		}
		
	
		
		window.clear();
		window.draw(backgroundSprite);
		window.draw(paddle);
		ball.draw(window);
		layout.draw(window);
		
		window.display();


	}
	cout << "Application Closed!\n";

	return 0;
}