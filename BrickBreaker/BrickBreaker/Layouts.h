#pragma once
#include "Bricks.h"
#include <vector>
#include <string>

using namespace std;
using namespace sf;

class Bricks;

class Layouts
{
public:
	Layouts();
	void draw(RenderWindow& window) const;


	
private:
	void createLayout1();

	vector<Bricks> bricks;
	
};

