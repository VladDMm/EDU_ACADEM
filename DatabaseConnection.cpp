#include "IncludesCentral.h"

DatabaseConnection db_conn;

DatabaseConnection::DatabaseConnection()
{
	// Configurare conexiune
	//sql::SQLString url("jdbc:mariadb://localhost:3306/academic_records");
	sql::SQLString url("jdbc:mariadb://localhost:3306/EDU");
	sql::Properties properties({ {"user", "root"}, {"password", "root"} });
	// Conectează la baza de date
	try {
		driver = sql::mariadb::get_driver_instance();  // Obține driverul MariaDB
		conn = std::unique_ptr<sql::Connection>(driver->connect(url, properties));
		//std::cout << "Conexiune reușită!" << std::endl;
	}
	catch (sql::SQLException &e) {
		std::cerr << "Eroare de conexiune: " << e.what() << std::endl;
	}
}

int DatabaseConnection::getLastInsertId()
{
	try
	{
		std::unique_ptr<sql::Statement> stmt(conn->createStatement());
		std::unique_ptr<sql::ResultSet> res(stmt->executeQuery("SELECT LAST_INSERT_ID()"));

		if (res->next())
		{
			return res->getInt(1);
		}
		else
		{
			std::cerr << "Nu s-a putut obține ultimul ID inserat." << std::endl;
			return -1;
		}
	}
	catch (sql::SQLException &e)
	{
		std::cerr << "SQL Exception: " << e.what() << std::endl;
		return -1;
	}
}

void DatabaseConnection::display_professors_from_db(unsigned short id_catedra)
{
	auto selectProfessors = db_conn.selectProfessors(id_catedra);

	std::cout << "ID\t\t\t" << "Full Name\t\t\t" << "Professor Role\t\t\t" << "Email\t\t\t" << std::endl;
	std::cout << "-------------------------------------------------------------------------------------------------------------" << std::endl;
	for (const auto &professor : selectProfessors)
	{
		std::string full_name, prof_role, email;
		unsigned short id_professor;
		std::tie(id_professor, full_name, prof_role, email) = professor;

		std::cout << id_professor << "\t\t\t" << full_name << "\t\t\t" << prof_role << "\t\t\t"
			<< email << std::endl;
	}
}

void DatabaseConnection::add_specialitate_to_db(unsigned short id_catedra, unsigned short id_prof, std::string denumire_specialitate)
{
	try 
	{
		// Verifică existența id_catedra în departments
		std::string checkDeptQuery = "SELECT COUNT(*) FROM departments WHERE department_id = ?";
		std::unique_ptr<sql::PreparedStatement> checkDeptStmt(conn->prepareStatement(checkDeptQuery));
		checkDeptStmt->setInt(1, id_catedra);
		std::unique_ptr<sql::ResultSet> deptRes(checkDeptStmt->executeQuery());

		if (deptRes->next() && deptRes->getInt(1) == 0) {
			throw std::runtime_error("Eroare: department_id nu există în tabela departments.");
		}

		// Verifică existența profesorului
		std::string checkProfQuery = "SELECT COUNT(*) FROM professors WHERE professor_id = ?";
		std::unique_ptr<sql::PreparedStatement> checkProfStmt(conn->prepareStatement(checkProfQuery));
		checkProfStmt->setInt(1, id_prof);
		std::unique_ptr<sql::ResultSet> profRes(checkProfStmt->executeQuery());

		if (profRes->next() && profRes->getInt(1) == 0) {
			throw std::runtime_error("Eroare: professor_id nu există în tabela professors.");
		}

		// Inserare în tabela 'specialty'
		std::string query = "INSERT INTO specialty (denumire_specialitate, department_id, director_program) "
			"VALUES (?, ?, ?)";
		std::unique_ptr<sql::PreparedStatement> pstmt(conn->prepareStatement(query));
		pstmt->setString(1, denumire_specialitate);
		pstmt->setInt(2, id_catedra);
		pstmt->setInt(3, id_prof); 

		unsigned short affectedRows = pstmt->executeUpdate();
		if (affectedRows > 0) {
			std::cout << "Specialitate adăugată cu succes." << std::endl;
		}
		else {
			std::cout << "Eroare: Nu s-a putut adăuga specialitatea." << std::endl;
		}
	}
	catch (sql::SQLException &e) {
		std::cerr << "Eroare SQL: " << e.what()
			<< " Cod: " << e.getErrorCode()
			<< " SQL State: " << e.getSQLState() << std::endl;
	}
	catch (const std::exception &e) {
		std::cerr << "Eroare generală: " << e.what() << std::endl;
	}
}

