-- --------------------------------------------------------
-- Host:                         127.0.0.1
-- Server version:               11.4.4-MariaDB - mariadb.org binary distribution
-- Server OS:                    Win64
-- HeidiSQL Version:             12.8.0.6908
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
  `professor_id` int(11) NOT NULL,
  PRIMARY KEY (`absence_id`),
  KEY `student_id` (`student_id`),
  KEY `course_id` (`course_id`),
  KEY `FK_absences_professors` (`professor_id`),
  CONSTRAINT `FK_absences_professors` FOREIGN KEY (`professor_id`) REFERENCES `professors` (`professor_id`),
  CONSTRAINT `absences_ibfk_1` FOREIGN KEY (`student_id`) REFERENCES `students` (`student_id`),
  CONSTRAINT `absences_ibfk_2` FOREIGN KEY (`course_id`) REFERENCES `courses` (`course_id`)
) ENGINE=InnoDB AUTO_INCREMENT=5 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

-- Dumping data for table edu.absences: ~4 rows (approximately)
INSERT INTO `absences` (`absence_id`, `student_id`, `course_id`, `absence_date`, `justified`, `professor_id`) VALUES
	(1, 6, 9, '2025-03-06', 0, 12),
	(2, 2, 9, '2025-03-06', 1, 12),
	(3, 8, 9, '2025-03-06', 0, 12),
	(4, 10, 9, '2025-03-06', 0, 12);

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
  `course_name` text NOT NULL,
  `nr_credite` int(11) DEFAULT NULL,
  `professor_id` int(11) DEFAULT NULL,
  PRIMARY KEY (`course_id`),
  KEY `proffesor_id_fk1` (`professor_id`),
  CONSTRAINT `proffesor_id_fk1` FOREIGN KEY (`professor_id`) REFERENCES `professors` (`professor_id`) ON DELETE SET NULL
) ENGINE=InnoDB AUTO_INCREMENT=10 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

-- Dumping data for table edu.courses: ~8 rows (approximately)
INSERT INTO `courses` (`course_id`, `course_name`, `nr_credite`, `professor_id`) VALUES
	(1, 'Drept Civil', 4, 1),
	(2, 'Drept Penal', 5, 2),
	(3, 'Drept Constituţional', 4, 3),
	(4, 'Politici Monetare', 3, NULL),
	(5, 'Marketing Financiar', 4, NULL),
	(6, 'Contabilitate Bancară', 4, NULL),
	(7, 'Algoritmi şi Structuri de Date', 4, 12),
	(9, 'Securitate Cibernetică', 3, 12);

-- Dumping structure for table edu.departments
CREATE TABLE IF NOT EXISTS `departments` (
  `department_id` int(11) NOT NULL AUTO_INCREMENT,
  `department_name` varchar(100) NOT NULL,
  `faculty` varchar(100) NOT NULL,
  PRIMARY KEY (`department_id`)
) ENGINE=InnoDB AUTO_INCREMENT=5 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci CHECKSUM=1;

-- Dumping data for table edu.departments: ~5 rows (approximately)
INSERT INTO `departments` (`department_id`, `department_name`, `faculty`) VALUES
	(1, 'Drept', 'Facultatea de Drept şi Administraţie Publică'),
	(2, 'Ştiinţe Politice şi Administrative', 'Facultatea de Drept şi Administraţie Publică'),
	(3, 'Inginerie şi Ştiinţe Aplicate', 'Facultatea de Economie, Inginerie şi Ştiinţe Aplicate'),
	(4, 'Ştiinţe Economice', 'Facultatea de Economie');

