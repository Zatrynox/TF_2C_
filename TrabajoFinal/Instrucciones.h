#pragma once
namespace PC02 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;


	public ref class Instrucciones : public System::Windows::Forms::Form
	{
	private:
		//Buffer
		Graphics^ g;
		BufferedGraphicsContext^ space;
		BufferedGraphics^ buffer;


		Bitmap^ bmpMap;
		Bitmap^ bmpComando;
		Bitmap^ bmpHola;
		Bitmap^ bmpBasura;
		Bitmap^ bmpNombre;
		Bitmap^ bmpEnemigos;

	private: System::Windows::Forms::Label^ label2;

		   Bitmap^ bmpniña;
		   //   Niña* niña;


	public:
		Instrucciones(void)
		{
			//srand(time(NULL));
			;		InitializeComponent();
			//Buffer
			g = panel1->CreateGraphics();
			space = BufferedGraphicsManager::Current;
			buffer = space->Allocate(g, panel1->ClientRectangle);

			//Bitmap

			bmpMap = gcnew Bitmap("Sprites2/dia.png");
			bmpNombre = gcnew Bitmap("Sprites2/instrucciones.png");
			bmpniña = gcnew Bitmap("Sprites2/niño6.png");
			bmpComando = gcnew Bitmap("Sprites2/wasd.png");
			bmpHola = gcnew Bitmap("Sprites2/hola.png");
			bmpniña->MakeTransparent(bmpniña->GetPixel(0, 0));
			bmpEnemigos = gcnew Bitmap("Sprites2/enemigo.png");
		    bmpBasura = gcnew Bitmap("Sprites2/basura1.png");
			//niña = new Niña(bmpniña->Width / 3, bmpniña->Height / 4);
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Instrucciones()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Panel^ panel1;
	private: System::Windows::Forms::Timer^ timerEntrada;
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
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->timerEntrada = (gcnew System::Windows::Forms::Timer(this->components));
			this->panel1->SuspendLayout();
			this->SuspendLayout();
			// 
			// panel1
			// 
			this->panel1->Controls->Add(this->label2);
			this->panel1->Location = System::Drawing::Point(-3, 1);
			this->panel1->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(1157, 692);
			this->panel1->TabIndex = 0;
			this->panel1->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &Instrucciones::panel1_Paint);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->BackColor = System::Drawing::Color::Black;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Tai Le", 7.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->ForeColor = System::Drawing::SystemColors::ControlLightLight;
			this->label2->Location = System::Drawing::Point(413, 348);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(26, 16);
			this->label2->TabIndex = 1;
			this->label2->Text = L"-->";
			this->label2->Click += gcnew System::EventHandler(this, &Instrucciones::label2_Click);
			// 
			// timerEntrada
			// 
			this->timerEntrada->Enabled = true;
			this->timerEntrada->Tick += gcnew System::EventHandler(this, &Instrucciones::timer1_Tick);
			// 
			// Instrucciones
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1152, 693);
			this->Controls->Add(this->panel1);
			this->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->Name = L"Instrucciones";
			this->Text = L"REFOREST QUEST";
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void panel1_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
		buffer->Graphics->DrawImage(bmpMap, 0, 0, panel1->Width, panel1->Height);
		buffer->Graphics->DrawImage(bmpNombre, 150, 20, panel1->Width / 1.5, panel1->Height / 3.5);
		buffer->Graphics->DrawImage(bmpniña, 150, 240, panel1->Width / 5, panel1->Height / 3.5);
		buffer->Graphics->DrawImage(bmpEnemigos, 540, 220, panel1->Width / 9, panel1->Height / 8);
		buffer->Graphics->DrawImage(bmpBasura, 700, 180, panel1->Width /7, panel1->Height /2.5);
		buffer->Graphics->DrawImage(bmpComando, 340, 270, panel1->Width / 15, panel1->Height / 13);
		buffer->Graphics->DrawImage(bmpHola, 200, 200, panel1->Width / 11, panel1->Height / 19);
		// Crear una fuente más grande y en negrita
		System::Drawing::Font^ customFont = gcnew System::Drawing::Font(L"Arial", 13, FontStyle::Bold);

		// Dibuja el texto "Hola que tal" en negro con la fuente más grande y gruesa
		buffer->Graphics->DrawString("MOVIMIENTO", customFont, Brushes::Black, 30, 300);
		buffer->Graphics->DrawString("ENEMIGOS", customFont, Brushes::Black , 410, 300);


		buffer->Graphics->DrawString("- El personaje se mueve con las teclas especiales WASD", customFont, Brushes::FloralWhite, 30, 435);
		buffer->Graphics->DrawString("- Cada que colisionas con los enemigos (ratones) pierdes energia ", customFont, Brushes::FloralWhite, 30, 450);
		buffer->Graphics->DrawString("- Tu misión es reforestar el medio ambiente contaminado y afectado por las desastres naturales", customFont, Brushes::FloralWhite, 30, 465);
		buffer->Graphics->DrawString("   y los  contaminantes, si logras reforestar el 70% ganas la partida ", customFont, Brushes::FloralWhite, 30, 480);
		buffer->Graphics->DrawString("- Tienes recursos para  completar tu mision, semillas, agua", customFont, Brushes::FloralWhite, 30, 497);
		buffer->Graphics->DrawString("- Si el tiempo llega a su limite  y la contaminación se extiende pierdes", customFont, Brushes::FloralWhite, 30, 512);
		buffer->Graphics->DrawString("- En la segunda fase debes regar las plantas y asi lograr ganar ", customFont, Brushes::FloralWhite, 30, 527);

		// Renderiza el contenido del buffer
		buffer->Render(e->Graphics);
	}

	private: System::Void button1_Click_1(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void label2_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void contextMenuStrip1_Opening(System::Object^ sender, System::ComponentModel::CancelEventArgs^ e) {
	}
	};
}
