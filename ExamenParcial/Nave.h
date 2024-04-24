#pragma once
#define ARRIBA 80
#define ABAJO 72
#define DERECHA 77
#define IZQUIERDA 75
#include "Movimiento.h"
#include <iostream>

using namespace std;
//Clase
class Nave : public Movimientos 
{//operaciones
public:
	Nave(int x, int y, int dx, int dy, int ancho, int alto): Movimientos (x,y,dx,dy,ancho,alto){}
	~Nave(){}

	void borrar() {
		Console::SetCursorPosition(x, y);     cout << "         ";
		Console::SetCursorPosition(x, y + 1); cout << "         ";
		Console::SetCursorPosition(x, y + 2); cout << "         ";
		Console::SetCursorPosition(x, y + 3); cout << "         ";
	}


	void mover(char tecla){
		if (tecla == DERECHA) {
			x++;
		}
		else if (tecla == IZQUIERDA) {
			x--;
		}
		else if (tecla == ABAJO) {
			y--;
		}
		else if (tecla == ARRIBA) {
			y++;
		}
		if (x+dx+ancho >= Console::WindowWidth)
		{
			system("cls");
			Console::Clear();
			cout << "FELICITACIONES!!! - LLEGO AL OBJETIVO!!!";
			exit(0);
		}
	}

	void dibujar() {
		Console::ForegroundColor = ConsoleColor::Yellow;
		Console::SetCursorPosition(x, y);     cout << " __";
		Console::SetCursorPosition(x, y + 1); cout << "\\ \\___";
		Console::SetCursorPosition(x, y + 2); cout << "#[==___> ";
		Console::SetCursorPosition(x, y + 3); cout << " /_/   ";
		
	}
};

