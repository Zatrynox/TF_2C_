#pragma once
#include "Duende.h"
namespace PC02 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for FrmMain
	/// </summary>
	public ref class Salida : public System::Windows::Forms::Form
	{
	private:
		//Buffer
		Graphics^ g;
		BufferedGraphicsContext^ space;
		BufferedGraphics^ buffer;

		//Bitmap
		Duende* plantas;
	private: System::Windows::Forms::Label^ label1;

		   Bitmap^ bmpPlan;

	public:
		Salida(void)
		{
			InitializeComponent();
			//Buffer
			g = panel1->CreateGraphics();
			space = BufferedGraphicsManager::Current;
			buffer = space->Allocate(g, panel1->ClientRectangle);

			bmpPlan = gcnew Bitmap("Sprites2/go.png");
			plantas = new Duende(bmpPlan->Width / 5, bmpPlan->Height / 5);



		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Salida()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Panel^ panel1;
	private: System::Windows::Forms::Timer^ tiempo3;
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
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->tiempo3 = (gcnew System::Windows::Forms::Timer(this->components));
			this->panel1->SuspendLayout();
			this->SuspendLayout();
			// 
			// panel1
			// 
			this->panel1->Controls->Add(this->label1);
			this->panel1->Location = System::Drawing::Point(1, 1);
			this->panel1->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(988, 703);
			this->panel1->TabIndex = 0;
			this->panel1->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &Salida::panel1_Paint_1);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->BackColor = System::Drawing::Color::LightSteelBlue;
			this->label1->Font = (gcnew System::Drawing::Font(L"MS Gothic", 25.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->ForeColor = System::Drawing::Color::White;
			this->label1->Location = System::Drawing::Point(802, 50);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(107, 43);
			this->label1->TabIndex = 0;
			this->label1->Text = L"EXIT";
			// 
			// tiempo3
			// 
			this->tiempo3->Enabled = true;
			this->tiempo3->Tick += gcnew System::EventHandler(this, &Salida::timer1_Tick);
			// 
			// Salida
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(991, 705);
			this->Controls->Add(this->panel1);
			this->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->Name = L"Salida";
			this->Text = L"Salida";
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &Salida::Salida_FormClosing);
			this->Load += gcnew System::EventHandler(this, &Salida::Salida_Load);
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e) {
		//if (buffer->Graphics != nullptr && g != nullptr) {
		buffer->Graphics->Clear(Color::WhiteSmoke);
		plantas->draw(buffer->Graphics, bmpPlan);
		plantas->move(buffer->Graphics);
		System::Drawing::Font^ customFont = gcnew System::Drawing::Font(L"Impact", 15, FontStyle::Bold);

		// Dibuja el texto "Hola que tal" en negro con la fuente más grande y gruesa
		buffer->Graphics->DrawString("UNTIL NEXT TIME", customFont, Brushes::White, 30, 60);
		buffer->Graphics->DrawString("THE GAME ENDS ", customFont, Brushes::White, 30, 85);
		buffer->Graphics->DrawString("BUT YOUR VICTORY SHINES ON! ", customFont, Brushes::White, 30, 110);

		buffer->Render(g);
		//}Until next time, the game ends, but your victory shines on!
	}
	private: System::Void panel1_Paint_1(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {

	}
	private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void pictureBox1_Click(System::Object^ sender, System::EventArgs^ e) {

	}
	private: System::Void progressBar1_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void Salida_Load(System::Object^ sender, System::EventArgs^ e) {

	}
	private: System::Void Salida_FormClosing(System::Object^ sender, System::Windows::Forms::FormClosingEventArgs^ e) {
		this->tiempo3->Stop();
	}
	};
}
