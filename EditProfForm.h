#pragma once

namespace EduAc {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for EditProfForm
	/// </summary>
	public ref class EditProfForm : public System::Windows::Forms::Form
	{
	private:String^ id;
	public:
		EditProfForm(String^ prof_id, DataTable^ departmentData)
		{
			InitializeComponent();
			this->id = prof_id;

			this->departComboBox->DataSource = departmentData;
			this->departComboBox->DisplayMember = "DepartmentInfo"; // Coloana care va fi afișată (id + nume)
			this->departComboBox->ValueMember = "ID"; // Coloana pentru valoare (ID-ul)
			//
			//TODO: Add the constructor code here
			//
			LoadProfData();
		}
	private:
		System::Void LoadProfData();

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~EditProfForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TextBox^  fnameTextBox;
	protected:
	private: System::Windows::Forms::TextBox^  emailTextBox;
	private: System::Windows::Forms::TextBox^  rollTextBox;
	private: System::Windows::Forms::TextBox^  phoneTextBox;
	private: System::Windows::Forms::TextBox^  usernameTextBox;
	private: System::Windows::Forms::TextBox^  passwTextBox;
	private: System::Windows::Forms::ComboBox^  departComboBox;

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
			this->fnameTextBox = (gcnew System::Windows::Forms::TextBox());
			this->emailTextBox = (gcnew System::Windows::Forms::TextBox());
			this->rollTextBox = (gcnew System::Windows::Forms::TextBox());
			this->phoneTextBox = (gcnew System::Windows::Forms::TextBox());
			this->usernameTextBox = (gcnew System::Windows::Forms::TextBox());
			this->passwTextBox = (gcnew System::Windows::Forms::TextBox());
			this->departComboBox = (gcnew System::Windows::Forms::ComboBox());
			this->confirmButton = (gcnew System::Windows::Forms::Button());
			this->cancelButton = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// fnameTextBox
			// 
			this->fnameTextBox->Location = System::Drawing::Point(71, 55);
			this->fnameTextBox->Name = L"fnameTextBox";
			this->fnameTextBox->Size = System::Drawing::Size(266, 22);
			this->fnameTextBox->TabIndex = 0;
			// 
			// emailTextBox
			// 
			this->emailTextBox->Location = System::Drawing::Point(71, 95);
			this->emailTextBox->Name = L"emailTextBox";
			this->emailTextBox->Size = System::Drawing::Size(266, 22);
			this->emailTextBox->TabIndex = 1;
			// 
			// rollTextBox
			// 
			this->rollTextBox->Location = System::Drawing::Point(71, 133);
			this->rollTextBox->Name = L"rollTextBox";
			this->rollTextBox->Size = System::Drawing::Size(266, 22);
			this->rollTextBox->TabIndex = 2;
			// 
			// phoneTextBox
			// 
			this->phoneTextBox->Location = System::Drawing::Point(71, 174);
			this->phoneTextBox->Name = L"phoneTextBox";
			this->phoneTextBox->Size = System::Drawing::Size(266, 22);
			this->phoneTextBox->TabIndex = 3;
			// 
			// usernameTextBox
			// 
			this->usernameTextBox->Location = System::Drawing::Point(71, 216);
			this->usernameTextBox->Name = L"usernameTextBox";
			this->usernameTextBox->Size = System::Drawing::Size(266, 22);
			this->usernameTextBox->TabIndex = 4;
			// 
			// passwTextBox
			// 
			this->passwTextBox->Location = System::Drawing::Point(71, 257);
			this->passwTextBox->Name = L"passwTextBox";
			this->passwTextBox->Size = System::Drawing::Size(266, 22);
			this->passwTextBox->TabIndex = 5;
			// 
			// departComboBox
			// 
			this->departComboBox->FormattingEnabled = true;
			this->departComboBox->Location = System::Drawing::Point(71, 12);
			this->departComboBox->Name = L"departComboBox";
			this->departComboBox->Size = System::Drawing::Size(266, 24);
			this->departComboBox->TabIndex = 9;
			// 
			// confirmButton
			// 
			this->confirmButton->Location = System::Drawing::Point(226, 304);
			this->confirmButton->Name = L"confirmButton";
			this->confirmButton->Size = System::Drawing::Size(96, 33);
			this->confirmButton->TabIndex = 10;
			this->confirmButton->Text = L"Confirmă";
			this->confirmButton->UseVisualStyleBackColor = true;
			this->confirmButton->Click += gcnew System::EventHandler(this, &EditProfForm::confirmButton_Click);
			// 
			// cancelButton
			// 
			this->cancelButton->Location = System::Drawing::Point(86, 304);
			this->cancelButton->Name = L"cancelButton";
			this->cancelButton->Size = System::Drawing::Size(88, 33);
			this->cancelButton->TabIndex = 11;
			this->cancelButton->Text = L"Anulare";
			this->cancelButton->UseVisualStyleBackColor = true;
			this->cancelButton->Click += gcnew System::EventHandler(this, &EditProfForm::cancelButton_Click);
			// 
			// EditProfForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(410, 348);
			this->Controls->Add(this->cancelButton);
			this->Controls->Add(this->confirmButton);
			this->Controls->Add(this->departComboBox);
			this->Controls->Add(this->passwTextBox);
			this->Controls->Add(this->usernameTextBox);
			this->Controls->Add(this->phoneTextBox);
			this->Controls->Add(this->rollTextBox);
			this->Controls->Add(this->emailTextBox);
			this->Controls->Add(this->fnameTextBox);
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"EditProfForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterParent;
			this->Text = L"EditProfForm";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void confirmButton_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void cancelButton_Click(System::Object^  sender, System::EventArgs^  e);
};
}