void DatabaseConnection::add_course_to_db(std::string &course_name, unsigned short count_credits)
{
	try {
		// Inserare curs
		std::string coursesQuery = "INSERT INTO courses (course_name, nr_credite) "
			"VALUES (?, ?)";
		std::unique_ptr<sql::PreparedStatement> pstmt(conn->prepareStatement(coursesQuery));
		pstmt->setString(1, course_name);
		pstmt->setInt(2, count_credits);
	}
	catch (sql::SQLException &e)
	{
		std::cerr << "Eroare SQL: " << e.what()
			<< " Cod: " << e.getErrorCode()
			<< " SQL State: " << e.getSQLState() << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << "Eroare generală: " << e.what() << std::endl;
	}
}

void DatabaseConnection::add_professor_to_db(unsigned short id_catedra, const std::string &full_name,
	const std::string &email, const std::string &phone_number,
	const std::string &professor_role, const std::string &username,
	const std::string &password_hash, const std::string &salt)
{
	try {
		// Verifică existența id_catedra în departments
		std::string checkDeptQuery = "SELECT COUNT(*) FROM departments WHERE department_id = ?";
		std::unique_ptr<sql::PreparedStatement> checkStmt(conn->prepareStatement(checkDeptQuery));
		checkStmt->setInt(1, id_catedra);
		std::unique_ptr<sql::ResultSet> res(checkStmt->executeQuery());

		if (res->next() && res->getInt(1) == 0) {
			throw std::runtime_error("Eroare: department_id nu exista in tabela departments.");
		}
		// Inserare în tabela 'users'
		std::string userQuery = "INSERT INTO users (fullname, phone_number, email, username, password_hash, salt, user_type) "
			"VALUES (?, ?, ?, ?, ?, ?, 'professor')";
		std::unique_ptr<sql::PreparedStatement> userStmt(conn->prepareStatement(userQuery));
		userStmt->setString(1, full_name);
		userStmt->setString(2, phone_number);
		userStmt->setString(3, email);
		userStmt->setString(4, username);
		userStmt->setString(5, password_hash);
		userStmt->setString(6, salt);
		userStmt->executeUpdate();

		// Obține ID-ul utilizatorului recent inserat
		std::string lastIdQuery = "SELECT LAST_INSERT_ID()";
		std::unique_ptr<sql::PreparedStatement> lastIdStmt(conn->prepareStatement(lastIdQuery));
		std::unique_ptr<sql::ResultSet> lastRes(lastIdStmt->executeQuery());

		int lastUserId = -1;
		if (lastRes->next()) 
		{
			lastUserId = lastRes->getInt(1);
		}

		if (lastUserId == -1) 
		{
			throw std::runtime_error("Eroare: Nu s-a putut obține ID-ul utilizatorului recent inserat.");
		}

		// Inserare în tabela 'professor'
		std::string profQuery = "INSERT INTO professors (professor_role, user_id, department_id) VALUES (?, ?, ?)";
		std::unique_ptr<sql::PreparedStatement> profStmt(conn->prepareStatement(profQuery));
		profStmt->setString(1, professor_role);
		profStmt->setInt(2, lastUserId);
		profStmt->setInt(3, id_catedra);

		unsigned short affectedRows = profStmt->executeUpdate();
		if (affectedRows > 0)
		{
			std::cout << "Profesor adăugat cu succes." << std::endl;
		}
		else {
			std::cout << "Eroare: Nu s-a putut adăuga profesorul." << std::endl;
		}
	}
	catch (sql::SQLException &e) 
	{
		std::cerr << "Eroare SQL: " << e.what()
			<< " Cod: " << e.getErrorCode()
			<< " SQL State: " << e.getSQLState() << std::endl;
	}
	catch (const std::exception &e) 
	{
		std::cerr << "Eroare generală: " << e.what() << std::endl;
	}
}

