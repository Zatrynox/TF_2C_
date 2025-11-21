#pragma once
#ifndef _BASURA_H_
#define _BASURA_H_
#include "Entidad.h"
class Basura : public Entidad {
private:
    int tipo;
    bool activo;
public:
    Basura() {
        this->x = 0;
        this->y = 0;
        this->ancho = 0;
        this->alto = 0;
        this->tipo = 0;
        this->indiceX=0;
        this->indiceY = 0;
        this->activo = false;
    }
    Basura(int x, int y, int tipo) {
        this->x = x;
        this->y = y;
        this->tipo = tipo;
        this->ancho = 250;
        this->alto = 250;
    }
    ~Basura() {

    }
    bool getActivo() {
        return activo;
    }
    void setActivo(bool activo) {
        this->activo = activo;
    }
    void dibujar(BufferedGraphics^ buffer, Bitmap^ bmp) override{
       
        if (tipo == 0)
        {
            indiceX = 0;
            indiceY = 0;
        }
        else if (tipo == 1) {
            indiceX = 1;
            indiceY = 0;
        }
        else if(tipo == 2)
        {
            indiceX = 0;
            indiceY = 1;
        }
        else if(tipo == 3)
        {
            indiceX = 1;
            indiceY = 1;
        }
        Rectangle porcionUsar = Rectangle(indiceX * ancho, indiceY * alto, ancho, alto);
        Rectangle aumentoPersonaje = Rectangle(x, y, ancho, alto);
        buffer->Graphics->DrawImage(bmp, aumentoPersonaje, porcionUsar, GraphicsUnit::Pixel);

    }
   
    

};
#endif // !_BASURA_H_
