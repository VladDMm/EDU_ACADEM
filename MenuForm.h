#pragma once
#include "AddDepartForm.h"
#include "IncludesCentral.h"

namespace EduAc {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MenuForm
	/// </summary>
	public ref class MenuForm : public System::Windows::Forms::Form
	{
	public:
		MenuForm(void)
		{
			InitializeComponent();
			
			tabControl1->Appearance = System::Windows::Forms::TabAppearance::Buttons;
			tabControl1->ItemSize = System::Drawing::Size(0, 1);
			tabControl1->SizeMode = System::Windows::Forms::TabSizeMode::Fixed;

			menuPanel->DrawMode = System::Windows::Forms::DrawMode::OwnerDrawFixed;
			menuPanel->ItemHeight = 50; // Setează înălțimea elementelor la 50 (crește spațiul între ele)
			
			this->Width = 1250;
			this->Height = 650;

			this->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
			CustomizeListBox();
		}
		void AddRowToDepartDataGridView();
		void AddRowToDepartDataGridView(String^ id, String^ dep_name, String^ faculty_name)
		{
			// Adaugă un rând în DataGridView
			this->departGridView->Rows->Add(gcnew cli::array<String^>{ id, dep_name, faculty_name });
		}
		void AddRowToProfDataGridView();
		void AddRowToProfDataGridView(String^ id, String^ full_name, String^ roll, String^ email, String^ phone, String^ username, String^ pass)
		{
			// Adaugă un rând în DataGridView
			this->profGridView2->Rows->Add(gcnew cli::array<String^>{ id, full_name, roll, email, phone, username, pass });
		}
		void AddRowToStudDataGridView();
		void AddRowToGroupDataGridView();
		void AddRowToCourseDataGridView();
		
		DataTable^ GetDepartments()
		{
			// Creează DataTable
			DataTable^ departments = gcnew DataTable();
			departments->Columns->Add("ID", int::typeid);                // Coloană pentru ID
			departments->Columns->Add("DepartmentInfo", String::typeid); // Coloană pentru informațiile departamentului

			// Obține instanța clasei SystemManagement
			SystemManagement* sys = SystemManagement::getInstance();

			// Obține lista de catedre
			std::vector<std::tuple<std::string, std::string, std::string>> catedre = sys->get_all_catedre();

			// Parcurge vectorul și adaugă datele în DataTable
			for (const auto& catedra : catedre)
			{
				// Extrage valorile din tuplu
				std::string idStr = std::get<0>(catedra);
				std::string departmentName = std::get<1>(catedra);
				std::string facultyName = std::get<2>(catedra);

				// Creează un text de afișare pentru a combina ID-ul, numele departamentului și facultatea
				std::string departmentInfo = idStr + " - " + departmentName + " (" + facultyName + ")";

				// Convertește valorile din std::string în System::String^
				int id = std::stoi(idStr); // Convertim ID-ul la int
				System::String^ cliDepartmentInfo = gcnew System::String(departmentInfo.c_str());

				// Adaugă un rând în DataTable
				departments->Rows->Add(id, cliDepartmentInfo);
			}

			return departments;
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MenuForm()
		{
			if (components)
			{
				delete components;
			}
		}





	private: System::Windows::Forms::Panel^  topPanel;
	private: System::Windows::Forms::TabControl^  tabControl1;
	private: System::Windows::Forms::TabPage^  tabPageHome;
	private: System::Windows::Forms::TabPage^  tabPageDepartamente;
	private: System::Windows::Forms::TabPage^  tabPageProfesori;
	private: System::Windows::Forms::TabPage^  tabPageStudenti;
	private: System::Windows::Forms::TabPage^  tabPageSpecialitati;

	private: System::Windows::Forms::TabPage^  tabPageGroups;
	private: System::Windows::Forms::TabPage^  tabPageCourses;
	private: System::Windows::Forms::TabPage^  tabPageMarks;
	private: System::Windows::Forms::TabPage^  tabPageAbsences;
	private: System::Windows::Forms::TabPage^  tabPageExam;
	private: System::Windows::Forms::TabPage^  tabPageAccount;
	private: System::Windows::Forms::ListBox^  menuPanel;
	private: System::Windows::Forms::Panel^  panel1;


	private: System::Windows::Forms::DataGridView^  departGridView;



	private: System::Windows::Forms::Button^  addButton;





	private: System::Windows::Forms::Button^  addStudButton;

	private: System::Windows::Forms::DataGridView^  studGridView1;



















	private: System::Windows::Forms::Button^  addSpecialtybutton;
	private: System::Windows::Forms::DataGridView^  specialtyGridView1;













	private: System::Windows::Forms::DataGridViewTextBoxColumn^  idSpecialty;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  denumire_specialitate;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  departament;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  director_program;
	private: System::Windows::Forms::DataGridViewButtonColumn^  edit_s;
	private: System::Windows::Forms::DataGridViewButtonColumn^  delete_s;
private: System::Windows::Forms::Button^  addProfbutton;








private: System::Windows::Forms::DataGridViewTextBoxColumn^  id_stud;
private: System::Windows::Forms::DataGridViewTextBoxColumn^  stud_name;
private: System::Windows::Forms::DataGridViewTextBoxColumn^  email_st;
private: System::Windows::Forms::DataGridViewTextBoxColumn^  phone_st;
private: System::Windows::Forms::DataGridViewTextBoxColumn^  grupa_st;
private: System::Windows::Forms::DataGridViewButtonColumn^  edit_st;
private: System::Windows::Forms::DataGridViewButtonColumn^  dell_st;
private: System::Windows::Forms::DataGridView^  profGridView2;








private: System::Windows::Forms::Button^  button1;
private: System::Windows::Forms::DataGridView^  groupGridView3;

private: System::Windows::Forms::DataGridViewTextBoxColumn^  id_group;
private: System::Windows::Forms::DataGridViewTextBoxColumn^  group_name;
private: System::Windows::Forms::DataGridViewTextBoxColumn^  study_year;
private: System::Windows::Forms::DataGridViewTextBoxColumn^  deparment_group;
private: System::Windows::Forms::DataGridViewTextBoxColumn^  specialty_id;
private: System::Windows::Forms::DataGridViewButtonColumn^  edit_gr;
private: System::Windows::Forms::DataGridViewButtonColumn^  delete_gr;
private: System::Windows::Forms::DataGridView^  coursGridView;


private: System::Windows::Forms::DataGridViewTextBoxColumn^  course_id;
private: System::Windows::Forms::DataGridViewTextBoxColumn^  course_name;
private: System::Windows::Forms::DataGridViewTextBoxColumn^  nr_credits;
private: System::Windows::Forms::DataGridViewTextBoxColumn^  proffesor_id;
private: System::Windows::Forms::DataGridViewButtonColumn^  edit_c;
private: System::Windows::Forms::DataGridViewButtonColumn^  delete_c;
private: System::Windows::Forms::Button^  addCoursebutton;
private: System::Windows::Forms::Button^  addMarkbutton;
private: System::Windows::Forms::DataGridView^  dataGridView1;
private: System::Windows::Forms::DataGridViewTextBoxColumn^  department_id;
private: System::Windows::Forms::DataGridViewTextBoxColumn^  denumire_departament;
private: System::Windows::Forms::DataGridViewTextBoxColumn^  facultate_depart;
private: System::Windows::Forms::DataGridViewButtonColumn^  edit_d;
private: System::Windows::Forms::DataGridViewButtonColumn^  delete_d;
private: System::Windows::Forms::DataGridViewTextBoxColumn^  id_proff;
private: System::Windows::Forms::DataGridViewTextBoxColumn^  fullname_prof;
private: System::Windows::Forms::DataGridViewTextBoxColumn^  proff_role;
private: System::Windows::Forms::DataGridViewTextBoxColumn^  email_proff;
private: System::Windows::Forms::DataGridViewTextBoxColumn^  phone_prof;
private: System::Windows::Forms::DataGridViewTextBoxColumn^  username_prof;
private: System::Windows::Forms::DataGridViewTextBoxColumn^  pass_prof;
private: System::Windows::Forms::DataGridViewButtonColumn^  edit_p;
private: System::Windows::Forms::DataGridViewButtonColumn^  delete_p;























































































































































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
			System::Windows::Forms::DataGridViewCellStyle^  dataGridViewCellStyle1 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			this->topPanel = (gcnew System::Windows::Forms::Panel());
			this->tabControl1 = (gcnew System::Windows::Forms::TabControl());
			this->tabPageHome = (gcnew System::Windows::Forms::TabPage());
			this->tabPageDepartamente = (gcnew System::Windows::Forms::TabPage());
			this->addButton = (gcnew System::Windows::Forms::Button());
			this->departGridView = (gcnew System::Windows::Forms::DataGridView());
			this->department_id = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->denumire_departament = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->facultate_depart = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->edit_d = (gcnew System::Windows::Forms::DataGridViewButtonColumn());
			this->delete_d = (gcnew System::Windows::Forms::DataGridViewButtonColumn());
			this->tabPageProfesori = (gcnew System::Windows::Forms::TabPage());
			this->profGridView2 = (gcnew System::Windows::Forms::DataGridView());
			this->id_proff = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->fullname_prof = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->proff_role = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->email_proff = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->phone_prof = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->username_prof = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->pass_prof = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->edit_p = (gcnew System::Windows::Forms::DataGridViewButtonColumn());
			this->delete_p = (gcnew System::Windows::Forms::DataGridViewButtonColumn());
			this->addProfbutton = (gcnew System::Windows::Forms::Button());
			this->tabPageStudenti = (gcnew System::Windows::Forms::TabPage());
			this->studGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->id_stud = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->stud_name = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->email_st = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->phone_st = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->grupa_st = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->edit_st = (gcnew System::Windows::Forms::DataGridViewButtonColumn());
			this->dell_st = (gcnew System::Windows::Forms::DataGridViewButtonColumn());
			this->addStudButton = (gcnew System::Windows::Forms::Button());
			this->tabPageSpecialitati = (gcnew System::Windows::Forms::TabPage());
			this->specialtyGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->idSpecialty = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->denumire_specialitate = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->departament = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->director_program = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->edit_s = (gcnew System::Windows::Forms::DataGridViewButtonColumn());
			this->delete_s = (gcnew System::Windows::Forms::DataGridViewButtonColumn());
			this->addSpecialtybutton = (gcnew System::Windows::Forms::Button());
			this->tabPageGroups = (gcnew System::Windows::Forms::TabPage());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->groupGridView3 = (gcnew System::Windows::Forms::DataGridView());
			this->id_group = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->group_name = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->study_year = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->deparment_group = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->specialty_id = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->edit_gr = (gcnew System::Windows::Forms::DataGridViewButtonColumn());
			this->delete_gr = (gcnew System::Windows::Forms::DataGridViewButtonColumn());
			this->tabPageCourses = (gcnew System::Windows::Forms::TabPage());
			this->coursGridView = (gcnew System::Windows::Forms::DataGridView());
			this->course_id = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->course_name = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->nr_credits = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->proffesor_id = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->edit_c = (gcnew System::Windows::Forms::DataGridViewButtonColumn());
			this->delete_c = (gcnew System::Windows::Forms::DataGridViewButtonColumn());
			this->addCoursebutton = (gcnew System::Windows::Forms::Button());
			this->tabPageMarks = (gcnew System::Windows::Forms::TabPage());
			this->addMarkbutton = (gcnew System::Windows::Forms::Button());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->tabPageAbsences = (gcnew System::Windows::Forms::TabPage());
			this->tabPageExam = (gcnew System::Windows::Forms::TabPage());
			this->tabPageAccount = (gcnew System::Windows::Forms::TabPage());
			this->menuPanel = (gcnew System::Windows::Forms::ListBox());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->tabControl1->SuspendLayout();
			this->tabPageDepartamente->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->departGridView))->BeginInit();
			this->tabPageProfesori->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->profGridView2))->BeginInit();
			this->tabPageStudenti->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->studGridView1))->BeginInit();
			this->tabPageSpecialitati->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->specialtyGridView1))->BeginInit();
			this->tabPageGroups->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->groupGridView3))->BeginInit();
			this->tabPageCourses->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->coursGridView))->BeginInit();
			this->tabPageMarks->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->panel1->SuspendLayout();
			this->SuspendLayout();
			// 
			// topPanel
			// 
			this->topPanel->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(39)), static_cast<System::Int32>(static_cast<System::Byte>(35)),
				static_cast<System::Int32>(static_cast<System::Byte>(67)));
			this->topPanel->Dock = System::Windows::Forms::DockStyle::Top;
			this->topPanel->Location = System::Drawing::Point(156, 0);
			this->topPanel->Name = L"topPanel";
			this->topPanel->Size = System::Drawing::Size(1076, 75);
			this->topPanel->TabIndex = 3;
			// 
			// tabControl1
			// 
			this->tabControl1->Controls->Add(this->tabPageHome);
			this->tabControl1->Controls->Add(this->tabPageDepartamente);
			this->tabControl1->Controls->Add(this->tabPageProfesori);
			this->tabControl1->Controls->Add(this->tabPageStudenti);
			this->tabControl1->Controls->Add(this->tabPageSpecialitati);
			this->tabControl1->Controls->Add(this->tabPageGroups);
			this->tabControl1->Controls->Add(this->tabPageCourses);
			this->tabControl1->Controls->Add(this->tabPageMarks);
			this->tabControl1->Controls->Add(this->tabPageAbsences);
			this->tabControl1->Controls->Add(this->tabPageExam);
			this->tabControl1->Controls->Add(this->tabPageAccount);
			this->tabControl1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tabControl1->Location = System::Drawing::Point(156, 75);
			this->tabControl1->Name = L"tabControl1";
			this->tabControl1->SelectedIndex = 0;
			this->tabControl1->Size = System::Drawing::Size(1076, 528);
			this->tabControl1->SizeMode = System::Windows::Forms::TabSizeMode::Fixed;
			this->tabControl1->TabIndex = 4;
			// 
			// tabPageHome
			// 
			this->tabPageHome->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(240)), static_cast<System::Int32>(static_cast<System::Byte>(240)),
				static_cast<System::Int32>(static_cast<System::Byte>(240)));
			this->tabPageHome->Location = System::Drawing::Point(4, 25);
			this->tabPageHome->Name = L"tabPageHome";
			this->tabPageHome->Padding = System::Windows::Forms::Padding(3);
			this->tabPageHome->Size = System::Drawing::Size(1068, 499);
			this->tabPageHome->TabIndex = 0;
			this->tabPageHome->Text = L"Acasa";
			// 
			// tabPageDepartamente
			// 
			this->tabPageDepartamente->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(240)),
				static_cast<System::Int32>(static_cast<System::Byte>(240)), static_cast<System::Int32>(static_cast<System::Byte>(240)));
			this->tabPageDepartamente->Controls->Add(this->addButton);
			this->tabPageDepartamente->Controls->Add(this->departGridView);
			this->tabPageDepartamente->Location = System::Drawing::Point(4, 25);
			this->tabPageDepartamente->Name = L"tabPageDepartamente";
			this->tabPageDepartamente->Padding = System::Windows::Forms::Padding(3);
			this->tabPageDepartamente->Size = System::Drawing::Size(1068, 499);
			this->tabPageDepartamente->TabIndex = 1;
			this->tabPageDepartamente->Text = L"Departamente";
			// 
			// addButton
			// 
			this->addButton->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->addButton->Cursor = System::Windows::Forms::Cursors::Hand;
			this->addButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->addButton->Location = System::Drawing::Point(837, 3);
			this->addButton->Name = L"addButton";
			this->addButton->Size = System::Drawing::Size(222, 37);
			this->addButton->TabIndex = 2;
			this->addButton->Text = L"+ Adauga Departament";
			this->addButton->UseVisualStyleBackColor = true;
			this->addButton->Click += gcnew System::EventHandler(this, &MenuForm::addButton_Click);
			// 
			// departGridView
			// 
			this->departGridView->AllowUserToDeleteRows = false;
			this->departGridView->AllowUserToOrderColumns = true;
			this->departGridView->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->departGridView->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::Fill;
			this->departGridView->BackgroundColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(240)),
				static_cast<System::Int32>(static_cast<System::Byte>(240)), static_cast<System::Int32>(static_cast<System::Byte>(240)));
			this->departGridView->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->departGridView->CellBorderStyle = System::Windows::Forms::DataGridViewCellBorderStyle::SingleHorizontal;
			this->departGridView->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->departGridView->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(5) {
				this->department_id,
					this->denumire_departament, this->facultate_depart, this->edit_d, this->delete_d
			});
			this->departGridView->GridColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(240)), static_cast<System::Int32>(static_cast<System::Byte>(240)),
				static_cast<System::Int32>(static_cast<System::Byte>(240)));
			this->departGridView->Location = System::Drawing::Point(7, 46);
			this->departGridView->Name = L"departGridView";
			this->departGridView->ReadOnly = true;
			this->departGridView->RowHeadersBorderStyle = System::Windows::Forms::DataGridViewHeaderBorderStyle::None;
			this->departGridView->RowHeadersVisible = false;
			this->departGridView->RowTemplate->Height = 24;
			this->departGridView->SelectionMode = System::Windows::Forms::DataGridViewSelectionMode::FullRowSelect;
			this->departGridView->Size = System::Drawing::Size(1055, 453);
			this->departGridView->TabIndex = 1;
			this->departGridView->CellContentClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &MenuForm::departGridView_CellContentClick);
			// 
			// department_id
			// 
			this->department_id->FillWeight = 52.99142F;
			this->department_id->HeaderText = L"ID";
			this->department_id->Name = L"department_id";
			this->department_id->ReadOnly = true;
			// 
			// denumire_departament
			// 
			this->denumire_departament->FillWeight = 229.1855F;
			this->denumire_departament->HeaderText = L"Nume Departament";
			this->denumire_departament->Name = L"denumire_departament";
			this->denumire_departament->ReadOnly = true;
			// 
			// facultate_depart
			// 
			this->facultate_depart->FillWeight = 115.9132F;
			this->facultate_depart->HeaderText = L"Facultate";
			this->facultate_depart->Name = L"facultate_depart";
			this->facultate_depart->ReadOnly = true;
			// 
			// edit_d
			// 
			this->edit_d->FillWeight = 53.68653F;
			this->edit_d->HeaderText = L"";
			this->edit_d->Name = L"edit_d";
			this->edit_d->ReadOnly = true;
			this->edit_d->Resizable = System::Windows::Forms::DataGridViewTriState::True;
			this->edit_d->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::Automatic;
			this->edit_d->Text = L"Edit";
			this->edit_d->UseColumnTextForButtonValue = true;
			// 
			// delete_d
			// 
			this->delete_d->FillWeight = 48.22335F;
			this->delete_d->HeaderText = L"";
			this->delete_d->Name = L"delete_d";
			this->delete_d->ReadOnly = true;
			this->delete_d->Resizable = System::Windows::Forms::DataGridViewTriState::True;
			this->delete_d->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::Automatic;
			this->delete_d->Text = L"Delete";
			this->delete_d->UseColumnTextForButtonValue = true;
			// 
			// tabPageProfesori
			// 
			this->tabPageProfesori->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(240)),
				static_cast<System::Int32>(static_cast<System::Byte>(240)), static_cast<System::Int32>(static_cast<System::Byte>(240)));
			this->tabPageProfesori->Controls->Add(this->profGridView2);
			this->tabPageProfesori->Controls->Add(this->addProfbutton);
			this->tabPageProfesori->Location = System::Drawing::Point(4, 25);
			this->tabPageProfesori->Name = L"tabPageProfesori";
			this->tabPageProfesori->Padding = System::Windows::Forms::Padding(3);
			this->tabPageProfesori->Size = System::Drawing::Size(1068, 499);
			this->tabPageProfesori->TabIndex = 2;
			this->tabPageProfesori->Text = L"Profesori";
			// 
			// profGridView2
			// 
			this->profGridView2->AllowUserToDeleteRows = false;
			this->profGridView2->AllowUserToOrderColumns = true;
			this->profGridView2->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->profGridView2->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::Fill;
			this->profGridView2->BackgroundColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(240)),
				static_cast<System::Int32>(static_cast<System::Byte>(240)), static_cast<System::Int32>(static_cast<System::Byte>(240)));
			this->profGridView2->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->profGridView2->CellBorderStyle = System::Windows::Forms::DataGridViewCellBorderStyle::SingleHorizontal;
			this->profGridView2->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->profGridView2->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(9) {
				this->id_proff,
					this->fullname_prof, this->proff_role, this->email_proff, this->phone_prof, this->username_prof, this->pass_prof, this->edit_p,
					this->delete_p
			});
			this->profGridView2->GridColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(240)), static_cast<System::Int32>(static_cast<System::Byte>(240)),
				static_cast<System::Int32>(static_cast<System::Byte>(240)));
			this->profGridView2->Location = System::Drawing::Point(3, 46);
			this->profGridView2->Name = L"profGridView2";
			this->profGridView2->ReadOnly = true;
			this->profGridView2->RowHeadersBorderStyle = System::Windows::Forms::DataGridViewHeaderBorderStyle::None;
			this->profGridView2->RowHeadersVisible = false;
			this->profGridView2->RowTemplate->Height = 24;
			this->profGridView2->SelectionMode = System::Windows::Forms::DataGridViewSelectionMode::FullRowSelect;
			this->profGridView2->Size = System::Drawing::Size(1057, 447);
			this->profGridView2->TabIndex = 1;
			this->profGridView2->CellContentClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &MenuForm::profGridView_CellContentClick);
			// 
			// id_proff
			// 
			this->id_proff->HeaderText = L"ID";
			this->id_proff->Name = L"id_proff";
			this->id_proff->ReadOnly = true;
			// 
			// fullname_prof
			// 
			this->fullname_prof->HeaderText = L"Nume, Prenume";
			this->fullname_prof->Name = L"fullname_prof";
			this->fullname_prof->ReadOnly = true;
			// 
			// proff_role
			// 
			this->proff_role->HeaderText = L"Rol";
			this->proff_role->Name = L"proff_role";
			this->proff_role->ReadOnly = true;
			// 
			// email_proff
			// 
			this->email_proff->HeaderText = L"Email";
			this->email_proff->Name = L"email_proff";
			this->email_proff->ReadOnly = true;
			// 
			// phone_prof
			// 
			this->phone_prof->HeaderText = L"Nr. Telefon";
			this->phone_prof->Name = L"phone_prof";
			this->phone_prof->ReadOnly = true;
			// 
			// username_prof
			// 
			this->username_prof->HeaderText = L"User Name";
			this->username_prof->Name = L"username_prof";
			this->username_prof->ReadOnly = true;
			// 
			// pass_prof
			// 
			this->pass_prof->HeaderText = L"Parola";
			this->pass_prof->Name = L"pass_prof";
			this->pass_prof->ReadOnly = true;
			// 
			// edit_p
			// 
			this->edit_p->HeaderText = L"";
			this->edit_p->Name = L"edit_p";
			this->edit_p->ReadOnly = true;
			this->edit_p->Text = L"Edit";
			this->edit_p->UseColumnTextForButtonValue = true;
			// 
			// delete_p
			// 
			this->delete_p->HeaderText = L"";
			this->delete_p->Name = L"delete_p";
			this->delete_p->ReadOnly = true;
			this->delete_p->Text = L"Delete";
			this->delete_p->UseColumnTextForButtonValue = true;
			// 
			// addProfbutton
			// 
			this->addProfbutton->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->addProfbutton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->addProfbutton->Location = System::Drawing::Point(843, 3);
			this->addProfbutton->Name = L"addProfbutton";
			this->addProfbutton->Size = System::Drawing::Size(222, 37);
			this->addProfbutton->TabIndex = 0;
			this->addProfbutton->Text = L"+ Adaugă Profesor";
			this->addProfbutton->UseVisualStyleBackColor = true;
			this->addProfbutton->Click += gcnew System::EventHandler(this, &MenuForm::addProfbutton_Click);
			// 
			// tabPageStudenti
			// 
			this->tabPageStudenti->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(240)), static_cast<System::Int32>(static_cast<System::Byte>(240)),
				static_cast<System::Int32>(static_cast<System::Byte>(240)));
			this->tabPageStudenti->Controls->Add(this->studGridView1);
			this->tabPageStudenti->Controls->Add(this->addStudButton);
			this->tabPageStudenti->Location = System::Drawing::Point(4, 25);
			this->tabPageStudenti->Name = L"tabPageStudenti";
			this->tabPageStudenti->Padding = System::Windows::Forms::Padding(3);
			this->tabPageStudenti->Size = System::Drawing::Size(1068, 499);
			this->tabPageStudenti->TabIndex = 3;
			this->tabPageStudenti->Text = L"Studenti";
			// 
			// studGridView1
			// 
			this->studGridView1->AllowUserToDeleteRows = false;
			this->studGridView1->AllowUserToOrderColumns = true;
			this->studGridView1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->studGridView1->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::Fill;
			this->studGridView1->BackgroundColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(240)),
				static_cast<System::Int32>(static_cast<System::Byte>(240)), static_cast<System::Int32>(static_cast<System::Byte>(240)));
			this->studGridView1->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->studGridView1->CellBorderStyle = System::Windows::Forms::DataGridViewCellBorderStyle::SingleHorizontal;
			this->studGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->studGridView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(7) {
				this->id_stud,
					this->stud_name, this->email_st, this->phone_st, this->grupa_st, this->edit_st, this->dell_st
			});
			this->studGridView1->GridColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(240)), static_cast<System::Int32>(static_cast<System::Byte>(240)),
				static_cast<System::Int32>(static_cast<System::Byte>(240)));
			this->studGridView1->Location = System::Drawing::Point(4, 46);
			this->studGridView1->Name = L"studGridView1";
			this->studGridView1->ReadOnly = true;
			this->studGridView1->RowHeadersBorderStyle = System::Windows::Forms::DataGridViewHeaderBorderStyle::None;
			dataGridViewCellStyle1->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
			dataGridViewCellStyle1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(243)),
				static_cast<System::Int32>(static_cast<System::Byte>(248)), static_cast<System::Int32>(static_cast<System::Byte>(255)));
			dataGridViewCellStyle1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			dataGridViewCellStyle1->ForeColor = System::Drawing::SystemColors::WindowText;
			dataGridViewCellStyle1->SelectionBackColor = System::Drawing::SystemColors::Highlight;
			dataGridViewCellStyle1->SelectionForeColor = System::Drawing::SystemColors::HighlightText;
			dataGridViewCellStyle1->WrapMode = System::Windows::Forms::DataGridViewTriState::True;
			this->studGridView1->RowHeadersDefaultCellStyle = dataGridViewCellStyle1;
			this->studGridView1->RowHeadersVisible = false;
			this->studGridView1->RowTemplate->Height = 24;
			this->studGridView1->SelectionMode = System::Windows::Forms::DataGridViewSelectionMode::FullRowSelect;
			this->studGridView1->Size = System::Drawing::Size(1056, 445);
			this->studGridView1->TabIndex = 2;
			// 
			// id_stud
			// 
			this->id_stud->FillWeight = 90.80542F;
			this->id_stud->HeaderText = L"Nr. Student";
			this->id_stud->Name = L"id_stud";
			this->id_stud->ReadOnly = true;
			this->id_stud->Resizable = System::Windows::Forms::DataGridViewTriState::True;
			// 
			// stud_name
			// 
			this->stud_name->FillWeight = 219.1386F;
			this->stud_name->HeaderText = L"Nume Studenţi";
			this->stud_name->Name = L"stud_name";
			this->stud_name->ReadOnly = true;
			this->stud_name->Resizable = System::Windows::Forms::DataGridViewTriState::True;
			// 
			// email_st
			// 
			this->email_st->FillWeight = 72.979F;
			this->email_st->HeaderText = L"Email";
			this->email_st->Name = L"email_st";
			this->email_st->ReadOnly = true;
			this->email_st->Resizable = System::Windows::Forms::DataGridViewTriState::True;
			// 
			// phone_st
			// 
			this->phone_st->FillWeight = 62.38884F;
			this->phone_st->HeaderText = L"Nr. Telefon";
			this->phone_st->Name = L"phone_st";
			this->phone_st->ReadOnly = true;
			this->phone_st->Resizable = System::Windows::Forms::DataGridViewTriState::True;
			// 
			// grupa_st
			// 
			this->grupa_st->FillWeight = 145.6853F;
			this->grupa_st->HeaderText = L"Grupa";
			this->grupa_st->Name = L"grupa_st";
			this->grupa_st->ReadOnly = true;
			this->grupa_st->Resizable = System::Windows::Forms::DataGridViewTriState::True;
			// 
			// edit_st
			// 
			this->edit_st->FillWeight = 55.56342F;
			this->edit_st->HeaderText = L"";
			this->edit_st->MinimumWidth = 20;
			this->edit_st->Name = L"edit_st";
			this->edit_st->ReadOnly = true;
			this->edit_st->Resizable = System::Windows::Forms::DataGridViewTriState::True;
			this->edit_st->Text = L"Edit";
			this->edit_st->UseColumnTextForButtonValue = true;
			// 
			// dell_st
			// 
			this->dell_st->FillWeight = 53.43945F;
			this->dell_st->HeaderText = L"";
			this->dell_st->MinimumWidth = 20;
			this->dell_st->Name = L"dell_st";
			this->dell_st->ReadOnly = true;
			this->dell_st->Resizable = System::Windows::Forms::DataGridViewTriState::True;
			this->dell_st->Text = L"Delete";
			this->dell_st->UseColumnTextForButtonValue = true;
			// 
			// addStudButton
			// 
			this->addStudButton->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->addStudButton->Cursor = System::Windows::Forms::Cursors::Hand;
			this->addStudButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->addStudButton->Location = System::Drawing::Point(843, 4);
			this->addStudButton->Name = L"addStudButton";
			this->addStudButton->Size = System::Drawing::Size(222, 37);
			this->addStudButton->TabIndex = 1;
			this->addStudButton->Text = L"+ Adaugă Student";
			this->addStudButton->UseVisualStyleBackColor = true;
			// 
			// tabPageSpecialitati
			// 
			this->tabPageSpecialitati->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(240)),
				static_cast<System::Int32>(static_cast<System::Byte>(240)), static_cast<System::Int32>(static_cast<System::Byte>(240)));
			this->tabPageSpecialitati->Controls->Add(this->specialtyGridView1);
			this->tabPageSpecialitati->Controls->Add(this->addSpecialtybutton);
			this->tabPageSpecialitati->Location = System::Drawing::Point(4, 25);
			this->tabPageSpecialitati->Name = L"tabPageSpecialitati";
			this->tabPageSpecialitati->Padding = System::Windows::Forms::Padding(3);
			this->tabPageSpecialitati->Size = System::Drawing::Size(1068, 499);
			this->tabPageSpecialitati->TabIndex = 4;
			this->tabPageSpecialitati->Text = L"Specialitati";
			// 
			// specialtyGridView1
			// 
			this->specialtyGridView1->AllowUserToDeleteRows = false;
			this->specialtyGridView1->AllowUserToOrderColumns = true;
			this->specialtyGridView1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->specialtyGridView1->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::Fill;
			this->specialtyGridView1->BackgroundColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(240)),
				static_cast<System::Int32>(static_cast<System::Byte>(240)), static_cast<System::Int32>(static_cast<System::Byte>(240)));
			this->specialtyGridView1->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->specialtyGridView1->CellBorderStyle = System::Windows::Forms::DataGridViewCellBorderStyle::SingleHorizontal;
			this->specialtyGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->specialtyGridView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(6) {
				this->idSpecialty,
					this->denumire_specialitate, this->departament, this->director_program, this->edit_s, this->delete_s
			});
			this->specialtyGridView1->GridColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(240)),
				static_cast<System::Int32>(static_cast<System::Byte>(240)), static_cast<System::Int32>(static_cast<System::Byte>(240)));
			this->specialtyGridView1->Location = System::Drawing::Point(3, 46);
			this->specialtyGridView1->Name = L"specialtyGridView1";
			this->specialtyGridView1->ReadOnly = true;
			this->specialtyGridView1->RowHeadersBorderStyle = System::Windows::Forms::DataGridViewHeaderBorderStyle::None;
			this->specialtyGridView1->RowHeadersVisible = false;
			this->specialtyGridView1->RowTemplate->Height = 24;
			this->specialtyGridView1->SelectionMode = System::Windows::Forms::DataGridViewSelectionMode::FullRowSelect;
			this->specialtyGridView1->Size = System::Drawing::Size(1059, 453);
			this->specialtyGridView1->TabIndex = 1;
			// 
			// idSpecialty
			// 
			this->idSpecialty->FillWeight = 67.00508F;
			this->idSpecialty->HeaderText = L"Nr.";
			this->idSpecialty->Name = L"idSpecialty";
			this->idSpecialty->ReadOnly = true;
			// 
			// denumire_specialitate
			// 
			this->denumire_specialitate->FillWeight = 146.8029F;
			this->denumire_specialitate->HeaderText = L"Denumire Specialitate";
			this->denumire_specialitate->Name = L"denumire_specialitate";
			this->denumire_specialitate->ReadOnly = true;
			// 
			// departament
			// 
			this->departament->FillWeight = 167.7954F;
			this->departament->HeaderText = L"Departament";
			this->departament->Name = L"departament";
			this->departament->ReadOnly = true;
			// 
			// director_program
			// 
			this->director_program->FillWeight = 80.3194F;
			this->director_program->HeaderText = L"Director Program";
			this->director_program->Name = L"director_program";
			this->director_program->ReadOnly = true;
			// 
			// edit_s
			// 
			this->edit_s->FillWeight = 69.05531F;
			this->edit_s->HeaderText = L"";
			this->edit_s->Name = L"edit_s";
			this->edit_s->ReadOnly = true;
			this->edit_s->Text = L"Edit";
			this->edit_s->UseColumnTextForButtonValue = true;
			// 
			// delete_s
			// 
			this->delete_s->FillWeight = 69.02204F;
			this->delete_s->HeaderText = L"";
			this->delete_s->Name = L"delete_s";
			this->delete_s->ReadOnly = true;
			this->delete_s->Text = L"Delete";
			this->delete_s->UseColumnTextForButtonValue = true;
			// 
			// addSpecialtybutton
			// 
			this->addSpecialtybutton->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->addSpecialtybutton->Cursor = System::Windows::Forms::Cursors::Hand;
			this->addSpecialtybutton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->addSpecialtybutton->Location = System::Drawing::Point(843, 3);
			this->addSpecialtybutton->Name = L"addSpecialtybutton";
			this->addSpecialtybutton->Size = System::Drawing::Size(222, 37);
			this->addSpecialtybutton->TabIndex = 0;
			this->addSpecialtybutton->Text = L"+ Adaugă Specialitate";
			this->addSpecialtybutton->UseVisualStyleBackColor = true;
			// 
			// tabPageGroups
			// 
			this->tabPageGroups->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(240)), static_cast<System::Int32>(static_cast<System::Byte>(240)),
				static_cast<System::Int32>(static_cast<System::Byte>(240)));
			this->tabPageGroups->Controls->Add(this->button1);
			this->tabPageGroups->Controls->Add(this->groupGridView3);
			this->tabPageGroups->Location = System::Drawing::Point(4, 25);
			this->tabPageGroups->Name = L"tabPageGroups";
			this->tabPageGroups->Padding = System::Windows::Forms::Padding(3);
			this->tabPageGroups->Size = System::Drawing::Size(1068, 499);
			this->tabPageGroups->TabIndex = 5;
			this->tabPageGroups->Text = L"Grupe";
			// 
			// button1
			// 
			this->button1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->button1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button1->Location = System::Drawing::Point(840, 3);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(222, 37);
			this->button1->TabIndex = 1;
			this->button1->Text = L"+ Adaugă Grupă";
			this->button1->UseVisualStyleBackColor = true;
			// 
			// groupGridView3
			// 
			this->groupGridView3->AllowUserToDeleteRows = false;
			this->groupGridView3->AllowUserToOrderColumns = true;
			this->groupGridView3->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->groupGridView3->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::Fill;
			this->groupGridView3->BackgroundColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(240)),
				static_cast<System::Int32>(static_cast<System::Byte>(240)), static_cast<System::Int32>(static_cast<System::Byte>(240)));
			this->groupGridView3->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->groupGridView3->CellBorderStyle = System::Windows::Forms::DataGridViewCellBorderStyle::SingleHorizontal;
			this->groupGridView3->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->groupGridView3->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(7) {
				this->id_group,
					this->group_name, this->study_year, this->deparment_group, this->specialty_id, this->edit_gr, this->delete_gr
			});
			this->groupGridView3->GridColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(240)), static_cast<System::Int32>(static_cast<System::Byte>(240)),
				static_cast<System::Int32>(static_cast<System::Byte>(240)));
			this->groupGridView3->Location = System::Drawing::Point(3, 46);
			this->groupGridView3->Name = L"groupGridView3";
			this->groupGridView3->ReadOnly = true;
			this->groupGridView3->RowHeadersBorderStyle = System::Windows::Forms::DataGridViewHeaderBorderStyle::None;
			this->groupGridView3->RowHeadersVisible = false;
			this->groupGridView3->RowTemplate->Height = 24;
			this->groupGridView3->SelectionMode = System::Windows::Forms::DataGridViewSelectionMode::FullRowSelect;
			this->groupGridView3->Size = System::Drawing::Size(1059, 450);
			this->groupGridView3->TabIndex = 0;
			// 
			// id_group
			// 
			this->id_group->HeaderText = L"Nr.";
			this->id_group->Name = L"id_group";
			this->id_group->ReadOnly = true;
			// 
			// group_name
			// 
			this->group_name->HeaderText = L"Denumire";
			this->group_name->Name = L"group_name";
			this->group_name->ReadOnly = true;
			// 
			// study_year
			// 
			this->study_year->HeaderText = L"An Studii";
			this->study_year->Name = L"study_year";
			this->study_year->ReadOnly = true;
			// 
			// deparment_group
			// 
			this->deparment_group->HeaderText = L"Departament Grupă";
			this->deparment_group->Name = L"deparment_group";
			this->deparment_group->ReadOnly = true;
			// 
			// specialty_id
			// 
			this->specialty_id->HeaderText = L"Specialitate";
			this->specialty_id->Name = L"specialty_id";
			this->specialty_id->ReadOnly = true;
			// 
			// edit_gr
			// 
			this->edit_gr->HeaderText = L"";
			this->edit_gr->Name = L"edit_gr";
			this->edit_gr->ReadOnly = true;
			// 
			// delete_gr
			// 
			this->delete_gr->HeaderText = L"";
			this->delete_gr->Name = L"delete_gr";
			this->delete_gr->ReadOnly = true;
			// 
			// tabPageCourses
			// 
			this->tabPageCourses->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(240)), static_cast<System::Int32>(static_cast<System::Byte>(240)),
				static_cast<System::Int32>(static_cast<System::Byte>(240)));
			this->tabPageCourses->Controls->Add(this->coursGridView);
			this->tabPageCourses->Controls->Add(this->addCoursebutton);
			this->tabPageCourses->Location = System::Drawing::Point(4, 25);
			this->tabPageCourses->Name = L"tabPageCourses";
			this->tabPageCourses->Padding = System::Windows::Forms::Padding(3);
			this->tabPageCourses->Size = System::Drawing::Size(1068, 499);
			this->tabPageCourses->TabIndex = 6;
			this->tabPageCourses->Text = L"Cursuri";
			// 
			// coursGridView
			// 
			this->coursGridView->AllowUserToDeleteRows = false;
			this->coursGridView->AllowUserToOrderColumns = true;
			this->coursGridView->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->coursGridView->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::Fill;
			this->coursGridView->BackgroundColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(240)),
				static_cast<System::Int32>(static_cast<System::Byte>(240)), static_cast<System::Int32>(static_cast<System::Byte>(240)));
			this->coursGridView->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->coursGridView->CellBorderStyle = System::Windows::Forms::DataGridViewCellBorderStyle::SingleHorizontal;
			this->coursGridView->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->coursGridView->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(6) {
				this->course_id,
					this->course_name, this->nr_credits, this->proffesor_id, this->edit_c, this->delete_c
			});
			this->coursGridView->GridColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(240)), static_cast<System::Int32>(static_cast<System::Byte>(240)),
				static_cast<System::Int32>(static_cast<System::Byte>(240)));
			this->coursGridView->Location = System::Drawing::Point(3, 46);
			this->coursGridView->Name = L"coursGridView";
			this->coursGridView->ReadOnly = true;
			this->coursGridView->RowHeadersBorderStyle = System::Windows::Forms::DataGridViewHeaderBorderStyle::None;
			this->coursGridView->RowHeadersVisible = false;
			this->coursGridView->RowTemplate->Height = 24;
			this->coursGridView->SelectionMode = System::Windows::Forms::DataGridViewSelectionMode::FullRowSelect;
			this->coursGridView->Size = System::Drawing::Size(1059, 450);
			this->coursGridView->TabIndex = 1;
			// 
			// course_id
			// 
			this->course_id->HeaderText = L"ID";
			this->course_id->Name = L"course_id";
			this->course_id->ReadOnly = true;
			// 
			// course_name
			// 
			this->course_name->HeaderText = L"Denumire Curs";
			this->course_name->Name = L"course_name";
			this->course_name->ReadOnly = true;
			// 
			// nr_credits
			// 
			this->nr_credits->HeaderText = L"Număr Credite";
			this->nr_credits->Name = L"nr_credits";
			this->nr_credits->ReadOnly = true;
			// 
			// proffesor_id
			// 
			this->proffesor_id->HeaderText = L"Coordonator Curs";
			this->proffesor_id->Name = L"proffesor_id";
			this->proffesor_id->ReadOnly = true;
			// 
			// edit_c
			// 
			this->edit_c->HeaderText = L"";
			this->edit_c->Name = L"edit_c";
			this->edit_c->ReadOnly = true;
			this->edit_c->Text = L"Edit";
			this->edit_c->UseColumnTextForButtonValue = true;
			// 
			// delete_c
			// 
			this->delete_c->HeaderText = L"";
			this->delete_c->Name = L"delete_c";
			this->delete_c->ReadOnly = true;
			this->delete_c->Text = L"Delete";
			this->delete_c->UseColumnTextForButtonValue = true;
			// 
			// addCoursebutton
			// 
			this->addCoursebutton->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->addCoursebutton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->addCoursebutton->Location = System::Drawing::Point(843, 3);
			this->addCoursebutton->Name = L"addCoursebutton";
			this->addCoursebutton->Size = System::Drawing::Size(222, 37);
			this->addCoursebutton->TabIndex = 0;
			this->addCoursebutton->Text = L"+ Adaugă Curs";
			this->addCoursebutton->UseVisualStyleBackColor = true;
			// 
			// tabPageMarks
			// 
			this->tabPageMarks->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(240)), static_cast<System::Int32>(static_cast<System::Byte>(240)),
				static_cast<System::Int32>(static_cast<System::Byte>(240)));
			this->tabPageMarks->Controls->Add(this->addMarkbutton);
			this->tabPageMarks->Controls->Add(this->dataGridView1);
			this->tabPageMarks->Location = System::Drawing::Point(4, 25);
			this->tabPageMarks->Name = L"tabPageMarks";
			this->tabPageMarks->Padding = System::Windows::Forms::Padding(3);
			this->tabPageMarks->Size = System::Drawing::Size(1068, 499);
			this->tabPageMarks->TabIndex = 7;
			this->tabPageMarks->Text = L"Note";
			// 
			// addMarkbutton
			// 
			this->addMarkbutton->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->addMarkbutton->Location = System::Drawing::Point(843, 3);
			this->addMarkbutton->Name = L"addMarkbutton";
			this->addMarkbutton->Size = System::Drawing::Size(222, 37);
			this->addMarkbutton->TabIndex = 1;
			this->addMarkbutton->Text = L"+ Adaugă Notă";
			this->addMarkbutton->UseVisualStyleBackColor = true;
			// 
			// dataGridView1
			// 
			this->dataGridView1->AllowUserToOrderColumns = true;
			this->dataGridView1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->dataGridView1->BackgroundColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(240)),
				static_cast<System::Int32>(static_cast<System::Byte>(240)), static_cast<System::Int32>(static_cast<System::Byte>(240)));
			this->dataGridView1->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->dataGridView1->CellBorderStyle = System::Windows::Forms::DataGridViewCellBorderStyle::SingleHorizontal;
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->GridColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(240)), static_cast<System::Int32>(static_cast<System::Byte>(240)),
				static_cast<System::Int32>(static_cast<System::Byte>(240)));
			this->dataGridView1->Location = System::Drawing::Point(6, 46);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->RowHeadersBorderStyle = System::Windows::Forms::DataGridViewHeaderBorderStyle::None;
			this->dataGridView1->RowHeadersVisible = false;
			this->dataGridView1->RowTemplate->Height = 24;
			this->dataGridView1->SelectionMode = System::Windows::Forms::DataGridViewSelectionMode::FullRowSelect;
			this->dataGridView1->Size = System::Drawing::Size(1059, 447);
			this->dataGridView1->TabIndex = 0;
			// 
			// tabPageAbsences
			// 
			this->tabPageAbsences->BackColor = System::Drawing::Color::Red;
			this->tabPageAbsences->Location = System::Drawing::Point(4, 25);
			this->tabPageAbsences->Name = L"tabPageAbsences";
			this->tabPageAbsences->Padding = System::Windows::Forms::Padding(3);
			this->tabPageAbsences->Size = System::Drawing::Size(1068, 499);
			this->tabPageAbsences->TabIndex = 8;
			this->tabPageAbsences->Text = L"Absente";
			// 
			// tabPageExam
			// 
			this->tabPageExam->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(240)), static_cast<System::Int32>(static_cast<System::Byte>(240)),
				static_cast<System::Int32>(static_cast<System::Byte>(240)));
			this->tabPageExam->Location = System::Drawing::Point(4, 25);
			this->tabPageExam->Name = L"tabPageExam";
			this->tabPageExam->Padding = System::Windows::Forms::Padding(3);
			this->tabPageExam->Size = System::Drawing::Size(1068, 499);
			this->tabPageExam->TabIndex = 9;
			this->tabPageExam->Text = L"Examene";
			// 
			// tabPageAccount
			// 
			this->tabPageAccount->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(240)), static_cast<System::Int32>(static_cast<System::Byte>(240)),
				static_cast<System::Int32>(static_cast<System::Byte>(240)));
			this->tabPageAccount->Location = System::Drawing::Point(4, 25);
			this->tabPageAccount->Name = L"tabPageAccount";
			this->tabPageAccount->Padding = System::Windows::Forms::Padding(3);
			this->tabPageAccount->Size = System::Drawing::Size(1068, 499);
			this->tabPageAccount->TabIndex = 10;
			this->tabPageAccount->Text = L"Cont Utilizator";
			// 
			// menuPanel
			// 
			this->menuPanel->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(227)), static_cast<System::Int32>(static_cast<System::Byte>(246)),
				static_cast<System::Int32>(static_cast<System::Byte>(245)));
			this->menuPanel->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->menuPanel->Dock = System::Windows::Forms::DockStyle::Left;
			this->menuPanel->DrawMode = System::Windows::Forms::DrawMode::OwnerDrawFixed;
			this->menuPanel->FormattingEnabled = true;
			this->menuPanel->ItemHeight = 16;
			this->menuPanel->Items->AddRange(gcnew cli::array< System::Object^  >(11) {
				L"Acasă", L"Departamente", L"Profesori", L"Studenți",
					L"Specialităţi", L"Grupe", L"Cursuri", L"Note", L"Absenţe", L"Examen", L"Cont Personal"
			});
			this->menuPanel->Location = System::Drawing::Point(0, 0);
			this->menuPanel->Name = L"menuPanel";
			this->menuPanel->Size = System::Drawing::Size(156, 603);
			this->menuPanel->TabIndex = 1;
			this->menuPanel->DrawItem += gcnew System::Windows::Forms::DrawItemEventHandler(this, &MenuForm::menuPanel_DrawItem);
			this->menuPanel->SelectedIndexChanged += gcnew System::EventHandler(this, &MenuForm::menuPanel_SelectedIndexChanged);
			// 
			// panel1
			// 
			this->panel1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(227)), static_cast<System::Int32>(static_cast<System::Byte>(246)),
				static_cast<System::Int32>(static_cast<System::Byte>(245)));
			this->panel1->Controls->Add(this->menuPanel);
			this->panel1->Dock = System::Windows::Forms::DockStyle::Left;
			this->panel1->Location = System::Drawing::Point(0, 0);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(156, 603);
			this->panel1->TabIndex = 2;
			// 
			// MenuForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::White;
			this->ClientSize = System::Drawing::Size(1232, 603);
			this->Controls->Add(this->tabControl1);
			this->Controls->Add(this->topPanel);
			this->Controls->Add(this->panel1);
			this->Name = L"MenuForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"AdminForm";
			this->tabControl1->ResumeLayout(false);
			this->tabPageDepartamente->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->departGridView))->EndInit();
			this->tabPageProfesori->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->profGridView2))->EndInit();
			this->tabPageStudenti->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->studGridView1))->EndInit();
			this->tabPageSpecialitati->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->specialtyGridView1))->EndInit();
			this->tabPageGroups->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->groupGridView3))->EndInit();
			this->tabPageCourses->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->coursGridView))->EndInit();
			this->tabPageMarks->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->panel1->ResumeLayout(false);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void menuPanel_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e);

	private: System::Void CustomizeListBox();
	// Evenimentul DrawItem
	private: System::Void menuPanel_DrawItem(System::Object^ sender, System::Windows::Forms::DrawItemEventArgs^ e);
	// Funcție pentru a desena un dreptunghi cu colțuri rotunjite
	private: void DrawRoundedRectangle(System::Drawing::Graphics^ graphics, System::Drawing::Rectangle rect, int radius, System::Drawing::Brush^ brush);
	// 
	private: System::Void addButton_Click(System::Object^ sender, System::EventArgs^ e);
	
	public: System::Void EduAc::MenuForm::LoadDataFromDatabase();
	
	private: System::Void profGridView_CellContentClick(System::Object^  sender, System::Windows::Forms::DataGridViewCellEventArgs^  e);

	private: System::Void addProfbutton_Click(System::Object^  sender, System::EventArgs^  e);

	private: System::Void departGridView_CellContentClick(System::Object^  sender, System::Windows::Forms::DataGridViewCellEventArgs^  e);
};
}
