#include "Postac.h"



Postac::Postac(Setup *passed_Setup, Enviroment* passed_enviroment):
	setup(passed_Setup), enviroment(passed_enviroment)
{
	character = new Sprite(setup->GetRenderer(), "img/postac.png", 100, 200, 50, 50, Collision(0, 0, 50, 50));
	character->SetUpAnimation(9, 4);//dzielniki img
	character->PlayAnimation(0, 0, 2, 0);//ustawienie na pozycji poczatkowej
}

Postac::~Postac()
{
	delete character;
	character = NULL;
	delete setup;
	setup = NULL;
	delete enviroment;
	enviroment = NULL;
}

void Postac::Draw()
{
	character->draw();
}

void Postac::Update()
{
	bool coliding=false;
	
	if (enviroment->GetMode() == 0)//kreator/gameplay
	{
		//kamyki
		for (int i = 0; i < enviroment->GetStones().size(); i++)
		{
			if (character->isColliding(enviroment->GetStones()[i]->GetStones()->GetColisionRect()) )
			{
				CollisionMove();
				coliding = true;			
			}
		}
		//cegly
		for (int i = 0; i < enviroment->GetWalls().size(); i++)
		{
			if (character->isColliding(enviroment->GetWalls()[i]->GetWalls()->GetColisionRect()))
			{
				CollisionMove();
				coliding = true;
			}
		}		
	}
	
	//belka pozioma
	for (int i = 0; i < enviroment->GetBeam_H().size(); i++)
	{
		if (character->isColliding(enviroment->GetBeam_H()[i]->GetBeamH()->GetColisionRect()))
		{
			CollisionMove();
			coliding = true;
		}
	}

	//belka pionowa
	for (int i = 0; i < enviroment->GetBeam_V().size(); i++)
	{
		if (character->isColliding(enviroment->GetBeam_V()[i]->GetBeamV()->GetColisionRect()))
		{
			CollisionMove();
			coliding = true;
		}
	}
	
	if (!coliding)
	{
		switch (setup->GetEvent()->type)
		{

		case SDL_KEYDOWN:
			switch (setup->GetEvent()->key.keysym.sym)
			{
			case SDLK_LEFT:
				MoveLeft = true;
				character->PlayAnimation(0, 8, 1, 50);
				break;
			case SDLK_DOWN:
				MoveDown = true;
				character->PlayAnimation(0, 8, 2, 50);
				break;
			case SDLK_UP:
				MoveUp = true;
				character->PlayAnimation(0, 8, 0, 50);
				break;
			case SDLK_RIGHT:
				MoveRight = true;
				character->PlayAnimation(0, 8, 3, 50);
				break;
			default:
				break;
			}
		default:
			break;
		case SDL_KEYUP:

			switch (setup->GetEvent()->key.keysym.sym)
			{

			case SDLK_LEFT:
				MoveLeft = false;
				character->PlayAnimation(0, 0, 1, 0);
				break;
			case SDLK_DOWN:
				MoveDown = false;
				character->PlayAnimation(0, 0, 2, 200);
				break;
			case SDLK_UP:
				MoveUp = false;
				character->PlayAnimation(0, 0, 0, 200);
				break;
			case SDLK_RIGHT:
				MoveRight = false;
				character->PlayAnimation(0, 0, 3, 200);
				break;
			default:
				break;
			}
		}
		//kreator
		if (enviroment->GetMode() == 1)
		{
			enviroment->pushStone(character->GetX(), character->GetY());
			enviroment->pushDiamond(character->GetX(), character->GetY());
			enviroment->pushWall(character->GetX(), character->GetY());
		}		
		if (timeCheck + 5 < SDL_GetTicks())
		{
			if (MoveRight)
			{
				character->SetX(character->GetX() + 1);
			}
			if (MoveLeft)
			{
				character->SetX(character->GetX() - 1);
			}
			if (MoveDown)
			{
				character->SetY(character->GetY() + 1);
			}
			if (MoveUp)
			{
				character->SetY(character->GetY() - 1);
			}
			timeCheck = SDL_GetTicks();
		}
	}
}

void Postac::CollisionMove()
{
	if (MoveLeft == true)
	{
		character->SetX(character->GetX() + 5);
	}
	if (MoveRight == true)
	{
		character->SetX(character->GetX() - 5);
	}
	if (MoveDown == true)
	{
		character->SetY(character->GetY() - 5);
	}
	if (MoveUp == true)
	{
		character->SetY(character->GetY() + 5);
	}
}
