#include "beam_vertical.h"


beam_vertical::beam_vertical(Setup *passed_Setup, int x, int y):
	setup(passed_Setup)
{
	beam_v = new Sprite(setup->GetRenderer(), "img/Enviroment/belka_pionowa.png", x, y, 25, 550, Collision(15, 0, -5, 6000));
}

beam_vertical::~beam_vertical()
{
	delete beam_v;
	beam_v = NULL;
	delete setup;
	setup = NULL;
}

void beam_vertical::Draw()
{
	beam_v->draw();
}
void beam_vertical::Update(){}