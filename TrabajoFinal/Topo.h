#pragma once
#ifndef _TOPO_H_
#define _TOPO_H_
#include "Entidad.h"

class Topo : public Entidad{
protected:

	int vx;
	int vy;
	bool despierto;

public:

	Topo() {
		this->x = 0;
		this->y = 0;
		this->vx = 0;
		this->vy = 0;
		this->ancho = 0.0;
		this->alto = 0.0;
		this->indiceX = 0;
		this->indiceY = 0;
		this->despierto = false;
	}
	Topo(int x, int y, int vx, int vy) {
		this->x = x;
		this->y = y;
		this->vx = vx;
		this->vy = vy;
		this->despierto = false;


		ancho = 48;
		alto = 48;

	}
	~Topo() {

	}
	void setvx(int vx) {
		this->vx = vx;
	}
	void setvy(int vy) {
		this->vy = vy;

	}
	int getvx() {
		return vx;
	}
	int getvy() {
		return vy;

	}
	void setDespierto(bool despierto) {

		this->despierto = despierto;
	}
	bool getDespierto() {
		return despierto;
	}
	void dibujar(BufferedGraphics^ buffer, Bitmap^ bmp) override {
		Rectangle porcionUsar = Rectangle(indiceX * ancho, indiceY * alto, ancho, alto);
		Rectangle aumentoPersonaje = Rectangle(x, y, ancho, alto);
		buffer->Graphics->DrawImage(bmp, aumentoPersonaje, porcionUsar, GraphicsUnit::Pixel);
		x += vx;
		y += vy;
	}
	void mover(BufferedGraphics^ buffer, Bitmap^ bmp) {

		if (vx + x < 0 || vx + x >buffer->Graphics->VisibleClipBounds.Width - ancho - 5) {
			vx = -vx;
		}
		x = x + vx;
		if (vy + y < 320 || vy + y >buffer->Graphics->VisibleClipBounds.Height - alto - 5) {
			vy = -vy;
		}
		y = y + vy;
		if (vx<0)
		{
			//iz
			indiceY = 0;

			if (indiceX >= 0 && indiceX < 7)
			{
				indiceX++;
			}
			else
			{
				indiceX = 0;
			}
		}
		//der
		else if (vx>0)
		{
			indiceY = 1;
			if (indiceX >= 0 && indiceX < 7)
			{
				indiceX++;
			}
			else
			{
				indiceX = 0;
			}
		}
		else if (vy < 0)
		{
			indiceY = 2;
			if (indiceX >= 0 && indiceX < 7)
			{
				indiceX++;
			}
			else
			{
				indiceX = 0;
			}
		}
		else if (vy > 0)
		{
			indiceY = 3;
			if (indiceX >= 0 && indiceX < 7)
			{
				indiceX++;
			}
			else
			{
				indiceX = 0;
			}
		}
		else if ( vy == 0 && vx == 0)
		{
			indiceY = 4;
			if (indiceX >= 0 && indiceX < 7)
			{
				indiceX++;
			}
			else
			{
				indiceX = 0;
			}
		}
		dibujar(buffer, bmp);
	}
	
	
};

#endif // !_TOPO_H_

