#include <iostream>
#include <SFML/Graphics.hpp>
using namespace std;
using namespace sf;
int main() {

	RenderWindow window(VideoMode(800, 600), "Brick Breaker");
	
	RectangleShape paddle(Vector2f(150, 20));
	paddle.setPosition(sf::Vector2f(350, 500));
	

	float speed = 300.0f;
	Clock clock;
	while (window.isOpen()) {
		float deltaTime = clock.restart().asSeconds();
		
		Event events;
		while (window.pollEvent(events)) {
			Vector2f paddlePos = paddle.getPosition(); //need this in game loop instead of out of it
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
				default:
					break;
				}
			default:
				break;
			}
		}
		
		
		if (Keyboard::isKeyPressed(Keyboard::A)) {	
		//	cout << "A pressed!\n"; //error handling  
				paddle.move(-speed * deltaTime, 0);
			
		}

		if (Keyboard::isKeyPressed(Keyboard::D)) {
		//	cout << " D pressed\n"; //error handling
				paddle.move(speed *deltaTime , 0);  
		}


		//wrapping function
		if (paddle.getPosition().x + paddle.getSize().x < 0) {
			paddle.setPosition(Vector2f(window.getSize().x, paddle.getPosition().y));  // Wrap to the right
		}

		if (paddle.getPosition().x > window.getSize().x) {
			paddle.setPosition(Vector2f(-paddle.getSize().x, paddle.getPosition().y));  // Wrap to the left
		}
		window.clear();
		window.draw(paddle);
		
		window.display();


	}
	cout << "Application Closed!\n";

	return 0;
}