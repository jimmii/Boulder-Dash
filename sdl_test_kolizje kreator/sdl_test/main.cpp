#include"Global_headers.h"
#include"MainClass.h"


int main(int argc, char* args[])
{
	MainClass* _main=new MainClass(800,600);

	_main->Loop();
	
	delete _main;
	_main = NULL;
	return 0;
}