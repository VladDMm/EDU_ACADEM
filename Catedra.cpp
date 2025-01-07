﻿#include "IncludesCentral.h"

void Catedra::insert_catedra_to_bd()
{
	std::string query = "INSERT INTO departments (department_name, faculty) VALUES ('" + catedra_name + "', '" + faculty + "')";
	db_conn.executeQuery(query);
}

void Catedra::add_students()
{
	system("cls");
	std::cin.ignore();
	std::string student_name;
	std::cout << "Pentru sfarsit apasa enter" << std::endl;
	do
	{
		std::cout << "Introdu numele studentului: ";
		std::getline(std::cin, student_name);

		if (student_name.size() != 0)
		{
			std::string email, user, pass;
			std::cout << "Introdu email-ul: ";
			std::cin >> email;
			std::cout << "Introdu username-ul: ";
			std::cin >> user;
			std::cout << "Introdu parola: ";
			std::cin >> pass;

			Student student_temp(student_name, email, user, pass);
			//	students[student_id] = student_temp;
			student_temp.insert_into_db();
			std::cin.ignore();
		}
		else
			break;

	} while (true);
	
}
// Funcție pentru a adăuga un profesor

void Catedra::add_professor(short id_depart, std::string fullname, std::string proff_role, std::string email,
	std::string phone_num, std::string username, std::string pass)
{
	Profesor profesor_temp(id_catedra, fullname, phone_num, email, proff_role, username, pass);
	profesor_temp.insert_into_db();

	//system("cls");
	//std::cin.ignore();
	//std::string professor_name;
	//std::string professor_role;
	//std::cout << "Pentru sfarsit apasa enter" << std::endl;
	//do
	//{
	//	std::cout << "Introdu numele profesorului: ";
	//	std::getline(std::cin, professor_name);
	//	if (professor_name.size() != 0)
	//	{
	//		std::string user, pass, email, phone_numb;
	//		std::cout << "Introdu rolul profesorului (titular, asistent etc.): ";
	//		std::getline(std::cin, professor_role);
	//		std::cout << "Introdu email: ";
	//		std::getline(std::cin, email);
	//		std::cout << "Introdu telefon: ";
	//		std::cin >> phone_numb;
	//		std::cin.ignore();
	//		std::cout << "Introdu username: ";
	//		std::getline(std::cin, user);
	//		std::cout << "Introdu parola: ";
	//		std::cin >> pass;
	//		std::cin.ignore();
	//		// Creăm un obiect Profesor cu datele introduse
	//		Profesor profesor_temp(id_catedra, professor_name, phone_numb, email, professor_role, user, pass);
	//		profesor_temp.insert_into_db();
	//		//professors[professor_id] = profesor_temp;
	//		//++professor_id;
	//	}
	//	else
	//		break;
	//} while (true);
}

void Catedra::add_speciality()
{
	std::string denumire_specialitate;
	
	std::cout << "Introdu denumire specialitate" << std::endl;
	std::getline(std::cin, denumire_specialitate);

	unsigned short id_profesor = 0;
	
	this->display_professors();

	std::cout << "Alege directorul de program" << std::endl;
	std::cin >> id_profesor;
	std::cin.ignore();

	db_conn.add_specialitate_to_db(id_catedra, id_profesor, denumire_specialitate);
}

