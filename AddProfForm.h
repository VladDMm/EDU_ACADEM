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
	/// Summary for AddProfForm
	/// </summary>
	public ref class AddProfForm : public System::Windows::Forms::Form
	{
	private: MenuForm^ menuForm;
	public:
		AddProfForm(MenuForm^ parentForm, DataTable^ departmentData)
		{
			InitializeComponent();
			this->menuForm = parentForm;
			// Populate ComboBox with department data
			this->departComboBox->DataSource = departmentData;
			this->departComboBox->DisplayMember = "DepartmentInfo"; // Coloana care va fi afișată (id + nume)
			this->departComboBox->ValueMember = "ID"; // Coloana pentru valoare (ID-ul)
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~AddProfForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  addButton;
	protected:

	private: System::Windows::Forms::Button^  cancelButton;
	protected:

	private: System::Windows::Forms::TextBox^  phoneTextBox;
	private: System::Windows::Forms::TextBox^  emailTextBox;
	private: System::Windows::Forms::TextBox^  profRoleTextBox;
	private: System::Windows::Forms::TextBox^  fnameTextBox;
	private: System::Windows::Forms::TextBox^  passtextBox;
	private: System::Windows::Forms::TextBox^  usernTextBox;
	private: System::Windows::Forms::ComboBox^  departComboBox;

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
			this->addButton = (gcnew System::Windows::Forms::Button());
			this->cancelButton = (gcnew System::Windows::Forms::Button());
			this->phoneTextBox = (gcnew System::Windows::Forms::TextBox());
			this->emailTextBox = (gcnew System::Windows::Forms::TextBox());
			this->profRoleTextBox = (gcnew System::Windows::Forms::TextBox());
			this->fnameTextBox = (gcnew System::Windows::Forms::TextBox());
			this->passtextBox = (gcnew System::Windows::Forms::TextBox());
			this->usernTextBox = (gcnew System::Windows::Forms::TextBox());
			this->departComboBox = (gcnew System::Windows::Forms::ComboBox());
			this->SuspendLayout();
			// 
			// addButton
			// 
			this->addButton->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->addButton->Location = System::Drawing::Point(236, 289);
			this->addButton->Name = L"addButton";
			this->addButton->Size = System::Drawing::Size(111, 34);
			this->addButton->TabIndex = 0;
			this->addButton->Text = L"Adaugă";
			this->addButton->UseVisualStyleBackColor = true;
			this->addButton->Click += gcnew System::EventHandler(this, &AddProfForm::addButton_Click);
			// 
			// cancelButton
			// 
			this->cancelButton->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->cancelButton->Location = System::Drawing::Point(74, 289);
			this->cancelButton->Name = L"cancelButton";
			this->cancelButton->Size = System::Drawing::Size(89, 34);
			this->cancelButton->TabIndex = 1;
			this->cancelButton->Text = L"Anulează";
			this->cancelButton->UseVisualStyleBackColor = true;
			this->cancelButton->Click += gcnew System::EventHandler(this, &AddProfForm::cancelButton_Click);
			// 
			// phoneTextBox
			// 
			this->phoneTextBox->Location = System::Drawing::Point(74, 172);
			this->phoneTextBox->Name = L"phoneTextBox";
			this->phoneTextBox->Size = System::Drawing::Size(273, 22);
			this->phoneTextBox->TabIndex = 2;
			this->phoneTextBox->Text = L"Telefon";
			// 
			// emailTextBox
			// 
			this->emailTextBox->Location = System::Drawing::Point(74, 134);
			this->emailTextBox->Name = L"emailTextBox";
			this->emailTextBox->Size = System::Drawing::Size(273, 22);
			this->emailTextBox->TabIndex = 3;
			this->emailTextBox->Text = L"Email";
			// 
			// profRoleTextBox
			// 
			this->profRoleTextBox->Location = System::Drawing::Point(74, 96);
			this->profRoleTextBox->Name = L"profRoleTextBox";
			this->profRoleTextBox->Size = System::Drawing::Size(273, 22);
			this->profRoleTextBox->TabIndex = 4;
			this->profRoleTextBox->Text = L"Rol Profesor";
			// 
			// fnameTextBox
			// 
			this->fnameTextBox->Location = System::Drawing::Point(74, 59);
			this->fnameTextBox->Name = L"fnameTextBox";
			this->fnameTextBox->Size = System::Drawing::Size(273, 22);
			this->fnameTextBox->TabIndex = 5;
			this->fnameTextBox->Text = L"Nume, Prenume";
			// 
			// passtextBox
			// 
			this->passtextBox->Location = System::Drawing::Point(74, 249);
			this->passtextBox->Name = L"passtextBox";
			this->passtextBox->Size = System::Drawing::Size(273, 22);
			this->passtextBox->TabIndex = 6;
			this->passtextBox->Text = L"Parola";
			// 
			// usernTextBox
			// 
			this->usernTextBox->Location = System::Drawing::Point(74, 210);
			this->usernTextBox->Name = L"usernTextBox";
			this->usernTextBox->Size = System::Drawing::Size(273, 22);
			this->usernTextBox->TabIndex = 7;
			this->usernTextBox->Text = L"User Name";
			// 
			// departComboBox
			// 
			this->departComboBox->FormattingEnabled = true;
			this->departComboBox->Location = System::Drawing::Point(75, 20);
			this->departComboBox->Name = L"departComboBox";
			this->departComboBox->Size = System::Drawing::Size(273, 24);
			this->departComboBox->TabIndex = 8;
			// 
			// AddProfForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(421, 367);
			this->Controls->Add(this->departComboBox);
			this->Controls->Add(this->usernTextBox);
			this->Controls->Add(this->passtextBox);
			this->Controls->Add(this->fnameTextBox);
			this->Controls->Add(this->profRoleTextBox);
			this->Controls->Add(this->emailTextBox);
			this->Controls->Add(this->phoneTextBox);
			this->Controls->Add(this->cancelButton);
			this->Controls->Add(this->addButton);
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"AddProfForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterParent;
			this->Text = L"AddProfForm";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void cancelButton_Click(System::Object^  sender, System::EventArgs^  e) {
		this->Close();
	}
private: System::Void addButton_Click(System::Object^  sender, System::EventArgs^  e);

};
}
