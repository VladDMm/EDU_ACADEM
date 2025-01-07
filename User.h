#pragma once
#ifndef USER
#define USER

class User
{
public:
	User() = default;

	enum UserType
	{
		admin,
		student,
		profesor
	};

	User(unsigned short id_user, const std::string &name, const std::string &email, const std::string &user, const std::string &pass, UserType type)
		: id_user(id_user), full_name(name), email(email), username(user), password_hash(pass), user_type(type) {}

	User(const std::string &name, const std::string &email, const std::string &user, const std::string &pass, UserType type)
		: full_name(name), email(email), username(user), password_hash(pass), user_type(type) {}

	User(const std::string &name, const std::string &phone_numb, const std::string &email, const std::string &user, const std::string &pass, UserType type)
		: full_name(name), phone_number(phone_numb), email(email), username(user), password_hash(pass), user_type(type) {}

	virtual void show_menu() = 0;

	std::string get_username()
	{
		return username;
	}

	std::string get_passw()
	{
		return password_hash;
	}

	virtual ~User() = default;

protected:
	unsigned short id_user;
	UserType user_type;

	std::string full_name;
	std::string email;
	std::string phone_number;
	std::string username;
	std::string password_hash;
	std::string salt;
};

#endif // !USER