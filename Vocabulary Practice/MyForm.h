#pragma once
#include "AskForm.h"
#include "SettingsForm.h"
namespace VocabularyPractice {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::IO;
	using namespace System::Collections::Generic;

	/// <summary>
	/// MyForm için özet
	/// </summary>


	public ref class MyForm : public System::Windows::Forms::Form
	{
	private:
		SettingsForm^ settingsForm;
		
	public:
		array<wchar_t>^ divider;
		array<bool>^ boolArrSettings;//[0]=shuffle [1]=reverse [2]=randomize reverse [3]=check correctness

		MyForm(void)
		{
			InitializeComponent();
			divider = gcnew array<wchar_t>(1);
			boolArrSettings = gcnew array<bool>(4);

			divider[0] = '=';
			boolArrSettings[0] = false;
			boolArrSettings[1] = false;
			boolArrSettings[2] = false;
			boolArrSettings[3] = false;
			settingsForm = gcnew SettingsForm(divider, boolArrSettings);
			//
			//TODO: Oluþturucu kodunu buraya ekle
			//
		}

	protected:
		/// <summary>
		///Kullanýlan tüm kaynaklarý temizleyin.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::OpenFileDialog^ openFileDialog1;
	private: System::Windows::Forms::Button^ btnSelectFile;


	private: System::Windows::Forms::TextBox^ textBoxDirectory;
	private: System::Windows::Forms::ListBox^ listBoxWords;
	private: System::Windows::Forms::Button^ btnAskSelected;




	private: System::Windows::Forms::Button^ btnSettings;





	protected:

	private:
		/// <summary>
		///Gerekli tasarýmcý deðiþkeni.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Tasarýmcý desteði için gerekli metot - bu metodun 
		///içeriðini kod düzenleyici ile deðiþtirmeyin.
		/// </summary>
		void InitializeComponent(void)
		{
			this->openFileDialog1 = (gcnew System::Windows::Forms::OpenFileDialog());
			this->btnSelectFile = (gcnew System::Windows::Forms::Button());
			this->textBoxDirectory = (gcnew System::Windows::Forms::TextBox());
			this->listBoxWords = (gcnew System::Windows::Forms::ListBox());
			this->btnAskSelected = (gcnew System::Windows::Forms::Button());
			this->btnSettings = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// openFileDialog1
			// 
			this->openFileDialog1->FileName = L"openFileDialog1";
			this->openFileDialog1->Filter = L"txt files (*.txt)|*.txt";
			this->openFileDialog1->RestoreDirectory = true;
			this->openFileDialog1->FileOk += gcnew System::ComponentModel::CancelEventHandler(this, &MyForm::openFileDialog1_FileOk);
			// 
			// btnSelectFile
			// 
			this->btnSelectFile->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(162)));
			this->btnSelectFile->Location = System::Drawing::Point(582, 347);
			this->btnSelectFile->Margin = System::Windows::Forms::Padding(0);
			this->btnSelectFile->Name = L"btnSelectFile";
			this->btnSelectFile->Size = System::Drawing::Size(89, 30);
			this->btnSelectFile->TabIndex = 1;
			this->btnSelectFile->Text = L"Select File";
			this->btnSelectFile->UseMnemonic = false;
			this->btnSelectFile->UseVisualStyleBackColor = true;
			this->btnSelectFile->Click += gcnew System::EventHandler(this, &MyForm::btnOpenFileDiolog_Click);
			// 
			// textBoxDirectory
			// 
			this->textBoxDirectory->Location = System::Drawing::Point(12, 354);
			this->textBoxDirectory->Name = L"textBoxDirectory";
			this->textBoxDirectory->ReadOnly = true;
			this->textBoxDirectory->Size = System::Drawing::Size(559, 20);
			this->textBoxDirectory->TabIndex = 2;
			// 
			// listBoxWords
			// 
			this->listBoxWords->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(162)));
			this->listBoxWords->FormattingEnabled = true;
			this->listBoxWords->HorizontalScrollbar = true;
			this->listBoxWords->ItemHeight = 16;
			this->listBoxWords->Location = System::Drawing::Point(12, 12);
			this->listBoxWords->Name = L"listBoxWords";
			this->listBoxWords->SelectionMode = System::Windows::Forms::SelectionMode::MultiExtended;
			this->listBoxWords->Size = System::Drawing::Size(759, 292);
			this->listBoxWords->TabIndex = 3;
			// 
			// btnAskSelected
			// 
			this->btnAskSelected->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(162)));
			this->btnAskSelected->Location = System::Drawing::Point(682, 347);
			this->btnAskSelected->Margin = System::Windows::Forms::Padding(0);
			this->btnAskSelected->Name = L"btnAskSelected";
			this->btnAskSelected->Size = System::Drawing::Size(89, 30);
			this->btnAskSelected->TabIndex = 4;
			this->btnAskSelected->Text = L"Start Asking";
			this->btnAskSelected->UseMnemonic = false;
			this->btnAskSelected->UseVisualStyleBackColor = true;
			this->btnAskSelected->Click += gcnew System::EventHandler(this, &MyForm::btnAskSelected_Click);
			// 
			// btnSettings
			// 
			this->btnSettings->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(162)));
			this->btnSettings->Location = System::Drawing::Point(682, 311);
			this->btnSettings->Margin = System::Windows::Forms::Padding(0);
			this->btnSettings->Name = L"btnSettings";
			this->btnSettings->Size = System::Drawing::Size(89, 30);
			this->btnSettings->TabIndex = 9;
			this->btnSettings->Text = L"Settings";
			this->btnSettings->UseMnemonic = false;
			this->btnSettings->UseVisualStyleBackColor = true;
			this->btnSettings->Click += gcnew System::EventHandler(this, &MyForm::btnSettings_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(780, 390);
			this->Controls->Add(this->btnSettings);
			this->Controls->Add(this->btnAskSelected);
			this->Controls->Add(this->listBoxWords);
			this->Controls->Add(this->textBoxDirectory);
			this->Controls->Add(this->btnSelectFile);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void openFileDialog1_FileOk(System::Object^ sender, System::ComponentModel::CancelEventArgs^ e) {

	}
	private: System::Void btnOpenFileDiolog_Click(System::Object^ sender, System::EventArgs^ e) {
		listBoxWords->Items->Clear();
		textBoxDirectory->Clear();
		StreamReader^ MyStream;
		List<int>^ newLineIndex = gcnew List<int>();
		try {
			if (openFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
				/*listBoxWords->Items->Clear();
				textBoxDirectory->Clear();*/
				if ((MyStream = File::OpenText(openFileDialog1->FileName)) != nullptr) {
					//MessageBox::Show("Found");
					textBoxDirectory->Text = openFileDialog1->FileName;
					addLinesToListBox(MyStream);
					MyStream->Close();
				}
				else{ MyStream->Close();}
			}
		}
		catch (Exception^ e)
		{
			if (dynamic_cast<UnauthorizedAccessException^>(e))
				MessageBox::Show(e->Message, "You don't have the authority ", MessageBoxButtons::OK, MessageBoxIcon::Error);
			if(dynamic_cast<ArgumentNullException^>(e))
				MessageBox::Show(e->Message, "Path is null", MessageBoxButtons::OK, MessageBoxIcon::Error);
			if (dynamic_cast<ArgumentException^>(e))
				MessageBox::Show(e->Message, "Path name is empty string / contains invalid characters/ consists of only white space", MessageBoxButtons::OK, MessageBoxIcon::Error);
			if (dynamic_cast<PathTooLongException^>(e))
				MessageBox::Show(e->Message, "Path Name Is Too Long", MessageBoxButtons::OK, MessageBoxIcon::Error);
			if (dynamic_cast<DirectoryNotFoundException^>(e))
				MessageBox::Show(e->Message, "Invalid Path", MessageBoxButtons::OK, MessageBoxIcon::Error);
			if (dynamic_cast<FileNotFoundException^>(e))
				MessageBox::Show(e->Message, "Path Not Found ", MessageBoxButtons::OK, MessageBoxIcon::Error);
			if (dynamic_cast<NotSupportedException^>(e))
				MessageBox::Show(e->Message, "Invalid Path Format", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
	}
	private: System::Void addLinesToListBox(StreamReader^ %MyStream) {
		String^ tempString = gcnew String("");
		int counter = 1;
		while ((tempString=MyStream->ReadLine())!=nullptr) {
			if (tempString->Length > 0 && tempString[0] != 0x5e)listBoxWords->Items->Add(Convert::ToString(counter++) + ") " + tempString);
		}
	}
	private: System::Void btnAskSelected_Click(System::Object^ sender, System::EventArgs^ e) {
		try {
			AskForm^ askForm = gcnew AskForm(listBoxWords, divider[0], boolArrSettings);
			askForm->ShowDialog();
			delete askForm;
		}
		catch (Exception^ e){
			MessageBox::Show(e->Message, "ERROR", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
	}

	private: System::Void btnSettings_Click(System::Object^ sender, System::EventArgs^ e) {
		settingsForm->ShowDialog();
	}
};
}
