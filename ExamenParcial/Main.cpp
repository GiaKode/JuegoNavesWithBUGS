#include "pch.h"
#include"Controladora.h"
#include<conio.h>
using namespace System;

Controladora* juego = new Controladora();

char tecla;

int main() {
	srand(time(NULL));
	Console::CursorVisible = false;
	Console::SetWindowSize(140, 40);

	while (1)
	{
		if (_kbhit())
		{
			tecla = _getch();
			tecla = toupper(tecla);
			juego->getnave()->borrar();
			juego->getnave()->mover(tecla);

		}
		

		juego->borrarTODO();
		juego->colisiones();
		juego->moverTODO();
		juego->dibujarTODO();
		juego->apariciones();

		_sleep(40);
	}
	_getch();
	return 0;
}