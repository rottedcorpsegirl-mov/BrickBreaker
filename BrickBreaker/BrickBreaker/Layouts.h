#pragma once
#include "Bricks.h"
#include "balls.h"
#include <vector>
#include <string>

using namespace std;
using namespace sf;

class Bricks;
class balls;

class Layouts
{
public:
	Layouts();
	void draw(RenderWindow& window) const;
	void handleCollision(balls& ball);

	
private:
	void createLayout1();

	vector<Bricks> bricks;
	
};

