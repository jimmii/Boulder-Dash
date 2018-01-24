#pragma once
#include"Global_headers.h"
#include"Sprite.h"
#include"Setup.h"
#include"Enviroment.h"

class Postac
{
private:
	Enviroment* enviroment;//!<inicjalizuje srodowisko

	Sprite* character;//!<tworzy postac
	int timeCheck = SDL_GetTicks();//!<zmienna przechowujaca czas w milisekundach od zalaczenia biblioteki SDL

	Setup *setup;//!<inicjalizuje ustawienia

	bool MoveRight = false;//!<zmienna typu bool, przechowuje wartosc ruchu w prawo
	bool MoveLeft = false;//!<zmienna typu bool, przechowuje wartosc ruchu w lewo
	bool MoveUp = false;//!<zmienna typu bool, przechowuje wartosc ruchu w dol
	bool MoveDown = false;//!<zmienna typu bool, przechowuje wartosc ruchu do gory
	
public:
	/*!
	*Konstruktor, inicjalizujacy postac
	* \param passed_Setup - inicjalizuje ustawienia
	* \param passed_enviroment - inicjalizuje srodowisko
	*/
	Postac(Setup *passed_Setup, Enviroment* passed_enviroment);
	/*!
	*Destruktor
	* \niszczy obiekty
	*/
	~Postac();
	/*!
	* Jezeli wystepuje kolizja postaci z elementem srodowiska, przesuwa postac o 5 pikseli od przedmiotu
	*/
	void CollisionMove();
	/*!
	* tworzy animacje oraz wykrywa kolizje
	*/
	void Update();
	/*!
	* Funkcja, ktora wyswietla postac
	*/
	void Draw();

};

