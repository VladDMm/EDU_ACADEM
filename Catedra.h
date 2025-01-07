#pragma once
#ifndef CATEDRA
#define CATEDRA

class Catedra {
public:
	Catedra() {}

	Catedra(unsigned short id, const std::string name, const std::string faculty)
		: id_catedra(id), catedra_name(name), faculty(faculty) {}

	void insert_catedra_to_bd();

	// Add a new professor to the system
	void add_professor(short id_depart, std::string fullname, std::string proff_role, std::string email,
		std::string phone_num, std::string username, std::string pass);

	void add_students();

	// Add a professor to a course
	void add_professor_to_course();

	void add_speciality();

	// Add students to a course
	void add_students_to_course();

	// Add a new group to the system
	void add_group();

	// Add students to a group
	void add_students_to_group();

	// Add a new course
	void add_course();

	void add_grade_to_course(unsigned short id_prof);

	void add_absence_to_course(unsigned short);

	void display_absence_in_course(unsigned short);

	void display_grades_in_course(unsigned short) const;

	// Display all students in the system
	void display_students() const;

	void display_specialty(unsigned short id_catera) const;

	// Display students in a course
	void display_students_in_course() const;

	// Afisare studentii de la curs dupa cursurile care ii apartin profesorului
	void display_students_in_course_by_prof(unsigned short) const;

	// Display students in a group
	void display_students_in_group() const;

	// Display all professors
	void display_professors() const;

	// Display professors in a course
	void display_professors_in_course() const;

	// Afisare grupe dupa id catedra
	void display_groups_by_department() const;

	// Afisare cursuri ale studentului dupa id-ul lui
	void show_student_courses(unsigned short id) const;

	// Afisarea cursurilor care ii apartine profesorului
	void show_professor_courses(unsigned short) const;

	// Obtine mapa cu studenti
	const std::map<unsigned short, Student>& get_studenti() const {
		return students;
	}

	// Obtine mapa cu profesori
	const std::map<unsigned short, Profesor>& get_profesori() const {
		return professors;
	}

	// Obtine id catedra;
	unsigned short get_id() const {
		return id_catedra;
	}

	// Obtine nume catedra
	std::string get_name_catedra() const {
		return catedra_name;
	}
	std::string getFaculty() const { return faculty; }

	// Verifică dacă un student este în această catedră
	bool has_student(unsigned short id_student) const;

	// Verifica daca un profesor este in aceasta catedra
	bool has_professor(unsigned short id_profesor) const;

	// Returneaza un obiect student, carui ii apartine user/pass-ul
	Student* authenticate_student(std::string &user, std::string &pass);

	Profesor* authenticate_profesor(std::string &user, std::string &pass);

private:
	unsigned short id_catedra;
	std::string catedra_name;
	std::string faculty;


	std::vector<Curs> courses;
	std::map<unsigned short, Student> students; // Lista de studenți
	std::map<unsigned short, Profesor> professors; // Lista de profesori
	std::map<unsigned short, Curs> course_prof_map; // Lista de cursuri cu profesori, studenti
	std::map<unsigned short, Grupa> groups; // Lista de grupe cu studentii lor
};

#endif // !CATEDRA