-- Dumping structure for table edu.grades
CREATE TABLE IF NOT EXISTS `grades` (
  `grade_id` int(11) NOT NULL AUTO_INCREMENT,
  `student_id` int(11) NOT NULL,
  `course_id` int(11) NOT NULL,
  `mark` int(11) NOT NULL DEFAULT 0,
  `date_of_grade` date NOT NULL,
  `professor_id` int(11) DEFAULT NULL,
  `activity_type` enum('Ev','Ex','S/L') DEFAULT 'S/L',
  PRIMARY KEY (`grade_id`),
  KEY `student_id` (`student_id`),
  KEY `course_id` (`course_id`),
  KEY `professor_id` (`professor_id`),
  CONSTRAINT `grades_ibfk_1` FOREIGN KEY (`student_id`) REFERENCES `students` (`student_id`),
  CONSTRAINT `grades_ibfk_2` FOREIGN KEY (`course_id`) REFERENCES `courses` (`course_id`),
  CONSTRAINT `grades_ibfk_3` FOREIGN KEY (`professor_id`) REFERENCES `professors` (`professor_id`)
) ENGINE=InnoDB AUTO_INCREMENT=27 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

-- Dumping data for table edu.grades: ~17 rows (approximately)
INSERT INTO `grades` (`grade_id`, `student_id`, `course_id`, `mark`, `date_of_grade`, `professor_id`, `activity_type`) VALUES
	(1, 1, 9, 8, '2025-02-16', 12, 'Ev'),
	(5, 6, 9, 8, '2025-02-18', 12, 'S/L'),
	(6, 10, 9, 7, '2025-02-18', 12, 'S/L'),
	(7, 9, 9, 8, '2025-02-18', 12, 'S/L'),
	(8, 5, 9, 8, '2025-02-17', 12, 'S/L'),
	(9, 5, 9, 9, '2025-02-18', 12, 'S/L'),
	(16, 2, 9, 9, '2025-02-17', 12, 'S/L'),
	(17, 7, 9, 5, '2025-02-16', 12, 'S/L'),
	(18, 6, 9, 7, '2025-03-07', 12, 'Ex'),
	(19, 5, 9, 8, '2025-03-07', 12, 'Ex'),
	(20, 7, 9, 8, '2025-03-07', 12, 'Ex'),
	(21, 2, 9, 8, '2025-03-07', 12, 'Ex'),
	(22, 1, 9, 7, '2025-03-07', 12, 'Ex'),
	(23, 9, 9, 8, '2025-03-07', 12, 'Ex'),
	(24, 8, 9, 9, '2025-03-07', 12, 'Ex'),
	(25, 10, 9, 8, '2025-03-07', 12, 'Ex'),
	(26, 11, 9, 9, '2025-03-07', 12, 'Ex');

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
	(3, 'D-2301', 2, 1, 1),
	(4, 'AJ-2101', 2, 1, 2),
	(5, 'IM-2101', 2, 3, 7),
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
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

-- Dumping data for table edu.group_course: ~1 rows (approximately)
INSERT INTO `group_course` (`course_id`, `group_id`) VALUES
	(7, 8),
	(9, 1);

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
) ENGINE=InnoDB AUTO_INCREMENT=15 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci CHECKSUM=1;

-- Dumping data for table edu.professors: ~10 rows (approximately)
INSERT INTO `professors` (`professor_id`, `professor_role`, `user_id`, `department_id`) VALUES
	(1, 'Profesor Titular', 1, 1),
	(2, 'Conferenţiar Universitar', 2, 1),
	(3, 'Asistent Universitar', 3, 1),
	(7, 'Asistent Universitar', 7, 2),
	(8, 'Profesor Titular', 8, 2),
	(9, 'Asistent Universitar', 9, 2),
	(10, 'Asistent Universitar', 10, 3),
	(11, 'Profesor Titular', 11, 3),
	(12, 'Conferenţiar Universitar', 12, 3),
	(14, 'Rol Profesor', 27, 4);

-- Dumping structure for table edu.specialty
CREATE TABLE IF NOT EXISTS `specialty` (
  `id_specialitate` int(11) NOT NULL AUTO_INCREMENT,
  `denumire_specialitate` varchar(150) NOT NULL,
  `department_id` int(11) DEFAULT NULL,
  `director_program` int(11) DEFAULT NULL,
  PRIMARY KEY (`id_specialitate`),
  KEY `departmentfk2` (`department_id`),
  KEY `professor_programfk1` (`director_program`),
  CONSTRAINT `departmentfk2` FOREIGN KEY (`department_id`) REFERENCES `departments` (`department_id`) ON DELETE CASCADE,
  CONSTRAINT `professor_programfk1` FOREIGN KEY (`director_program`) REFERENCES `professors` (`professor_id`) ON DELETE SET NULL
) ENGINE=InnoDB AUTO_INCREMENT=9 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

