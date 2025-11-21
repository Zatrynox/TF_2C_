#pragma once
#include "Inicio.h"
namespace PC02{

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;


	public ref class Entrada : public System::Windows::Forms::Form
	{
	private:
		//Buffer
		Graphics^ g;
		BufferedGraphicsContext^ space;
		BufferedGraphics^ buffer;


		Bitmap^ bmpMap;



		Bitmap^ bmpNombre;
		Bitmap^ bmpniña;
	private: System::Windows::Forms::Button^ button1;



	public:
		Entrada(void)
		{
			//srand(time(NULL));
			;		InitializeComponent();
			//Buffer
			g = panel1->CreateGraphics();
			space = BufferedGraphicsManager::Current;
			buffer = space->Allocate(g, panel1->ClientRectangle);

			//Bitmap

			bmpMap = gcnew Bitmap("Sprites2/menu2.png");
			bmpNombre = gcnew Bitmap("Sprites2/texto.png");
			bmpniña = gcnew Bitmap("Sprites2/elfo2.png");
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Entrada()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Panel^ panel1;
	private: System::Windows::Forms::Timer^ timerInicio;
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
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->timerInicio = (gcnew System::Windows::Forms::Timer(this->components));
			this->panel1->SuspendLayout();
			this->SuspendLayout();
			// 
			// panel1
			// 
			this->panel1->Controls->Add(this->button1);
			this->panel1->Location = System::Drawing::Point(-3, 1);
			this->panel1->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(1157, 682);
			this->panel1->TabIndex = 0;
			this->panel1->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &Entrada::panel1_Paint);
			// 
			// button1
			// 
			this->button1->BackColor = System::Drawing::Color::Green;
			this->button1->Font = (gcnew System::Drawing::Font(L"Microsoft Uighur", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button1->Location = System::Drawing::Point(490, 554);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(171, 54);
			this->button1->TabIndex = 0;
			this->button1->Text = L"PLAY";
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Click += gcnew System::EventHandler(this, &Entrada::button1_Click);
			// 
			// timerInicio
			// 
			this->timerInicio->Enabled = true;
			this->timerInicio->Tick += gcnew System::EventHandler(this, &Entrada::timer1_Tick);
			// 
			// Entrada
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1152, 682);
			this->Controls->Add(this->panel1);
			this->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->Name = L"Entrada";
			this->Text = L"REFOREST QUEST";
			this->panel1->ResumeLayout(false);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void panel1_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
		buffer->Graphics->Clear(Color::WhiteSmoke);
		buffer->Graphics->DrawImage(bmpMap, 0, 0, panel1->Width, panel1->Height);
		buffer->Graphics->DrawImage(bmpNombre, 110, 20, panel1->Width / 1.4, panel1->Height / 2.2);
		buffer->Graphics->DrawImage(bmpniña, 0, 280, panel1->Width /2, panel1->Height / 2.2);
		//niña->draw(buffer->Graphics, bmpniña);
		//niña->move(buffer->Graphics);
		buffer->Render(g);
	}
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Hide();
		ElMenu^ ge = gcnew ElMenu();
		ge->ShowDialog();
		this->Show();
		//niña->setVisible(false);
	}
	};

}