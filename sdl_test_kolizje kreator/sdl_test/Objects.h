#pragma once
class Objects
{
public:
	/*!
	* virtualna czysta metoda sluzaca do wyswietlania grafik w oknie
	*/
	virtual void Draw() =0;
	/*!
	* virtualna czysta metoda sluzaca do uruchamiania akcji
	*/
	virtual void Update() =0;

};

