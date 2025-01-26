-- --------------------------------------------------------
-- Host:                         127.0.0.1
-- Server version:               11.4.3-MariaDB - mariadb.org binary distribution
-- Server OS:                    Win64
-- HeidiSQL Version:             12.6.0.6765
-- --------------------------------------------------------

/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET NAMES utf8 */;
/*!50503 SET NAMES utf8mb4 */;
/*!40103 SET @OLD_TIME_ZONE=@@TIME_ZONE */;
/*!40103 SET TIME_ZONE='+00:00' */;
/*!40014 SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0 */;
/*!40101 SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='NO_AUTO_VALUE_ON_ZERO' */;
/*!40111 SET @OLD_SQL_NOTES=@@SQL_NOTES, SQL_NOTES=0 */;


-- Dumping database structure for edu
CREATE DATABASE IF NOT EXISTS `edu` /*!40100 DEFAULT CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci */;
USE `edu`;

-- Dumping structure for table edu.absences
CREATE TABLE IF NOT EXISTS `absences` (
  `absence_id` int(11) NOT NULL AUTO_INCREMENT,
  `student_id` int(11) NOT NULL,
  `course_id` int(11) NOT NULL,
  `absence_date` date NOT NULL,
  `justified` tinyint(1) DEFAULT 0,
  PRIMARY KEY (`absence_id`),
  KEY `student_id` (`student_id`),
  KEY `course_id` (`course_id`),
  CONSTRAINT `absences_ibfk_1` FOREIGN KEY (`student_id`) REFERENCES `students` (`student_id`),
  CONSTRAINT `absences_ibfk_2` FOREIGN KEY (`course_id`) REFERENCES `courses` (`course_id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

-- Dumping data for table edu.absences: ~0 rows (approximately)

-- Dumping structure for table edu.admins
CREATE TABLE IF NOT EXISTS `admins` (
  `admin_id` int(11) NOT NULL AUTO_INCREMENT,
  `user_id` int(11) NOT NULL,
  PRIMARY KEY (`admin_id`),
  KEY `user_id` (`user_id`),
  CONSTRAINT `admins_ibfk_1` FOREIGN KEY (`user_id`) REFERENCES `users` (`user_id`) ON DELETE CASCADE
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

-- Dumping data for table edu.admins: ~0 rows (approximately)

-- Dumping structure for table edu.courses
CREATE TABLE IF NOT EXISTS `courses` (
  `course_id` int(11) NOT NULL AUTO_INCREMENT,
  `course_name` varchar(100) NOT NULL,
  `nr_credite` int(11) DEFAULT NULL,
  `professor_id` int(11) DEFAULT NULL,
  PRIMARY KEY (`course_id`),
  KEY `proffesor_id_fk1` (`professor_id`),
  CONSTRAINT `proffesor_id_fk1` FOREIGN KEY (`professor_id`) REFERENCES `professors` (`professor_id`) ON DELETE SET NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

-- Dumping data for table edu.courses: ~0 rows (approximately)

-- Dumping structure for table edu.departments
CREATE TABLE IF NOT EXISTS `departments` (
  `department_id` int(11) NOT NULL AUTO_INCREMENT,
  `department_name` varchar(100) NOT NULL,
  `faculty` varchar(100) NOT NULL,
  PRIMARY KEY (`department_id`)
) ENGINE=InnoDB AUTO_INCREMENT=5 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci CHECKSUM=1;

-- Dumping data for table edu.departments: ~4 rows (approximately)
INSERT INTO `departments` (`department_id`, `department_name`, `faculty`) VALUES
	(1, 'Drept', 'Facultatea de Drept Si Administratie Publica'),
	(2, 'Stiințe Politice Si Administrative', 'Facultatea de Drept Si Administratie Publica'),
	(3, 'Inginerie si Stiinte Aplicate', 'Facultatea de Economie, Inginerie si Stiinte Aplicate'),
	(4, 'Stiinte Economice', 'Facultatea de Economie, Inginerie si Stiinte Aplicate');

-- Dumping structure for table edu.grades
CREATE TABLE IF NOT EXISTS `grades` (
  `grade_id` int(11) NOT NULL AUTO_INCREMENT,
  `student_id` int(11) NOT NULL,
  `course_id` int(11) NOT NULL,
  `mark` decimal(4,2) NOT NULL,
  `date_of_grade` date NOT NULL,
  PRIMARY KEY (`grade_id`),
  KEY `student_id` (`student_id`),
  KEY `course_id` (`course_id`),
  CONSTRAINT `grades_ibfk_1` FOREIGN KEY (`student_id`) REFERENCES `students` (`student_id`),
  CONSTRAINT `grades_ibfk_2` FOREIGN KEY (`course_id`) REFERENCES `courses` (`course_id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

-- Dumping data for table edu.grades: ~0 rows (approximately)

-- Dumping structure for table edu.groups
CREATE TABLE IF NOT EXISTS `groups` (
  `group_id` int(11) NOT NULL AUTO_INCREMENT,
  `group_name` varchar(50) NOT NULL,
  `study_year` int(11) NOT NULL,
  `department_id` int(11) NOT NULL,
  `specialitate_id` int(11) DEFAULT NULL,
  PRIMARY KEY (`group_id`),
  KEY `groups_ibfk_1` (`department_id`),
  KEY `specialitate_ibfk_2` (`specialitate_id`),
  CONSTRAINT `groups_ibfk_1` FOREIGN KEY (`department_id`) REFERENCES `departments` (`department_id`) ON DELETE CASCADE,
  CONSTRAINT `specialitate_ibfk_2` FOREIGN KEY (`specialitate_id`) REFERENCES `specialty` (`id_specialitate`) ON DELETE SET NULL
) ENGINE=InnoDB AUTO_INCREMENT=9 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci CHECKSUM=1;

-- Dumping data for table edu.groups: ~8 rows (approximately)
INSERT INTO `groups` (`group_id`, `group_name`, `study_year`, `department_id`, `specialitate_id`) VALUES
	(1, 'IT-2201', 3, 3, 6),
	(2, 'BA-2201', 3, 4, 4),
	(3, 'D-2201', 3, 1, 1),
	(4, 'AJ-2101', 2, 1, 2),
	(5, 'IM-2101', 2, 3, 7),
	(6, 'FB-2001', 1, 4, 3),
	(7, 'AP-2101', 2, 2, 5),
	(8, 'IT-2101', 2, 3, 6);

-- Dumping structure for table edu.group_course
CREATE TABLE IF NOT EXISTS `group_course` (
  `course_id` int(11) NOT NULL,
  `group_id` int(11) NOT NULL,
  KEY `course_ibfk1` (`course_id`),
  KEY `group_ibfk2` (`group_id`),
  CONSTRAINT `course_ibfk1` FOREIGN KEY (`course_id`) REFERENCES `courses` (`course_id`) ON DELETE CASCADE,
  CONSTRAINT `group_ibfk2` FOREIGN KEY (`group_id`) REFERENCES `groups` (`group_id`) ON DELETE CASCADE
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;

-- Dumping data for table edu.group_course: ~0 rows (approximately)

-- Dumping structure for table edu.professorcourses
CREATE TABLE IF NOT EXISTS `professorcourses` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `professor_id` int(11) DEFAULT NULL,
  `course_id` int(11) DEFAULT NULL,
  PRIMARY KEY (`id`),
  KEY `professor_id` (`professor_id`),
  KEY `course_id` (`course_id`),
  CONSTRAINT `professorcourses_ibfk_1` FOREIGN KEY (`professor_id`) REFERENCES `professors` (`professor_id`) ON DELETE CASCADE,
  CONSTRAINT `professorcourses_ibfk_2` FOREIGN KEY (`course_id`) REFERENCES `courses` (`course_id`) ON DELETE CASCADE
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

-- Dumping data for table edu.professorcourses: ~0 rows (approximately)

-- Dumping structure for table edu.professors
CREATE TABLE IF NOT EXISTS `professors` (
  `professor_id` int(11) NOT NULL AUTO_INCREMENT,
  `professor_role` varchar(200) DEFAULT NULL,
  `user_id` int(11) NOT NULL,
  `department_id` int(11) DEFAULT NULL,
  PRIMARY KEY (`professor_id`),
  KEY `user_id` (`user_id`),
  KEY `department_id` (`department_id`),
  CONSTRAINT `professors_ibfk_1` FOREIGN KEY (`user_id`) REFERENCES `users` (`user_id`) ON DELETE CASCADE,
  CONSTRAINT `professors_ibfk_2` FOREIGN KEY (`department_id`) REFERENCES `departments` (`department_id`) ON DELETE SET NULL
) ENGINE=InnoDB AUTO_INCREMENT=13 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci CHECKSUM=1;

-- Dumping data for table edu.professors: ~11 rows (approximately)
INSERT INTO `professors` (`professor_id`, `professor_role`, `user_id`, `department_id`) VALUES
	(1, 'Profesor Titular', 1, 1),
	(2, 'Conferentiar Universitar', 2, 1),
	(3, 'Asistent Universitar', 3, 1),
	(4, 'Profesor Titular', 4, 4),
	(5, 'Conferentiar Universitar', 5, 4),
	(6, 'Asistent Universitar', 6, 4),
	(7, 'Asistent Universitar', 7, 2),
	(8, 'Profesor Titular', 8, 2),
	(9, 'Asistent Universitar', 9, 2),
	(10, 'Asistent Universitar', 10, 3),
	(11, 'Profesor Titular', 11, 3),
	(12, 'Conferentiar Universitar', 12, 3);

-- Dumping structure for table edu.specialty
CREATE TABLE IF NOT EXISTS `specialty` (
  `id_specialitate` int(11) NOT NULL AUTO_INCREMENT,
  `denumire_specialitate` varchar(150) NOT NULL,
  `department_id` int(11) DEFAULT NULL,
  `director_program` int(11) DEFAULT NULL,
  PRIMARY KEY (`id_specialitate`),
  KEY `professor_programfk1` (`director_program`),
  KEY `departmentfk2` (`department_id`),
  CONSTRAINT `departmentfk2` FOREIGN KEY (`department_id`) REFERENCES `departments` (`department_id`) ON DELETE SET NULL,
  CONSTRAINT `professor_programfk1` FOREIGN KEY (`director_program`) REFERENCES `professors` (`professor_id`) ON DELETE SET NULL
) ENGINE=InnoDB AUTO_INCREMENT=8 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

-- Dumping data for table edu.specialty: ~7 rows (approximately)
INSERT INTO `specialty` (`id_specialitate`, `denumire_specialitate`, `department_id`, `director_program`) VALUES
	(1, 'Drept', 1, 1),
	(2, 'Administratie Judiciara', 1, 2),
	(3, 'Finante-Banci', 4, 4),
	(4, 'Bussiness si Management', 4, 5),
	(5, 'Administratie Publica', 2, 7),
	(6, 'Informatica', 3, 11),
	(7, 'Ingineria Mecanica', 3, 10);

-- Dumping structure for table edu.specialty_courses
CREATE TABLE IF NOT EXISTS `specialty_courses` (
  `specialitate_id` int(11) DEFAULT NULL,
  `course_id` int(11) DEFAULT NULL,
  KEY `course_id` (`course_id`),
  KEY `specialitatecourses_ibfk_2` (`specialitate_id`),
  CONSTRAINT `specialitatecourses_ibfk_2` FOREIGN KEY (`specialitate_id`) REFERENCES `specialty` (`id_specialitate`) ON DELETE CASCADE,
  CONSTRAINT `specialty_courses_ibfk_2` FOREIGN KEY (`course_id`) REFERENCES `courses` (`course_id`) ON DELETE CASCADE
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

-- Dumping data for table edu.specialty_courses: ~0 rows (approximately)

-- Dumping structure for table edu.students
CREATE TABLE IF NOT EXISTS `students` (
  `student_id` int(11) NOT NULL AUTO_INCREMENT,
  `user_id` int(11) NOT NULL,
  `group_id` int(11) DEFAULT NULL,
  `roll_type` enum('Licenta','Master') DEFAULT NULL,
  PRIMARY KEY (`student_id`),
  KEY `user_id` (`user_id`),
  KEY `group_id` (`group_id`),
  CONSTRAINT `students_ibfk_1` FOREIGN KEY (`user_id`) REFERENCES `users` (`user_id`) ON DELETE CASCADE,
  CONSTRAINT `students_ibfk_2` FOREIGN KEY (`group_id`) REFERENCES `groups` (`group_id`) ON DELETE SET NULL
) ENGINE=InnoDB AUTO_INCREMENT=3 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci CHECKSUM=1;

-- Dumping data for table edu.students: ~3 rows (approximately)
INSERT INTO `students` (`student_id`, `user_id`, `group_id`, `roll_type`) VALUES
	(1, 13, 1, 'Licenta'),
	(2, 14, 1, 'Licenta');

-- Dumping structure for table edu.users
CREATE TABLE IF NOT EXISTS `users` (
  `user_id` int(11) NOT NULL AUTO_INCREMENT,
  `fullname` varchar(255) NOT NULL,
  `date_of_birth` timestamp NULL DEFAULT NULL,
  `email` varchar(100) NOT NULL,
  `phone_number` char(50) DEFAULT NULL,
  `username` varchar(50) NOT NULL,
  `password_hash` varchar(255) NOT NULL,
  `salt` varchar(255) DEFAULT NULL,
  `user_type` enum('student','professor','admin') NOT NULL,
  `created_at` timestamp NOT NULL DEFAULT current_timestamp(),
  PRIMARY KEY (`user_id`)
) ENGINE=InnoDB AUTO_INCREMENT=15 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

-- Dumping data for table edu.users: ~14 rows (approximately)
INSERT INTO `users` (`user_id`, `fullname`, `date_of_birth`, `email`, `phone_number`, `username`, `password_hash`, `salt`, `user_type`, `created_at`) VALUES
	(1, 'Maria Popescu', '2024-12-31 22:00:00', 'Email', 'Telefon', 'User Name', 'Parola', '', 'professor', '2025-01-26 09:59:46'),
	(2, 'Andrei Ionescu', '2025-01-01 22:00:00', 'Email', 'Telefon', 'User Name', 'Parola', '', 'professor', '2025-01-26 10:00:11'),
	(3, 'Ioana Dumitrescu', '2025-01-02 22:00:00', 'Email', 'Telefon', 'User Name', 'Parola', '', 'professor', '2025-01-26 10:00:29'),
	(4, 'George Vasilescu', '2025-01-03 22:00:00', 'Email', 'Telefon', 'User Name', 'Parola', '', 'professor', '2025-01-26 10:00:59'),
	(5, 'Simona Radu', '2025-01-04 22:00:00', 'Email', 'Telefon', 'User Name', 'Parola', '', 'professor', '2025-01-26 10:01:20'),
	(6, 'Alexandru Stan', '2025-01-05 22:00:00', 'Email', 'Telefon', 'User Name', 'Parola', '', 'professor', '2025-01-26 10:01:39'),
	(7, 'Roxana Marin', '2025-01-06 22:00:00', 'Email', 'Telefon', 'User Name', 'Parola', '', 'professor', '2025-01-26 10:01:57'),
	(8, 'Cristian Mihai', '2025-01-07 22:00:00', 'Email', 'Telefon', 'User Name', 'Parola', '', 'professor', '2025-01-26 10:02:12'),
	(9, 'Oana Dobrin', '2025-01-09 22:00:00', 'Email', 'Telefon', 'User Name', 'Parola', '', 'professor', '2025-01-26 10:02:32'),
	(10, 'Bogdan Enache', '2025-01-10 22:00:00', 'Email', 'Telefon', 'User Name', 'Parola', '', 'professor', '2025-01-26 10:03:02'),
	(11, 'Victor Gheorghiu', '2025-01-11 22:00:00', 'Email', 'Telefon', 'User Name', 'Parola', '', 'professor', '2025-01-26 10:03:17'),
	(12, 'Ana Munteanu', '2025-01-11 22:00:00', 'Email', 'Telefon', 'User Name', 'Parola', '', 'professor', '2025-01-26 10:03:35'),
	(13, 'Mihai Vlad', '2025-01-06 22:00:00', 'Email', 'Telefon', 'Username', 'Parola', '', 'student', '2025-01-26 11:20:02'),
	(14, 'Matcas Andrian', '2025-01-25 22:00:00', 'Email', 'Telefon', 'Username', 'Parola', '', 'student', '2025-01-26 11:20:27');

/*!40103 SET TIME_ZONE=IFNULL(@OLD_TIME_ZONE, 'system') */;
/*!40101 SET SQL_MODE=IFNULL(@OLD_SQL_MODE, '') */;
/*!40014 SET FOREIGN_KEY_CHECKS=IFNULL(@OLD_FOREIGN_KEY_CHECKS, 1) */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40111 SET SQL_NOTES=IFNULL(@OLD_SQL_NOTES, 1) */;