int DatabaseConnection::getLastInsertId(const char *query)
{
	try
	{
		std::unique_ptr<sql::Statement> stmt(conn->createStatement());
		std::unique_ptr<sql::ResultSet> res(stmt->executeQuery(query));

		if (res->next())
		{
			return res->getInt(1);
		}
		else
		{
			std::cerr << "Nu s-a putut obține ultimul ID inserat." << std::endl;
			return -1;
		}
	}
	catch (sql::SQLException &e)
	{
		std::cerr << "SQL Exception: " << e.what() << std::endl;
		return -1;
	}
}

std::vector<std::tuple<std::string, std::string, std::string, std::string, std::string, std::string>> DatabaseConnection::get_professor(std::string id_prof, std::string& fullname, std::string& email, std::string& roll,
	std::string& phone_number, std::string& username, std::string& pass)
{
	std::vector<std::tuple<std::string, std::string, std::string, std::string, std::string, std::string>> professors;
	try {
		std::string query =
			"SELECT u.fullname, u.email, u.phone_number, u.username, u.password_hash, p.professor_role "
			"FROM professors p "
			"JOIN users u ON p.user_id = u.user_id "
			"WHERE p.professor_id = ?";

		std::unique_ptr<sql::PreparedStatement> pstmt(conn->prepareStatement(query));
		pstmt->setString(1, id_prof);

		std::unique_ptr<sql::ResultSet> res(pstmt->executeQuery());

		while (res->next())
		{
			// sql::SQLString department_id = res->getString("department_id");
			 fullname = res->getString("fullname");
			 email = res->getString("email");
			 roll = res->getString("professor_role");
			 phone_number = res->getString("phone_number");
			 username = res->getString("username");
			 pass = res->getString("password_hash");

			//professors.emplace_back(fullname, email, professor_role, phone_number, username, password_hash);
		}
	}
	catch (sql::SQLException &e) {
		std::cerr << "SQL Exception: " << e.what() << std::endl;
	}
	return professors;
}

void DatabaseConnection::addGroupToDatabase(const Grupa &grupa_obj)
{
	try
	{
		std::unique_ptr<sql::PreparedStatement> pstmt(conn->prepareStatement("INSERT INTO groups (group_name, study_year, department_id) VALUES (?, ?, ?)"));
		pstmt->setString(1, grupa_obj.get_group_name());
		pstmt->setInt(2, grupa_obj.get_group_year_of_study());
		pstmt->setInt(3, grupa_obj.get_id_catedra_of_group());
		pstmt->executeUpdate();
		std::cout << "Grupa a fost adaugata cu succes in baza de date!" << std::endl;
	}
	catch (sql::SQLException &e)
	{
		std::cerr << "SQL Exception: " << e.what() << std::endl;
	}
}

void DatabaseConnection::updateCatedra(unsigned short id, const std::string &newName)
{
	try
	{
		std::unique_ptr<sql::PreparedStatement> pstmt(conn->prepareStatement("UPDATE departments SET department_name = ? WHERE department_id = ?"));
		pstmt->setString(1, newName);
		pstmt->setInt(2, id);

		unsigned short affectedRows = pstmt->executeUpdate();

		if (affectedRows > 0)
		{
			std::cout << "Catedra cu ID-ul " << id << " a fost actualizată cu succes." << std::endl;
		}
		else
		{
			std::cout << "Nu s-a găsit o catedră cu acest ID." << std::endl;
		}
	}
	catch (sql::SQLException &e)
	{
		std::cerr << "SQL Exception: " << e.what() << std::endl;
	}
}

void DatabaseConnection::display_specialty_from_db() const
{

}

void DatabaseConnection::display_specialty_from_db_by_department(unsigned short) const
{

}

