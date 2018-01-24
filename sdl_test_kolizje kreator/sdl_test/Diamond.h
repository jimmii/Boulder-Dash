#pragma once
#include"Global_headers.h"
#include"Sprite.h"
#include"Setup.h"
#include"Objects.h"


class Diamond : public Objects
{
private:
	
	Sprite* diamond;//!<inicjalizuje sprite diamentu
	int timeCheck = SDL_GetTicks();//!<zmienna przechowujaca czas w milisekundach od zalaczenia biblioteki SDL
	Setup *setup;//!<inicjalizuje ustawienia
public:
	/*!
	*Konstruktor, ktory tworzy obiekt diamentu
	* \param  *passed_Setup - inicjalizuje ustawienia okna
	* \param int x ustawia punkt wstawienia grafiki w poziomie
	* \param int y ustawia punkt wstawienia grafiki w pionie
	*/
	Diamond(Setup *passed_Setup, int x, int y);
	/*!
	*Konstruktor, ktory tworzy obiekt mur
	*niszczy obiekty
	*/
	~Diamond();
	/*!
	* Funkcja obslugujaca animacje
	*/
	void Update();
	/*!
	* Funkcja wstawiajaca grafike
	*/
	void Draw();
	/*!
	* Funkcja zwracajaca wrtosc Diamond
	*/
	Sprite* GetDiamonds() { return diamond; }
};

