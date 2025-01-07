#include "IncludesCentral.h"
#include <Windows.h>
SystemManagement* SystemManagement::instance = nullptr; // Definiția variabilei statice

void SystemManagement::display_students_from_db()
{
	//std::string query = "SELECT user_id, full_name FROM users";
	auto students = db_conn.selectStudents();

	std::cout << "ID\tFull Name\tEmail\t\tUsername\tGroup ID\n";
	std::cout << "-----------------------------------------------------------------------\n";
	for (const auto& student : students) {
		unsigned short student_id;
		std::string fullname, email, username, password;
		unsigned short group_id;

		// Destructurează tuple-ul
		std::tie(student_id, fullname, email, username, group_id) = student;

		// Afișează informațiile
		std::cout << student_id << "\t\t" << fullname << "\t" << email << "\t"
			<< username << "\t\t\t" << group_id << "\n";
	}
}

void SystemManagement::display_catedre() const
{
	std::string query = "Select department_id, department_name FROM departments";

	std::vector<std::pair<unsigned short, std::string>> catedre = db_conn.selectDepartments(query);

	for (const auto &catedra : catedre)
		std::cout << "ID: " << catedra.first << ", " << catedra.second << std::endl;
}

void SystemManagement::add_catedra(std::string nume_catedra, std::string faculty)
{
	/*system("cls");
	std::cin.ignore();
	std::cout << "Pentru sfarsit apasa enter" << std::endl;
	unsigned short id = 1;

	if (!catedre.empty())
	{
		id = (--catedre.end())->first;
		++id;
		do
		{
			std::cout << "Introdu nume catedra: ";
			std::string nume_catedra;
			std::getline(std::cin, nume_catedra);
			if (!nume_catedra.empty())
			{
				std::string faculty;
				std::cout << "Introdu facultatea: ";
				std::getline(std::cin, faculty);

				Catedra temp(id, nume_catedra, faculty);
				catedre[id] = temp;
				temp.insert_catedra_to_bd();
				++id;
			}
			else
				break;

		} while (true);
	}

	else
	{
		do
		{
			std::cout << "Introdu nume catedra: ";
			std::string nume_catedra;
			std::getline(std::cin, nume_catedra);
			if (!nume_catedra.empty())
			{
				std::string faculty;
				std::cout << "Introdu facultatea: ";
				std::getline(std::cin, faculty);

				Catedra temp(id, nume_catedra, faculty);
				catedre[id] = temp;
				temp.insert_catedra_to_bd();
				++id;
			}
			else
				break;

		} while (true);
	}*/

	unsigned short id = 1;

	if (!catedre.empty())
	{
		id = (--catedre.end())->first;
		Catedra temp(id, nume_catedra, faculty);
		catedre[id] = temp;
		temp.insert_catedra_to_bd();
	}
	else
	{
		Catedra temp(id, nume_catedra, faculty);
		catedre[id] = temp;
		temp.insert_catedra_to_bd();
	}
}

void SystemManagement::remove_catedra()
{
	system("cls");

	this->display_catedre();

	std::cout << "Introdu id catedra: ";
	unsigned short id_catedra;
	std::cin >> id_catedra;
	std::cin.ignore();

	std::string query = "DELETE FROM departments WHERE department_id = id_catedra";
	db_conn.executeQuery(query);

	auto catedra_it = catedre.find(id_catedra);
	if (catedra_it == catedre.end())
	{
		std::cout << "nu este asa catedra" << std::endl;
		return;
	}
	catedre.erase(catedra_it);
	std::cout << "catedra " << id_catedra << " a fost stearsa cu succes" << std::endl;
}

//
//void SystemManagement::display_catedre() const
//{
//	system("cls");
//	for (const auto catedra_entry : catedre)
//	{
//		std::cout << catedra_entry.first << ": " 
//			<< catedra_entry.second.get_name_catedra() << std::endl;
//	}
//}
// Implementare actualizare informatii catedra

