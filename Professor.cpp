#include "IncludesCentral.h"


void Profesor::show_menu()
{
	SystemManagement *system = SystemManagement::getInstance();

	// Apelează get_catedra_profesor pentru a obtine catedra profesorului curent
	Catedra *catedra = system->get_catedra_profesor(id_professor);

	if (!catedra)
	{
		std::cout << "Nu esti inscris la nici o catedra" << std::endl;
		return;
	}

	short option;
	do
	{
		std::cout << "1. Afisare cursuri disponibile" << std::endl;
		std::cout << "2. Afisare studenti la curs" << std::endl;
		std::cout << "3. Adauga nota la curs" << std::endl;
		std::cout << "4. Adauga absenta la curs" << std::endl;
		std::cout << "5. Afisare note la curs" << std::endl;
		std::cout << "6. Afisare absente la curs" << std::endl;
		std::cout << "0. Iesi" << std::endl;

		std::cin >> option;
		std::cin.ignore();

		switch (option)
		{
		case 1:
		{
			catedra->show_professor_courses(id_professor);
			break;
		}
		case 2:
		{
			catedra->display_students_in_course_by_prof(id_professor);
			break;
		}
		case 3:
		{
			catedra->add_grade_to_course(id_professor);
			break;
		}
		case 4:
		{
			catedra->add_absence_to_course(id_professor);
			break;
		}
		case 5:
			catedra->display_grades_in_course(id_professor);
			break;
		case 6:
			catedra->display_absence_in_course(id_professor);
		case 0:
			break;
		default:
			std::cout << "Alegere incorecta!" << std::endl;
			break;
		}
	} while (option != 0);

}

std::string Profesor::get_full_name() const
{
	return full_name;
}

unsigned short Profesor::get_id_prof()const
{
	return id_professor;
}

std::string Profesor::get_role() const
{
	return professor_role;
}

void Profesor::insert_into_db() const {
	//// Inserare în tabela users
	//std::string user_query = "INSERT INTO users (username, password) VALUES ('" + username + "', '" + password_hash + "')";
	//db_conn.executeQuery(user_query);
	//// Inserare în tabela professors
	//std::string professor_query = "INSERT INTO professors (id, full_name, professor_role, username, password) VALUES ('" +
	//	std::to_string(id_professor) + "', '" + full_name + "', '" + professor_role + "', '" + username + "', '" + password_hash + "')";
	//db_conn.executeQuery(professor_query);

	db_conn.add_professor_to_db(catedra_id, full_name, email, phone_number, professor_role, username, password_hash, salt);
}
