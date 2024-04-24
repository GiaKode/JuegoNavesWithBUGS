#pragma once
#include "Movimiento.h"
#include <iostream>

using namespace std;
//Clase
class ProyectilABAJO : public Movimientos
{
public://operaciones
	ProyectilABAJO(int x, int y, int dx, int dy, int ancho, int alto) : Movimientos(x, y, dx, dy, ancho, alto) {}
	~ProyectilABAJO() {}

	void borrar() {
		Console::SetCursorPosition(x, y);     cout << "      ";
		Console::SetCursorPosition(x, y + 1); cout << "      ";
		Console::SetCursorPosition(x, y + 2); cout << "      ";
		Console::SetCursorPosition(x, y + 3); cout << "      ";
		Console::SetCursorPosition(x, y + 4); cout << "      ";
		Console::SetCursorPosition(x, y + 5); cout << "      ";
	}


	void mover() {
		

		if (y + dy < 0 || 32 < y + dy + alto) {


			y -= dy;

			if (y + dy + alto >= 32) {



				x = rand() % 100 + 25;
				y = 0;
				y -= dy;


			}

		}
		y += dy;
	}

	void dibujar() {
		Console::ForegroundColor = ConsoleColor::Red;
		Console::SetCursorPosition(x, y);     cout << "|\\**/|";
		Console::SetCursorPosition(x, y + 1); cout << "\\ == /";
		Console::SetCursorPosition(x, y + 2); cout << "  |  | ";
		Console::SetCursorPosition(x, y + 3); cout << "  |  | ";
		Console::SetCursorPosition(x, y + 4); cout << " \\  / ";
		Console::SetCursorPosition(x, y + 5); cout << "  \\/  ";

	}
};
