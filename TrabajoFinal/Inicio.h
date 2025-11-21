#pragma once
#include "Instrucciones.h"
#include "Creditos.h"
#include "Salida.h"
#include "MyForm.h"
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
	public ref class ElMenu : public System::Windows::Forms::Form
	{
	private:
		//Buffer
		Graphics^ g;
		BufferedGraphicsContext^ space;
		BufferedGraphics^ buffer;

		//Bitmap
		Bitmap^ bmpNombre;
		Bitmap^ bmpPajaro;


		Bitmap^ bmpMap;
		Bitmap^ bmpIns;
	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Button^ button1;

		   Bitmap^ bmpInst;
	private: System::Windows::Forms::Button^ button4;
		   Bitmap^ bmpPlan;

	public:
		ElMenu(void)
		{
			InitializeComponent();
			//Buffer
			g = panel1->CreateGraphics();
			space = BufferedGraphicsManager::Current;
			buffer = space->Allocate(g, panel1->ClientRectangle);

			bmpMap = gcnew Bitmap("Sprites2/fondo2.png");
			bmpNombre = gcnew Bitmap("Sprites2/menu.png");
			bmpIns = gcnew Bitmap("Sprites2/todos.png");
			//	bmpInst = gcnew Bitmap("Sprites/instrucciones.png");


		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~ElMenu()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Panel^ panel1;
	private: System::Windows::Forms::Timer^ tiempo2;
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
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->tiempo2 = (gcnew System::Windows::Forms::Timer(this->components));
			this->panel1->SuspendLayout();
			this->SuspendLayout();
			// 
			// panel1
			// 
			this->panel1->Controls->Add(this->button4);
			this->panel1->Controls->Add(this->button1);
			this->panel1->Controls->Add(this->button3);
			this->panel1->Controls->Add(this->button2);
			this->panel1->Location = System::Drawing::Point(0, 1);
			this->panel1->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(1101, 726);
			this->panel1->TabIndex = 0;
			this->panel1->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &ElMenu::panel1_Paint_1);
			// 
			// button4
			// 
			this->button4->BackColor = System::Drawing::Color::DarkGoldenrod;
			this->button4->Font = (gcnew System::Drawing::Font(L"Agency FB", 7.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button4->Location = System::Drawing::Point(452, 671);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(112, 32);
			this->button4->TabIndex = 4;
			this->button4->Text = L"EXIT";
			this->button4->UseVisualStyleBackColor = false;
			this->button4->Click += gcnew System::EventHandler(this, &ElMenu::button4_Click);
			// 
			// button1
			// 
			this->button1->BackColor = System::Drawing::Color::Silver;
			this->button1->ForeColor = System::Drawing::SystemColors::ButtonFace;
			this->button1->Location = System::Drawing::Point(860, 407);
			this->button1->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(40, 32);
			this->button1->TabIndex = 3;
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Click += gcnew System::EventHandler(this, &ElMenu::button1_Click);
			// 
			// button3
			// 
			this->button3->BackColor = System::Drawing::Color::Silver;
			this->button3->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->button3->Location = System::Drawing::Point(857, 574);
			this->button3->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(43, 33);
			this->button3->TabIndex = 2;
			this->button3->UseVisualStyleBackColor = false;
			this->button3->Click += gcnew System::EventHandler(this, &ElMenu::button3_Click);
			// 
			// button2
			// 
			this->button2->BackColor = System::Drawing::Color::Silver;
			this->button2->ForeColor = System::Drawing::SystemColors::ButtonFace;
			this->button2->Location = System::Drawing::Point(860, 242);
			this->button2->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(40, 32);
			this->button2->TabIndex = 1;
			this->button2->UseVisualStyleBackColor = false;
			this->button2->Click += gcnew System::EventHandler(this, &ElMenu::button2_Click);
			// 
			// tiempo2
			// 
			this->tiempo2->Enabled = true;
			this->tiempo2->Tick += gcnew System::EventHandler(this, &ElMenu::timer1_Tick);
			// 
			// ElMenu
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1101, 729);
			this->Controls->Add(this->panel1);
			this->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->Name = L"ElMenu";
			this->Text = L"ElMenu";
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &ElMenu::ElMenu_FormClosing);
			this->Load += gcnew System::EventHandler(this, &ElMenu::ElMenu_Load);
			this->panel1->ResumeLayout(false);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e) {

	}
	private: System::Void panel1_Paint_1(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
		buffer->Graphics->DrawImage(bmpMap, 0, 0, panel1->Width, panel1->Height);
		buffer->Graphics->DrawImage(bmpNombre, 260, 10, panel1->Width / 3.1, panel1->Height / 3.5);
		buffer->Graphics->DrawImage(bmpIns, 110, 160, panel1->Width / 1.5, panel1->Height / 1.5);
		buffer->Render(g);
	}
	private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void pictureBox1_Click(System::Object^ sender, System::EventArgs^ e) {

	}
	private: System::Void progressBar1_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {

		this->Hide();
		Instrucciones^ ga = gcnew Instrucciones();
		ga->ShowDialog();
		this->Show();

	}
	private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Hide();
		Creditos^ ga = gcnew Creditos();
		ga->ShowDialog();
		this->Show();
	}
	private: System::Void ElMenu_Load(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void ElMenu_FormClosing(System::Object^ sender, System::Windows::Forms::FormClosingEventArgs^ e) {
		this->tiempo2->Stop();
	}
	private: System::Void button4_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Hide();
		Salida^ sal = gcnew Salida();
		sal->ShowDialog();
		this->Show();
	}
	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Hide();
		MyForm^ juego = gcnew MyForm();
		juego->ShowDialog();
		this->Show();
		this->Close();
	}
};
}
