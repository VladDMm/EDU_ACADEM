#pragma once
#ifndef CURS
#define CURS

class Curs {
public:
	Curs() {}
	~Curs() {}

	void insert_into_db();

	// Constructor care inițializează un curs cu un ID și o denumire
	Curs(unsigned short id, unsigned short count_credits, const std::string& name) :
		id_course(id),count_credits(count_credits), course_name(name) {}

	// Constructor care inițializează un curs cu un ID și o denumire
	Curs(unsigned short count_credits, const std::string& name) :
		id_course(0), count_credits(count_credits), course_name(name) {}

	// Constructor de copiere care primește un curs și un profesor
	Curs(Curs& obj_curs, Profesor& prof)
		: id_course(obj_curs.id_course), course_name(obj_curs.course_name)
	{
		course_professors.push_back(prof);
	}

	// Constructor care primește un student și îl adaugă la curs
	Curs(const Student& obj_student)
	{
		course_students.push_back(obj_student);
	}

	// Get the course details
	//Curs get_course() const;

	 // Adaugă o notă pentru un student într-un curs
	void add_grade_for_student(std::string, Student &, double);

	// Display the course details(name)
	void display_course() const;

	// Display students in the course
	void display_students_in_course() const;

	// Add a professor to the course
	void add_professor(Profesor &p_tmp);

	// Adauga absenta pentru student. Parametri - nume curs; - obiect student; -absenta
	void add_absence_for_student(std::string &, const Student &, std::string&);

	// Add students to the course
	void add_students(const std::vector<Student> &);

	void add_single_student(const Student &);

	// Display the professors of the course
	void display_professors_in_course()const;

	void display_students_absences() const;

	void display_students_grades() const;

	// Remove a student by ID
	void remove_student(unsigned short id_student);

	// Get the course ID
	unsigned short get_id();

	std::string get_name_course() {
		return course_name;
	}

	// Get a vector of id students
	std::vector<unsigned short> get_id_students() const;

	// Get a vector of id professors
	std::vector<unsigned short> get_id_professors() const;

private:
	unsigned short id_course;
	std::string course_name;
	unsigned short count_credits;
	std::vector<Student> course_students;
	std::vector<Profesor> course_professors;
	Nota nota;
	Absente absente;
};

#endif // !CURS