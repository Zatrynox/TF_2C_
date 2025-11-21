#pragma once
#include <iostream>
using namespace System::Drawing;
class Character {
protected:
	int x, y;
	int dx, dy;
	int width, height;
	int idx, idy;
	bool visible;
	float zoomxy;

public:
	Character(int width, int height) {
		this->width = width;
		this->height = height;
		idx = idy = 0;
		visible = true;
		zoomxy = 1.0;
	}
	Character(int x, int y, int width, int height) {
		this->x = x;
		this->y = y;
		this->width = width;
		this->height = height;
		idx = idy = 0;
		visible = true;
		zoomxy = 1.0;
	}

	~Character() {}

	void virtual draw(Graphics^ g, Bitmap^ bmp) {
		Rectangle sectionShown = Rectangle(idx * width, idy * height, width, height);
		Rectangle zoom = Rectangle(x, y, width * zoomxy, height * zoomxy);
		g->DrawImage(bmp, zoom, sectionShown, GraphicsUnit::Pixel);
	}

	void  virtual move() {}

};