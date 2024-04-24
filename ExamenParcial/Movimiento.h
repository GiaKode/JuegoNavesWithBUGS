#pragma once
#include <iostream>
using namespace std;
#include<conio.h>
using namespace System;
using namespace System::Drawing;
//Clase
class Movimientos {//Atributos

protected:
	int x, y, dx, dy, ancho, alto;
	//operaciones
	public:
	Movimientos(int x, int y, int dx, int dy, int ancho, int alto) {
		this->x = x;
		this->y = y;
		this->dx = dx;
		this->dy = dy;
		this->ancho = ancho;
		this->alto = alto;

	}
	~Movimientos() {}

	virtual void borrar(){}
	virtual void mover() {}
	virtual void dibujar(){}

	virtual Rectangle getRectangulo() {
		return Rectangle(x, y, ancho, alto);
	}


};