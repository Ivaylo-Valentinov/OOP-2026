#include <iostream>
#include <fstream>
#include <cstring>
//
//constexpr size_t MAX_LENGTH = 1024;
//
//int main() {
//    //absolute path -> char filename[MAX_LENGTH] = "C:\\Users\\ipetkov\\source\\repos\\ConsoleApplication2\\ConsoleApplication2\\file.txt";
//    //relative path -> char filename[MAX_LENGTH] = ".\\file.txt"; "file.txt"  
//    char filename[MAX_LENGTH];
//    std::cin.getline(filename, MAX_LENGTH);
//
//    std::ifstream fin(filename);
//    //std::ifstream fin; fin.open(filename);
//
//    if (!fin) {
//        std::cout << "File cound not be opened!" << std::endl;
//        return 1;
//    }
//
//    char c;
//    //if we are reading numbers, for example -> while (fin >> num) {...
//    while (fin.get(c)) {
//        std::cout << c;
//    }
//
//    fin.close();
//    return 0;
//}

struct StudentNote {
	char studentId[10];
	char courseId[6];
	size_t note;
};

int main() {
	const char filename[] = "students.bin";
	/*StudentNote studentNotes[] = { {"123456890", "12345", 6}, {"123456891", "12344", 5} };

	std::ofstream fout("students.bin", std::ios::app | std::ios::binary);
	if (!fout) {
		std::cout << "Could not open file!" << std::endl;
	}

	for (size_t i = 0; i < 2; i++)
	{
		fout.write((const char*)(studentNotes + i), sizeof(StudentNote));
	}

	fout.close();*/

	std::ifstream fin(filename, std::ios::binary);
	if (!fin) {
		//error;
		return 1;
	}

	fin.seekg(std::ios::end);
	size_t size = fin.tellg() / sizeof(StudentNote);

	//get the note with index 0 from the binary file
	fin.seekg(0 * sizeof(StudentNote), std::ios::beg);
	StudentNote note;
	fin.read((char*)&note, sizeof(StudentNote));
	std::cout << "Student: " << note.studentId << "; CourseId: " << note.courseId << "; Note:" << note.note << std::endl;

	fin.close();
	return 0;
}
