#include "MenuForm.h"
#include "EditDepartForm.h"
#include "EditProfForm.h"
#include "AddProfForm.h"
#include <windows.h>    // Pentru LoadIcon, GetModuleHandle, HICON, NULL
#include <tchar.h>      // Pentru MAKEINTRESOURCE
#include <string>
#include "IncludesCentral.h"

void EduAc::MenuForm::AddRowToDepartDataGridView()
{
	// Obține datele din baza de date
	SystemManagement* system = SystemManagement::getInstance();
	system->initialize_catedre();
	std::map<unsigned short, Catedra> catedre = system->get_catedre();

	// Curăță grid-ul înainte de a adăuga date noi
	departGridView->Rows->Clear();

	// Adaugă datele în DataGridView
	for (const auto& pair : catedre) {
		unsigned short department_id = pair.first;
		const Catedra& catedra = pair.second;

		departGridView->Rows->Add(
			gcnew String(std::to_string(department_id).c_str()),
			gcnew String(catedra.get_name_catedra().c_str()),
			gcnew String(catedra.getFaculty().c_str())
		);
	}
}

void EduAc::MenuForm::AddRowToProfDataGridView()
{
	// Obține datele din baza de date
	auto proff_map = db_conn.selectProfessors();
	// Curăță grid-ul înainte de a adăuga date noi
	
	profGridView2->Rows->Clear();

	// Adaugă fiecare profesor în DataGridView
	for (const auto& prof : proff_map)
	{
		unsigned short id = std::get<0>(prof);
		std::string firstName = std::get<1>(prof);
		std::string roll = std::get<2>(prof);
		std::string email = std::get<3>(prof);
		std::string phone = std::get<4>(prof);
		std::string username = std::get<5>(prof);
		std::string pass = std::get<6>(prof);

		// Adaugă rândul în grid
		profGridView2->Rows->Add(
			gcnew String(std::to_string(id).c_str()), // ID-ul profesorului
			gcnew String(firstName.c_str()), // Prenumele
			gcnew String(roll.c_str()), // Numele
			gcnew String(email.c_str()), // Email-ul
			gcnew String(phone.c_str()), // Telefonul
			gcnew String(username.c_str()), // Departamentul
			gcnew String(pass.c_str()) // Facultatea
		);
	}
}

void EduAc::MenuForm::AddRowToStudDataGridView()
{
	throw gcnew System::NotImplementedException();
}

void EduAc::MenuForm::AddRowToGroupDataGridView()
{
	throw gcnew System::NotImplementedException();
}

void EduAc::MenuForm::AddRowToCourseDataGridView()
{
	throw gcnew System::NotImplementedException();
}

System::Void EduAc::MenuForm::menuPanel_SelectedIndexChanged(System::Object ^ sender, System::EventArgs ^ e)
{
	if (menuPanel->SelectedItem != nullptr) {
		System::String^ selectedItem = menuPanel->SelectedItem->ToString();

		// Mesaj de debug pentru a verifica valoarea selectată
		System::Diagnostics::Debug::WriteLine(L"Selected Item: " + selectedItem);

		if (System::String::Compare(selectedItem, L"Acasă", true) == 0) {
			tabControl1->SelectedTab = tabPageHome;
		}
		else if (System::String::Compare(selectedItem, L"Departamente", true) == 0) {
			tabControl1->SelectedTab = tabPageDepartamente;
			this->AddRowToDepartDataGridView();
		}
		else if (System::String::Compare(selectedItem, L"Profesori", true) == 0) {
			tabControl1->SelectedTab = tabPageProfesori;
			this->AddRowToProfDataGridView();
		}
		else if (System::String::Compare(selectedItem, L"Studenți", true) == 0) {
			tabControl1->SelectedTab = tabPageStudenti;
		}
		else if (System::String::Compare(selectedItem, L"Specialităţi", true) == 0) {
			tabControl1->SelectedTab = tabPageSpecialitati;
		}
		else if (System::String::Compare(selectedItem, L"Grupe", true) == 0) {
			tabControl1->SelectedTab = tabPageGroups;
		}
		else if (System::String::Compare(selectedItem, L"Cursuri", true) == 0) {
			tabControl1->SelectedTab = tabPageCourses;
		}
		else if (System::String::Compare(selectedItem, L"Note", true) == 0) {
			tabControl1->SelectedTab = tabPageMarks;
		}
		else if (System::String::Compare(selectedItem, L"Absenţe", true) == 0) {
			tabControl1->SelectedTab = tabPageAbsences;
		}
		else if (System::String::Compare(selectedItem, L"Examene", true) == 0) {
			tabControl1->SelectedTab = tabPageExam;
		}
		else if (System::String::Compare(selectedItem, L"Cont Utilizator", true) == 0) {
			tabControl1->SelectedTab = tabPageAccount;
		}
		
	}
}

