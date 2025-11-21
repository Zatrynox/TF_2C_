	#include "Entidad.h"
	#include "Arbol.h"
	#include "Basura.h"
	#include "Topo.h"


	enum Direcciones { Arriba, Abajo, Derecha, Izquierda, Ninguna };

	class Jugador : public Entidad
	{
	protected:
		int vx;
		int vy;
		Direcciones UltimaTecla;
		bool detener;
		int a;
		int b;
		int c;
		int d;


	public:
		Jugador() {
			this->x = 0;
			this->y = 0;
			this->vx = 0;
			this->vy = 0;
			this->ancho = 0.0;
			this->alto = 0.0;
			this->indiceX = 0;
			this->indiceY = 0;
			this->UltimaTecla = Ninguna;
		};

		//0,0
		Direcciones direccion;
		Jugador(int x, int y) {
			this->x = x;
			this->y = y;
			this->vx = 0;
			this->vy = 0;
			UltimaTecla = Abajo;
			direccion = Ninguna;
			//de cada 1
			ancho = 64;
			alto = 96;

		}
		~Jugador() {};


		Direcciones getDireccion() {
			return direccion;
		}
		Direcciones getUltima() {

			return UltimaTecla;
		}


		void setvx(int vx) {
			this->vx = vx;
		}
		void setvy(int vy) {
			this->vy = vy;

		}
		bool getDetener() {
			return detener;
		}
		void setDetener(bool detener) {
			this->detener = detener;
		}
		void dibujarP(BufferedGraphics^ buffer, Bitmap^ bmp){
			if (buffer == nullptr || bmp == nullptr)
			{
				return;
			}
			else
			{
				Rectangle porcionUsar = Rectangle(indiceX * ancho, indiceY * alto, ancho, alto);
				Rectangle aumentoPersonaje = Rectangle(x, y, ancho, alto);
				
				buffer->Graphics->DrawImage(bmp, aumentoPersonaje, porcionUsar, GraphicsUnit::Pixel);
				
				x += vx;
				y += vy;
			}
			
		
		}
		virtual void mover(BufferedGraphics^ buffer, Bitmap^ bmp, Basura* bsr, Basura* bsr2, Basura* bsr3, Basura* bsr4, Basura* bsr5, Basura* bsr6, Arbol* abl) {
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
					indiceY = 3;
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
					indiceY = 2;
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
					indiceY = 1;
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
		bool ValidacionHitboxArbol(Arbol* arbol) {
			return arbol->validadTodosArboles(x,y,ancho,alto);


		}
		bool ValidacionHitboxBasura(Basura* basura) {

			if ((x + ancho > basura->getx() + 82) && (basura->getx() + 250 > x)
				&& (y + alto > basura->gety() + 79) && (basura->gety() + 119 > y))
			{
				if (basura->getActivo() == true)
				{
					return true;

				}

			}

			return false;


		}
		bool ValidacionHitboxTopoRuido(Topo* topo) {
			if ((x + ancho > topo->getx()-50) && (topo->getx()+ 50 > x)
				&& (y + alto > topo->gety() -50) && (topo->gety()+50 > y))
			{
			
					return true;

			}

			return false;


		}
		int ValidacionHitboxTopoDaño(Topo* topo, int vida) {
			if ((x + ancho > topo->getx() +5) && (topo->getx() + 30 > x)
				&& (y + alto > topo->gety() + 10) && (topo->gety() + 20> y))
			{

				vida--;


			}

			return vida;

		}
		int validacionPlantar(Basura* bsr, Basura* bsr2, Basura* bsr3,
			Basura* bsr4, Basura* bsr5, Basura* bsr6, Arbol* abl) {

			int dato = 0;

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
				dato = 1;
			}

			return dato;


		}
		void verChoqueTopo(Topo* top, Topo* top2) {
			if ((top2->getx()+top2->getAncho() > top->getx()) && (top->getx() + top->getAncho() > top2->getx())
				&& (top2->gety() + top2->getAlto() > top->gety()) && (top->gety() + top->getAncho() > top2->gety()))
			{

				top->setvx(-top->getvx());
				top2->setvx(-top2->getvx());


			}

		}
	};

