#pragma once
#ifndef SYSTEMANAGMENT
#define SYSTEMMANAGMENT

class SystemManagement
{
public:
	// Metoda statica pentru a obtine instanta Singleton
	static SystemManagement* getInstance();

	// Functia care returneaza o harta de catedre
	std::map<unsigned short, Catedra> &get_catedre();

	// Funcția care returnează catedra la care apartine un student
	// pe baza unui id_student
	const Catedra *get_catedra_student(unsigned short id_student);

	// Funcția care returnează catedra la care apartine un profesor
	// pe baza unui id_profesor
	Catedra *get_catedra_profesor(unsigned short id_profesor);

	//function for db
	//void add_group();
	void add_catedra(std::string nume_catedra, std::string facultate);
	void add_group_to_catedra();
	void add_students_to_group();
	void update_info_catedra();					// Redenumire catedra
	void remove_catedra();
	void display_students_from_db();
	void add_specialitate();
	void delete_professor(std::string id);

	void display_specialty();

	// function for variable
	void display_students() const;				// Afisarea studentilor

	void add_students();
	void add_professor_to_department(short id_depart, std::string fullname, std::string proff_role, std::string email,
		std::string phone_num, std::string username, std::string pass);
	void add_courses_to_catedra();

	void add_students_to_course();
	void add_professor_to_course();

	void display_catedre() const;

	void display_students_in_course() const;	// Afisarea studentilor intr-un curs
	void display_students_in_group() const;		// Afisarea studentilor dintr-un grup
	void display_professors() const;			// Afisarea profesorilor
	void display_professors_in_course() const;	// Afisarea profesorilor dintr-un curs
	void display_groups_by_department() const;				// Afisarea grupelor
	void display_all_groups() const;				// Afisarea grupelor

	~SystemManagement() {
		delete instance;
	}

	void initialize_catedre()
	{
		catedre = db_conn.select_catedre();
	}

	void delete_catedra(const std::string& id);

	void update_catedra(const std::string& id, const std::string& depName, const std::string& facultyName)
	{
		std::string query = "UPDATE departments SET department_name = '" + depName + "', faculty = '" + facultyName + "' WHERE department_id = '" + id + "';";
		db_conn.executeQuery(query);
	}
	
	void get_catedra(const std::string&, std::string&, std::string&);

	void get_professor(const std::string&, std::string&, std::string&, std::string&, std::string&, std::string&, std::string&);

	std::vector<std::tuple<std::string, std::string, std::string>> get_all_catedre();

	std::vector<std::tuple<std::string, std::string, std::string>> get_all_professors();

private:

	std::map<unsigned short, Catedra> catedre;
	static SystemManagement* instance;
	
	SystemManagement() { initialize_catedre(); }
	

};

#endif // !SYSTEMANAGMENT

