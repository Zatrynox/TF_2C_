#pragma once
#include <fstream>
#include <iostream>
#include <string>

namespace PC02 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	public ref class PrimeraVictoria : public System::Windows::Forms::Form
	{
	private:
		Bitmap^ fondo = gcnew Bitmap("Sprites2/wingame.png");

	public:
		PrimeraVictoria(void)
		{
			InitializeComponent();
		}

	protected:
		~PrimeraVictoria()
		{
			if (components)
			{
				delete components;
			}
		}

	private:
		System::Windows::Forms::Label^ lblPuntj;
		System::ComponentModel::IContainer^ components;

#pragma region Windows Form Designer generated code
		void InitializeComponent(void)
		{
			this->lblPuntj = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// lblPuntj
			// 
			this->lblPuntj->AutoSize = true;
			this->lblPuntj->Location = System::Drawing::Point(196, 291);
			this->lblPuntj->Name = L"lblPuntj";
			this->lblPuntj->Size = System::Drawing::Size(35, 13);
			this->lblPuntj->TabIndex = 0;
			this->lblPuntj->Text = L"label1";
			// 
			// PrimeraVictoria
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(437, 441);
			this->Controls->Add(this->lblPuntj);
			this->Name = L"PrimeraVictoria";
			this->Text = L"PrimeraVictoria";
			this->WindowState = System::Windows::Forms::FormWindowState::Maximized;
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &PrimeraVictoria::PrimeraVictoria_FormClosing);
			this->Load += gcnew System::EventHandler(this, &PrimeraVictoria::PrimeraVictoria_Load);
			this->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &PrimeraVictoria::PrimeraVictoria_Paint);
			this->ResumeLayout(false);
			this->PerformLayout();
		}
#pragma endregion

	private:
		System::Void PrimeraVictoria_Load(System::Object^ sender, System::EventArgs^ e) {}

		System::Void PrimeraVictoria_FormClosing(System::Object^ sender, System::Windows::Forms::FormClosingEventArgs^ e) {}

		System::Void PrimeraVictoria_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
			Graphics^ g = e->Graphics;
			g->DrawImage(fondo, 0, 0, this->Width, this->Height);
			// Variables para leer el archivo
			std::ifstream nomArch("Score.txt", std::ios::in);
			int puntaj = 0;
			std::string line;

			if (nomArch.is_open()) {
				// Leer línea por línea
				while (std::getline(nomArch, line)) {
					// Buscar el número en el texto (después de "Puntaje: ")
					size_t pos = line.find("Puntaje: ");
					if (pos != std::string::npos) {
						try {
							std::string numberPart = line.substr(pos + 9); // Extraer solo el número
							puntaj = std::stoi(numberPart);               // Convertir el número a entero
						}
						catch (...) {
							puntaj = 0;  // En caso de error, el puntaje será 0
						}
					}
				}
				nomArch.close();
			}

			// Actualizar el texto del label
			this->lblPuntj->Text = "Tu puntaje: " + puntaj.ToString();
		}
	};
}