System::Void EduAc::MenuForm::CustomizeListBox()
	{
		// Setăm ListBox pentru desenare personalizată
		menuPanel->DrawMode = System::Windows::Forms::DrawMode::OwnerDrawFixed;
		menuPanel->ItemHeight = 50; // Înălțimea fiecărui element
		//menuPanel->BackColor = System::Drawing::Color::White; // Fundalul ListBox-ului
		menuPanel->BorderStyle = System::Windows::Forms::BorderStyle::None;

		// Extindem menuPanel pentru a ocupa întreaga înălțime a ferestrei
		menuPanel->Dock = System::Windows::Forms::DockStyle::Fill;

		// Conectăm evenimentul DrawItem
		menuPanel->DrawItem += gcnew System::Windows::Forms::DrawItemEventHandler(this, &MenuForm::menuPanel_DrawItem);
	}

// Evenimentul DrawItem
System::Void EduAc::MenuForm::menuPanel_DrawItem(System::Object^ sender, System::Windows::Forms::DrawItemEventArgs^ e) {
	if (e->Index < 0) return; // Verificăm dacă indexul este valid

	// Pregătim zona elementului
	System::Drawing::Rectangle rect = System::Drawing::Rectangle(e->Bounds.X + 5, e->Bounds.Y + 5, e->Bounds.Width - 10, e->Bounds.Height - 10);

	// Creăm pensula pentru fundal
	System::Drawing::Brush^ backgroundBrush;

	// Fundal diferit dacă este selectat sau nu
	if ((e->State & System::Windows::Forms::DrawItemState::Selected) == System::Windows::Forms::DrawItemState::Selected) {
		// Fundal albastru pentru elementele selectate
		backgroundBrush = gcnew System::Drawing::SolidBrush(System::Drawing::Color::LightBlue);
	}
	else {
		// Fundal uniform (de exemplu, portocaliu deschis) pentru elementele ne-selectate
		backgroundBrush = gcnew System::Drawing::SolidBrush(System::Drawing::Color::FromArgb(227, 246, 245));
	}

	// Desenăm un dreptunghi cu colțuri rotunjite
	DrawRoundedRectangle(e->Graphics, rect, 10, backgroundBrush);

	//// Iconița
	//System::Drawing::Image^ icon = nullptr;
	//if (e->Index == 0) {
	//	icon = System::Drawing::Image::FromFile("C:\\Users\\Vladoss\\source\\repos\\EduAc\\ico\\add_group.png"); // Exemplu: imagine pentru "Acasă"
	//}
	//else if (e->Index == 1) {
	//	icon = System::Drawing::Image::FromFile("C:\\Users\\Vladoss\\source\\repos\\EduAc\\ico\\add_group.png"); // Exemplu: imagine pentru "Departamente"
	//}
	//else if (e->Index == 2) {
	//	icon = System::Drawing::Image::FromFile("C:\\Users\\Vladoss\\source\\repos\\EduAc\\ico\\add_group.png"); // Exemplu: imagine pentru "Profesori"
	//}
	//// Adaugă câte imagini vrei pentru alte elemente
	//if (icon != nullptr) {
	//	System::Drawing::Rectangle iconRect = System::Drawing::Rectangle(rect.X + 5, rect.Y + 5, 24, 24); // Dimensiune și poziție pentru iconiță
	//	e->Graphics->DrawImage(icon, iconRect);
	//}

	// Desenăm textul elementului
	System::String^ itemText = menuPanel->Items[e->Index]->ToString();
	System::Drawing::Brush^ textBrush = gcnew System::Drawing::SolidBrush(System::Drawing::Color::Black);
	System::Drawing::StringFormat^ stringFormat = gcnew System::Drawing::StringFormat();
	stringFormat->Alignment = System::Drawing::StringAlignment::Center; // Centrare orizontală
	stringFormat->LineAlignment = System::Drawing::StringAlignment::Center; // Centrare verticală
	e->Graphics->DrawString(itemText, e->Font, textBrush, rect, stringFormat);

	// Eliminăm desenarea focusului implicit
	//e->DrawFocusRectangle();
}

 // Funcție pentru a desena un dreptunghi cu colțuri rotunjite
