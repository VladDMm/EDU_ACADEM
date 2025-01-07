#include "IncludesCentral.h"

void Grupa::add_student(std::vector<Student> &student_vector)
{
	students.insert(students.begin(), student_vector.begin(), student_vector.end());

	for (const auto &student : student_vector)
	{
		student.insert_into_db();
	}
}

void Grupa::add_student(std::map<unsigned short, Student>::iterator &it)
{

	students.push_back(it->second);
}

void Grupa::remove_student(unsigned short student_id)
{
	students.erase(std::remove_if(students.begin(), students.end(),
		[student_id](const Student& student)
	{ return student.get_id() == student_id; }), students.end());
}

void Grupa::display_group() const
{
	db_conn.display_all_groups_from_bd();
}

void Grupa::display_all_students() const
{
	for (const auto &x : students)
	{
		std::cout << x.get_name() << std::endl;
	}
}

void Grupa::display_students_in_group() const
{
	std::cout << id_group << ": Grupa " << group_name << " (Anul " << year_of_study << ")\n";
	for (const auto &x : students)
	{
		std::cout << x.get_name() << std::endl;
	}
}

unsigned short Grupa::get_number_of_students() const
{
	return students.size();
}

unsigned short Grupa::get_group_id() const
{
	return id_group;
}

const std::vector<Student> Grupa::get_students() const
{
	return students;
}