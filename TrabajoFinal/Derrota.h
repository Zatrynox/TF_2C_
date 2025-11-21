#pragma once
namespace PC02 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for Derrota
	/// </summary>
	public ref class Derrota : public System::Windows::Forms::Form
	{
	private:
		Bitmap^ fondo = gcnew Bitmap("sprites/gameover.png");

	public:
		Derrota(void)
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
		~Derrota()
		{
			if (components)
			{
				delete components;
			}
		}

	protected:


	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->SuspendLayout();
			// 
			// Derrota
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(879, 536);
			this->Margin = System::Windows::Forms::Padding(2);
			this->Name = L"Derrota";
			this->Text = L"Derrota";
			this->WindowState = System::Windows::Forms::FormWindowState::Maximized;
			this->Load += gcnew System::EventHandler(this, &Derrota::Derrota_Load);
			this->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &Derrota::Derrota_Paint);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void Derrota_Load(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void Derrota_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
		Graphics^ g = e->Graphics;  
		g->DrawImage(fondo, 0, 0, this->Width, this->Height);
		System::Drawing::Font^ customFont = gcnew System::Drawing::Font(L"Impact", 15, FontStyle::Bold);

		// Dibuja el texto "Hola que tal" en negro con la fuente más grande y gruesa
		g->DrawString("NO LOGRASTE REFORESTAR", customFont, Brushes::Red, 660, 60);
		g->DrawString("PERDISTE ! ! ! ", customFont, Brushes::Red, 690, 625);

	}
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	};
}