void EduAc::MenuForm::DrawRoundedRectangle(System::Drawing::Graphics^ graphics, System::Drawing::Rectangle rect, int radius, System::Drawing::Brush^ brush) {
	// Definim un GraphicsPath pentru colțurile rotunjite
	System::Drawing::Drawing2D::GraphicsPath^ path = gcnew System::Drawing::Drawing2D::GraphicsPath();
	path->AddArc(rect.X, rect.Y, radius, radius, 180, 90); // Stânga sus
	path->AddArc(rect.X + rect.Width - radius, rect.Y, radius, radius, 270, 90); // Dreapta sus
	path->AddArc(rect.X + rect.Width - radius, rect.Y + rect.Height - radius, radius, radius, 0, 90); // Dreapta jos
	path->AddArc(rect.X, rect.Y + rect.Height - radius, radius, radius, 90, 90); // Stânga jos
	path->CloseFigure();

	// Umplem dreptunghiul cu brush-ul specificat
	graphics->FillPath(brush, path);
}
//
System::Void EduAc::MenuForm::addButton_Click(System::Object^ sender, System::EventArgs^ e) {

	// Creează o instanță a noii forme și transmite referința la MenuForm
	EduAc::AddDepartForm^ addDeptForm = gcnew EduAc::AddDepartForm(this);
	// Afișează forma în mod modal
	addDeptForm->ShowDialog();
}
//
System::Void EduAc::MenuForm::departGridView_CellContentClick(System::Object^  sender, System::Windows::Forms::DataGridViewCellEventArgs^  e)
{
	// Verifică dacă indexul rândului este valid
	if (e->RowIndex < 0) return;

	// Obține coloana apăsată
	String^ columnName = this->departGridView->Columns[e->ColumnIndex]->Name;

	// Obține ID-ul sau cheia primară din rând
	String^ id = this->departGridView->Rows[e->RowIndex]->Cells["department_id"]->Value->ToString();

	if (columnName == "edit_d")
	{
		// Deschide formularul de editare și transmite datele necesare
		EduAc::EditDepartForm^ editForm = gcnew EduAc::EditDepartForm(id);
		editForm->ShowDialog();

		// Actualizează rândul în DataGridView dacă e nevoie
		LoadDataFromDatabase(); // Exemplu: reîncarcă datele
	}
	else if (columnName == "delete_d")
	{
		// Confirmare pentru ștergere
		if (MessageBox::Show("Sigur doriți să ștergeți acest departament?", "Confirmare", MessageBoxButtons::YesNo, MessageBoxIcon::Warning) == System::Windows::Forms::DialogResult::Yes)
		{
			// Șterge din baza de date
			SystemManagement* system = SystemManagement::getInstance();
			system->delete_catedra(msclr::interop::marshal_as<std::string>(id));

			// Șterge rândul din DataGridView
			this->departGridView->Rows->RemoveAt(e->RowIndex);
		}
	}
}
//
System::Void EduAc::MenuForm::profGridView_CellContentClick(System::Object ^ sender, System::Windows::Forms::DataGridViewCellEventArgs ^ e)
{
	// Verifică dacă indexul rândului este valid
	if (e->RowIndex < 0) return;

	// Obține coloana apăsată
	String^ columnName = this->profGridView2->Columns[e->ColumnIndex]->Name;

	// Obține ID-ul sau cheia primară din rând
	String^ id = this->profGridView2->Rows[e->RowIndex]->Cells["id_proff"]->Value->ToString();

	if (columnName == "edit_p")
	{
		auto departments = GetDepartments();
		// Deschide formularul de editare și transmite datele necesare
		EduAc::EditProfForm^ editForm = gcnew EduAc::EditProfForm(id, departments);
		editForm->ShowDialog();
		
		// Actualizează rândul în DataGridView dacă e nevoie
		this->AddRowToProfDataGridView();
		//LoadDataFromDatabase(); // Exemplu: reîncarcă datele
	}
	else if (columnName == "delete_p")
	{
		// Confirmare pentru ștergere
		if (MessageBox::Show("Sigur doriți să ștergeți acest profesor?", "Confirmare", MessageBoxButtons::YesNo, MessageBoxIcon::Warning) == System::Windows::Forms::DialogResult::Yes)
		{
			// Șterge din baza de date
			SystemManagement* system = SystemManagement::getInstance();
			system->delete_professor(msclr::interop::marshal_as<std::string>(id)); // de sters profesor
			
			// Șterge rândul din DataGridView
			this->profGridView2->Rows->RemoveAt(e->RowIndex);
		}
	}
}
//
System::Void EduAc::MenuForm::LoadDataFromDatabase()
{
	this->departGridView->Rows->Clear();

	SystemManagement* system = SystemManagement::getInstance();
	std::vector<std::tuple<std::string, std::string, std::string>> data = system->get_all_catedre();

	for (const auto& row : data)
	{
		this->departGridView->Rows->Add(gcnew String(std::get<0>(row).c_str()), // ID
			gcnew String(std::get<1>(row).c_str()), // Nume departament
			gcnew String(std::get<2>(row).c_str())); // Facultate
	}
}
//
System::Void EduAc::MenuForm::addProfbutton_Click(System::Object^  sender, System::EventArgs^  e)
{
	// Creează o instanță a noii forme și transmite referința la MenuForm
	//EduAc::AddProfForm^ addDeptForm = gcnew EduAc::AddProfForm(this);

	//// Afișează forma în mod modal
	//addDeptForm->ShowDialog();

	DataTable^ departments = GetDepartments();
	AddProfForm^ addProfForm = gcnew AddProfForm(this, departments);
	addProfForm->ShowDialog();

}

