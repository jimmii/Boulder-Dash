#include "Stone.h"



Stone::Stone( Setup *passed_Setup, int x, int y):
	setup(passed_Setup)
{
	stone = new Sprite(setup->GetRenderer(), "img/Enviroment/kamyk.png", x, y, 50, 50, Collision(20,10,10,20));
}


Stone::~Stone()
{
	delete stone;
	stone = NULL;
	delete setup;
	setup = NULL;
}

void Stone::Draw()
{
	
	stone->draw();

}

void Stone::Update() {};

