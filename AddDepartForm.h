#pragma once

#include "MenuForm.h"

namespace EduAc {
	
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	ref class MenuForm; // Forward declaration
	/// <summary>
	/// Summary for AddDepartForm
	/// </summary>
	public ref class AddDepartForm : public System::Windows::Forms::Form
	{
	private: MenuForm^ menuForm;
	public:
		AddDepartForm(MenuForm^ parentForm)
		{
			InitializeComponent();
			this->menuForm = parentForm; // Stochează referința la MenuForm
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~AddDepartForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TextBox^  textBox1;
	protected:
	private: System::Windows::Forms::TextBox^  textBox2;
	private: System::Windows::Forms::Button^  confirmButton;
	private: System::Windows::Forms::Button^  cancelButton;

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
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->confirmButton = (gcnew System::Windows::Forms::Button());
			this->cancelButton = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// textBox1
			// 
			this->textBox1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBox1->Location = System::Drawing::Point(35, 35);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(317, 30);
			this->textBox1->TabIndex = 0;
			this->textBox1->Text = L"Nume Departament";
			// 
			// textBox2
			// 
			this->textBox2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBox2->Location = System::Drawing::Point(35, 98);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(317, 30);
			this->textBox2->TabIndex = 1;
			this->textBox2->Text = L"Facultate";
			// 
			// confirmButton
			// 
			this->confirmButton->Location = System::Drawing::Point(209, 168);
			this->confirmButton->Name = L"confirmButton";
			this->confirmButton->Size = System::Drawing::Size(88, 32);
			this->confirmButton->TabIndex = 2;
			this->confirmButton->Text = L"Adaugă";
			this->confirmButton->UseVisualStyleBackColor = true;
			this->confirmButton->Click += gcnew System::EventHandler(this, &AddDepartForm::confirmButton_Click);
			// 
			// cancelButton
			// 
			this->cancelButton->Location = System::Drawing::Point(64, 168);
			this->cancelButton->Name = L"cancelButton";
			this->cancelButton->Size = System::Drawing::Size(84, 32);
			this->cancelButton->TabIndex = 3;
			this->cancelButton->Text = L"Anulare";
			this->cancelButton->UseVisualStyleBackColor = true;
			this->cancelButton->Click += gcnew System::EventHandler(this, &AddDepartForm::cancelButton_Click);
			// 
			// AddDepartForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(380, 238);
			this->Controls->Add(this->cancelButton);
			this->Controls->Add(this->confirmButton);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->textBox1);
			this->Name = L"AddDepartForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Adăgare Departament";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

private: System::Void confirmButton_Click(System::Object^  sender, System::EventArgs^  e);

private: System::Void cancelButton_Click(System::Object^  sender, System::EventArgs^  e) {
	this->Close();
}
};
}