void DatabaseConnection::displayGroups_from_bd_by_department(unsigned short id_catedra)const
{
	const std::string query = "Select group_id, group_name, study_year FROM groups"
		" WHERE department_id = ?";
	try 
	{
		std::unique_ptr<sql::PreparedStatement> pstmt(conn->prepareStatement(query));
		pstmt->setInt(1, id_catedra);
	//	std::unique_ptr<sql::Statement> stmt(conn->createStatement());
		std::unique_ptr<sql::ResultSet> res(pstmt->executeQuery());
		std::cout << "ID\t\t\t" << "Nume Grupa\t\t\t" << "An Studii" << std::endl;
		std::cout << "------------------------------------------------------------------------" << std::endl;
		while (res->next())
		{
			unsigned short id = res->getInt("group_id");
			sql::SQLString name = res->getString("group_name");
			unsigned short year_study = res->getInt("study_year");
			std::cout << id << "\t\t\t" << name << "\t\t\t\t" << year_study << std::endl;
		}
	}
	catch (sql::SQLException& e) {
		std::cerr << "Query failed: " << query << "\nError: " << e.what() << std::endl;
	}
}

void DatabaseConnection::display_all_groups_from_bd() const
{
	const std::string query = "Select group_id, group_name, study_year FROM groups";
	try
	{
		std::unique_ptr<sql::PreparedStatement> pstmt(conn->prepareStatement(query));
		std::unique_ptr<sql::ResultSet> res(pstmt->executeQuery());

		std::cout << "ID\t\t\t" << "Nume Grupa\t\t\t" << "An studii" << std::endl;
		std::cout << "------------------------------------------------------------------------" << std::endl;

		while (res->next())
		{
			unsigned short id = res->getInt("group_id");
			sql::SQLString name = res->getString("group_name");
			unsigned short year_study = res->getInt("study_year");
			std::cout << id << "\t\t\t" << name << "\t\t\t\t" << year_study << std::endl;
		}
	}
	catch (sql::SQLException& e) {
		std::cerr << "Query failed: " << query << "\nError: " << e.what() << std::endl;
	}
}

std::vector<std::tuple<unsigned short, std::string, std::string, std::string, std::string, std::string, std::string>> DatabaseConnection::selectProfessors()
{
	std::vector<std::tuple<unsigned short, std::string, std::string, std::string, std::string, std::string, std::string>> professors;
	try {
		// Creează interogarea SQL cu spațiere corectă
		std::string query =
			"SELECT p.professor_id, u.fullname, p.professor_role, u.email, u.phone_number, u.username, u.password_hash "
			"FROM professors p "
			"JOIN users u ON p.user_id = u.user_id";

		// Pregătește interogarea
		if (!conn) {
			throw std::runtime_error("Database connection is not initialized.");
		}

		std::unique_ptr<sql::PreparedStatement> pstmt(conn->prepareStatement(query));
		std::unique_ptr<sql::ResultSet> res(pstmt->executeQuery());

		// Iterează prin rezultatele interogării
		while (res->next()) {
			unsigned short professor_id = res->getInt("professor_id");
			std::string fullname = res->getString("fullname");
			std::string email = res->getString("email");
			std::string professor_role = res->getString("professor_role");
			std::string phone_number = res->getString("phone_number");
			std::string username = res->getString("username");
			std::string password_hash = res->getString("password_hash");

			// Adaugă rezultatul în vector
			professors.emplace_back(professor_id, fullname, professor_role, email, phone_number, username, password_hash);
		}
	}
	catch (const sql::SQLException& e) {
		std::cerr << "SQL Exception: " << e.what() << std::endl;
	}
	catch (const std::exception& e) {
		std::cerr << "Standard Exception: " << e.what() << std::endl;
	}

	return professors;
}

