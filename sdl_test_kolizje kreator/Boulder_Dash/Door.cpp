#include "Door.h"

Door::Door(Setup *passed_Setup):
	setup(passed_Setup)
{
	door = new Sprite(setup->GetRenderer(), "img/Enviroment/drzwi.png", 725, 525, 50, 50, Collision(0, 0, 50, 50));
	door->SetUpAnimation(6, 1);//dzielniki img
	door->PlayAnimation(0, 0, 0, 0);//ustawienie na pozycji poczatkowej
}

Door::~Door()
{
	delete door;
	door = NULL;
	delete setup;
	setup = NULL;
}

void Door::Draw()
{
	door->draw();
}

void Door::Update()
{
	door->PlayAnimation(0,5,0,200);
}