void SystemManagement::update_info_catedra() {
	system("cls");

	this->display_catedre();

	unsigned short id;
	std::cout << "Introdu ID-ul catedrei pe care vrei sa o actualizezi: ";
	std::cin >> id;
	std::cin.ignore();

	auto it = catedre.find(id);
	if (it == catedre.end()) {
		std::cout << "Catedra nu exista!\n";
		return;
	}

	std::cout << "Introdu nume nou" << std::endl;
	std::string new_name;
	std::getline(std::cin, new_name);

	db_conn.updateCatedra(id, new_name);
}

void SystemManagement::add_specialitate()
{
	system("cls");
	
	this->display_catedre();

	std::cout << "Alege catedra" << std::endl;
	unsigned short id_catedra = 0;
	std::cin >> id_catedra;
	std::cin.ignore();

	auto it_catedra = catedre.find(id_catedra);
	if (it_catedra == catedre.end())
	{
		std::cout << "Nu este asa id catedra in sistem" << std::endl;
		return;
	}

	it_catedra->second.add_speciality();

}

//void SystemManagement::add_group()
//{
//	this->display_catedre();
//
//	unsigned short id_catedra;
//	std::cout << "Introdu ID-ul catedrei: ";
//	std::cin >> id_catedra;
//	auto it = catedre.find(id_catedra); // Caută catedra
//	if (it == catedre.end()) {
//		std::cout << "Catedra cu ID-ul " << id_catedra << " nu a fost găsită.\n";
//		return;
//	}
//	it->second.add_group();
//}

// nu folosita
void SystemManagement::add_group_to_catedra()
{
	for (const auto &x : catedre)
		std::cout << x.first << ": " <<
		x.second.get_name_catedra() << std::endl;

	unsigned short id_catedra;
	std::cout << "Introdu ID-ul catedrei: ";
	std::cin >> id_catedra;
	std::cin.ignore();

	auto it = catedre.find(id_catedra); // Caută catedra

	if (it == catedre.end()) {
		std::cout << "Catedra cu ID-ul " << id_catedra << " nu a fost găsită.\n";
		return;
	}

	it->second.add_group();
}

void SystemManagement::add_students()
{
	system("cls");

	for (const auto &x : catedre)
		std::cout << x.first << ": " <<
		x.second.get_name_catedra() << std::endl;

	std::cout << "Introdu id-ul catedra: ";
	unsigned short catedra_id;
	std::cin >> catedra_id;

	auto it_catedra = catedre.find(catedra_id);
	
	if (it_catedra != catedre.end())
	{
		it_catedra->second.add_students();
		std::cout << "Studenti adaugati cu succes" << std::endl;
	}
	
}

void SystemManagement::add_professor_to_department(short id_depart, std::string fullname, std::string proff_role, std::string email,
	std::string phone_num, std::string username, std::string pass)
{
	/*system("cls");

	//for (const auto &x : catedre)
	//	std::cout << x.first << ": " <<
	//	x.second.get_name_catedra() << std::endl;

	//std::cout << "Introdu id-ul catedra: ";
	//unsigned short catedra_id;
	//std::cin >> catedra_id;
	auto it_catedra = catedre.find(id_depart);
	if (it_catedra != catedre.end())
	{
		it_catedra->second.add_professor(id_depart, fullname, proff_role, email,
			phone_num, username, pass);
	}
	else
		throw "Nu este asa catedra!";*/

	auto it_catedra = catedre.find(id_depart);

	if (it_catedra != catedre.end())
	{
		it_catedra->second.add_professor(id_depart, fullname, proff_role, email,
			phone_num, username, pass);
	}
}