// select professors from db
std::vector<std::tuple<unsigned short, std::string, std::string, std::string>> DatabaseConnection::selectProfessors(unsigned short id_catedra)
{
	std::vector<std::tuple<unsigned short, std::string, std::string, std::string>> professors;
	try {
		std::string query =
			"SELECT p.professor_id, u.fullname, u.email, p.professor_role, p.department_id "
			"FROM professors p "
			"JOIN users u ON p.user_id = u.user_id "
			"WHERE p.department_id = ?";

		std::unique_ptr<sql::PreparedStatement> pstmt(conn->prepareStatement(query));
		pstmt->setInt(1, id_catedra);

		std::unique_ptr<sql::ResultSet> res(pstmt->executeQuery());

		while (res->next())
		{
			unsigned short professor_id = res->getInt("professor_id");
			sql::SQLString fullname = res->getString("fullname");
			sql::SQLString email = res->getString("email");
			sql::SQLString professor_role = res->getString("professor_role");

			professors.emplace_back(professor_id, fullname, email, professor_role);
		}
	}
	catch (sql::SQLException &e) {
		std::cerr << "SQL Exception: " << e.what() << std::endl;
	}
	return professors;
}

void DatabaseConnection::display_students_from_db_by_group(unsigned short id_group)
{
	system("cls");
	auto students = db_conn.selectStudents(id_group);

	std::cout << "ID\tFull Name\tEmail\t\tUsername\tGroup ID\n";
	std::cout << "-----------------------------------------------------------------------\n";
	for (const auto& student : students) {
		unsigned short student_id;
		std::string fullname, email, username, password;
		unsigned short group_id;

		// Destructurează tuple-ul
		std::tie(student_id, fullname, email, username, group_id) = student;

		// Afișează informațiile
		std::cout << student_id << "\t\t" << fullname << "\t" << email << "\t"
			<< username << "\t\t\t" << group_id << "\n";
	}
}

std::vector<std::pair<unsigned short, std::string>> DatabaseConnection::selectDepartments(const std::string& query) {
	std::vector<std::pair<unsigned short, std::string>> results;
	try {
		std::unique_ptr<sql::Statement> stmt(conn->createStatement());
		std::unique_ptr<sql::ResultSet> res(stmt->executeQuery(query));

		while (res->next())
		{
			unsigned short id = res->getInt("department_id");
			sql::SQLString name = res->getString("department_name");
			results.emplace_back(id, name);
		}
	}
	catch (sql::SQLException& e) {
		std::cerr << "Query failed: " << query << "\nError: " << e.what() << std::endl;
	}
	return results;
}

// Metodă pentru a obține lista de studenți
std::vector<std::tuple<unsigned short, std::string, std::string, std::string, unsigned short>> DatabaseConnection::selectStudents() {
	std::vector<std::tuple<unsigned short, std::string, std::string, std::string, unsigned short>> students;
	try {
		std::string query =
			"SELECT s.student_id, u.fullname, u.email, u.username, s.group_id "
			"FROM students s "
			"JOIN users u ON s.user_id = u.user_id";
		std::unique_ptr<sql::PreparedStatement> pstmt(conn->prepareStatement(query));
		std::unique_ptr<sql::ResultSet> res(pstmt->executeQuery());

		while (res->next()) {
			unsigned short student_id = res->getInt("student_id");
			sql::SQLString fullname = res->getString("fullname");
			sql::SQLString email = res->getString("email");
			sql::SQLString username = res->getString("username");
			unsigned short group_id = res->getInt("group_id");

			students.emplace_back(student_id, fullname, email, username, group_id);
		}
	}
	catch (sql::SQLException &e) {
		std::cerr << "SQL Exception: " << e.what() << std::endl;
	}
	return students;
}

