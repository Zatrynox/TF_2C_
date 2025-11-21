#pragma once
#include <conio.h>
#include <iostream>
#include "PrimeraVictoria.h"
#include "Derrota.h"
#include "Bombero.h"
#include<conio.h>
#include<iostream>
#include<fstream>
#define TC 45

namespace PC02 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace std;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	private:
		int activado = 0;
		//
		int regado = 0;
		int mensaje = 0;
		int vez1 = 0;
		int vez2 = 0;
		int vez3 = 0;
		int vez4 = 0;
		int vez5 = 0;
		int vez6 = 0;
		//
		int score2 = 0;
		int vida = 100;
		char tecla;
		bool mostrado = false;
		int score = 0;
		int time = 0;
		//
		int time2 = 0;
		//
		int time3 = 0;
		//

		int cont = 0;
		int comentario = 0;
		Topo* topo1 = new Topo(1200, 300, 0, 0);//20
		Topo* topo2 = new Topo(450, 300, 0, 0);	//20
		Topo* topo3 = new Topo(1100, 500, 0, 0);	//02
		Topo* topo4 = new Topo(200, 500, 0, 0);	//02
		Topo* topo5 = new Topo(600, 600, 0, 0);	//20
		Topo* topo6 = new Topo(950, 700, 0, 0);	//02

		Jugador* jugador = new Jugador(50, 240);
		Bombero* bombero = new Bombero(50, 240);
		Arbol* arboles = new Arbol();

		Basura* basura1 = new Basura(50, 500, 0);
		Basura* basura2 = new Basura(350, 500, 1);
		Basura* basura3 = new Basura(1100, 600, 2);
		Basura* basura4 = new Basura(1200, 300, 3);
		Basura* basura5 = new Basura(700, 500, 1);
		Basura* basura6 = new Basura(600, 300, 0);



	private: System::Windows::Forms::Timer^ Time;
	private: System::Windows::Forms::Label^ TimeLbl;
	private: System::Windows::Forms::Label^ TimeLbl2;


		   Bitmap^ fondo = gcnew Bitmap("sprites/mapa1.png");
	private: System::Windows::Forms::Label^ Energia;
	private: System::Windows::Forms::Label^ Score;

		   Bitmap^ bomb = gcnew Bitmap("sprites/Bombero (1).png");

		   Bitmap^ topo = gcnew Bitmap("sprites/Rata.png");
		   Bitmap^ bmp = gcnew Bitmap("sprites/niño.png");
	private: System::Windows::Forms::Label^ LabelAdvertencia;

		   Bitmap^ basr = gcnew Bitmap("sprites/basura.png");


	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:


		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm()
		{
			if (components)
				delete components;

			delete jugador;
			delete arboles;
			delete basura1;
			delete basura2;
			delete basura3;
			delete basura4;
			delete basura5;
			delete basura6;
			delete fondo;
			delete bmp;
			delete basr;
		}
	private: System::Windows::Forms::Timer^ T1;
	protected:
	private: System::ComponentModel::IContainer^ components;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->T1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->Time = (gcnew System::Windows::Forms::Timer(this->components));
			this->TimeLbl = (gcnew System::Windows::Forms::Label());
			this->TimeLbl2 = (gcnew System::Windows::Forms::Label());
			this->Energia = (gcnew System::Windows::Forms::Label());
			this->Score = (gcnew System::Windows::Forms::Label());
			this->LabelAdvertencia = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// T1
			// 
			this->T1->Enabled = true;
			this->T1->Interval = 1;
			this->T1->Tick += gcnew System::EventHandler(this, &MyForm::T1_Tick);
			// 
			// Time
			// 
			this->Time->Enabled = true;
			this->Time->Interval = 1000;
			this->Time->Tick += gcnew System::EventHandler(this, &MyForm::Time_Tick);
			// 
			// TimeLbl
			// 
			this->TimeLbl->AutoSize = true;
			this->TimeLbl->BackColor = System::Drawing::Color::Black;
			this->TimeLbl->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 19.875F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->TimeLbl->Location = System::Drawing::Point(827, 45);
			this->TimeLbl->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->TimeLbl->Name = L"TimeLbl";
			this->TimeLbl->Size = System::Drawing::Size(164, 39);
			this->TimeLbl->TabIndex = 0;
			this->TimeLbl->Text = L"TIEMPO:";
			this->TimeLbl->Click += gcnew System::EventHandler(this, &MyForm::TimeLbl_Click);
			// 
			// TimeLbl2
			// 
			this->TimeLbl2->AutoSize = true;
			this->TimeLbl2->BackColor = System::Drawing::Color::Black;
			this->TimeLbl2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 19.875F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->TimeLbl2->Location = System::Drawing::Point(985, 45);
			this->TimeLbl2->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->TimeLbl2->Name = L"TimeLbl2";
			this->TimeLbl2->Size = System::Drawing::Size(37, 39);
			this->TimeLbl2->TabIndex = 1;
			this->TimeLbl2->Text = L"0";
			this->TimeLbl2->Click += gcnew System::EventHandler(this, &MyForm::TimeLbl2_Click);
			// 
			// Energia
			// 
			this->Energia->AutoSize = true;
			this->Energia->BackColor = System::Drawing::Color::Black;
			this->Energia->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 22.125F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Energia->Location = System::Drawing::Point(401, 45);
			this->Energia->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->Energia->Name = L"Energia";
			this->Energia->Size = System::Drawing::Size(84, 42);
			this->Energia->TabIndex = 2;
			this->Energia->Text = L"100";
			this->Energia->Click += gcnew System::EventHandler(this, &MyForm::label1_Click);
			// 
			// Score
			// 
			this->Score->AutoSize = true;
			this->Score->BackColor = System::Drawing::Color::Black;
			this->Score->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 22.125F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Score->Location = System::Drawing::Point(1707, 45);
			this->Score->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->Score->Name = L"Score";
			this->Score->Size = System::Drawing::Size(40, 42);
			this->Score->TabIndex = 3;
			this->Score->Text = L"0";
			this->Score->Click += gcnew System::EventHandler(this, &MyForm::label2_Click);
			// 
			// LabelAdvertencia
			// 
			this->LabelAdvertencia->AutoSize = true;
			this->LabelAdvertencia->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 22.125F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->LabelAdvertencia->Location = System::Drawing::Point(653, 292);
			this->LabelAdvertencia->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->LabelAdvertencia->Name = L"LabelAdvertencia";
			this->LabelAdvertencia->Size = System::Drawing::Size(0, 42);
			this->LabelAdvertencia->TabIndex = 4;
			this->LabelAdvertencia->Click += gcnew System::EventHandler(this, &MyForm::label1_Click_1);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::White;
			this->ClientSize = System::Drawing::Size(1283, 628);
			this->Controls->Add(this->LabelAdvertencia);
			this->Controls->Add(this->Score);
			this->Controls->Add(this->Energia);
			this->Controls->Add(this->TimeLbl2);
			this->Controls->Add(this->TimeLbl);
			this->ForeColor = System::Drawing::Color::LightCoral;
			this->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->WindowState = System::Windows::Forms::FormWindowState::Maximized;
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &MyForm::MyForm_FormClosing);
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MyForm::Presionar);
			this->KeyUp += gcnew System::Windows::Forms::KeyEventHandler(this, &MyForm::Soltar);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void T1_Tick(System::Object^ sender, System::EventArgs^ e) {

		Graphics^ g = this->CreateGraphics();
		BufferedGraphicsContext^ espacio = BufferedGraphicsManager::Current;
		BufferedGraphics^ buffer = espacio->Allocate(g, this->ClientRectangle);
		buffer->Graphics->Clear(Color::White);
		buffer->Graphics->DrawImage(fondo, 0, 0, this->Width, this->Height);

		

		this->TimeLbl2->Text = "" + time;
		this->Score->Text = "" + score;
		this->Energia->Text = "" + vida;

		//guardando datos

		//creamos la variable del archivo
		ofstream nomArch;

		//guardamos el score
		int puntaje = score;

		//apertura de archvio
		nomArch.open("Score.txt", ios::out);

		//verificacion
		if (nomArch.is_open()) {
			nomArch << "Puntaje: " << puntaje << endl;

			nomArch.close();
		}

		//


		if (time <= TC)
		{
			arboles->mostrarArboles(buffer);

			if (jugador->getx() < 0)
			{
				jugador->setvx(0);
			}
			if (jugador->getx() < this->Width - jugador->getAncho() - 5) {
				jugador->setvx(0);
			}
			if (jugador->gety() < 239)
			{
				jugador->setvy(0);
			}
			if (jugador->gety() < this->Height - jugador->getAlto() - 5) {
				jugador->setvy(0);
			}
			if (time >= 5 && score <= 5)
			{
				basura1->dibujar(buffer, basr);
				basura1->setActivo(true);
			}
			else
			{
				basura1->setActivo(false);

			}
			if (time >= 10 && score <= 8)
			{
				basura2->dibujar(buffer, basr);
				basura2->setActivo(true);
			}
			else
			{
				basura2->setActivo(false);

			}

			if (time >= 15 && score <= 10)
			{
				basura3->dibujar(buffer, basr);
				basura3->setActivo(true);
			}
			else
			{
				basura3->setActivo(false);

			}
			if (time >= 20 && score <= 15)
			{
				basura4->setActivo(true);

				basura4->dibujar(buffer, basr);
			}
			else
			{
				basura4->setActivo(false);

			}
			if (time >= 25 && score <= 20)

			{
				basura5->dibujar(buffer, basr);
				basura5->setActivo(true);
			}
			else
			{
				basura5->setActivo(false);

			}
			if (time >= 0)
			{
				basura6->dibujar(buffer, basr);
				basura6->setActivo(true);
			}
			else
			{
				basura6->setActivo(false);

			}
			//

			if (cont == 1)
			{
				arboles->aumentarMemoriaSemilla(buffer);
				cont = 0;
			}


			if (time2 % 3 == 0)
			{
				this->LabelAdvertencia->Text = "";
				time2 = 1;

			}
			topo1->setDespierto(jugador->ValidacionHitboxTopoRuido(topo1));
			topo2->setDespierto(jugador->ValidacionHitboxTopoRuido(topo2));
			topo3->setDespierto(jugador->ValidacionHitboxTopoRuido(topo3));
			topo4->setDespierto(jugador->ValidacionHitboxTopoRuido(topo4));
			topo5->setDespierto(jugador->ValidacionHitboxTopoRuido(topo5));
			topo6->setDespierto(jugador->ValidacionHitboxTopoRuido(topo6));

			if (topo1->getDespierto() == true && vez1 == 0)
			{
				vez1 = 1;
				topo1->setvx(2);
			}
			if (topo2->getDespierto() == true && vez2 == 0)
			{
				vez2 = 1;
				topo2->setvx(2);

			}
			if (topo3->getDespierto() == true && vez3 == 0)
			{
				vez3 = 1;
				topo3->setvy(2);

			}
			if (topo4->getDespierto() == true && vez4 == 0)
			{
				vez4 = 1;
				topo4->setvy(2);

			}
			if (topo5->getDespierto() == true && vez5 == 0)
			{
				vez5 = 1;
				topo5->setvx(2);

			}
			if (topo6->getDespierto() == true && vez6 == 0)
			{
				vez6 = 1;
				topo6->setvy(2);

			}

			topo1->mover(buffer, topo);
			topo2->mover(buffer, topo);
			topo3->mover(buffer, topo);
			topo4->mover(buffer, topo);
			topo5->mover(buffer, topo);
			topo6->mover(buffer, topo);



			vida = jugador->ValidacionHitboxTopoDaño(topo1, vida);
			vida = jugador->ValidacionHitboxTopoDaño(topo2, vida);
			vida = jugador->ValidacionHitboxTopoDaño(topo3, vida);
			vida = jugador->ValidacionHitboxTopoDaño(topo4, vida);
			vida = jugador->ValidacionHitboxTopoDaño(topo5, vida);
			vida = jugador->ValidacionHitboxTopoDaño(topo6, vida);
			jugador->verChoqueTopo(topo1, topo2);

			jugador->mover(buffer, bmp, basura6, basura1, basura2, basura3, basura4, basura5, arboles);

		}
		else if (time > TC)
		{
			if (score < 15)
			{
				vida = 0;
			}
			basura1->setActivo(false);
			basura2->setActivo(false);
			basura3->setActivo(false);
			basura4->setActivo(false);
			basura5->setActivo(false);
			basura6->setActivo(false);
			if (regado == 1)
			{
				arboles->validacionRegar(score, time, buffer, bombero->getx(), bombero->gety(),
				bombero->getAncho(), bombero->getAlto());
				regado = 0;
				activado = 1;
			}

			arboles->mostrarArbolesQuemados(buffer,time3,time);
			if (bombero->getx() < 0)
			{
				bombero->setvx(0);
			}
			if (bombero->getx() < this->Width - bombero->getAncho() - 5) {
				bombero->setvx(0);
			}
			if (bombero->gety() < 239)
			{
				bombero->setvy(0);
			}
			if (bombero->gety() < this->Height - bombero->getAlto() - 5) {
				bombero->setvy(0);
			}

			bombero->mover(buffer, bomb, basura6, basura1, basura2, basura3, basura4, basura5, arboles);
			
		}

		if (time == 95 && score == 2*score2 && !mostrado)
		{
			mostrado = true;
			this->Hide();  // Hide the current form
			PrimeraVictoria^ pvc = gcnew PrimeraVictoria();
			pvc->ShowDialog();  // Show victory screen (blocks until it closes)
			this->Close();  // Close the current form after the dialog is closed
		}
		else if ((vida == 0 && !mostrado) || (time == 95 && score < 2*score2 && !mostrado))
		{
			mostrado = true;
			this->Hide();  // Hide the current form
			Derrota^ der = gcnew Derrota();
			der->ShowDialog();  // Show defeat screen (blocks until it closes)
			this->Close();  
		}
			buffer->Render(g);
			
			delete buffer;
			delete espacio;
			delete g;

		
	}


	private: System::Void Presionar(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
		switch (e->KeyCode)
		{
		case Keys::A:

			jugador->direccion = Izquierda;
			bombero->direccion = Izquierda;



			break;
		case Keys::D:

			jugador->direccion = Derecha;
			bombero->direccion = Derecha;



			break;
		case Keys::W:

			jugador->direccion = Arriba;
			bombero->direccion = Arriba;


			break;

		case Keys::S:

			jugador->direccion = Abajo;
			bombero->direccion = Abajo;


			break;

		case Keys::E:
			if (time <= TC)
			{
				if (jugador->validacionPlantar(basura1, basura2, basura3, basura4, basura5,
					basura6, arboles) == 1)
				{
					score++;
					score2++;
					if (jugador->getUltima() == Arriba)
					{
						arboles->setx(jugador->getx());
						arboles->sety(jugador->gety() - 130);
					}
					else if (jugador->getUltima() == Abajo)
					{
						arboles->setx(jugador->getx());
						arboles->sety(jugador->gety() + 105);
					}
					else if (jugador->getUltima() == Derecha)
					{
						arboles->setx(jugador->getx() + 50);
						arboles->sety(jugador->gety());
					}
					else if (jugador->getUltima() == Izquierda)
					{
						arboles->setx(jugador->getx() - 90);
						arboles->sety(jugador->gety());
					}


					cont = 1;
				}
				else if (jugador->validacionPlantar(basura1, basura2, basura3, basura4, basura5,
					basura6, arboles) == 0)
				{
					mensaje = 1;
					this->LabelAdvertencia->Text = "NO PUEDES PLANTAR AQUÍ";

				}
			}
			else if (time > TC)
			{
				if (bombero->validacionPlantar(basura1, basura2, basura3, basura4, basura5,
					basura6, arboles) == 0)
				{
					regado = 1;
					time3 = 0;
					//
					if (arboles->scoreArboles() == 1)
					{
						score++;

					}
					
				}
			}


			break;
		case Keys::Escape:
			exit(0);
			break;
		}


	}
	private: System::Void Soltar(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {


		jugador->direccion = Ninguna;
	}
	private: System::Void Time_Tick(System::Object^ sender, System::EventArgs^ e) {
		time++;
		if (mensaje == 1)
		{
			time2++;

		}
		if (activado == 1 )
		{
			time3++;
			
		}
	}
	private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {

	}
	private: System::Void panel1_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {


	}
	private: System::Void TimeLbl_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void TimeLbl2_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void label2_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void label1_Click_1(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void MyForm_FormClosing(System::Object^ sender, System::Windows::Forms::FormClosingEventArgs^ e) {
	}
	};
}