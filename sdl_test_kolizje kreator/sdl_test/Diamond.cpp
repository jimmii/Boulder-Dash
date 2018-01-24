#include "Diamond.h"


Diamond::Diamond(Setup *passed_Setup, int x, int y):
	setup(passed_Setup)
{
	diamond = new Sprite(setup->GetRenderer(), "img/Enviroment/krysztal.png", x, y, 50, 50, Collision(0, 0, 50, 50));
	diamond->SetUpAnimation(5, 6);//dzielniki img
	diamond->PlayAnimation(0, 0, 0, 0);//ustawienie na pozycji poczatkowej
}


Diamond::~Diamond()
{
	delete diamond;
	diamond = NULL;
	delete setup;
	setup = NULL;
}

void Diamond::Draw()
{
	diamond->draw();
	
}

void Diamond::Update()
{
	diamond->PlayAnimation(0,4,0,200);
	
}

