#pragma once
namespace VocabularyPractice {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// SettingsForm için özet
	/// </summary>
	public ref class SettingsForm : public System::Windows::Forms::Form
	{
	private: System::Windows::Forms::CheckBox^ checkBoxRandomReverse;
	private: System::Windows::Forms::Label^ label4;



	private: array<bool>^ boolArr;
		     array<wchar_t>^ divider;
	public:
		SettingsForm(array<wchar_t>^ %incomingStrDivider, array<bool>^ %incomingBoolArr)
		{
			InitializeComponent();
			divider = gcnew array<wchar_t>(1);
			boolArr = gcnew array<bool>(4);

			divider = incomingStrDivider;
			boolArr = incomingBoolArr;
			//
			//TODO: Oluþturucu kodunu buraya ekle
			//
		}

	protected:
		/// <summary>
		///Kullanýlan tüm kaynaklarý temizleyin.
		/// </summary>
		~SettingsForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TextBox^ textBoxDivider;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::CheckBox^ checkBoxReverse;
	private: System::Windows::Forms::CheckBox^ checkBoxShuffle;

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
			this->textBoxDivider = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->checkBoxShuffle = (gcnew System::Windows::Forms::CheckBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->checkBoxReverse = (gcnew System::Windows::Forms::CheckBox());
			this->checkBoxRandomReverse = (gcnew System::Windows::Forms::CheckBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// textBoxDivider
			// 
			this->textBoxDivider->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(162)));
			this->textBoxDivider->Location = System::Drawing::Point(129, 25);
			this->textBoxDivider->MaxLength = 1;
			this->textBoxDivider->Name = L"textBoxDivider";
			this->textBoxDivider->Size = System::Drawing::Size(39, 21);
			this->textBoxDivider->TabIndex = 7;
			this->textBoxDivider->Text = L"=";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(19, 29);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(40, 13);
			this->label1->TabIndex = 8;
			this->label1->Text = L"Divider";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(19, 57);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(40, 13);
			this->label2->TabIndex = 9;
			this->label2->Text = L"Shuffle";
			// 
			// checkBoxShuffle
			// 
			this->checkBoxShuffle->AutoSize = true;
			this->checkBoxShuffle->Location = System::Drawing::Point(129, 56);
			this->checkBoxShuffle->Name = L"checkBoxShuffle";
			this->checkBoxShuffle->Size = System::Drawing::Size(15, 14);
			this->checkBoxShuffle->TabIndex = 10;
			this->checkBoxShuffle->UseVisualStyleBackColor = true;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(19, 85);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(47, 13);
			this->label3->TabIndex = 11;
			this->label3->Text = L"Reverse";
			// 
			// checkBoxReverse
			// 
			this->checkBoxReverse->AutoSize = true;
			this->checkBoxReverse->Location = System::Drawing::Point(129, 84);
			this->checkBoxReverse->Name = L"checkBoxReverse";
			this->checkBoxReverse->Size = System::Drawing::Size(15, 14);
			this->checkBoxReverse->TabIndex = 12;
			this->checkBoxReverse->UseVisualStyleBackColor = true;
			// 
			// checkBoxRandomReverse
			// 
			this->checkBoxRandomReverse->AutoSize = true;
			this->checkBoxRandomReverse->Location = System::Drawing::Point(129, 112);
			this->checkBoxRandomReverse->Name = L"checkBoxRandomReverse";
			this->checkBoxRandomReverse->Size = System::Drawing::Size(15, 14);
			this->checkBoxRandomReverse->TabIndex = 14;
			this->checkBoxRandomReverse->UseVisualStyleBackColor = true;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(19, 113);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(103, 13);
			this->label4->TabIndex = 13;
			this->label4->Text = L"Randomize Reverse";
			// 
			// SettingsForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(182, 139);
			this->Controls->Add(this->checkBoxRandomReverse);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->checkBoxReverse);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->checkBoxShuffle);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->textBoxDivider);
			this->Name = L"SettingsForm";
			this->Text = L"Settings";
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &SettingsForm::SettingsForm_FormClosing);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void SettingsForm_FormClosing(System::Object^ sender, System::Windows::Forms::FormClosingEventArgs^ e) {
		if (textBoxDivider->Text->Length < 1) {
			MessageBox::Show("Please specify the divider", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			e->Cancel = true;
			textBoxDivider->Text = "=";
		}
		divider[0] = textBoxDivider->Text[0];
		boolArr[0] = checkBoxShuffle->Checked;
		boolArr[1] = checkBoxReverse->Checked;
		boolArr[2] = checkBoxRandomReverse->Checked;
	}
};
}