-- Dumping data for table edu.specialty: ~7 rows (approximately)
INSERT INTO `specialty` (`id_specialitate`, `denumire_specialitate`, `department_id`, `director_program`) VALUES
	(1, 'Drept', 1, 1),
	(2, 'Administraţie Judiciară', 1, 2),
	(5, 'Administratie Publica', 2, 7),
	(6, 'Informatica', 3, 11),
	(7, 'Inginerie Mecanică', 3, 10),
	(8, 'Finanțe și Bănci', 4, 14);

-- Dumping structure for table edu.specialty_courses
CREATE TABLE IF NOT EXISTS `specialty_courses` (
  `specialitate_id` int(11) DEFAULT NULL,
  `course_id` int(11) DEFAULT NULL,
  KEY `course_id` (`course_id`),
  KEY `specialitatecourses_ibfk_2` (`specialitate_id`),
  CONSTRAINT `specialitatecourses_ibfk_2` FOREIGN KEY (`specialitate_id`) REFERENCES `specialty` (`id_specialitate`) ON DELETE CASCADE,
  CONSTRAINT `specialty_courses_ibfk_2` FOREIGN KEY (`course_id`) REFERENCES `courses` (`course_id`) ON DELETE CASCADE
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

-- Dumping data for table edu.specialty_courses: ~5 rows (approximately)
INSERT INTO `specialty_courses` (`specialitate_id`, `course_id`) VALUES
	(1, 2),
	(1, 3),
	(1, 1),
	(6, 7),
	(6, 9);

-- Dumping structure for table edu.students
CREATE TABLE IF NOT EXISTS `students` (
  `student_id` int(11) NOT NULL AUTO_INCREMENT,
  `user_id` int(11) NOT NULL,
  `group_id` int(11) DEFAULT NULL,
  `roll_type` enum('Licenţă','Master') DEFAULT NULL,
  PRIMARY KEY (`student_id`),
  KEY `user_id` (`user_id`),
  KEY `group_id` (`group_id`),
  CONSTRAINT `students_ibfk_1` FOREIGN KEY (`user_id`) REFERENCES `users` (`user_id`) ON DELETE CASCADE,
  CONSTRAINT `students_ibfk_2` FOREIGN KEY (`group_id`) REFERENCES `groups` (`group_id`) ON DELETE SET NULL
) ENGINE=InnoDB AUTO_INCREMENT=12 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci CHECKSUM=1;

-- Dumping data for table edu.students: ~11 rows (approximately)
INSERT INTO `students` (`student_id`, `user_id`, `group_id`, `roll_type`) VALUES
	(1, 13, 1, 'Licenţă'),
	(2, 14, 1, 'Licenţă'),
	(3, 16, 3, 'Licenţă'),
	(4, 17, 3, 'Licenţă'),
	(5, 19, 1, 'Licenţă'),
	(6, 20, 1, 'Licenţă'),
	(7, 21, 1, 'Licenţă'),
	(8, 22, 1, 'Licenţă'),
	(9, 23, 1, 'Licenţă'),
	(10, 24, 1, 'Licenţă'),
	(11, 25, 1, 'Licenţă');

-- Dumping structure for table edu.users
CREATE TABLE IF NOT EXISTS `users` (
  `user_id` int(11) NOT NULL AUTO_INCREMENT,
  `fullname` varchar(255) CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci DEFAULT NULL,
  `date_of_birth` timestamp NULL DEFAULT NULL,
  `email` varchar(100) CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci NOT NULL,
  `phone_number` char(50) CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci DEFAULT NULL,
  `username` varchar(50) CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci NOT NULL,
  `password_hash` varchar(255) CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci NOT NULL,
  `salt` varchar(255) CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci DEFAULT NULL,
  `user_type` enum('student','professor','admin') CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci NOT NULL,
  `created_at` timestamp NOT NULL DEFAULT current_timestamp(),
  PRIMARY KEY (`user_id`)
) ENGINE=InnoDB AUTO_INCREMENT=28 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

-- Dumping data for table edu.users: ~25 rows (approximately)
INSERT INTO `users` (`user_id`, `fullname`, `date_of_birth`, `email`, `phone_number`, `username`, `password_hash`, `salt`, `user_type`, `created_at`) VALUES
	(1, 'Aristița Popescu', '2024-12-30 22:00:00', 'Email', 'Telefon', 'User Name', 'Parola', '', 'professor', '2025-01-26 09:59:46'),
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
	(12, 'Ana Munteanu', '2025-01-11 22:00:00', 'Email', 'Telefon', 'prof', 'prof', '', 'professor', '2025-01-26 10:03:35'),
	(13, 'Mihai Vlad', '2025-01-06 22:00:00', 'Email', 'Telefon', 'vladoss', 'vladoss', '', 'student', '2025-01-26 11:20:02'),
	(14, 'Matcaș Andrian', '2025-01-25 22:00:00', 'Email', 'Telefon', 'Username', 'Parola', '', 'student', '2025-01-26 11:20:27'),
	(16, 'ă', '2025-01-25 22:00:00', 'Email', 'Telefon', 'Username', 'Parola', '', 'student', '2025-01-26 14:24:38'),
	(17, 'Bălcănuţă Ştefan', '2025-01-25 22:00:00', 'balcanuta@gmail.com', '3737898796', 'balacanuta.u', 'parola1234', '', 'student', '2025-01-26 14:33:53'),
	(18, 'admin', '2025-02-09 15:34:45', 'admin@gmail.com', NULL, 'admin', 'admin', NULL, 'admin', '2025-02-09 15:35:05'),
	(19, 'Coteţ Alim', '2025-02-15 22:00:00', 'Email', 'Telefon', 'Username', 'Parola', '', 'student', '2025-02-16 14:02:33'),
	(20, 'Cernobrovchin Edem', '2025-02-15 22:00:00', 'Email', 'Telefon', 'Username', 'Parola', '', 'student', '2025-02-16 14:02:44'),
	(21, 'Cucereanu Daniel', '2025-02-15 22:00:00', 'Email', 'Telefon', 'Username', 'Parola', '', 'student', '2025-02-16 14:02:52'),
	(22, 'Onică Cătălin', '2025-02-15 22:00:00', 'Email', 'Telefon', 'Username', 'Parola', '', 'student', '2025-02-16 14:03:02'),
	(23, 'Nedelcu Valeriu', '2025-02-15 22:00:00', 'Email', 'Telefon', 'Username', 'Parola', '', 'student', '2025-02-16 14:03:10'),
	(24, 'Sârbu David', '2025-02-15 22:00:00', 'Email', 'Telefon', 'Username', 'Parola', '', 'student', '2025-02-16 14:03:19'),
	(25, 'Zidu Nichita', '2025-02-15 22:00:00', 'Email', 'Telefon', 'Username', 'Parola', '', 'student', '2025-02-16 14:03:34'),
	(26, 'Profesor Economic', '2025-03-05 22:00:00', 'Email', 'Telefon', 'User Name', 'Parola', '', 'professor', '2025-03-06 09:47:40'),
	(27, 'Prof economic', '2025-03-05 22:00:00', 'Email', 'Telefon', 'User Name', 'Parola', '', 'professor', '2025-03-06 09:52:43');

/*!40103 SET TIME_ZONE=IFNULL(@OLD_TIME_ZONE, 'system') */;
/*!40101 SET SQL_MODE=IFNULL(@OLD_SQL_MODE, '') */;
/*!40014 SET FOREIGN_KEY_CHECKS=IFNULL(@OLD_FOREIGN_KEY_CHECKS, 1) */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40111 SET SQL_NOTES=IFNULL(@OLD_SQL_NOTES, 1) */;