std::vector<std::pair<unsigned short, std::string>> DatabaseConnection::get_id_name_students()
{
	std::vector<std::pair<unsigned short, std::string>> id_name;
	try {
		std::string query =
			"SELECT s.student_id, u.fullname "
			"FROM students s "
			"JOIN users u ON s.user_id = u.user_id";
		std::unique_ptr<sql::PreparedStatement> pstmt(conn->prepareStatement(query));
		std::unique_ptr<sql::ResultSet> res(pstmt->executeQuery());

		while (res->next()) 
		{
			unsigned short student_id = res->getInt("student_id");
			sql::SQLString fullname = res->getString("fullname");
			id_name.emplace_back(student_id, fullname);
		}
	}
	catch (sql::SQLException &e) {
		std::cerr << "SQL Exception: " << e.what() << std::endl;
	}
	return id_name;
}
// Metodă pentru a obține lista de studenți
std::vector<std::tuple<unsigned short, std::string, std::string, std::string, unsigned short>> DatabaseConnection::selectStudents(unsigned short id_group)
{
	std::vector<std::tuple<unsigned short, std::string, std::string, std::string, unsigned short>> students;
	try {
		std::string query =
			"SELECT s.student_id, u.fullname, u.email, u.username, s.group_id "
			"FROM students s "
			"JOIN users u ON s.user_id = u.user_id "
			"WHERE s.group_id = ?";

		std::unique_ptr<sql::PreparedStatement> pstmt(conn->prepareStatement(query));
		pstmt->setInt(1, id_group);

		std::unique_ptr<sql::ResultSet> res(pstmt->executeQuery());

		while (res->next()) 
		{
			unsigned short student_id = res->getInt("student_id");
			sql::SQLString fullname = res->getString("fullname");
			sql::SQLString email = res->getString("email");
			sql::SQLString username = res->getString("username");
			unsigned short group_id = res->getInt("group_id");

			students.emplace_back(student_id, fullname, email, username, group_id);
		}
	}
	catch (sql::SQLException &e) {
		std::cerr << "SQL Exception: " << e.what() << std::endl;
	}
	return students;
}

//std::vector<std::pair<int, std::string>> DatabaseConnection::selectStudents(const std::string& query)
//{
//	std::vector<std::pair<int, std::string>> results;
//	try {
//		std::unique_ptr<sql::Statement> stmt(conn->createStatement());
//		std::unique_ptr<sql::ResultSet> res(stmt->executeQuery(query));
//
//		while (res->next()) {
//			int id = res->getInt("id");
//			sql::SQLString full_name = res->getString("full_name");
//			results.emplace_back(id, full_name);
//		}
//	}
//	catch (sql::SQLException& e) {
//		std::cerr << "Query failed: " << query << "\nError: " << e.what() << std::endl;
//	}
//	return results;
//}

//void DatabaseConnection::add_students_to_group_in_db(unsigned short id_student, unsigned short id_group)
//{
//	try {
//		std::string query =
//			"UPDATE Students SET group_id = ? WHERE student_id = ?";
//
//		std::unique_ptr<sql::PreparedStatement> pstmt(conn->prepareStatement(query));
//		pstmt->setInt(1, id_group);
//		pstmt->setInt(2, id_student);
//
//		unsigned short affectedRows = pstmt->executeUpdate();
//		if (affectedRows > 0)
//		{
//			std::cout <<"Student adaugat cu succes." << std::endl;
//		}
//		else
//		{
//			std::cout << "Nu s-a găsit asa student cu acest ID." << std::endl;
//		}
//		std::unique_ptr<sql::ResultSet> res(pstmt->executeQuery());
//
//	}
//	catch (sql::SQLException &e) {
//		std::cerr << "SQL Exception: " << e.what() << std::endl;
//	}
//
//}

