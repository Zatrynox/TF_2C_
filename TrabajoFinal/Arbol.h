#pragma once
#ifndef _ARBOL_H_
#define _ARBOL_H_
#include "Semilla.h"

class Arbol {
private:
    int x, y, cantidadSemillas;
    Semilla* semillas; int encima;
public:
    Arbol() {
        this->x = 0;
        this->y = 0;
        this->cantidadSemillas = 0;
        this->semillas = NULL;
        this->encima = 0;

    }
  
    ~Arbol() {
    }
    void setx(int x) {
        this->x = x;
    }
    void sety(int y) {
        this->y = y;
    }
    int getx() {
        return x;
    }
    int gety() {
        return y;
    }
    int getcantidadSemillas() {
        return cantidadSemillas;

    }

    void aumentarMemoriaSemilla(BufferedGraphics^ buffer) {
        //semillas
        Semilla* semillasTemporal = new Semilla[cantidadSemillas + 1];
        for (int i = 0; i < cantidadSemillas; i++)
        {
            semillasTemporal[i] = semillas[i];
        }

        semillasTemporal[cantidadSemillas].setx(x - 5);
        semillasTemporal[cantidadSemillas].sety(y);

        
            delete[] semillas;
        
        cantidadSemillas++;
        semillas = new Semilla[cantidadSemillas];
        for (int i = 0; i < cantidadSemillas; i++) {
            semillas[i] = semillasTemporal[i];
        }
        if ((semillas[cantidadSemillas - 1].getx() == semillas[cantidadSemillas - 2].getx())
            && (semillas[cantidadSemillas - 1].gety() == semillas[cantidadSemillas - 2].gety()))
        {
            encima = 1;
        }
        if (semillasTemporal!=NULL)
        {
            delete[] semillasTemporal;

        }
        

    }

    void mostrarArboles(BufferedGraphics^ buffer) {
        for (int i = 0; i < cantidadSemillas; i++) {
            semillas[i].dibujarArboles(buffer);
        }
    }

    bool validadTodosArboles(int x, int y, int ancho, int alto) {
        if (cantidadSemillas == 0)
        {
            return false;
        }
        for (int i = 0; i < cantidadSemillas; i++)
        {
            if ((x + ancho > semillas[i].getx() + 46) && (semillas[i].getx() + 46 + 16 > x)
                && (y + alto > semillas[i].gety()) && (semillas[i].gety() + 85 > y))
            {

                return true;
            }
        }
        return false;

        
    }
    void validacionRegar(int score,int temp,BufferedGraphics^ buffer, int x, int y, int ancho, int alto) {
        for (int i = 0; i < cantidadSemillas; i++)
        {
            if ((x + ancho > semillas[i].getx() + 46) && (semillas[i].getx() + 46 + 16 > x)
                && (y + alto > semillas[i].gety()) && (semillas[i].gety() + 85 > y))
            {
                if (semillas[i].getCantidadMojado() != 1)
                {
                    semillas[i].setCantidadMojado(1);
                    score++;
                }
          
            }
        }


    }
    int scoreArboles() {
        for (int i = 0; i < cantidadSemillas; i++)
        {
            if (semillas[i].getCantidadMojado()==1 && semillas[i].getscoreAumentado()==0)
            {
                semillas[i].setscoreAumentado(1);
                return 1;
            }
        }
    }

    void mostrarArbolesQuemados(BufferedGraphics^ buffer, int temp2, int temp) {

        for (int i = 0; i < cantidadSemillas; i++) {
            if (semillas[i].getCantidadMojado() == 1)
            {
                semillas[i].dibujarArbolesRegados(temp2, buffer);
            }
            else
            {
                semillas[i].dibujarArbolQuemado(temp, buffer);

            }
        }
    }
};
#endif // !_CONTROLADORA_H_
