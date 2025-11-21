#pragma once
#ifndef _SEMILLA_H_
#define _SEMILLA_H_
#include "Entidad.h"
class Semilla : public Entidad {
private:
    int mojado = 0;
    int CantidadMojado = 0;
    int color = 0;
    int scoreAumentado = 0;
public:
    Semilla() {
        this->x = 0;
        this->y = 0;
        this->ancho = 105;
        this->alto = 146;
        this->indiceX = 0;
        this->indiceY = 0;
        this->mojado = 0;
        this->CantidadMojado = 0;
        this->color = 0;
    }
    Semilla(int x, int y, int mojado, int CantidadMojado) {
        this->x = x;
        this->y = y;
        this->mojado = mojado;
        this->CantidadMojado = CantidadMojado;
        this->ancho = 105;
        this->alto = 146;
    }
    ~Semilla() {
    }
    void setx(int x) {
        this->x = x;
    }
    void sety(int y) {
        this->y = y;
    }

    //
    void setscoreAumentado(int scoreAumentado) {
        this->scoreAumentado = scoreAumentado;
    }
    int getscoreAumentado() {
        return scoreAumentado;
    }
    //
    int getx() {
        return x;
    }
    int gety() {
        return y;
    }
    //
    void setMojado(int mojado) {
        this->mojado = mojado;
    }
    int getMojado() {
        return mojado;
    }
    void setCantidadMojado(int CantidadMojado) {
        this->CantidadMojado = CantidadMojado;
    }
    int getCantidadMojado() {
        return CantidadMojado;
    }
    void setColor(int color) {
        this->color = color;
    }
    int getColor() {
        return color;
    }
    void dibujarArboles(BufferedGraphics^ buffer) {
        Bitmap^ arbol = gcnew Bitmap("sprites/arbolr.png");
        Rectangle porcionUsar = Rectangle(indiceX * ancho, indiceY * alto, ancho, alto);
        Rectangle aumentoPersonaje = Rectangle(x, y, ancho, alto);
        buffer->Graphics->DrawImage(arbol, aumentoPersonaje, porcionUsar, GraphicsUnit::Pixel);

    }
    void dibujarArbolesRojosOscuros(BufferedGraphics^ buffer) {

        Bitmap^ arbolquemado2 = gcnew Bitmap("sprites/arbolQuemado2.png");
        Rectangle porcionUsar = Rectangle(indiceX * ancho, indiceY * alto, ancho, alto);
        Rectangle aumentoPersonaje = Rectangle(x, y, ancho, alto);
        buffer->Graphics->DrawImage(arbolquemado2, aumentoPersonaje, porcionUsar, GraphicsUnit::Pixel);

    }
    void dibujarArbolesRojos(BufferedGraphics^ buffer) {
        Bitmap^ arbolquemado = gcnew Bitmap("sprites/arbolQuemado.png");
        Rectangle porcionUsar = Rectangle(indiceX * ancho, indiceY * alto, ancho, alto);
        Rectangle aumentoPersonaje = Rectangle(x, y, ancho, alto);
        buffer->Graphics->DrawImage(arbolquemado, aumentoPersonaje, porcionUsar, GraphicsUnit::Pixel);


    }
    void dibujarArbolesRegados(int temp, BufferedGraphics^ buffer) {
        if (color== 1)
        {
            Bitmap^ arbol = gcnew Bitmap("sprites/arbolr.png");
            Rectangle porcionUsar = Rectangle(indiceX * ancho, indiceY * alto, ancho, alto);
            Rectangle aumentoPersonaje = Rectangle(x, y, ancho, alto);
            buffer->Graphics->DrawImage(arbol, aumentoPersonaje, porcionUsar, GraphicsUnit::Pixel);
            
        }
        else if(temp == 0 || temp == 1 || temp == 2)
        {
            Bitmap^ arbolmojado = gcnew Bitmap("sprites/arbolMojado.png");

            Rectangle porcionUsar = Rectangle(indiceX * ancho, indiceY * alto, ancho, alto);
            Rectangle aumentoPersonaje = Rectangle(x, y, ancho, alto);
            buffer->Graphics->DrawImage(arbolmojado, aumentoPersonaje, porcionUsar, GraphicsUnit::Pixel);

            if (temp == 2)
            {
                setColor(1);

            }
        }

    }

    void dibujarArbolQuemado(int temp, BufferedGraphics^ buffer) {
        if (temp % 2 == 0)
            dibujarArbolesRojosOscuros(buffer);
        else
            dibujarArbolesRojos(buffer);
    }

};
#endif // !_SEMILLA_H_
