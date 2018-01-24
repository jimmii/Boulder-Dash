#pragma once
#include"Global_headers.h"
#include"Collision.h"
/*!
* Klasa odpowiedzialna za ustawianie oraz modyfikowanie textur, grafik, animacji.
*/
class Sprite
{
private:
	SDL_Texture *_image=NULL;//!<inicjalizacja tekstury do wstawiania obrazow
	SDL_Texture *collisionimage=NULL;//!< Inicjalizacja tekstury wstawiajacej kwadrat kolizyjny na obiekty
	SDL_Rect _rect;//!<tworzy prostokat, w ktory bedzie wstawiana grafika
	SDL_Rect _crop;//!<tworzy prostokat, w ktory beda wstawiane grafik, pozwala na warstwowe wstawianie grafik, nadpisanie 

	Collision collisionRect;//!<inicjalizacja obiektu, ktory jest odbowiedzialny za kolizje

	int img_width;//!<szerokosc grafiki
	int img_height;//!<wysokosc grafiki

	int currentFrame;//!<zmienna pomocnicza do ustalania aktualnej pozycji przy tworzeniu animacji
	int animationDelay;//!przyjmuje wartosc SDL_GetTicks()-liczbe milisekund od zainicjalizowania bliblioteki SDL. Sluzy do tworzenia animacji
	
	int Amount_Frame_X;//!<Przyjmuje wartosc dzielnika grafiki w poziomie. Sluzy do przycinania grafiki przy animacji(na ile czesci podzielic obraz w poziomie)
	int Amount_Frame_Y;//!<Przyjmuje wartosc dzielnika grafiki w pionie. Sluzy do przycinania grafiki przy animacji(na ile czesci podzielic obraz w pionie)

	SDL_Renderer *sprite_renderer;//!<inicjalizacja renderera, do ktorego zostanie przypisany renderer z klasy Setup
public:
	/*!
	*Konstruktor, ktory tworzy obiekt sprite, sluzy do wstawiania i modyfikowania textur,grafik, animacji
	* \param przekazywany_renderer - nadpisuje renderer z klasy Setup
	* \param std::string File_Path - sciezka do grafiki
	* \param int x - wspolrzedne x grafiki, do wstawiania
	* \param int y - wspolrzedne y grafiki, do wstawiania
	* \param int w - szerokosc grafiki, do wstawiania
	* \param int h - wysokosc grafiki, do wstawiania
	* \param Collision passed_collisionRectangle - wstawienie kwadratu kolizyjnego na grafike
	*/
	Sprite(SDL_Renderer *przekazywany_renderer, std::string File_Path, int x, int y, int w, int h, Collision passed_collisionRectangle);
	/*!
	*Destruktor, ktory niszczy obiekt sprite
	* \note wewnatrz niszczenie textur
	*/
	~Sprite();
	/*!
	* Funkcja ustawiajaca pozycje oraz kopiujaca(nadpisujaca) renderer _crop do renderer _rect
	*/
	void draw();
	/*!
	* Funkcja ustawiajaca wartosc x
	*/
	void SetX(int X);
	/*!
	* Funkcja ustawiajaca wartosc y
	*/
	void SetY(int Y);
	/*!
	* Funkcja ustawiajaca pozycje x oraz y
	*/
	void SetPosition(int X, int Y);
	/*!
	* Funkcja zwracajaca wartosc x
	*/
	int GetX();
	/*!
	* Funkcja zwracajaca wartosc y
	*/
	int GetY();
	/*!
	* Funkcja nadpisuje wartosci na ile czesci podzielic grafike do animacji
	* \param int passed_Amount_X - w poziomie
	* \param int passed_Amount_Y - w pionie
	*/
	void SetUpAnimation(int passed_Amount_X, int passed_amount_Y);
	/*!
	* Funkcja odpowiedzialna za tworzenie animacji. 
	* \param int beginFrame - ustawienie od ktorej czesci grafiki zaczyna animacje
	* \param int endFrame - ustawienie na ktorej czesci grafiki konczy animacje
	* \param int beginFrame - ustawienie, w ktorym rzedzie podzielonej grafiki ma odbywaæ siê animacja
	* \param int beginFrame - ustawienie z jak¹ predkoscia sa zmieniane czesci grafiki
	*/
	void PlayAnimation(int beginFrame, int endFrame, int row, float speed);
	/*!
	* Funkcja typu bool wykrywajaca kolizje z kazdej strony obiektu(grafiki)
	* \param Collision Collider - kwadrat kolizyjny 
	*/
	bool isColliding(Collision Collider);
	/*!
	*Funkcja zwracajaca kwadrat kolizyjny
	*/
	Collision GetColisionRect() { return collisionRect; }
};

