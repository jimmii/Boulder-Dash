#pragma once
#include"Global_headers.h"
#include"Sprite.h"
#include"Setup.h"
#include "Objects.h"

class Door: public Objects
{
private:

	Sprite* door;//!<inicjalizuje sprite drzwi
	int timeCheck = SDL_GetTicks();//!<zmienna przechowujaca czas w milisekundach od zalaczenia biblioteki SDL
	Setup *setup;//!<inicjalizuje ustawienia
public:
	/*!
	*Konstruktor, ktory tworzy obiekt drzwi
	* \param  *passed_Setup - inicjalizuje ustawienia okna
	*/
	Door(Setup *passed_Setup);
	/*!
	*Konstruktor, ktory tworzy obiekt mur
	*niszczy obiekty
	*/
	~Door();
	/*!
	* Funkcja wstawiajaca grafike
	*/
	void Update();
	/*!
	* Funkcja obslugujaca animacje
	*/
	void Draw();
};