void SystemManagement::display_specialty()
{
	system("cls");

	for (const auto &x : catedre)
	{
		std::cout << x.second.get_id() << x.second.get_name_catedra() << std::endl;
	}
	unsigned short id_catedra;
	std::cin >> id_catedra;
	std::cin.ignore();

	auto it = catedre.find(id_catedra);

	try
	{
		if (it == catedre.end())
			throw("Nu este asa catedra");

		it->second.display_specialty(id_catedra);
	}
	catch (const std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
}

void SystemManagement::add_courses_to_catedra()
{
	system("cls");
	std::cin.ignore();

	unsigned short numar_credite = 0;
	std::string course_name;

	this->display_specialty();

	std::cout << "Pentru sfarsit apasa enter" << std::endl;
	do
	{
		std::cout << "Introdu nume curs: ";
		std::getline(std::cin, course_name);
		std::cout << std::endl << "Introdu numar credite ";
		std::cin >> numar_credite;
		std::cin.ignore();

		if (course_name.size() != 0)
		{
			Curs curs_temp(numar_credite, course_name);
			//course_prof_map[course_id] = curs_temp;
			curs_temp.insert_into_db();
		}
		else
			break;

	} while (true);

	/*
	for (const auto &x : catedre)
		std::cout << x.first << ": " <<
		x.second.get_name_catedra() << std::endl;

	std::cout << "Introdu id-ul catedra: ";
	unsigned short catedra_id;
	std::cin >> catedra_id;

	auto it_catedra = catedre.find(catedra_id);

	if (it_catedra != catedre.end())
	{
		it_catedra->second.add_course();
	}
	else
	{
		std::cout << "Nu este asa catedra!" << std::endl;
	}*/
}

void SystemManagement::add_students_to_group()
{
	system("cls");

	db_conn.display_all_groups_from_bd();

	unsigned short group_id;
	std::cout << "Introdu ID-ul grupei: ";
	std::cin >> group_id;
	std::cin.ignore();

	std::string student_name;
	std::cout << "Pentru sfarsit apasa enter" << std::endl;
	do
	{
		std::cout << "Introdu numele studentului: ";
		std::getline(std::cin, student_name);

		if (student_name.size() != 0)
		{
			std::string email, tel, user, pass;
			std::cout << "Introdu email-ul: ";
			std::cin >> email;
			std::cout << "Introdu nr telefon: ";
			std::cin >> tel;
			std::cout << "Introdu username-ul: ";
			std::cin >> user;
			std::cout << "Introdu parola: ";
			std::cin >> pass;

			Student student_temp(student_name, tel, email, group_id, user, pass);
			//students[student_id] = student_temp;
			student_temp.insert_into_db();
			std::cin.ignore();
		}
		else
			break;

	} while (true);

}

void SystemManagement::add_students_to_course()
{
	system("cls");

	for (const auto &x : catedre)
		std::cout << x.first << ": " <<
		x.second.get_name_catedra() << std::endl;

	std::cout << "Introdu id-ul catedra: ";
	unsigned short catedra_id;
	std::cin >> catedra_id;
	std::cin.ignore();

	auto it_catedra = catedre.find(catedra_id);

	if (it_catedra != catedre.end())
	{
		it_catedra->second.add_students_to_course();
		std::cout << "Studenti adaugati cu succes" << std::endl;
	}
}

void SystemManagement::add_professor_to_course()
{
	system("cls");

	for (const auto &x : catedre)
		std::cout << x.first << ": " <<
		x.second.get_name_catedra() << std::endl;

	std::cout << "Introdu id-ul catedra: ";
	unsigned short catedra_id;
	std::cin >> catedra_id;

	auto it_catedra = catedre.find(catedra_id);

	if (it_catedra != catedre.end())
	{
		it_catedra->second.add_professor_to_course();
		std::cout << "Profesori adaugati cu succes" << std::endl;
	}
}

const Catedra* SystemManagement::get_catedra_student(unsigned short id_student)
{
	for (const auto& catedra_pair : catedre)
	{
		const Catedra& catedra = catedra_pair.second;
		if (catedra.has_student(id_student))
		{ // Verifică dacă studentul este în catedră
			return &catedra; // Returnează pointer către catedra găsită
		}
	}
	return nullptr; // Returneaza nullptr daca studentul nu este gasit in nicio catedra
}

Catedra* SystemManagement::get_catedra_profesor(unsigned short id_profesor)
{
	for (auto& catedra_pair : catedre)
	{
		Catedra& catedra = catedra_pair.second;
		if (catedra.has_professor(id_profesor))
		{ // Verifica dacă prof-ul este in catedra
			return &catedra; // Returneaza pointer catre catedra gasita
		}
	}
	return nullptr; // Returneaza nullptr daca proful nu este gasit in nicio catedra
}

std::map<unsigned short, Catedra>& SystemManagement::get_catedre()
{
	return catedre;
}

SystemManagement* SystemManagement::getInstance() {
	if (instance == nullptr) {
		instance = new SystemManagement();
	}
	return instance;
}

void SystemManagement::display_students() const
{
	system("cls");
	for (const auto &pair : catedre)
		std::cout << pair.first << ": "
		<< pair.second.get_name_catedra();

	std::cout << "Alege catedra: ";
	unsigned short id_catedra;
	std::cin >> id_catedra;

	auto it_catedra = catedre.find(id_catedra);
	if (it_catedra == catedre.end())
	{
		std::cout << "Nu este asa catedra!";
	}

	it_catedra->second.display_students();
}

void SystemManagement::display_professors() const
{
	system("cls");

	for (const auto &pair : catedre)
		std::cout << pair.first << ": "
		<< pair.second.get_name_catedra();

	std::cout << "Alege catedra: ";
	unsigned short id_catedra;
	std::cin >> id_catedra;

	auto it_catedra = catedre.find(id_catedra);
	if (it_catedra == catedre.end())
	{
		std::cout << "Nu este asa catedra!";
	}

	it_catedra->second.display_professors();
}

void SystemManagement::display_students_in_group() const
{
	system("cls");

	for (const auto &pair : catedre)
		std::cout << pair.first << ": "
		<< pair.second.get_name_catedra();

	std::cout << "Alege catedra: ";
	unsigned short id_catedra;
	std::cin >> id_catedra;

	auto it_catedra = catedre.find(id_catedra);
	if (it_catedra == catedre.end())
	{
		std::cout << "Nu este asa catedra!";
	}

	it_catedra->second.display_students_in_group();
}

void SystemManagement::display_students_in_course() const
{
	system("cls");

	for (const auto &pair : catedre)
		std::cout << pair.first << ": "
		<< pair.second.get_name_catedra();

	std::cout << "Alege catedra: ";
	unsigned short id_catedra;
	std::cin >> id_catedra;

	auto it_catedra = catedre.find(id_catedra);
	if (it_catedra == catedre.end())
	{
		std::cout << "Nu este asa catedra!";
	}

	it_catedra->second.display_students_in_course();
}

void SystemManagement::display_professors_in_course() const
{
	system("cls");

	for (const auto &pair : catedre)
		std::cout << pair.first << ": "
		<< pair.second.get_name_catedra();

	std::cout << "Alege catedra: ";
	unsigned short id_catedra;
	std::cin >> id_catedra;

	auto it_catedra = catedre.find(id_catedra);
	if (it_catedra == catedre.end())
	{
		std::cout << "Nu este asa catedra!";
	}

	it_catedra->second.display_professors_in_course();
}

void SystemManagement::display_groups_by_department() const
{
	system("cls");

	for (const auto &pair : catedre)
		std::cout << pair.first << ": "
		<< pair.second.get_name_catedra() << std::endl;

	std::cout << "Alege catedra: ";
	unsigned short id_catedra;
	std::cin >> id_catedra;

	auto it_catedra = catedre.find(id_catedra);
	if (it_catedra == catedre.end())
	{
		std::cout << "Nu este asa catedra!";
	}

	it_catedra->second.display_groups_by_department();
}

void SystemManagement::display_all_groups() const
{
	system("cls");
	db_conn.display_all_groups_from_bd();
}

void SystemManagement::get_catedra(const std::string& id, std::string& depName, std::string& facultyName)
{
	try
	{
		if (db_conn.isConnected()) {
			// Creează interogarea pregătită
			std::string query = "SELECT department_name, faculty FROM departments WHERE department_id = ?";
			std::shared_ptr<sql::PreparedStatement> pstmt(db_conn.conn->prepareStatement(query));

			// Setează valoarea parametrului din interogare
			pstmt->setString(1, id);
			// Execută interogarea
			std::shared_ptr<sql::ResultSet> result(pstmt->executeQuery());

			// Verifică dacă există rezultate
			if (result && result->next()) {
				depName = result->getString("department_name").c_str();
				facultyName = result->getString("faculty").c_str();
			}
			else {
				throw std::runtime_error("Catedra nu a fost găsită!");
			}
		}
		else {
			throw std::runtime_error("Conexiunea la baza de date nu este activă!");
		}
	}
	catch (const std::exception& e)
	{
		std::cerr << "Eroare la obținerea datelor despre catedră: " << e.what() << std::endl;
		System::Windows::Forms::MessageBox::Show(gcnew System::String(e.what()), "Eroare", System::Windows::Forms::MessageBoxButtons::OK, System::Windows::Forms::MessageBoxIcon::Error);
	}
}

void SystemManagement::get_professor(const std::string& id, std::string& full_name, std::string& email, std::string& roll, std::string& phone_number,
	std::string& username, std::string& pass)
{
	try
	{
		db_conn.get_professor(id, full_name, email, roll, phone_number, username, pass);

	}
	catch (const std::exception&)
	{

	}
}

std::vector<std::tuple<std::string, std::string, std::string>> SystemManagement::get_all_catedre()
{
	std::vector<std::tuple<std::string, std::string, std::string>> catedre;

	try
	{
		// Creează interogarea SQL
		std::string query = "SELECT department_id, department_name, faculty FROM departments;";
		// Execută interogarea
		std::shared_ptr<sql::PreparedStatement> pstmt(db_conn.conn->prepareStatement(query));
		std::shared_ptr<sql::ResultSet> result(pstmt->executeQuery());

		// Iterează prin rezultatele interogării
		while (result->next())
		{
			int id = result->getInt("department_id");
			std::string dep_name = result->getString("department_name");
			std::string faculty_name = result->getString("faculty");

			// Adaugă catedra în vector
			catedre.emplace_back(std::to_string(id), dep_name, faculty_name);
		}
	}
	catch (const std::exception& e)
	{
		std::cerr << "Eroare la obținerea listei de catedre: " << e.what() << std::endl;
	}

	return catedre;
}

std::vector<std::tuple<std::string, std::string, std::string>> SystemManagement::get_all_professors()
{
	std::vector<std::tuple<std::string, std::string, std::string>> catedre;

	try
	{
		// Creează interogarea SQL
		std::string query = "SELECT department_id, department_name, faculty FROM departments;";
		// Execută interogarea
		std::shared_ptr<sql::PreparedStatement> pstmt(db_conn.conn->prepareStatement(query));
		std::shared_ptr<sql::ResultSet> result(pstmt->executeQuery());

		// Iterează prin rezultatele interogării
		while (result->next())
		{
			int id = result->getInt("department_id");
			std::string dep_name = result->getString("department_name");
			std::string faculty_name = result->getString("faculty");

			// Adaugă catedra în vector
			catedre.emplace_back(std::to_string(id), dep_name, faculty_name);
		}
	}
	catch (const std::exception& e)
	{
		std::cerr << "Eroare la obținerea listei de catedre: " << e.what() << std::endl;
	}

	return catedre;
}

void SystemManagement::delete_professor(std::string id)
{
	try
	{
		db_conn.delete_professor_from_db(id);
	}
	catch (const std::exception& e)
	{
		std::cerr << "Eroare la stergerea profesorului: " << e.what() << std::endl;
	}
	catch (const sql::SQLException& e)
	{
		std::cerr << "Eroare la stergerea profesorului: " << e.what() << std::endl;
		std::cerr << "Eroare la stergerea profesorului: " << e.getCause() << std::endl;
	}
}

void SystemManagement::delete_catedra(const std::string& id)
{
	/*std::string query = "DELETE FROM departments WHERE department_id = '" + id + "';";
	db_conn.executeQuery(query);*/
	db_conn.delete_department_from_db(id);
}