#pragma once
#ifndef STUDENT
#define STUDENT


class Student : public User
{
public:
	// CTOR
	Student() {}

	/*Student(size_t &id, const std::string& nume)
		: id_student(id){}*/

	Student(unsigned short &id, std::string& nume, std::string& email, unsigned short id_grupa, std::string &user, std::string &pass)
		: id_student(id), group_id(id_grupa), User(id, nume, email, user, pass, UserType::student) {};

	Student(std::string& nume, std::string& email, unsigned short id_grupa, std::string &user, std::string &pass)
		: group_id(id_grupa), User(nume, email, user, pass, UserType::student) {};

	Student(std::string& nume, std::string phone_num,std::string& email, unsigned short id_grupa, std::string &user, std::string &pass)
		: group_id(id_grupa), User(nume, phone_num, email, user, pass, UserType::student) {};

	Student(std::string& nume, std::string& email, std::string &user, std::string &pass)
		: User(nume, email, user, pass, UserType::student) {};

	// Suprascrierea operatorului <
	bool operator<(const Student& other) const {
		// Compară întâi după nume
		if (full_name != other.full_name) {
			return full_name < other.full_name;
		}
		// Dacă numele sunt egale, compară după ID
		return id_student < other.id_student;
	}

	void insert_into_db() const;

	// function
	void show_menu() override;

	// actualizeaza numele
	void update_name();

	// afisare informatii student
	void display_student() const;

	// obtine id studentului
	unsigned short get_id() const;

	// obtine numele
	std::string get_name() const;

	~Student() override = default;
private:
	unsigned short id_student = 0;
	unsigned short user_id = 0;
	unsigned short group_id = 0;
};

#endif // !STUDENT