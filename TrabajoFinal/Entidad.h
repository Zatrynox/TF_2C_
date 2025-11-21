#pragma once
#ifndef _ENTIDAD_H_
#define _ENTIDAD_H_
#include <iostream>
#include<conio.h>
using namespace System;
using namespace System::Drawing;


class Entidad{
protected:
    int x, y;
    double ancho, alto;
    int indiceX;
    int indiceY;
public:
    Entidad() {

    }
    ~Entidad() {
    }
    //
    double getAncho() {
        return ancho;
    }
    double getAlto() {
        return alto;
    }
    int getx() {
        return x;
    }
    int gety() {
        return y;
    }
    void setx(int x) {
        this->x = x;
    }
    void sety(int y) {
        this-> y = y;
    }
    //
    virtual void dibujar(BufferedGraphics^ buffer, Bitmap^ bmp) {

    }
   
};
#endif // !_ENTIDAD_H_
