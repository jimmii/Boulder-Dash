#pragma once
#include"Global_headers.h"

#include"Setup.h"
#include"Sprite.h"
#include"Postac.h"
#include"Enviroment.h"
#include"Stone.h"
#include"Wall.h"

class MainClass
{
private:
	Postac *character;//!<inicjalizuje postac
	
	int screenWidth;//!<szerokosc okna
	int screenHeight;//!<wysokosc okna

	bool quit=false;//zmienna przechowujaca wartosc wyjscia lub otwartego okna

	Enviroment *Stage;//!<inicjalizuje  srodowisko	
	Setup* setup;//!<inicjalizuje ustawienia okna

public:
	/*!
	*Konstruktor
	* \param przekazywany_screenwidth - przypisuje szerokosc okna(tlo)
	* \param przekazywany_screenheight - przypisuje wysokosc okna(tlo)
	*/
	MainClass(int przekazywany_screenwidth, int przekazywany_screeheight);
	/*!
	*Destruktor, ktory niszczy obiekty
	* \usuwa obiekty
	*/
	~MainClass();
	/*!
	* Funkcja, ktora dziala na zasadzie, dopoki jest otwarte okno wywoluje funkcje programu
	*/
	void Loop();
};

