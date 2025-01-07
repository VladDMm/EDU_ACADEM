#pragma once
#ifndef PROFESSORREPOSITORY_H_
#define PROFESSORREPOSITORY_H_

#include <vector>
#include "DatabaseConnection.h"
#include "Professor.h"

class ProfessorRepository {
public:
	explicit ProfessorRepository(DatabaseConnection& dbConn);

	std::vector<Profesor> getAllProfessors();
	void addProfessor(const Profesor& profesor);

private:
	DatabaseConnection& dbConn;
};

#endif // !1
