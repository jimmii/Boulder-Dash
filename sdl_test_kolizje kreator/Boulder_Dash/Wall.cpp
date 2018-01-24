#include "Wall.h"



Wall::Wall(Setup *passed_Setup, int x, int y):
	setup(passed_Setup)
{
	wall = new Sprite(setup->GetRenderer(), "img/Enviroment/mur.jpg", x, y, 50, 50, Collision(20, 0, 15, 40));
}


Wall::~Wall()
{
	delete wall;
	wall = NULL;
	delete setup;
	setup = NULL;
}

void Wall::Draw()
{
	wall->draw();
}

void Wall :: Update() {};