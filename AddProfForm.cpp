#include "AddProfForm.h"
#include "IncludesCentral.h"

System::Void EduAc::AddProfForm::addButton_Click(System::Object^ sender, System::EventArgs^ e) {
	
	int dep_id = Convert::ToInt32(this->departComboBox->SelectedValue); // Preia ID-ul selectat
	String^ dep_name = Convert::ToString(this->departComboBox->SelectedValue);
	String^ full_name = this->fnameTextBox->Text;
	String^ proff_role = this->profRoleTextBox->Text;
	String^ email = this->emailTextBox->Text;
	String^ phone_numb = this->phoneTextBox->Text;
	String^ username = this->usernTextBox->Text;
	String^ pass = this->passtextBox->Text;

	if (String::IsNullOrEmpty(full_name) || String::IsNullOrEmpty(proff_role) || String::IsNullOrEmpty(email)
		|| String::IsNullOrEmpty(phone_numb) || String::IsNullOrEmpty(username) || String::IsNullOrEmpty(pass))
	{
		MessageBox::Show("Introdu campurile cu text!", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
		return;
	}

	SystemManagement *sys = SystemManagement::getInstance();
	sys->add_professor_to_department(dep_id, msclr::interop::marshal_as<std::string>(full_name), msclr::interop::marshal_as<std::string>(proff_role), msclr::interop::marshal_as<std::string>(email),
		msclr::interop::marshal_as<std::string>(phone_numb), msclr::interop::marshal_as<std::string>(username), msclr::interop::marshal_as<std::string>(pass));

	// Actualizează DataGridView în MenuForm
	if (this->menuForm != nullptr)
	{
		unsigned short id = db_conn.getLastInsertId();
		String^ idConv = System::Convert::ToString(id);
		this->menuForm->AddRowToProfDataGridView(idConv, full_name, proff_role, email, phone_numb, username, pass);
	}
}

