#include"Global_headers.h"
#include "MainClass.h"



MainClass::MainClass(int przekazywany_screenwidth, int przekazywany_screeheight):
	screenWidth(przekazywany_screenwidth), screenHeight(przekazywany_screeheight)
{
	 setup = new Setup( przekazywany_screenwidth, przekazywany_screeheight);
	 Stage = new Enviroment(przekazywany_screenwidth, przekazywany_screeheight, setup);	
	 character = new Postac(setup, Stage);
	
}

MainClass::~MainClass()
{	
	delete setup;
	setup = NULL;
	delete character;
	character = NULL;
	delete Stage;
	Stage = NULL;
	
}

void MainClass::Loop()
{
	while (!quit && setup->GetEvent()->type!=SDL_QUIT)
	{
		setup->begin();//czysci
		
		Stage->DrawBack();

		character->Draw();
		character->Update();
			
		Stage->Update();
		Stage->DrawFront();
		
		setup->end();//wyswietla
			
	}
}