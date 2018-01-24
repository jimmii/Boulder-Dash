#pragma once
#include"Global_headers.h"
#include"Setup.h"
#include"Sprite.h"
#include"Objects.h"
class Stone:public Objects
{
private:

	Sprite *stone;//!<inicjalizuje sprite kamieni
	Setup *setup; //!<inicjalizuje ustawienia

public:
	/*!
	*Konstruktor, ktory tworzy obiekt kamien
	* \param  *passed_Setup - inicjalizuje ustawienia okna
	* \param int x ustawia punkt wstawienia grafiki w poziomie
	* \param int y ustawia punkt wstawienia grafiki w pionie
	*/
	Stone(Setup *passed_Setup, int x, int y);
	/*!
	*Konstruktor, ktory tworzy obiekt mur
	*niszczy obiekty
	*/
	~Stone();
	/*!
	* Funkcja wstawiajaca grafike
	*/
	void Draw();	
	void Update();
	/*!
	* Funkcja zwracajaca wrtosc Stone
	*/
	Sprite* GetStones() { return stone; }
};

