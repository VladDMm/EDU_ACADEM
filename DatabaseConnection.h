#pragma once
#ifndef DATABASECONNECT
#define DATABASECONNECT

class DatabaseConnection
{
public:
	DatabaseConnection();

	~DatabaseConnection()
	{
		if (conn) {
			conn->close();
		}
	}

	bool connect(const std::string& host, const std::string& user, const std::string& password, const std::string& database) {
		try {
			conn = std::unique_ptr<sql::Connection>(driver->connect(host, user, password));
			conn->setSchema(database);
			return true;
		}
		catch (sql::SQLException& e) {
			std::cerr << "Eroare la conectarea la baza de date: " << e.what() << std::endl;
			return false;
		}
	}
	bool isConnected() const {
		if (conn) {
			try {
				// Dacă conexiunea este activă, o interogare simplă poate ajuta să o verifici.
				std::unique_ptr<sql::Statement> stmt(conn->createStatement());
				std::unique_ptr<sql::ResultSet> res(stmt->executeQuery("SELECT 1"));
				return res->next(); // Dacă există un rezultat, conexiunea este activă
			}
			catch (sql::SQLException& e) {
				return false; // Dacă apare o eroare, conexiunea nu este activă
			}
		}
		return false; // Dacă conexiunea nu este validă
	}
	// Metodă pentru a executa un query
	void executeQuery(const std::string &query);

	std::shared_ptr<sql::ResultSet> executeSelectQuery(const std::string& query);

	void delete_professor_from_db(std::string id_proff);

	void delete_department_from_db(std::string id_depart);

	// Metoda pentru a selecta toti studentii. Se foloseste la afisarea studentilor
	std::vector<std::tuple<unsigned short, std::string, std::string, std::string, unsigned short>> selectStudents();

	// Metoda pentru a selecta toti studentii dupa un id grupa. Se foloseste la afisarea studentilor
	std::vector<std::tuple<unsigned short, std::string, std::string, std::string, unsigned short>> selectStudents(unsigned short);


	std::vector<std::tuple<unsigned short, std::string, std::string, std::string>> selectProfessors(unsigned short);

	std::vector<std::tuple<unsigned short, std::string, std::string, std::string, std::string, std::string, std::string>> selectProfessors();

	std::vector<std::pair<unsigned short, std::string>> get_id_name_students();

	std::map<unsigned short, Catedra> select_catedre()
	{
		std::map<unsigned short,Catedra> catedre_temp;
		
		try {
			std::string query =
				"SELECT d.department_id, d.department_name, d.faculty "
				"FROM departments d ";
			std::unique_ptr<sql::PreparedStatement> pstmt(conn->prepareStatement(query));
			std::unique_ptr<sql::ResultSet> res(pstmt->executeQuery());

			while (res->next()) {
				int department_id = res->getInt("department_id");
				std::string name = std::string(res->getString("department_name"));
				std::string faculty = std::string(res->getString("faculty"));
				//sql::SQLString name = res->getString("department_name");
				//sql::SQLString faculty = res->getString("faculty");

				catedre_temp.emplace(department_id, Catedra(department_id, name, faculty));
			}
		}
		catch (sql::SQLException &e) {
			std::cerr << "SQL Exception: " << e.what() << std::endl;
		}
		return catedre_temp;
	}

	// Metodă pentru a executa un query de tip SELECT student
	//std::vector<std::pair<int, std::string>> selectStudents(const std::string& query);

	void add_students_to_group_in_db(unsigned short, unsigned short);

	// Metodă pentru a executa un query de tip SELECT departments
	std::vector<std::pair<unsigned short, std::string>> selectDepartments(const std::string&);

	void add_students_to_group(unsigned short grupa_id, const std::string &, const std::string &, const std::string &, 
		const std::string &, const std::string &, const std::string &);

	void add_course_to_db(std::string &course_name, unsigned short count_credits);

	void add_professor_to_db(unsigned short id_catedra, const std::string &full_name, const std::string &email, const std::string &phone_number,
		const std::string &professor_role, const std::string &username, const std::string &password_hash, const std::string &salt);

	void add_specialitate_to_db(unsigned short id_catedra, unsigned short id_prof, std::string denumire_specialitate);

	void displayGroups_from_bd_by_department(unsigned short)const;

	void display_professors_from_db(unsigned short id_catedra);

	// Metoda pentru a afisa toti studentii din db
	void display_all_groups_from_bd()const;

	// Metoda pentru a afisa studenti dupa un anumit id grupa
	void display_students_from_db_by_group(unsigned short);

	void display_specialty_from_db() const;
	void display_specialty_from_db_by_department(unsigned short) const;

	// Metodă pentru a actualiza catedra
	void updateCatedra(unsigned short id, const std::string &newName);

	// Metoda pentru a adauga o grupa in db care contine nume_grupa, an_grupa, id_catedra din care face parte
	void addGroupToDatabase(const Grupa &);

	// Metodă pentru a obține ultimul ID inserat
	int getLastInsertId();

	// Metodă pentru a obține ultimul ID inserat dupa un query
	int getLastInsertId(const char *);

	std::vector<std::tuple<std::string, std::string, std::string, std::string, std::string, std::string>> get_professor(std::string, std::string&, std::string&,
		std::string&, std::string&, std::string&, std::string&);

public:
	sql::Driver *driver;
	std::unique_ptr<sql::Connection> conn;
};


#endif