#pragma once
namespace PC02 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;


	public ref class Creditos : public System::Windows::Forms::Form
	{
	private:
		//Buffer
		Graphics^ g;
		BufferedGraphicsContext^ space;
		BufferedGraphics^ buffer;


		Bitmap^ bmpMap;



		Bitmap^ bmpNombre;
		Bitmap^ bmp1;
		Bitmap^ bmp2;
		Bitmap^ bmp3;





	public:
		Creditos(void)
		{
			//srand(time(NULL));
			;		InitializeComponent();
			//Buffer
			g = panel1->CreateGraphics();
			space = BufferedGraphicsManager::Current;
			buffer = space->Allocate(g, panel1->ClientRectangle);

			//Bitmap

			bmpMap = gcnew Bitmap("Sprites2/credi.png");
			bmpNombre = gcnew Bitmap("Sprites2/creditos.png");
			bmp1 = gcnew Bitmap("Sprites2/niño1.png");
			bmp2 = gcnew Bitmap("Sprites2/aki.png");
			bmp3 = gcnew Bitmap("Sprites2/niño5.png");

			//niña = new Niña(bmpniña->Width / 3, bmpniña->Height / 4);
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Creditos()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Panel^ panel1;
	private: System::Windows::Forms::Timer^ timercreditos;
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
			this->timercreditos = (gcnew System::Windows::Forms::Timer(this->components));
			this->SuspendLayout();
			// 
			// panel1
			// 
			this->panel1->Location = System::Drawing::Point(-3, 1);
			this->panel1->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(1157, 717);
			this->panel1->TabIndex = 0;
			this->panel1->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &Creditos::panel1_Paint);
			// 
			// timercreditos
			// 
			this->timercreditos->Enabled = true;
			this->timercreditos->Tick += gcnew System::EventHandler(this, &Creditos::timer1_Tick);
			// 
			// Creditos
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1152, 718);
			this->Controls->Add(this->panel1);
			this->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->Name = L"Creditos";
			this->Text = L"REFOREST QUEST";
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void panel1_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
		buffer->Graphics->Clear(Color::WhiteSmoke);
		buffer->Graphics->DrawImage(bmpMap, 0, 0, panel1->Width, panel1->Height);
		buffer->Graphics->DrawImage(bmpNombre, 240, 20, panel1->Width / 2.5, panel1->Height / 4);
		buffer->Graphics->DrawImage(bmp1, 10, 160, panel1->Width / 2.2, panel1->Height / 2.2);
		buffer->Graphics->DrawImage(bmp2, 240, 160, panel1->Width / 2.2, panel1->Height / 2.2);
		buffer->Graphics->DrawImage(bmp3, 460, 190, panel1->Width / 2.4, panel1->Height / 2.4);
		System::Drawing::Font^ customFont = gcnew System::Drawing::Font(L"Impact", 15, FontStyle::Bold);

		// Dibuja el texto "Hola que tal" en negro con la fuente más grande y gruesa
		buffer->Graphics->DrawString("VICTOR JHOSEF ", customFont, Brushes::Black, 370, 440);
		buffer->Graphics->DrawString("LAURA ACOSTA", customFont, Brushes::Black, 375, 460);

		buffer->Graphics->DrawString("LUIS YATZEL", customFont, Brushes::Black, 140, 440);
		buffer->Graphics->DrawString("MATA DOÑE", customFont, Brushes::Black, 140, 460);

		buffer->Graphics->DrawString("ISABEL APONTE", customFont, Brushes::Black, 570, 440);
		buffer->Graphics->DrawString("PABLO ", customFont, Brushes::Black, 600, 460);

		//niña->draw(buffer->Graphics, bmpniña);
		//niña->move(buffer->Graphics);
		buffer->Render(g);
	}
	private: System::Void button1_Click_1(System::Object^ sender, System::EventArgs^ e) {

	}
	};
}
