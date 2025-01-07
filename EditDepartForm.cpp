#include "EditDepartForm.h"
#include "IncludesCentral.h"

System::Void EduAc::EditDepartForm::LoadDepartData()
{
	SystemManagement* system = SystemManagement::getInstance();
	System::String^ idManaged = id; // Asigură-te că 'id' este deja un System::String^
	std::string depName, facultyName;

	std::string idConv = msclr::interop::marshal_as<std::string>(idManaged);
	// Elimină spațiile dinainte și după
	idConv.erase(0, idConv.find_first_not_of(" \n\r\t"));
	idConv.erase(idConv.find_last_not_of(" \n\r\t") + 1);
	// Conversia din System::String^ în std::string pentru metoda get_catedra
	system->get_catedra(idConv, depName, facultyName);

	// Afișează rezultatele în TextBox-uri
	this->textBox1->Text = gcnew String(depName.c_str());
	this->textBox2->Text = gcnew String(facultyName.c_str());
}

System::Void EduAc::EditDepartForm::confirm_button_Click(System::Object^ sender, System::EventArgs^ e)
{
	String^ depName = this->textBox1->Text;
	String^ facultyName = this->textBox2->Text;
	System::String^ idManaged = id;
	if (String::IsNullOrEmpty(depName) || String::IsNullOrEmpty(facultyName))
	{
		MessageBox::Show("Completează toate câmpurile!", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
		return;
	}

	// Conversia din System::String^ în std::string pentru update_catedra
	SystemManagement* system = SystemManagement::getInstance();
	system->update_catedra(msclr::interop::marshal_as<std::string>(idManaged),
		msclr::interop::marshal_as<std::string>(depName),
		msclr::interop::marshal_as<std::string>(facultyName));

	MessageBox::Show("Departamentul a fost actualizat!", "Succes", MessageBoxButtons::OK, MessageBoxIcon::Information);
	this->Close();
}