void Catedra::add_course()
{
	system("cls");
	std::cin.ignore();

	unsigned short numar_credite = 0;
	std::string course_name;

	std::cout << "Pentru sfarsit apasa enter" << std::endl;
	do
	{
		std::cout << "Introdu nume curs: ";
		std::getline(std::cin, course_name);
		std::cout << std::endl << "Introdu numar credite";
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

}

void Catedra::add_group()
{	
	//if (!groups.empty())
	//{
	//	size_t group_id = (--groups.end())->first;
	//	++group_id;
	//	std::string group_name;
	//	int group_year = 0;
	//	std::cout << "Pentru sfarsit apasa enter" << std::endl;
	//	do
	//	{
	//		std::cout << "Introdu denumirea grupei: ";
	//		std::getline(std::cin, group_name);
	//		if (!group_name.empty())
	//		{
	//			std::cout << "Introdu anul grupei: ";
	//			std::cin >> group_year;
	//			std::cin.ignore();
	//			// Creăm obiectul de tip Grupa și îl adăugăm în map
	//			Grupa group_temp(group_id, group_name, group_year);
	//			
	//			groups.emplace(group_id, group_temp);
	//			++group_id;
	//			std::cout << "Grupa a fost adaugata cu succes!\n";
	//		}
	//		else
	//			break;
	//	} while (true);
	//}
	//else
	//{
	//	size_t group_id = 1;
	//	std::string group_name;
	//	int group_year = 0;
	//	std::cout << "Pentru sfarsit apasa enter" << std::endl;
	//	do
	//	{
	//		std::cout << "Introdu denumirea grupei: ";
	//		std::getline(std::cin, group_name);
	//		if (!group_name.empty())
	//		{
	//			std::cout << "Introdu anul grupei: ";
	//			std::cin >> group_year;
	//			std::cin.ignore();
	//			// Creăm obiectul de tip Grupa și îl adăugăm în map
	//			Grupa group_temp(group_id, group_name, group_year);
	//			groups.emplace(group_id, group_temp);
	//			++group_id;
	//			std::cout << "Grupa a fost adaugata cu succes!\n";
	//		}
	//		else
	//			break;
	//	} while (true);
	//}

	system("cls");
	std::cin.ignore();
	unsigned short group_year;
	std::string group_name;
	std::cout << "Pentru sfarsit apasa enter" << std::endl;
	do
	{
		std::cout << "Introdu denumirea grupei: ";
		std::getline(std::cin, group_name);
		if (!group_name.empty())
		{
			std::cout << "Introdu anul grupei: ";
			std::cin >> group_year;
			std::cin.ignore();
			// Adăugăm grupul în baza de date
			db_conn.addGroupToDatabase(Grupa(id_catedra, group_name, group_year));
		}
		else
			break;

	} while (true);
}

// -------------------------------------------
void Catedra::add_students_to_group()
{
	system("cls");
	std::cin.ignore();
	//if (students.empty())
	//{
	//	std::cout << "Nu exista studenti!\n";
	//	return;
	//}
	//for (const auto &group : groups)
	//{
	//	std::cout << group.first << ": ";
	//	group.second.display_group();
	//	std::cout << std::endl;
	//}

	db_conn.display_all_groups_from_bd();

	unsigned short group_id = 0;
	std::cout << "Introdu ID-ul grupei: ";
	std::cin >> group_id;
	std::cin.ignore();

	auto students = db_conn.get_id_name_students();
	std::cout << "ID\t" << "\t\tNume" << std::endl;
	for (const auto &x : students)
	{
		unsigned short id = 0;
		std::string name;
		std::cout << x.first << "\t\t\t" << x.second << std::endl;
	}

	unsigned short id_students = 0;
	std::cout << "Alege id-ul studentului si apasa enter" << std::endl;
	std::cout << "Pentru sfarsit apasa 0" << std::endl;

	do
	{
		std::cin >> id_students;
		std::cin.ignore();

		//db_conn.add_students_to_group_in_db(id_students, group_id);

		if (id_students == 0)
			break;

	} while (true);


	/*if (groups.find(group_id) == groups.end()) {
		std::cout << "Grupa cu acest ID nu există!\n";
		return;
	}
	for (auto &x : students)
	{
		std::cout << x.first << ": ";
		x.second.display_student();
		std::cout << std::endl;
	}
	//size_t id;
	//do
	//{
	//	std::cout << "Alege id-ul studentilor(pentru iesire apasa 0):" << std::endl;
	//	std::cin >> id;
	//	if (id == 0)
	//		break;
	//	auto it = students.find(id);
	//	groups[group_id].add_student(it);
	//} while (true);


	//size_t student_id = db_conn.getLastInsertId("SELECT  LAST_INSERT_ID() FROM `students`");
	std::string student_name;

	std::cout << "Pentru sfarsit apasa enter" << std::endl;
	do
	{
		std::cout << "Introdu numele studentului: ";
		std::getline(std::cin, student_name);

		if (student_name.size() != 0)
		{
			std::string email, user, pass;
			std::cout << "Introdu email-ul: ";
			std::cin >> email;
			std::cout << "Introdu username-ul: ";
			std::cin >> user;
			std::cout << "Introdu parola: ";
			std::cin >> pass;

			Student student_temp(student_name, email, group_id, user, pass);
			//students[student_id] = student_temp;
			student_temp.insert_into_db();
			//++student_id;
			std::cin.ignore();

		}
		else
			break;

	} while (true);

	/*std::vector<Student> students_in_group;
	std::cout << "Pentru sfarsit apasa enter" << std::endl;
	size_t student_id = db_conn.getLastInsertId("SELECT FROM `students` LAST_INSERT_ID()");
	std::string student_name;

	do
	{
		std::cout << "Introdu numele studentului: ";
		std::getline(std::cin, student_name);
		if (!student_name.empty())
		{
			students_in_group.emplace_back(student_id, student_name);
			++student_id;
		}
		else
			break;
	} while (true);

	groups[group_id].add_student(students_in_group);*/
}

void Catedra::add_professor_to_course()
{
	system("cls");
	for (const auto &course_entry : course_prof_map)
	{
		std::cout << course_entry.first << ": ";
		course_entry.second.display_course();
	}

	unsigned short course_id = 0;
	std::cout << "Alege cursul: ";
	std::cin >> course_id;
	std::cin.ignore();

	auto it_course = course_prof_map.find(course_id);
	/*auto it = std::find_if(curs.begin(), curs.end(), [&](Curs &p)
	{return p.get_id_curs() == id_curs; });*/

	if (it_course == course_prof_map.end())
	{
		std::cout << "Nu exista un curs cu acest ID!" << std::endl;
		return;
	}

	std::cout << "Cati profesori doresti sa adaugi la curs: ";
	unsigned short num_professors;
	std::cin >> num_professors;
	std::cin.ignore();
	std::cout << std::endl;

	if (professors.empty())
	{
		std::cout << "Nu sunt profesori adaugati!" << std::endl;
		return;
	}
	for (const auto &professor : professors)
		std::cout << professor.second.get_id_prof() << ": " << professor.second.get_full_name() << std::endl;

	unsigned short i = 0;
	while (i < num_professors)
	{
		unsigned short professor_id = 0;
		std::cout << "Alege profesorul: ";
		std::cin >> professor_id;
		std::cin.ignore();
		std::cout << std::endl;
		auto it_professor = professors.find(professor_id);
		//auto it_professor = std::find_if(professors.begin(), professors.end(), [&](const Profesor &p)
		//{return p.get_id() == professor_id; });

		if (it_professor != professors.end())
		{
			it_course->second.add_professor(it_professor->second);
		}
		++i;
	}
	std::cout << "Profesori adaugati cu succes!";
}

void Catedra::add_students_to_course()
{
	system("cls");



	if (course_prof_map.empty()) {
		std::cout << "Nu sunt cursuri disponibile pentru adăugarea de studenți.\n";
		return;
	}

	// Afișează cursurile disponibile
	std::cout << "Cursurile disponibile:\n";
	for (const auto& curs_entry : course_prof_map) {
		std::cout << "ID Curs: " << curs_entry.first << "\n";
		curs_entry.second.display_course();  // Metoda pentru afisarea detaliilor cursului
	}

	unsigned short course_id = 0;
	std::cout << "Alege ID-ul cursului la care dorești să adaugi studenți: ";
	std::cin >> course_id;
	std::cin.ignore();

	// Caută cursul în mapa profesori_curs
	auto course_it = course_prof_map.find(course_id);
	if (course_it == course_prof_map.end())
	{
		std::cout << "Nu există un curs cu acest ID.\n";
		return;
	}

	if (groups.empty())
	{
		std::cout << "Nu sunt studenți disponibili în grupe.\n";
		return;
	}

	// Afișează studenții din fiecare grupă
	std::cout << "Studenții disponibili:\n";
	for (const auto& grupa_entry : groups)
	{
		std::cout << "Grupa " << grupa_entry.first << ":\n";
		grupa_entry.second.display_students_in_group();  // Metodă pentru afișarea studenților din grupă
	}

	unsigned short group_id = 0;
	std::cout << "Alege ID-ul grupei de unde dorești să adaugi studenți: ";
	std::cin >> group_id;
	std::cin.ignore();

	// Cauta grupa in mapa grupe
	auto group_it = groups.find(group_id);
	if (group_it == groups.end())
	{
		std::cout << "Nu s-a găsit grupa cu acest ID.\n";
		return;
	}

	const Grupa& grupa = group_it->second;
	// Obține studentii din grupa
	auto studenti = grupa.get_students();
	course_it->second.add_students(studenti);
}

void Catedra::add_absence_to_course(unsigned short id_prof)
{
	system("cls");
	this->show_professor_courses(id_prof);

	std::cout << "Introdu ID-ul cursului: ";
	unsigned short course_id;
	std::cin >> course_id;
	std::cin.ignore();

	auto course_it = course_prof_map.find(course_id);
	if (course_it == course_prof_map.end())
	{
		std::cout << "Nu este asa id la curs" << std::endl;
		return;
	}

	for (auto &x : course_prof_map)
	{
		std::cout << x.first << ": ";
		x.second.display_students_in_course();
		std::cout << std::endl;
	}
	// Solicităm ID-ul studentului
	std::cout << "Introduceți ID-ul studentului: ";
	unsigned short student_id;
	std::cin >> student_id;
	std::cin.ignore();

	// Căutăm studentul în sistem
	auto student_it = students.find(student_id);
	if (student_it == students.end()) {
		std::cout << "Studentul cu ID-ul " << student_id << " nu a fost găsit.\n";
		return;
	}

	std::cout << "Absenta a-absent/m-motivat" << std::endl;
	std::string absence;
	std::cin >> absence;

	Student& student = student_it->second;
	std::string name_cours = course_it->second.get_name_course();

	course_it->second.add_absence_for_student(name_cours, student, absence);

	std::cout << "Absenta a fost adaugata!" << std::endl;
}

void Catedra::add_grade_to_course(unsigned short id_prof)
{
	system("cls");
	this->show_professor_courses(id_prof);

	unsigned short course_id, student_id;
	double grade_value;

	// Solicităm ID-ul cursului
	std::cout << "Introduceți ID-ul cursului: ";
	std::cin >> course_id;

	// Căutăm cursul după ID
	auto course_it = course_prof_map.find(course_id);
	if (course_it == course_prof_map.end()) {
		std::cout << "Cursul cu ID-ul " << course_id << " nu a fost găsit.\n";
		return;
	}

	for (auto &x : course_prof_map)
	{
		std::cout << x.first << ": ";
		x.second.display_students_in_course();
		std::cout << std::endl;
	}
	// Solicităm ID-ul studentului
	std::cout << "Introduceți ID-ul studentului: ";

	std::cin >> student_id;
	std::cin.ignore();

	// Căutăm studentul în sistem
	auto student_it = students.find(student_id);
	if (student_it == students.end()) {
		std::cout << "Studentul cu ID-ul " << student_id << " nu a fost găsit.\n";
		return;
	}

	// Solicităm valoarea notei
	std::cout << "Introduceți nota: ";
	std::cin >> grade_value;
	std::cin.ignore();

	// Adăugăm nota pentru studentul specificat în cursul selectat
	Student& student = student_it->second;
	std::string name_cours = course_it->second.get_name_course();
	course_it->second.add_grade_for_student(name_cours, student, grade_value);

	std::cout << "Nota a fost adăugată cu succes!\n";
}

void Catedra::display_absence_in_course(unsigned short id_prof)
{
	system("cls");
	this->show_professor_courses(id_prof);

	std::cout << "Alege cursul: ";
	unsigned short course_id;
	std::cin >> course_id;

	auto it_course = course_prof_map.find(course_id);
	if (it_course == course_prof_map.end())
	{
		std::cout << "Nu este asa id la curs" << std::endl;
		return;
	}

	it_course->second.display_students_absences();
}

// Funcție pentru a afișa  grupele dupa catedra
void Catedra::display_groups_by_department() const
{
	system("cls");

	db_conn.displayGroups_from_bd_by_department(id_catedra);
}

void Catedra::display_grades_in_course(unsigned short id_prof) const
{
	system("cls");

	this->show_professor_courses(id_prof);

	std::cout << "Alege cursul: ";
	unsigned short course_id;
	std::cin >> course_id;

	auto it_course = course_prof_map.find(course_id);
	if (it_course == course_prof_map.end())
	{
		std::cout << "Nu este asa id la curs" << std::endl;
		return;
	}

	it_course->second.display_students_grades();
}

// Funcție pentru a afișa toți studenții
void Catedra::display_students() const
{
	//if (groups.empty())
	//{
	//	std::cout << "Nu sunt studenti.";
	//	return;
	//}
	//bool find_students = false;
	//for (const auto &group_entry : groups)
	//{
	//	const Grupa& group_obj = group_entry.second;
	//	// Verifică dacă grupa are studenți
	//	if (group_obj.get_num_students() > 0)
	//	{
	//		std::cout << "Grupa " << group_entry.first << ":\n";  // Afișează ID-ul grupei
	//		group_obj.display_group();
	//		group_obj.display_all_students();  // Afișează studenții din această grupă
	//		find_students = true;
	//	}
	//}
	//// Dacă nu a fost găsit niciun student în nicio grupă
	//if (!find_students)
	//{
	//	std::cout << "Nu sunt studenți în nicio grupă.\n";
	//}

	system("cls");


}

void Catedra::display_specialty(unsigned short id_catedra) const
{
	system("cls");

	db_conn.display_specialty_from_db_by_department(id_catedra);
}

void Catedra::show_professor_courses(unsigned short id_profesor) const
{
	for (const auto &x : course_prof_map)
	{
		// Obține lista de ID-uri ale profesorilor din curs
		std::vector<unsigned short> professor_ids = x.second.get_id_professors();

		// Verifică dacă ID-ul profesorului se află în lista de ID-uri
		if (std::find(professor_ids.begin(), professor_ids.end(), id_profesor) != professor_ids.end())
		{
			std::cout << x.first << ": ";
			// Afișează detalii despre curs dacă profesorul este înscris la acest curs
			x.second.display_course();
		}
	}
}

// Afiseaza cursurile pentru studentul specific, functie pentru studenti
void Catedra::show_student_courses(unsigned short id_student) const
{
	for (const auto &x : course_prof_map)
	{
		// Obține lista de ID-uri ale studenților din curs
		std::vector<unsigned short> student_ids = x.second.get_id_students();

		// Verifică dacă ID-ul studentului se află în lista de ID-uri
		if (std::find(student_ids.begin(), student_ids.end(), id_student) != student_ids.end())
		{
			// Afișează detalii despre curs dacă studentul este înscris la acest curs
			x.second.display_course();
		}
	}
}

// Funcție pentru a afișa toți profesorii
void Catedra::display_professors() const
{
	system("cls");
	db_conn.display_professors_from_db(id_catedra);
}

void Catedra::display_students_in_group() const
{
	system("cls");

	if (groups.empty()) {
		std::cout << "Nu sunt grupe disponibile.\n";
		return;
	}

	std::cout << "Alege grupa:" << std::endl;
	for (const auto &group_entry : groups)
	{
		std::cout << "ID Grupa: " << group_entry.first << std::endl;
		group_entry.second.display_group();
		std::cout << std::endl;
	}
	unsigned short id_group = 0;
	std::cin >> id_group;

	// Verifică dacă grupa există
	auto group_it = groups.find(id_group);
	if (group_it == groups.end()) {
		std::cout << "Nu există o grupă cu acest ID.\n";
		return;
	}
	if (group_it->second.get_number_of_students() == 0)
	{
		std::cout << "Nu există studenti in aceasta grupa." << std::endl;
		return;
	}
	// Afișează studenții din grupa selectată
	//const Grupa& group_obj = group_it->second;
	std::cout << "Studenții din grupa " << id_group << ":\n";
	group_it->second.display_students_in_group();
}

// Afisare studentii de la curs dupa cursurile care ii apartin profesorului
void Catedra::display_students_in_course_by_prof(unsigned short id_prof) const
{
	system("cls");
	this->show_professor_courses(id_prof);

	std::cout << "Alege cursul:\n";
	unsigned short id_course;
	std::cin >> id_course;
	std::cin.ignore();

	auto course_it = course_prof_map.find(id_course);
	if (course_it == course_prof_map.end())
	{
		std::cout << "Nu este asa curs" << std::endl;
		return;
	}

	course_it->second.display_students_in_course();


	//short option;
	//do
	//{
	//	std::cout << "1. Afisare studenti la curs" << std::endl;
	//	std::cout << "2. Adauga nota la curs" << std::endl;
	//	std::cout << "3. Adauga absenta la curs" << std::endl;
	//	std::cout << "0. Iesi" << std::endl;
	//	std::cin >> option;
	//	switch (option)
	//	{
	//	case 1:
	//	{
	//		short id;
	//		std::cin >> id;
	//		auto it_course = course_prof_map.find(id);
	//		if (it_course == course_prof_map.end())
	//		{
	//			std::cout << "Id incorect" << std::endl;
	//			return;
	//		}
	//		it_course->second.display_students_in_course();
	//		break;
	//	}
	//	case 2:
	//	{
	//		break;
	//	}
	//	case 3:
	//	{
	//		break;
	//	}
	//	case 0:
	//		break;
	//	default:
	//		std::cout << "Alegere incorecta" << std::endl;
	//		break;
	//	}
	//} while (option != 0);	
}

// Afisarea studentilor dupa cursurile selectate, functie pentru admin
void Catedra::display_students_in_course() const
{
	system("cls");

	for (const auto &course_entry : course_prof_map)
	{
		course_entry.second.display_course();
	}

	std::cout << "Alege cursul:\n";
	unsigned short id_course;
	std::cin >> id_course;
	std::cin.ignore();

	auto course_it = course_prof_map.find(id_course);
	if (course_it == course_prof_map.end())
	{
		std::cout << "Nu este asa curs" << std::endl;
		return;
	}

	course_it->second.display_students_in_course();
}

// Afisarea profesorilor dupa cursurile selectate, functie pentru admin
void Catedra::display_professors_in_course() const
{
	system("cls");
	std::cout << "Alege cursul:\n";
	unsigned short id_course;
	std::cin >> id_course;
	std::cin.ignore();

	auto it_professor = course_prof_map.find(id_course);
	if (it_professor == course_prof_map.end())
	{
		std::cout << "Nu este asa curs" << std::endl;
		return;
	}
	it_professor->second.display_professors_in_course();
}

// Verifică dacă un student este în această catedră
bool Catedra::has_student(unsigned short id_student) const {
	return students.find(id_student) != students.end();
}
// Verifica daca un profesor este in aceasta catedra
bool Catedra::has_professor(unsigned short id_profesor) const
{
	return professors.find(id_profesor) != professors.end();
}

Student* Catedra::authenticate_student(std::string &usern, std::string &pass)
{
	for (auto &pair : students)
	{
		if (pair.second.get_username() == usern && pair.second.get_passw() == pass)
			return &(pair.second);
	}
	return nullptr; // daca nu se găseste studentul
}

Profesor* Catedra::authenticate_profesor(std::string &user, std::string &pass)
{
	for (auto &pair : professors)
	{
		if (pair.second.get_username() == user && pair.second.get_passw() == pass)
			return &(pair.second);
	}
	return nullptr; // daca nu se găseste proful
}