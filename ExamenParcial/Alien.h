#pragma once

#include "Movimiento.h"
#include <iostream>

using namespace std;
//Clase
class Alien : public Movimientos
{//operaciones
public:
	Alien(int x, int y, int dx, int dy, int ancho, int alto) : Movimientos(x, y, dx, dy, ancho, alto) {}
	~Alien() {}

	void borrar() {
		Console::SetCursorPosition(x, y);     cout << "           ";
		Console::SetCursorPosition(x, y + 1); cout << "           ";
		Console::SetCursorPosition(x, y + 2); cout << "           ";
		
	}


	void mover() {

		if (y + dy < 0 || 32 < y + dy + alto) {


			dy *= -1;


		}
		y += dy;

	}

	void dibujar() {
		Console::ForegroundColor = ConsoleColor::Green;
		Console::SetCursorPosition(x, y);     cout << "   .---.";
		Console::SetCursorPosition(x, y + 1); cout << " _/__~0_\\_";
		Console::SetCursorPosition(x, y + 2); cout << "(_________)";
		

	}
};