#pragma once
#include <msclr\marshal_cppstd.h>
#include "Impl.cpp"
namespace TiLFSR {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for LeftRegister
	/// </summary>
	public ref class LeftRegister : public System::Windows::Forms::Form
	{
	public:
		LeftRegister(void)
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
		~LeftRegister()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TextBox^ RegisterTextBox;
	private: System::Windows::Forms::MenuStrip^ FileMenu;
	private: System::Windows::Forms::ToolStripMenuItem^ FileMenuStrip;
	protected:


	private: System::Windows::Forms::ToolStripMenuItem^ EncryptSubMenu;
	private: System::Windows::Forms::ToolStripMenuItem^ DecryptSubMenu;




	private: System::Windows::Forms::Label^ RegisterLabel;

	private: System::Windows::Forms::RichTextBox^ EncryptFileBin;

	private: System::Windows::Forms::RichTextBox^ DecryptFileBin;
	private: System::Windows::Forms::Label^ EncryptFileLabel;
	private: System::Windows::Forms::Label^ ResultLabel;


	private: System::Windows::Forms::Label^ ResKeyTextBox;
	private: System::Windows::Forms::RichTextBox^ KeyTextBox;
	private: System::Windows::Forms::TextBox^ TBoxPolynom;
	private: System::Windows::Forms::Label^ PolynomLbl;






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
			this->RegisterTextBox = (gcnew System::Windows::Forms::TextBox());
			this->FileMenu = (gcnew System::Windows::Forms::MenuStrip());
			this->FileMenuStrip = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->EncryptSubMenu = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->DecryptSubMenu = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->RegisterLabel = (gcnew System::Windows::Forms::Label());
			this->EncryptFileBin = (gcnew System::Windows::Forms::RichTextBox());
			this->DecryptFileBin = (gcnew System::Windows::Forms::RichTextBox());
			this->EncryptFileLabel = (gcnew System::Windows::Forms::Label());
			this->ResultLabel = (gcnew System::Windows::Forms::Label());
			this->ResKeyTextBox = (gcnew System::Windows::Forms::Label());
			this->KeyTextBox = (gcnew System::Windows::Forms::RichTextBox());
			this->TBoxPolynom = (gcnew System::Windows::Forms::TextBox());
			this->PolynomLbl = (gcnew System::Windows::Forms::Label());
			this->FileMenu->SuspendLayout();
			this->SuspendLayout();
			// 
			// RegisterTextBox
			// 
			this->RegisterTextBox->Location = System::Drawing::Point(12, 63);
			this->RegisterTextBox->Name = L"RegisterTextBox";
			this->RegisterTextBox->Size = System::Drawing::Size(578, 22);
			this->RegisterTextBox->TabIndex = 0;
			this->RegisterTextBox->TextChanged += gcnew System::EventHandler(this, &LeftRegister::RegisterTextBox_TextChanged);
			// 
			// FileMenu
			// 
			this->FileMenu->ImageScalingSize = System::Drawing::Size(20, 20);
			this->FileMenu->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->FileMenuStrip });
			this->FileMenu->Location = System::Drawing::Point(0, 0);
			this->FileMenu->Name = L"FileMenu";
			this->FileMenu->Size = System::Drawing::Size(1474, 28);
			this->FileMenu->TabIndex = 1;
			this->FileMenu->Text = L"menuStrip1";
			// 
			// FileMenuStrip
			// 
			this->FileMenuStrip->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->EncryptSubMenu,
					this->DecryptSubMenu
			});
			this->FileMenuStrip->Enabled = false;
			this->FileMenuStrip->Name = L"FileMenuStrip";
			this->FileMenuStrip->Size = System::Drawing::Size(59, 24);
			this->FileMenuStrip->Text = L"Файл";
			// 
			// EncryptSubMenu
			// 
			this->EncryptSubMenu->Name = L"EncryptSubMenu";
			this->EncryptSubMenu->Size = System::Drawing::Size(189, 26);
			this->EncryptSubMenu->Text = L"Шифровать";
			this->EncryptSubMenu->Click += gcnew System::EventHandler(this, &LeftRegister::EncryptSubMenu_Click);
			// 
			// DecryptSubMenu
			// 
			this->DecryptSubMenu->Name = L"DecryptSubMenu";
			this->DecryptSubMenu->Size = System::Drawing::Size(189, 26);
			this->DecryptSubMenu->Text = L"Дешифровать";
			this->DecryptSubMenu->Click += gcnew System::EventHandler(this, &LeftRegister::DecryptSubMenu_Click);
			// 
			// RegisterLabel
			// 
			this->RegisterLabel->AutoSize = true;
			this->RegisterLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->RegisterLabel->Location = System::Drawing::Point(12, 28);
			this->RegisterLabel->Name = L"RegisterLabel";
			this->RegisterLabel->Size = System::Drawing::Size(437, 32);
			this->RegisterLabel->TabIndex = 3;
			this->RegisterLabel->Text = L"Начальное состояние регистра:";
			// 
			// EncryptFileBin
			// 
			this->EncryptFileBin->BackColor = System::Drawing::SystemColors::ButtonHighlight;
			this->EncryptFileBin->Location = System::Drawing::Point(12, 255);
			this->EncryptFileBin->Name = L"EncryptFileBin";
			this->EncryptFileBin->Size = System::Drawing::Size(578, 150);
			this->EncryptFileBin->TabIndex = 5;
			this->EncryptFileBin->Text = L"";
			// 
			// DecryptFileBin
			// 
			this->DecryptFileBin->BackColor = System::Drawing::SystemColors::ButtonHighlight;
			this->DecryptFileBin->ForeColor = System::Drawing::SystemColors::WindowText;
			this->DecryptFileBin->Location = System::Drawing::Point(692, 255);
			this->DecryptFileBin->Name = L"DecryptFileBin";
			this->DecryptFileBin->Size = System::Drawing::Size(578, 150);
			this->DecryptFileBin->TabIndex = 6;
			this->DecryptFileBin->Text = L"";
			// 
			// EncryptFileLabel
			// 
			this->EncryptFileLabel->AutoSize = true;
			this->EncryptFileLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16.2F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->EncryptFileLabel->Location = System::Drawing::Point(6, 220);
			this->EncryptFileLabel->Name = L"EncryptFileLabel";
			this->EncryptFileLabel->Size = System::Drawing::Size(233, 32);
			this->EncryptFileLabel->TabIndex = 7;
			this->EncryptFileLabel->Text = L"Исходный файл:";
			// 
			// ResultLabel
			// 
			this->ResultLabel->AutoSize = true;
			this->ResultLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->ResultLabel->Location = System::Drawing::Point(686, 220);
			this->ResultLabel->Name = L"ResultLabel";
			this->ResultLabel->Size = System::Drawing::Size(159, 32);
			this->ResultLabel->TabIndex = 8;
			this->ResultLabel->Text = L"Результат:";
			// 
			// ResKeyTextBox
			// 
			this->ResKeyTextBox->AutoSize = true;
			this->ResKeyTextBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->ResKeyTextBox->Location = System::Drawing::Point(12, 98);
			this->ResKeyTextBox->Name = L"ResKeyTextBox";
			this->ResKeyTextBox->Size = System::Drawing::Size(338, 32);
			this->ResKeyTextBox->TabIndex = 10;
			this->ResKeyTextBox->Text = L"Сгенерированный ключ:";
			// 
			// KeyTextBox
			// 
			this->KeyTextBox->BackColor = System::Drawing::SystemColors::ButtonHighlight;
			this->KeyTextBox->Location = System::Drawing::Point(18, 133);
			this->KeyTextBox->Name = L"KeyTextBox";
			this->KeyTextBox->Size = System::Drawing::Size(1252, 84);
			this->KeyTextBox->TabIndex = 11;
			this->KeyTextBox->Text = L"";
			// 
			// TBoxPolynom
			// 
			this->TBoxPolynom->BackColor = System::Drawing::SystemColors::HighlightText;
			this->TBoxPolynom->Enabled = false;
			this->TBoxPolynom->Location = System::Drawing::Point(692, 63);
			this->TBoxPolynom->Name = L"TBoxPolynom";
			this->TBoxPolynom->Size = System::Drawing::Size(578, 22);
			this->TBoxPolynom->TabIndex = 12;
			this->TBoxPolynom->Text = L"x^35+x^2+1";
			// 
			// PolynomLbl
			// 
			this->PolynomLbl->AutoSize = true;
			this->PolynomLbl->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->PolynomLbl->Location = System::Drawing::Point(686, 28);
			this->PolynomLbl->Name = L"PolynomLbl";
			this->PolynomLbl->Size = System::Drawing::Size(160, 32);
			this->PolynomLbl->TabIndex = 13;
			this->PolynomLbl->Text = L"Многочлен";
			// 
			// LeftRegister
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1474, 647);
			this->Controls->Add(this->PolynomLbl);
			this->Controls->Add(this->TBoxPolynom);
			this->Controls->Add(this->KeyTextBox);
			this->Controls->Add(this->ResKeyTextBox);
			this->Controls->Add(this->ResultLabel);
			this->Controls->Add(this->EncryptFileLabel);
			this->Controls->Add(this->DecryptFileBin);
			this->Controls->Add(this->EncryptFileBin);
			this->Controls->Add(this->RegisterLabel);
			this->Controls->Add(this->RegisterTextBox);
			this->Controls->Add(this->FileMenu);
			this->MainMenuStrip = this->FileMenu;
			this->MinimumSize = System::Drawing::Size(1371, 545);
			this->Name = L"LeftRegister";
			this->Text = L"Сдвиговый Регистр";
			this->FileMenu->ResumeLayout(false);
			this->FileMenu->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void RegisterTextBox_TextChanged(System::Object^ sender, System::EventArgs^ e) {
		if (this->RegisterTextBox->Text=="")  // change on length reg?
		this->FileMenuStrip->Enabled = false;
		else 
			this->FileMenuStrip->Enabled = true;
}
	
