#include <iostream>
#include <fstream>
#include <cstring>

const char* DATA_FILE = "student_records.data";

struct StudentRecord {
	char studentId[10];
	char courseId[6];
	int grade;

	bool isStudent(const char* studentId) const {
		return strncmp(studentId, this->studentId, 10) == 0;
	}

	bool isCourse(const char* courseId) const {
		return strncmp(courseId, this->courseId, 6) == 0;
	}
};

void printStudentCount() {
	std::ifstream fin(DATA_FILE, std::ios::in | std::ios::binary);
	if (!fin) {
		throw std::exception("Could not open file for reading!");
	}

	fin.seekg(0, std::ios::end);
	long long size = fin.tellg();

	std::cout << size / sizeof(StudentRecord) << std::endl;;
	fin.close();
}


void getStudentNotes(const char* studentId) {
	std::ifstream fin(DATA_FILE, std::ios::in | std::ios::binary);
	if (!fin) {
		throw std::exception("Could not open file for reading!");
	}

	StudentRecord r;
	while (fin.read((char*)&r, sizeof(r))) {
		if (r.isStudent(studentId)) {
			std::cout << r.grade;
		}
	}
	fin.close();
}

void getCourseNotes(const char* courseId) {
	std::ifstream fin(DATA_FILE, std::ios::in | std::ios::binary);
	if (!fin) {
		throw std::exception("Could not open file for reading!");
	}

	StudentRecord r;
	while (fin.read((char*)&r, sizeof(r))) {
		if (r.isCourse(courseId)) {
			std::cout << r.grade;
		}
	}
	fin.close();
}

double getStudentAverage(const char* studentId) {
	std::ifstream fin(DATA_FILE, std::ios::in | std::ios::binary);
	if (!fin) {
		throw std::exception("Could not open file for reading!");
	}

	StudentRecord r;
	int sum = 0;
	int count = 0;

	while (fin.read((char*)&r, sizeof(r))) {
		if (r.isStudent(studentId)) {
			sum += r.grade;
			count++;
		}
	}
	fin.close();

	return ((double)sum) / count;
}

double getCourseAverage(const char* courseId) {
	std::ifstream fin(DATA_FILE, std::ios::binary);
	if (!fin) {
		throw std::exception("Could not open file for reading!");
	}

	StudentRecord r;
	int sum = 0;
	int count = 0;

	while (fin.read((char*)&r, sizeof(r))) {
		if (r.isCourse(courseId)) {
			sum += r.grade;
			count++;
		}
	}
	fin.close();

	return ((double)sum) / count;
}


int main() {
	const char* studentId = "5MI0213977";
	const char* courseId = "CS321";

	try {
		std::cout << "Number of students: ";
		printStudentCount();
		std::cout << "Notes for student " << studentId << ": ";
		getStudentNotes(studentId);
		std::cout << "Avg. note for student " << studentId << ": "
			<< getStudentAverage(studentId) << std::endl;

		std::cout << "Notes for course " << courseId << ": ";
		getCourseNotes(courseId);
		std::cout << "Avg. note for course " << courseId << ": "
			<< getCourseAverage(courseId) << std::endl;
	}
	catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
		return 1;
	}

	return 0;
}
