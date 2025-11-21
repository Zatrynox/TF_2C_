#pragma once
#include "Jugador.h"

class Bombero: public Jugador {

public:
	Bombero() {
		this->x = 0;
		this->y = 0;
		this->vx = 0;
		this->vy = 0;
		this->ancho = 0.0;
		this->alto = 0.0;
		this->indiceX = 0;
		this->indiceY = 0;
		this->UltimaTecla = Ninguna;
	}
	Bombero(int x, int y) {
		this->x = x;
		this->y = y;
		this->vx = 0;
		this->vy = 0;
		UltimaTecla = Abajo;
		direccion = Ninguna;
		//de cada 1
		ancho = 60;
		alto  = 89.75;

	}
	~Bombero() {};

	void mover(BufferedGraphics^ buffer, Bitmap^ bmp, Basura* bsr, Basura* bsr2, 
		Basura* bsr3, Basura* bsr4, Basura* bsr5, Basura* bsr6, Arbol* abl) override{
		if (buffer == nullptr || bmp == nullptr || bsr == nullptr || bsr2 == nullptr ||
			bsr3 == nullptr || bsr4 == nullptr || bsr5 == nullptr || bsr6 == nullptr || abl == nullptr) {
			// Maneja el error, por ejemplo:
			return;
		}
		else
		{
			bool colisionBasura;
			bool colisionArbol;

			colisionBasura = ValidacionHitboxBasura(bsr);
			bool colisionBasura2 = ValidacionHitboxBasura(bsr2);
			bool colisionBasura3 = ValidacionHitboxBasura(bsr3);
			bool colisionBasura4 = ValidacionHitboxBasura(bsr4);
			bool colisionBasura5 = ValidacionHitboxBasura(bsr5);
			bool colisionBasura6 = ValidacionHitboxBasura(bsr6);

			colisionArbol = ValidacionHitboxArbol(abl);

			if (!colisionBasura && !colisionArbol && !colisionBasura2 && !colisionBasura3 && !colisionBasura4
				&& !colisionBasura5 && !colisionBasura6) {
				a = 1;
				b = 1;
				c = 1;
				d = 1;
			}

			switch (direccion)
			{

			case Arriba:
				indiceY = 1;
				if (indiceX >= 0 && indiceX < 3)
				{
					indiceX++;
				}
				else
				{
					indiceX = 0;
				}
				vx = 0;
				if (((y >= 239) && colisionBasura == false && colisionBasura2 == false && colisionBasura3 == false
					&& colisionBasura4 == false && colisionBasura5 == false && colisionBasura6 == false && colisionArbol == false) || a == 0)

				{
					vy = -10;

				}
				else
				{
					b = 0;
					c = 0;
					d = 0;
				}
				UltimaTecla = Arriba;
				break;
			case Abajo:
				indiceY = 0;
				if (indiceX >= 0 && indiceX < 3)
				{
					indiceX++;
				}
				else
				{
					indiceX = 0;
				}
				vx = 0;
				if (((y < buffer->Graphics->VisibleClipBounds.Height - alto - 5) && colisionBasura == false && colisionBasura2 == false && colisionBasura3 == false
					&& colisionBasura4 == false && colisionBasura5 == false && colisionBasura6 == false && colisionArbol == false) || b == 0)
				{
					vy = 10;


				}
				else
				{
					a = 0;
					c = 0;
					d = 0;
				}
				UltimaTecla = Abajo;
				break;

			case Derecha:
				indiceY = 3;
				if (indiceX >= 0 && indiceX < 3)
				{
					indiceX++;
				}
				else
				{
					indiceX = 0;
				}
				if (((x < buffer->Graphics->VisibleClipBounds.Width - ancho - 5) && colisionBasura == false && colisionBasura2 == false && colisionBasura3 == false
					&& colisionBasura4 == false && colisionBasura5 == false && colisionBasura6 == false && colisionArbol == false) || c == 0)
				{

					vx = 10;


				}
				else
				{
					b = 0;
					a = 0;
					d = 0;
				}
				vy = 0;
				UltimaTecla = Derecha;
				break;
			case Izquierda:
				indiceY = 2;
				if (indiceX >= 0 && indiceX < 3)
				{
					indiceX++;
				}
				else
				{
					indiceX = 0;
				}
				if (((x >= 0) && colisionBasura == false && colisionBasura2 == false && colisionBasura3 == false
					&& colisionBasura4 == false && colisionBasura5 == false && colisionBasura6 == false && colisionArbol == false) || d == 0) {
					vx = -10;

				}
				else
				{
					b = 0;
					c = 0;
					a = 0;
				}
				vy = 0;
				UltimaTecla = Izquierda;
				break;
			case Ninguna:
				vx = 0;
				vy = 0;
				switch (UltimaTecla)
				{
				case Arriba:

					indiceY = 3;
					indiceX = 0;

					break;
				case Abajo:

					indiceY = 0;
					indiceX = 0;

					break;
				case Derecha:

					indiceY = 2;
					indiceX = 0;

					break;
				case Izquierda:

					indiceY = 1;
					indiceX = 0;

					break;

				}
				break;
			}

			dibujarP(buffer, bmp);

		}
	
	}

	
};
