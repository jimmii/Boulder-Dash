#pragma once
#include"Global_headers.h"
#include"Setup.h"
#include"Sprite.h"
#include"Objects.h"


class Wall : public Objects
{
private:

	Sprite *wall;//!<inicjalizuje sprite muru
	Setup *setup;//!<inicjalizuje ustawienia
public:
	   /*!
	   *Konstruktor, ktory tworzy obiekt mur
	   * \param  *passed_Setup - inicjalizuje ustawienia okna
	   * \param int x ustawia punkt wstawienia grafiki w poziomie
	   * \param int y ustawia punkt wstawienia grafiki w pionie
	   */
	Wall(Setup *passed_Setup, int x, int y);
	/*!
	*Konstruktor, ktory tworzy obiekt mur
	*niszczy obiekty
	*/
	~Wall();
	/*!
	* Funkcja wstawiajaca grafike
	*/
	void Draw();
	void Update();
	/*!
	* Funkcja zwracajaca wrtosc WALL
	*/
	Sprite* GetWalls() { return wall; }
};

