#include "Enviroment.h"



Enviroment::Enviroment(int przekazywany_screenwidth, int przekazywany_screeheight, Setup *passed_Setup):
	setup(passed_Setup)
{
	background = new Sprite(setup->GetRenderer(), "img/Enviroment/tlo1.jpg", 0, 0, przekazywany_screenwidth, przekazywany_screeheight, Collision());
	
	door = new Door(setup);
	
	//pozioma belka
	BeamSH.push_back(new beam_horizontal(setup, 0, 0));
	BeamSH.push_back(new beam_horizontal(setup, 0, 575));

	//pionowa belka
	BeamSV.push_back(new beam_vertical(setup, 0, 25));
	BeamSV.push_back(new beam_vertical(setup, 775, 25));

	mode = Creator;
	onePressed = false;
}


Enviroment::~Enviroment()
{
	delete background; background = NULL;
	delete setup; setup = NULL; 
	delete door; door = NULL;
	delete stone; stone = NULL;
	delete wall; wall = NULL;
	delete beamH; beamH = NULL;
	delete beamV; beamV = NULL;
	delete diamond; diamond = NULL;

	//kamienie
	for (std::vector<Stone*>::iterator i = Stones.begin(); i != Stones.end(); ++i)
	{
		delete (*i);
	}
	Stones.clear();
	//mur
	for (std::vector<Wall*>::iterator i = Walls.begin(); i != Walls.end(); ++i)
	{
		delete (*i);
	}
	Walls.clear();
	//belka h
	for (std::vector<beam_horizontal*>::iterator i = BeamSH.begin(); i != BeamSH.end(); ++i)
	{
		delete (*i);
	}
	BeamSH.clear();
	//belka v
	for (std::vector<beam_vertical*>::iterator i = BeamSV.begin(); i != BeamSV.end(); ++i)
	{
		delete (*i);
	}
	BeamSV.clear();
	//diamenty
	for (std::vector<Diamond*>::iterator i = Diamonds.begin(); i != Diamonds.end(); ++i)
	{
		delete (*i);
	}
	Diamonds.clear();
}

void Enviroment::DrawBack()
{
	background->draw();

	for (std::vector<Stone*>::iterator i = Stones.begin(); i != Stones.end(); ++i)
	{
		(*i)->Draw();
	}

	//mur
	for (std::vector<Wall*>::iterator i = Walls.begin(); i != Walls.end(); ++i)
	{
		(*i)->Draw();
	}

	//belka pozioma
	for (std::vector<beam_horizontal*>::iterator i = BeamSH.begin(); i != BeamSH.end(); ++i)
	{
		(*i)->Draw();
	}

	//pionowa
	for (std::vector<beam_vertical*>::iterator i = BeamSV.begin(); i != BeamSV.end(); ++i)
	{
		(*i)->Draw();
	}

	//diamenty
	for (std::vector<Diamond*>::iterator i = Diamonds.begin(); i != Diamonds.end(); ++i)
	{
		(*i)->Draw();
	}
}