void DatabaseConnection::add_students_to_group(unsigned short grupa_id, const std::string &full_name, const std::string &phone_number,
	const std::string &email, const std::string &username,
	const std::string &password_hash, const std::string &salt)
{
	try {
		std::string query = "INSERT INTO users (fullname, phone_number, email, username, password_hash, salt, user_type) "
			"VALUES (?, ?, ?, ?, ?, ?, 'student')";
		std::unique_ptr<sql::PreparedStatement> pstmt(conn->prepareStatement(query));
		pstmt->setString(1, full_name);
		pstmt->setString(2, phone_number);
		pstmt->setString(3, email);
		pstmt->setString(4, username);
		pstmt->setString(5, password_hash);
		pstmt->setString(6, salt);

		query = "INSERT INTO students (user_id, group_id) "
			"VALUES (?, ?)";

		int last_id_student = db_conn.getLastInsertId("SELECT LAST_INSERT_ID() FROM users");
		if (last_id_student == -1)
		{
			last_id_student = 1;
			pstmt->setString(1, std::to_string(last_id_student));
			pstmt->setString(2, std::to_string(grupa_id));

			unsigned short affectedRows = pstmt->executeUpdate();
			if (affectedRows > 0) 
			{
				std::cout << "Student adăugat cu succes." << std::endl;
			}
			else 
			{
				std::cout << "Eroare: Nu s-a putut adăuga studentul." << std::endl;
			}
		}

		else
		{
			pstmt->setString(1, std::to_string(last_id_student));
			pstmt->setString(2, std::to_string(grupa_id));

			unsigned short affectedRows = pstmt->executeUpdate();
			if (affectedRows > 0) {
				std::cout << "Student adăugat cu succes." << std::endl;
			}
			else {
				std::cout << "Eroare: Nu s-a putut adăuga studentul." << std::endl;
			}
		}
		
	}
	catch (sql::SQLException &e) {
		std::cerr << "Eroare SQL: " << e.what()
			<< " Cod: " << e.getErrorCode()
			<< " SQL State: " << e.getSQLState() << std::endl;
	}
}


void DatabaseConnection::executeQuery(const std::string &query) {
	try {
		std::shared_ptr<sql::PreparedStatement> pstmt(db_conn.conn->prepareStatement(query));
		pstmt->executeQuery();
		//std::shared_ptr<sql::ResultSet> result(pstmt->executeQuery());
		//std::unique_ptr<sql::Statement> stmt(conn->createStatement());
		//stmt->execute(query);
	}
	catch (sql::SQLException &e) {
		std::cerr << "Query failed: " << query << std::endl;
		std::cerr << "Error: " << e.what() << std::endl;
	}
}

std::shared_ptr<sql::ResultSet> DatabaseConnection::executeSelectQuery(const std::string& query) {
	try {
		if (!conn || conn->isClosed()) {
			throw std::runtime_error("Conexiunea la baza de date este închisă.");
		}
		std::shared_ptr<sql::PreparedStatement> pstmt(db_conn.conn->prepareStatement(query));
		std::shared_ptr<sql::ResultSet> result(pstmt->executeQuery());

		if (!result) {
			throw std::runtime_error("Rezultatul interogării este null.");
		}

		return result;
	}
	catch (const sql::SQLException& e) {
		std::cerr << "Query failed: " << query << std::endl;
		std::cerr << "Error: " << e.what() << std::endl;
		throw;
	}
}

void DatabaseConnection::delete_professor_from_db(std::string id)
{
	//std::string query = "DELETE FROM professors WHERE professor_id = ?;";
	//std::shared_ptr<sql::PreparedStatement> pstmt(db_conn.conn->prepareStatement(query));

	//// Setează valoarea parametrului
	//pstmt->setString(1, id);
	//pstmt->executeUpdate();

	// Interogare pentru a șterge utilizatorul
	std::string query_user = "DELETE FROM users WHERE user_id = ?;";
	// Interogare pentru a șterge profesorul
	std::string query_professor = "DELETE FROM professors WHERE professor_id = ?;";

	// Pregătește ambele interogări
	std::shared_ptr<sql::PreparedStatement> pstmt_user(db_conn.conn->prepareStatement(query_user));
	std::shared_ptr<sql::PreparedStatement> pstmt_professor(db_conn.conn->prepareStatement(query_professor));

	// Setează valoarea parametrului pentru fiecare interogare
	pstmt_user->setString(1, id);
	pstmt_professor->setString(1, id);

	// Execută ambele interogări
	pstmt_user->executeUpdate();
	pstmt_professor->executeUpdate();

}

void DatabaseConnection::delete_department_from_db(std::string id_depart)
{
	std::string query = "DELETE FROM departments WHERE department_id = ?;";
	std::shared_ptr<sql::PreparedStatement> pstmt(db_conn.conn->prepareStatement(query));

	// Setează valoarea parametrului
	pstmt->setString(1, id_depart);
	pstmt->executeUpdate();
}

