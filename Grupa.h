#pragma once
#ifndef GRUPA
#define GRUPA

class Grupa
{
public:
	Grupa() {}

	// Constructor to initialize group with id_catedra, name, and year
	Grupa(unsigned short id, const std::string& name, int year) :
		id_catedra(id), group_name(name), year_of_study(year) {}

	// Add students to the group
	void add_student(std::vector<Student> &);
	void add_student(std::map<unsigned short, Student>::iterator &);

	// Display students in the group
	void display_students_in_group() const;
	void display_all_students() const;

	// Remove a student by ID
	void remove_student(unsigned short);

	// Display group details
	void display_group() const;

	// Get the group ID
	unsigned short get_group_id() const;

	unsigned short get_id_catedra_of_group() const
	{
		return id_catedra;
	}
	std::string get_group_name() const
	{
		return group_name;
	}
	unsigned short get_group_year_of_study() const
	{
		return year_of_study;
	}

	// Get a list of students in the group
	const std::vector<Student> get_students() const;

	// Get the number of students
	unsigned short get_number_of_students() const;

private:
	unsigned short id_group;
	unsigned short id_catedra; //catedra la care apartine grupa
	std::string group_name;
	unsigned short year_of_study;
	std::vector<Student> students;
};

#endif // ! GRUPA