void Enviroment::DrawFront()
{
	door->Draw();
}
void Enviroment::pushStone(int x, int y)
{
	//wstawianie
	if (setup->GetEvent()->type == SDL_KEYDOWN)
	{
		if (!onePressed && setup->GetEvent()->key.keysym.sym == SDLK_F1)
		{
			Stones.push_back(new Stone(setup, x, y));
			onePressed = true;
		}
	}
	if (setup->GetEvent()->type == SDL_KEYUP)
	{
		if (onePressed && setup->GetEvent()->key.keysym.sym == SDLK_F1)
		{
			onePressed = false;
		}
	}//end wstawiane

	//usuwanie
	if (setup->GetEvent()->type == SDL_KEYDOWN)
	{
		if (!onePressed && setup->GetEvent()->key.keysym.sym == SDLK_1)
		{
			if (Stones.size() > 0)
			{				
				int count = 0;
				for (std::vector<Stone*>::iterator i = Stones.begin(); i != Stones.end(); i++)
				{
					if (count == Stones.size())
					{
						delete(*i);
					}
					count++;
				}
				Stones.pop_back();
			}
						
			onePressed = true;
		}
	}
	if (setup->GetEvent()->type == SDL_KEYUP)
	{
		if (onePressed && setup->GetEvent()->key.keysym.sym == SDLK_1)
		{
			onePressed = false;
		}
	}//end usuwanie
}
void Enviroment::pushDiamond(int x, int y)
{
	if (setup->GetEvent()->type == SDL_KEYDOWN)
	{
		if (!onePressed && setup->GetEvent()->key.keysym.sym == SDLK_F2)
		{
			Diamonds.push_back(new Diamond(setup, x, y));
			onePressed = true;
		}
	}

	if (setup->GetEvent()->type == SDL_KEYUP)
	{
		if (onePressed && setup->GetEvent()->key.keysym.sym == SDLK_F2)
		{
			onePressed = false;
		}
	}
	//usuwanie
	if (setup->GetEvent()->type == SDL_KEYDOWN)
	{
		if (!onePressed && setup->GetEvent()->key.keysym.sym == SDLK_2)
		{
			if (Diamonds.size() > 0)
			{
				int count = 0;
				for (std::vector<Diamond*>::iterator i = Diamonds.begin(); i != Diamonds.end(); i++)
				{
					if (count == Diamonds.size())
					{
						delete(*i);
					}
					count++;
				}
				Diamonds.pop_back();
			}

			onePressed = true;
		}
	}
	if (setup->GetEvent()->type == SDL_KEYUP)
	{
		if (onePressed && setup->GetEvent()->key.keysym.sym == SDLK_2)
		{
			onePressed = false;
		}
	}//end usuwanie
}

void Enviroment::pushWall(int x, int y)
{
	if (setup->GetEvent()->type == SDL_KEYDOWN)
	{
		if (!onePressed && setup->GetEvent()->key.keysym.sym == SDLK_F3)
		{
			Walls.push_back(new Wall(setup, x, y));
			onePressed = true;
		}
	}

	if (setup->GetEvent()->type == SDL_KEYUP)
	{
		if (onePressed && setup->GetEvent()->key.keysym.sym == SDLK_F3)
		{
			onePressed = false;
		}
	}
	//usuwanie
	if (setup->GetEvent()->type == SDL_KEYDOWN)
	{
		if (!onePressed && setup->GetEvent()->key.keysym.sym == SDLK_3)
		{
			if (Walls.size() > 0)
			{
				int count = 0;
				for (std::vector<Wall*>::iterator i = Walls.begin(); i != Walls.end(); i++)
				{
					if (count == Walls.size())
					{
						delete(*i);
					}
					count++;
				}
				Walls.pop_back();
			}

			onePressed = true;
		}
	}
	if (setup->GetEvent()->type == SDL_KEYUP)
	{
		if (onePressed && setup->GetEvent()->key.keysym.sym == SDLK_3)
		{
			onePressed = false;
		}
	}//end usuwanie
}


void Enviroment::Update()
{
	if (setup->GetEvent()->type == SDL_KEYDOWN)
	{
		if (!onePressed && setup->GetEvent()->key.keysym.sym == SDLK_F7)
		{
			if (mode == Creator)
			{
				mode = GamePlay;
			}
			else
				if (mode == GamePlay)
				{
					mode = Creator;
				}

			onePressed = true;
		}
	}

	if (setup->GetEvent()->type == SDL_KEYUP)
	{
		if (onePressed && setup->GetEvent()->key.keysym.sym == SDLK_F7)
		{
			onePressed = false;
		}
	}

		if (mode == GamePlay)
		{
			door->Update();

			//diamenty
			for (std::vector<Diamond*>::iterator i = Diamonds.begin(); i != Diamonds.end(); ++i)
			{
				(*i)->Update();
			}
		}
}

