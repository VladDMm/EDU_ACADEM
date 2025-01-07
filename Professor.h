#pragma once
#ifndef PROFESSORS
#define PROFESSORS


class Profesor : public User
{
public:

	Profesor() {}

	Profesor(unsigned short id, const std::string &name, std::string &role)
		: id_professor(id), full_name(name), professor_role(role) {}

	Profesor(unsigned short id, const std::string &name, const std::string &email, std::string &role, std::string &user, std::string &pass)
		: id_professor(id), full_name(name), professor_role(role), User(id, name, email, user, pass, UserType::profesor) {}

	/*Profesor(unsigned short id, const std::string &name, const std::string &phone_num, const std::string &email, const std::string &role,
		const std::string &user, const std::string &pass)
		: id_professor(id), full_name(name), professor_role(role), User(name, phone_num, email, user, pass, UserType::profesor) {}*/

	Profesor(const std::string &name, const std::string &email, std::string &role, std::string &user, std::string &pass)
		: full_name(name), professor_role(role), User(name, email, user, pass, UserType::profesor) {}

	Profesor(const std::string &name, const std::string &phone_num, const std::string &email, const std::string &role, const std::string &user, const std::string &pass)
		: full_name(name), professor_role(role), User(name, phone_num, email, user, pass, UserType::profesor) {}

	Profesor(unsigned short id_catedra, const std::string &name, const std::string &phone_num, const std::string &email, const std::string &role, const std::string &user, const std::string &pass)
		: catedra_id(id_catedra), full_name(name), professor_role(role), User(name, phone_num, email, user, pass, UserType::profesor) {}

	void show_menu() override;

	unsigned short get_id_prof() const;

	std::string get_full_name() const;

	std::string get_role() const;

	~Profesor() override = default;

	void insert_into_db() const;


private:
	unsigned short id_professor = 0;
	unsigned short catedra_id = 0;
	std::string full_name;
	std::string professor_role;
};

#endif // !PROFESSORS