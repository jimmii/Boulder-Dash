#pragma once
#include"Global_headers.h"
class Collision
{
private:
	int offsetX;
	int offsetY;

	SDL_Rect CollisionRect;//!<tworzy prostokat kolizyjny

	
public:
	/*!
	*Konstruktor domyslny
	*ustawia wartosci na 0
	*/
	Collision();
	/*!
	*Konstruktor , ktory tworzy prodstokat kolizyjny
	* \param int x pozycja w poziomie
	* \param int y pozycja w pionie
	* \param int w szerokosc
	* \param int h wysokosc
	*/
	Collision(int x, int y, int w, int h);
	/*!
	*Destruktor
	*niszczy obiekty
	*/
	~Collision();
	/*!
	* Funkcja przypisujaca wrtosci prostokatowi
	* \param int x pozycja w poziomie
	* \param int y pozycja w pionie
	* \param int w szerokosc
	* \param int h wysokosc
	*/
	void SetRectangle(int x, int y, int w, int h);
	/*!
	* Funkcja zwracajaca wrtosc collisionRect
	*/
	SDL_Rect GetRectangle() { return CollisionRect; };
	/*!
	* Funkcja ustawiajaca wartosc x prostokata
	* \param int x pozycja w poziomie
	*/
	void setXRectangle(int x) { CollisionRect.x = x + offsetX; }
	/*!
	* Funkcja ustawiajaca wartosc y prostokata
	* \param int x pozycja w pionie
	*/
	void setYRectangle(int y) { CollisionRect.y = y + offsetY; }
};

