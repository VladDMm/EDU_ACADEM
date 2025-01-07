#include "AddDepartForm.h"
#include "IncludesCentral.h"


//System::Void EduAc::AddDepartForm::confirmButton_Click(System::Object ^ sender, System::EventArgs ^ e)
//{
//	// obtine textul din textBox-uri
//	String^ dep_name = this->textBox1->Text;
//	String^ faculty_name = this->textBox2->Text;
//
//	// validare date introduse
//	if (String::IsNullOrEmpty(dep_name) || String::IsNullOrEmpty(faculty_name))
//	{
//		MessageBox::Show("Introdu campurile cu text!", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
//		return;
//	}
//	// obtine instanta si adauga catedra
//	SystemManagement *system = SystemManagement::getInstance();
//	if (system != nullptr)
//		system->add_catedra(msclr::interop::marshal_as< std::string >(dep_name), msclr::interop::marshal_as< std::string >(faculty_name));
//	else
//		MessageBox::Show("SystemManagement instance is not initialized!", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
//
//	// inchide formularul
//	this->Close();
//	
//	return System::Void();
//}

System::Void EduAc::AddDepartForm::confirmButton_Click(System::Object^ sender, System::EventArgs^ e)
{
	String^ dep_name = this->textBox1->Text;
	String^ faculty_name = this->textBox2->Text;

	if (String::IsNullOrEmpty(dep_name) || String::IsNullOrEmpty(faculty_name))
	{
		MessageBox::Show("Introdu campurile cu text!", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
		return;
	}

	// Adaugă în baza de date (presupunând că SystemManagement funcționează corect)
	SystemManagement* system = SystemManagement::getInstance();
	if (system != nullptr)
	{
		system->add_catedra(
			msclr::interop::marshal_as<std::string>(dep_name),
			msclr::interop::marshal_as<std::string>(faculty_name)
		);

		// Actualizează DataGridView în MenuForm
		if (this->menuForm != nullptr)
		{
			unsigned short id = db_conn.getLastInsertId();
			this->menuForm->AddRowToDepartDataGridView(id.ToString(), dep_name, faculty_name);
		}

		//MessageBox::Show("Catedra a fost adăugată cu succes!", "Success", MessageBoxButtons::OK, MessageBoxIcon::Information);
	}
	else
		MessageBox::Show("System is nullptr!", "Error", MessageBoxButtons::OK, MessageBoxIcon::Information);

	// Închide fereastra
	this->Close();
}
