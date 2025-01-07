#pragma once

namespace EduAc {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for EditDepartForm
	/// </summary>
	public ref class EditDepartForm : public System::Windows::Forms::Form
	{
	private:
		String^ id;
	public:
		EditDepartForm(String^ depId)
		{
			InitializeComponent();
			this->id = depId;

			// Încarcă datele existente din baza de date
			LoadDepartData();
			//
			//TODO: Add the constructor code here
			//
		}
	private:
		System::Void LoadDepartData();

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~EditDepartForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TextBox^  textBox1;
	private: System::Windows::Forms::TextBox^  textBox2;
	private: System::Windows::Forms::Button^  confirm_button;
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
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->confirm_button = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(12, 51);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(258, 22);
			this->textBox1->TabIndex = 0;
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(12, 98);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(258, 22);
			this->textBox2->TabIndex = 1;
			// 
			// confirm_button
			// 
			this->confirm_button->Location = System::Drawing::Point(88, 138);
			this->confirm_button->Name = L"confirm_button";
			this->confirm_button->Size = System::Drawing::Size(100, 36);
			this->confirm_button->TabIndex = 2;
			this->confirm_button->Text = L"Confirmă";
			this->confirm_button->UseVisualStyleBackColor = true;
			this->confirm_button->Click += gcnew System::EventHandler(this, &EditDepartForm::confirm_button_Click);
			// 
			// EditDepartForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(282, 188);
			this->Controls->Add(this->confirm_button);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->textBox1);
			this->Name = L"EditDepartForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterParent;
			this->Text = L"Editare";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void confirm_button_Click(System::Object^  sender, System::EventArgs^  e);
	};
}