//System::Void EduAc::MenuForm::menuPanel_DrawItem(System::Object^ sender, System::Windows::Forms::DrawItemEventArgs^ e) {
//	if (e->Index < 0) return;
//
//	// Declarăm variabila hIcon de tip HICON
//	HICON hIcon = NULL;
//
//	// Obținem zona elementului
//	System::Drawing::Rectangle rect = e->Bounds;
//	e->Graphics->FillRectangle(gcnew System::Drawing::SolidBrush(System::Drawing::Color::PeachPuff), rect);
//
//	// Fundal pentru element selectat
//	if ((e->State & System::Windows::Forms::DrawItemState::Selected) == System::Windows::Forms::DrawItemState::Selected) {
//		e->Graphics->FillRectangle(gcnew System::Drawing::SolidBrush(System::Drawing::Color::LightBlue), rect);
//	}
//
//	// Iconițe pentru fiecare element din listă
//	if (e->Index == 0) {
//		hIcon = LoadIcon(GetModuleHandle(NULL), MAKEINTRESOURCE(IDB_PNG1)); // Icon pentru "Acasă"
//	}
//	else if (e->Index == 1) {
//		hIcon = LoadIcon(GetModuleHandle(NULL), MAKEINTRESOURCE(IDB_PNG13)); // Icon pentru "Grupe"
//	}
//
//	// Desenăm iconița, dacă există
//	if (hIcon) {
//		System::Drawing::Icon^ icon = System::Drawing::Icon::FromHandle(System::IntPtr(hIcon));
//		e->Graphics->DrawIcon(icon, rect.X + 5, rect.Y + 5);
//	}
//
//	// Textul elementului
//	System::String^ itemText = menuPanel->Items[e->Index]->ToString();
//	System::Drawing::Brush^ textBrush = gcnew System::Drawing::SolidBrush(System::Drawing::Color::Black);
//	e->Graphics->DrawString(itemText, e->Font, textBrush, rect.X + 35, rect.Y + 5);
//
//	// Eliminăm focusul implicit
//	e->DrawFocusRectangle();
//}

// Evenimentul DrawItem
//System::Void EduAc::MenuForm::menuPanel_DrawItem(System::Object^ sender, System::Windows::Forms::DrawItemEventArgs^ e) {
//	if (e->Index < 0) return; // Verificăm dacă indexul este valid
//
//	// Pregătim zona elementului
//	System::Drawing::Rectangle rect = System::Drawing::Rectangle(e->Bounds.X + 5, e->Bounds.Y + 5, e->Bounds.Width - 10, e->Bounds.Height - 10);
//
//	// Creăm pensula pentru fundal
//	System::Drawing::Brush^ backgroundBrush;
//	if ((e->State & System::Windows::Forms::DrawItemState::Selected) == System::Windows::Forms::DrawItemState::Selected) {
//	//	 Fundal albastru dacă este selectat
//		backgroundBrush = gcnew System::Drawing::SolidBrush(System::Drawing::Color::LightBlue);
//	//	 Desenăm un dreptunghi cu colțuri rotunjite
//		DrawRoundedRectangle(e->Graphics, rect, 10, backgroundBrush);
//	}
//	else {
//	//	 Fundal alb pentru elementele ne-selectate
//		backgroundBrush = gcnew System::Drawing::SolidBrush(System::Drawing::Color::White);
//		e->Graphics->FillRectangle(backgroundBrush, rect);
//	}
//
//	// Desenăm textul elementului
//	System::String^ itemText = menuPanel->Items[e->Index]->ToString();
//	System::Drawing::Brush^ textBrush = gcnew System::Drawing::SolidBrush(System::Drawing::Color::Black);
//	System::Drawing::StringFormat^ stringFormat = gcnew System::Drawing::StringFormat();
//	stringFormat->Alignment = System::Drawing::StringAlignment::Center; // Centrare orizontală
//	stringFormat->LineAlignment = System::Drawing::StringAlignment::Center; // Centrare verticală
//	e->Graphics->DrawString(itemText, e->Font, textBrush, rect, stringFormat);
//
//	// Înlăturăm desenarea focusului implicit
//	// Comentăm sau eliminăm această linie pentru a nu desena conturul de selecție
//	 e->DrawFocusRectangle();
//}
