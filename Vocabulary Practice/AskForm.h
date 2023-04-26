#pragma once

namespace VocabularyPractice {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// AskForm için özet
	/// </summary>
	public ref class AskForm : public System::Windows::Forms::Form
	{
	private:
		ListBox^ listBoxWords;
		array<int>^ arrAskingOrder;
		array<bool>^ arrSettingBooleans;//[0]=shuffle [1]=reverse
		
		String^ firstHalf;
		String^ secondHalf;

		bool canWrite;
		int currentAskingIndex;
		int currentPos;
		wchar_t divider;


	public:
		AskForm(ListBox^ %incomingListBox, wchar_t incomingStr, array<bool>^ incomingBoolArr)
		{
			InitializeComponent();
			listBoxWords = gcnew ListBox;
			arrSettingBooleans = gcnew array<bool>(4);

			listBoxWords = incomingListBox;
			arrSettingBooleans = incomingBoolArr;
			divider = incomingStr;
			canWrite = true;

			firstHalf = "";
			secondHalf = "";
			currentAskingIndex = 0;
			currentPos = 0;

			arrAskingOrder = gcnew array<int>(listBoxWords->SelectedIndices->Count);
			//
			//TODO: Oluþturucu kodunu buraya ekle
			//
		}

	protected:
		/// <summary>
		///Kullanýlan tüm kaynaklarý temizleyin.
		/// </summary>
		~AskForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TextBox^ textBoxWord;
	protected:

	protected:

	protected:

	protected:

	protected:
	private: System::Windows::Forms::TextBox^ textBoxAnswer;
	private: System::Windows::Forms::Button^ btnNext;
	private: System::Windows::Forms::Button^ btnIncreaseFont;
	private: System::Windows::Forms::Button^ btnDecreaseFont;

	protected:

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
			this->textBoxWord = (gcnew System::Windows::Forms::TextBox());
			this->textBoxAnswer = (gcnew System::Windows::Forms::TextBox());
			this->btnNext = (gcnew System::Windows::Forms::Button());
			this->btnIncreaseFont = (gcnew System::Windows::Forms::Button());
			this->btnDecreaseFont = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// textBoxWord
			// 
			this->textBoxWord->Location = System::Drawing::Point(15, 36);
			this->textBoxWord->Multiline = true;
			this->textBoxWord->Name = L"textBoxWord";
			this->textBoxWord->ReadOnly = true;
			this->textBoxWord->ScrollBars = System::Windows::Forms::ScrollBars::Both;
			this->textBoxWord->Size = System::Drawing::Size(500, 175);
			this->textBoxWord->TabIndex = 0;
			// 
			// textBoxAnswer
			// 
			this->textBoxAnswer->Location = System::Drawing::Point(15, 230);
			this->textBoxAnswer->Name = L"textBoxAnswer";
			this->textBoxAnswer->Size = System::Drawing::Size(439, 20);
			this->textBoxAnswer->TabIndex = 1;
			// 
			// btnNext
			// 
			this->btnNext->Location = System::Drawing::Point(474, 231);
			this->btnNext->Name = L"btnNext";
			this->btnNext->Size = System::Drawing::Size(41, 19);
			this->btnNext->TabIndex = 2;
			this->btnNext->Text = L"Next";
			this->btnNext->UseVisualStyleBackColor = true;
			this->btnNext->Click += gcnew System::EventHandler(this, &AskForm::btnNext_Click);
			// 
			// btnIncreaseFont
			// 
			this->btnIncreaseFont->Location = System::Drawing::Point(15, 6);
			this->btnIncreaseFont->Name = L"btnIncreaseFont";
			this->btnIncreaseFont->Size = System::Drawing::Size(28, 24);
			this->btnIncreaseFont->TabIndex = 3;
			this->btnIncreaseFont->Text = L"A+";
			this->btnIncreaseFont->UseVisualStyleBackColor = true;
			this->btnIncreaseFont->Click += gcnew System::EventHandler(this, &AskForm::btnIncreaseFont_Click);
			// 
			// btnDecreaseFont
			// 
			this->btnDecreaseFont->Location = System::Drawing::Point(49, 6);
			this->btnDecreaseFont->Name = L"btnDecreaseFont";
			this->btnDecreaseFont->Size = System::Drawing::Size(28, 24);
			this->btnDecreaseFont->TabIndex = 4;
			this->btnDecreaseFont->Text = L"A-";
			this->btnDecreaseFont->UseVisualStyleBackColor = true;
			this->btnDecreaseFont->Click += gcnew System::EventHandler(this, &AskForm::btnDecreaseFont_Click);
			// 
			// AskForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(529, 261);
			this->Controls->Add(this->btnDecreaseFont);
			this->Controls->Add(this->btnIncreaseFont);
			this->Controls->Add(this->btnNext);
			this->Controls->Add(this->textBoxAnswer);
			this->Controls->Add(this->textBoxWord);
			this->Name = L"AskForm";
			this->Text = L"Asking";
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &AskForm::AskForm_FormClosing);
			this->Load += gcnew System::EventHandler(this, &AskForm::AskForm_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void AskForm_Load(System::Object^ sender, System::EventArgs^ e) {
		for (int i = 0;i < listBoxWords->SelectedIndices->Count;i++) {
			arrAskingOrder[i] = i;
		}
		if(arrSettingBooleans[0])shuffleIntArray();
		determineFirstHalf();
		determineSecondHalf();
		checkTextBoxStrSize(firstHalf->Length + secondHalf->Length + 5);//+5 for the divider and two new lines
		if(arrSettingBooleans[2])randomizeReverse();
		if (canWrite) {
			if(!arrSettingBooleans[1])textBoxWord->AppendText(firstHalf);
			else textBoxWord->AppendText(secondHalf);
		}
		/*textBoxWord->Text += "ssdasdefsf";
		textBoxWord->Select(1,5);
		textBoxWord->SelectionFont = gcnew System::Drawing::Font(textBoxWord->SelectionFont, System::Drawing::FontStyle::Strikeout);
		textBoxWord->SelectionColor = System::Drawing::Color::Red;*/
		
	}
	
	private: System::Void btnNext_Click(System::Object^ sender, System::EventArgs^ e) {
		if (canWrite) {
			if (!arrSettingBooleans[1])textBoxWord->Text += divider + secondHalf + "\r\n\r\n";
			else textBoxWord->Text += divider + firstHalf + "\r\n\r\n";

			determineFirstHalf();
			determineSecondHalf();
			checkTextBoxStrSize(firstHalf->Length + secondHalf->Length + 5);//+5 for the divider and two new lines
			if (arrSettingBooleans[2])randomizeReverse();
			if (canWrite) {
				if (!arrSettingBooleans[1])textBoxWord->AppendText(firstHalf);
				else textBoxWord->AppendText(secondHalf);
			}
		}
	}

	private: System::Void btnIncreaseFont_Click(System::Object^ sender, System::EventArgs^ e) {
		if (Convert::ToDouble(textBoxWord->Font->Size) < 20) {
			textBoxWord->Font = gcnew System::Drawing::Font(textBoxWord->Font->FontFamily, Convert::ToDouble(textBoxWord->Font->Size) + 1);
		}
	}

	private: System::Void btnDecreaseFont_Click(System::Object^ sender, System::EventArgs^ e) {
		if (Convert::ToDouble(textBoxWord->Font->Size) > 3) {
			textBoxWord->Font = gcnew System::Drawing::Font(textBoxWord->Font->FontFamily, Convert::ToDouble(textBoxWord->Font->Size) - 1);
		}
	}

	private: System::Void AskForm_FormClosing(System::Object^ sender, System::Windows::Forms::FormClosingEventArgs^ e) {
		delete arrAskingOrder;
		delete arrSettingBooleans;
		delete firstHalf;
		delete secondHalf;
	}

	private: System::Void shuffleIntArray() {
		int currentIndex = arrAskingOrder->Length;
		Random^ random = gcnew Random;
		int randomPos;
		int temp;
		while (currentIndex > 1) {
			randomPos = random->Next(currentIndex--);
			temp = arrAskingOrder[currentIndex];
			arrAskingOrder[currentIndex] = arrAskingOrder[randomPos];
			arrAskingOrder[randomPos] = temp;
		}
		delete random;
	}

	private: System::Void determineFirstHalf() {
		if (currentAskingIndex < arrAskingOrder->Length) {
			firstHalf = "";
			String^ tempStr;
			int strLength;

			tempStr = Convert::ToString(listBoxWords->SelectedItems[arrAskingOrder[currentAskingIndex]]);
			strLength = tempStr->Length;
			while ((currentPos < strLength) && (tempStr[currentPos++] != ')')) {}

			while (currentPos < strLength) {
				if (tempStr[currentPos] == divider) break;
				firstHalf += tempStr[currentPos++];
			}
			currentPos++;//to skip divider
			delete tempStr;
		}
		else canWrite = false;
	}

	private:System::Void determineSecondHalf() {
		if (currentAskingIndex < arrAskingOrder->Length) {
			secondHalf = "";
			String^ tempStr;
			int strLength;

			tempStr = Convert::ToString(listBoxWords->SelectedItems[arrAskingOrder[currentAskingIndex]]);
			strLength = tempStr->Length;
			while (currentPos < strLength) {
				secondHalf += tempStr[currentPos++];
			}
			currentAskingIndex++;
			currentPos = 0;
			
			delete tempStr;
		}
		else canWrite=false;
	}

	private:System::Boolean checkTextBoxStrSize(int strLength) {
		if (strLength + textBoxWord->Text->Length > textBoxWord->MaxLength) {
			MessageBox::Show("Max text length exceeded. Please start another asking queue.", "ERROR", MessageBoxButtons::OK, MessageBoxIcon::Error);
			canWrite = false;
			return false;
		}
		return true;
	}
	private: System::Void randomizeReverse() {
		Random^ random = gcnew Random;
		arrSettingBooleans[1] = random->Next(2);
		delete random;
	}
};
}
