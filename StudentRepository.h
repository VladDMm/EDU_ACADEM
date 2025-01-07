#pragma once
#ifndef STUDENTREPOSITORY_H_
#define STUDENTREPOSITORY_H_

#include <vector>
#include "DatabaseConnection.h"
#include "Student.h"

class StudentRepository {
public:
	explicit StudentRepository(DatabaseConnection& dbConn);

	std::vector<Student> getAllStudents();
	void addStudent(const Student& student);

private:
	DatabaseConnection& dbConn;
};

#endif