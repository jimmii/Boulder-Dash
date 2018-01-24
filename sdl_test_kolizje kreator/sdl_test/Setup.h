#pragma once
#include"Global_headers.h"
/*!
* Klasa odpowiedzialna za ustawianie oraz modyfikowanie okna oraz tego co sie w nim dzieje.
* Rozmiar, eventy, wyswietlanie elementow.
*/
class Setup
{
private:
	
	SDL_Window *_window=NULL;//!<zmienna wksaznikowa SDL sluzaca do tworzenia okna. Jezeli przyjmuje NULL, oznacza to blad inicjalizacji.
	SDL_Renderer *_renderer=NULL;//!<zmienna wksaznikowa SDL sluzaca do renderowania elementow w oknie. Jezeli przyjmuje NULL, oznacza to blad inicjalizacji.
	SDL_Event *mEvent = new SDL_Event();//!<zmienna wksaznikowa SDL sluzaca do wykonywania eventow. 
	
public:
	/*!
	*Konstruktor, ktory tworzy obiekt(okno)
	* \param przekazywany_screenwidth - szerokosc okna
	* \param przekazywany_screenheight - wysokosc okna
	* \note wewnatrz wykonywana jest inicjalizacja SDL, tworzenie okna SDL na srodku monitora z przyjetymi rozmiarami okna oraz kontrola bledow,
	* inicjalizacja renderera z kontrola bledow.
	*/
	Setup(int przekazywany_screenwidth, int przekazywany_screeheight);
	/*!
	*Destruktor, ktory niszczy obiekt(okno)
	* \note wewnatrz niszczenie elementow _window, _renderer, mEvent oraz wyjscie z SDL
	*/
	~Setup();
	/*!
	*Publiczna funkcja typu SDL_Renderer zwracajaca renderer(getter)
	*/
	SDL_Renderer *GetRenderer();
	/*!
	*Publiczna funkcja typu SDL_Event zwracajaca event(getter)
	*/
	SDL_Event *GetEvent();
	/*!
	*Publiczna funkcja typu void 
	* wewnatrz znajduja sie metody SDL_Pollevent(param) oczekujaca na zdarzenie, 
	* SDL_RenderClear(_renderer) czysci renderer przed nadpisaniem
	*/
	void begin();
	/*!
	*Publiczna funkcja typu void
	* wewnatrz znajduje sie metoda SDL_RenderPresent(_renderer) ktora wyswietla renderer w oknie
	*/
	void end();

};

