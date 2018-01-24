#pragma once
#include"Global_headers.h"
#include"Setup.h"
#include"Sprite.h"
#include"Objects.h"

class beam_horizontal:Objects
{
private:
	
	Sprite *beam_h;//!<inicjalizuje sprite belki
	Setup *setup;  //!<inicjalizuje ustawienia

public:
	/*!
	*Konstruktor, ktory tworzy obiekt belka
	* \param  *passed_Setup - inicjalizuje ustawienia okna
	* \param int x ustawia punkt wstawienia grafiki w poziomie
	* \param int y ustawia punkt wstawienia grafiki w pionie
	*/
	beam_horizontal(Setup *passed_Setup, int x, int y);
	/*!
	*Konstruktor, ktory tworzy obiekt mur
	*niszczy obiekty
	*/
	~beam_horizontal();
	/*!
	* Funkcja wstawiajaca grafike
	*/
	void Draw();
	void Update();
	/*!
	* Funkcja zwracajaca wrtosc beamH
	*/
	Sprite* GetBeamH() { return beam_h; }
};