private: System::Void EncryptSubMenu_Click(System::Object^ sender, System::EventArgs^ e) {
	System::IO::Stream^ MyStream;
	OpenFileDialog^ OpenF = gcnew OpenFileDialog;
	OpenF->InitialDirectory = "C:\\Users\\User\\source\\repos\\TiLFSR";
	OpenF->FilterIndex = 1;
	OpenF->RestoreDirectory = true;

	if (OpenF->ShowDialog() == System::Windows::Forms::DialogResult::OK)
	{
		MyStream = OpenF->OpenFile();
		if (MyStream != nullptr)
		{

			std::string FilePath = msclr::interop::marshal_as<std::string>(OpenF->FileName);
			std::string regstr = msclr::interop::marshal_as<std::string>(RegisterTextBox->Text);
			KeyTextBox->Clear();
			EncryptFileBin->Clear();
			DecryptFileBin->Clear();
			try {
				LFSR::Encrypt(FilePath, regstr, KeyTextBox, EncryptFileBin, DecryptFileBin);
			}
			catch (System::String^ ex)
			{
				MessageBox::Show(ex, gcnew String("Error"), MessageBoxButtons::OK, MessageBoxIcon::Error);
			}
			MyStream->Close();
		}
	}
}

private: System::Void DecryptSubMenu_Click(System::Object^ sender, System::EventArgs^ e) {

	System::IO::Stream^ MyStream;
	OpenFileDialog^ OpenF = gcnew OpenFileDialog;
	OpenF->InitialDirectory = "C:\\Users\\User\\source\\repos\\TiLFSR";
	OpenF->FilterIndex = 1;
	OpenF->RestoreDirectory = true;
	OpenF->Filter= "Bin files (*.b2n)|*.b2n";
	if (OpenF->ShowDialog() == System::Windows::Forms::DialogResult::OK)
	{
		MyStream = OpenF->OpenFile();
		if (MyStream != nullptr)
		{

			std::string FilePath = msclr::interop::marshal_as<std::string>(OpenF->FileName);
			std::string regstr = msclr::interop::marshal_as<std::string>(RegisterTextBox->Text);
			KeyTextBox->Clear();
			EncryptFileBin->Clear();
			DecryptFileBin->Clear();
			try {
				LFSR::Decrypt(FilePath, regstr, KeyTextBox, EncryptFileBin, DecryptFileBin);
			}
			catch (System::String^ ex)
			{
				MessageBox::Show(ex, gcnew String("Error"), MessageBoxButtons::OK, MessageBoxIcon::Error);
			}
			MyStream->Close();
		}
	}
}

};
}
