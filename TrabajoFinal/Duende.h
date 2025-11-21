#pragma once
#include "Caracter.h"

class Duende : public Character {
public:
    Duende(int width, int height) : Character(width, height) {
        x = 0;
        y = 0;
        dx = dy = 5;
        zoomxy = 1.6;
    }

    ~Duende() {}
    void move(Graphics^ g) {
        x += dx;

        if (x + width * zoomxy > g->VisibleClipBounds.Width / 4) {
            dx = -dx;
            x += dx;
            idy = 0;
        }
        if (x < 0) {

            dx = -dx;
            x += dx;
            idy = 1;
        }

        idx++;
        if (idx > 1) {
            idx = 0;

        }
    }
};