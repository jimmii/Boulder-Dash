#include "beam_horizontal.h"

beam_horizontal::beam_horizontal(Setup *passed_Setup, int x, int y):
	setup(passed_Setup)
{
	beam_h = new Sprite(setup->GetRenderer(), "img/Enviroment/belka_pozioma.png", x, y, 800, 25, Collision(0, 0, 800, 12));
}

beam_horizontal::~beam_horizontal()
{
	delete beam_h;
	beam_h = NULL;
	delete setup;
	setup = NULL;
	
}
void beam_horizontal::Draw()
{
	beam_h->draw();
}
void beam_horizontal::Update(){}

