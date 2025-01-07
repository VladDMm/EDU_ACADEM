#include "EditProfForm.h"
#include "IncludesCentral.h"

System::Void EduAc::EditProfForm::LoadProfData()
{
	SystemManagement* sys = SystemManagement::getInstance();
	System::String^ idManaged = id; // Asigură-te că 'id' este deja un System::String^
	std::string full_name, email, roll, phone, username, pass;

	std::string idConv = msclr::interop::marshal_as<std::string>(idManaged);
	// Elimină spațiile dinainte și după
	idConv.erase(0, idConv.find_first_not_of(" \n\r\t"));
	idConv.erase(idConv.find_last_not_of(" \n\r\t") + 1);
	// Conversia din System::String^ în std::string pentru metoda get_professor
	sys->get_professor(idConv, full_name, email, roll, phone, username, pass);
	this->fnameTextBox->Text = gcnew String(full_name.c_str());
	this->emailTextBox->Text = gcnew String(email.c_str());
	this->rollTextBox->Text = gcnew String(roll.c_str());
	this->phoneTextBox->Text = gcnew String(phone.c_str());
	this->usernameTextBox->Text = gcnew String(username.c_str());
	this->passwTextBox->Text = gcnew String(pass.c_str());
	
	//system->get_catedra();

	// Afișează rezultatele în TextBox-uri
//	this->textBox1->Text = gcnew String(depName.c_str());
//	this->textBox2->Text = gcnew String(facultyName.c_str());
}

System::Void EduAc::EditProfForm::confirmButton_Click(System::Object ^ sender, System::EventArgs ^ e)
{
	int dep_id = Convert::ToInt32(this->departComboBox->SelectedValue); // Preia ID-ul selectat
	String^ fullname = this->fnameTextBox->Text;
	String^ email = this->emailTextBox->Text;
	String^ roll = this->rollTextBox->Text;
	String^ phone = this->phoneTextBox->Text;
	String^ username = this->usernameTextBox->Text;
	String^ pass = this->passwTextBox->Text;
	System::String^ idManaged = id;

	if (String::IsNullOrEmpty(fullname) || String::IsNullOrEmpty(email) || String::IsNullOrEmpty(roll) || String::IsNullOrEmpty(phone) ||
		String::IsNullOrEmpty(username) || String::IsNullOrEmpty(pass))
	{
		MessageBox::Show("Completează toate câmpurile!", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
		return;
	}

	// Conversia din System::String^ în std::string pentru update_catedra
	SystemManagement* sys = SystemManagement::getInstance();
	/*sys->update_catedra(msclr::interop::marshal_as<std::string>(idManaged),
		msclr::interop::marshal_as<std::string>(depName),
		msclr::interop::marshal_as<std::string>(facultyName));*/

	MessageBox::Show("Departamentul a fost actualizat!", "Succes", MessageBoxButtons::OK, MessageBoxIcon::Information);
	this->Close();
}

System::Void EduAc::EditProfForm::cancelButton_Click(System::Object ^ sender, System::EventArgs ^ e)
{
	this->Close();
}
