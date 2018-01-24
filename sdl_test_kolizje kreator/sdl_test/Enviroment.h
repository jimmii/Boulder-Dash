#pragma once
#include"Global_headers.h"
#include"Setup.h"
#include"Sprite.h"
#include"Stone.h"
#include"Wall.h"
#include"beam_horizontal.h"
#include"beam_vertical.h"
#include"Door.h"
#include"Diamond.h"

class Enviroment
{
private:

	int mode;//!<zmienna przechowujaca wartosc enum, kreator/gameplay	
	bool onePressed;//!<zmienna przechowujaca wartosc, czy ktorys klawisz zostal wcisniety

	Sprite* background;//!<zmienna tworzaca tlo okna
	//dorobic smart ptr (mozna)
	Setup *setup;//!<zmienna inicjalizujaca ustawienia okna



	Stone* stone;//!<zmienna inicjalizujaca kamienie
	std::vector <Stone*> Stones;//!<vector kamieni

	Wall* wall;//!<zmienna inicjalizujaca mur
	std::vector <Wall*> Walls;//!<vector typu mur

	beam_horizontal* beamH;//!<zmienna inicjalizujaca belke  pozioma
	std::vector <beam_horizontal*> BeamSH;//!<vector belek poziomych

	beam_vertical* beamV;//!<zmienna inicjalizujaca belke pionowa
	std::vector <beam_vertical*> BeamSV;//!<vector belek pionowych

	Door *door;//!<zmienna inicjalizujaca drzwi

	Diamond *diamond;//!<zmienna inicjalizujaca diamenty
	std::vector <Diamond*> Diamonds;//<vector diamentow

public:
	/*!
	*Konstruktor, ktory tworzy obiekt enviroment, sluzy do tworzenia srodowiska gry(zawiera elementy gry typu kamienie, mur, diamenty)
	* \param przekazywany_screenwidth - przypisuje szerokosc okna(tlo)
	* \param przekazywany_screenheight - przypisuje wysokosc okna(tlo)
	* \param Setup *passed_Setup - inicjalizuje ustawienia okna
	*/
	Enviroment(int przekazywany_screenwidth, int przekazywany_screeheight, Setup *passed_Setup);
	/*!
	*Destruktor, ktory niszczy obiekty
	* \usuwa obiekty, czysci vectory
	*/
	~Enviroment();
	/*!
	* Funkcja wstawia grafiki "z tylu" w oknie
	*/
	void DrawBack();
	/*!
	* Funkcja, ktora wylacza/wlacza tryb kreator/gameplay. W trybie gameplay blokuje wstwianie elementow na plansze oraz uruchamia animacje
	*/
	void Update();
	/*!
	* Funkcja wstawia grafiki "z przodu" w oknie
	*/
	void DrawFront();
	/*!
	* Funkcja wstawia kamienie
	*/
	void pushStone(int x, int y);
	/*!
	* Funkcja wstawia diamenty
	*/
	void pushDiamond(int x, int y);
	/*!
	* Funkcja wstawia mur
	*/
	void pushWall(int x, int y);
	/*!
	* Funkcja zwraca aktualna wartosc mode
	*/
	int GetMode() { return mode; }
	
	/*!
	* Funkcja zwraca aktualna zawartosc vectora Stone
	*/
	std::vector <Stone*> GetStones() { return Stones; }
	/*!
	* Funkcja zwraca aktualna zawartosc vectora Walls
	*/
	std::vector<Wall*> GetWalls() { return Walls; }
	/*!
	* Funkcja zwraca aktualna zawartosc vectora Diamonds
	*/
	std::vector<Diamond*> GetDiamonds() { return Diamonds; }
	/*!
	* Funkcja zwraca aktualna zawartosc vectora BeamsH
	*/
	std::vector<beam_horizontal*> GetBeam_H() { return BeamSH; }
	/*!
	* Funkcja zwraca aktualna zawartosc vectora BeamsV
	*/
	std::vector<beam_vertical*> GetBeam_V() { return BeamSV; }
	/*!
	* Typ Enum
	* przetrzymuje wartosci kreator/gameplay
	*/
	enum ModeType{
		GamePlay,//!<tryb gry
		Creator//!<tryb kreator
	};
		
};

