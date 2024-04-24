#pragma once
#include"Alien.h"
#include"Proyectil.h"
#include"Proyectil2.h"
#include"Nave.h"
#include <vector>
//Clase
class Controladora
{
private:
	Nave* nave;
	vector<ProyectilABAJO*>proyectiles1;
	vector<ProyectilARRIBA*>proyectiles2;
	vector<Alien*>aliens;
	time_t cronometro;
	time_t nuevoPROYECTILabajo;
	time_t nuevoPROYECTIL2arriba;

public:
	Controladora() {
		nuevoPROYECTILabajo = time(0);
		nuevoPROYECTIL2arriba = time(0);
		nave = new Nave(0, 15, 1, 1, 7, 4);

		for (int i = 0; i < 10; i++) { agregarP1(); }
		for (int i = 0; i < 10; i++) { agregarP2(); }
		for (int i = 0; i < 2; i++) { agregarAlien(); }
	}

	~Controladora() {
		delete nave;
		for (auto& p : proyectiles1) delete p;
		for (auto& p : proyectiles2) delete p;
		for (auto& a : aliens) delete a;
	}

	void agregarP1() { proyectiles1.push_back(new ProyectilABAJO(30, rand() % 30, 1, 1, 6, 6)); }
	void agregarP2() { proyectiles2.push_back(new ProyectilARRIBA(30, rand() % 30, 1, 1, 6, 6)); }
	void agregarAlien() { aliens.push_back(new Alien(rand() % 130 + 10, rand() % 32, 2, 2, 11, 3)); }


	void borrarTODO(){

		Console::SetCursorPosition(1, 1); cout << "               ";
	
		nave->borrar();
	
		for (int i = 0; i < proyectiles1.size(); i++) {
			proyectiles1[i]->borrar();
		}

		for (int i = 0; i < proyectiles2.size(); i++) {
			proyectiles2[i]->borrar();
		}

		for (int i = 0; i < aliens.size(); i++) {
			aliens[i]->borrar();
		}

	}

	void moverTODO(){

		char tecla;

		nave->mover(tecla);

		for (int i = 0; i < proyectiles1.size(); i++) {
			proyectiles1[i]->mover();
		}

		for (int i = 0; i < proyectiles2.size(); i++) {
			proyectiles2[i]->mover();
		}

		for (int i = 0; i < aliens.size(); i++) {
			aliens[i]->mover();
		}
		
	
	}

	void dibujarTODO(){

		Console::SetCursorPosition(1, 1); cout << "Cronometro: " << int(60 - clock() / 1000);
	
	
		nave->dibujar();

		for (int i = 0; i < proyectiles1.size(); i++) {
			proyectiles1[i]->dibujar();
		}

		for (int i = 0; i < proyectiles2.size(); i++) {
			proyectiles2[i]->dibujar();
		}

		for (int i = 0; i < aliens.size(); i++) {
			aliens[i]->dibujar();
		}
	
	}

	Nave* getnave() { return nave; }

	void colisiones() {
		//Verification
		for (int i = 0; i < proyectiles1.size(); i++) {
			if (nave->getRectangulo().IntersectsWith(proyectiles1[i]->getRectangulo())) {
				cout << "IMPACTO NAVE - PROYECTIL!!! -GAME OVER !!!";
				exit(0);
			}
		}

		for (int i = 0; i < proyectiles2.size(); i++) {
			if (nave->getRectangulo().IntersectsWith(proyectiles2[i]->getRectangulo())) {

				cout << "IMPACTO NAVE - PROYECTIL!!! -GAME OVER !!!";
				exit(0);
			}
		}
	}

	void apariciones() {
		if (difftime(time(0), nuevoPROYECTILabajo) >= 10) {
			nuevoPROYECTILabajo = time(0);
			agregarP1();
		}

		if (difftime(time(0), nuevoPROYECTIL2arriba) >= 10) {
			nuevoPROYECTIL2arriba = time(0);
			agregarP2();
		}
		
	}

	bool cronometro() {
		if (difftime(time(0), cronometro) >= 60)return true;
		else return false;
	}

};

