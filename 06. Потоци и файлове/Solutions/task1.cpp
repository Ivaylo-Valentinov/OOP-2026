
#include <iostream>
#include <fstream>

int main() {
    char filename[60];
    std::cin.getline(filename, 60);

    //std::ifstream fin;
    //fin.open(filename);
    std::ifstream fin(filename);

    if (!fin) {
        throw std::exception("An error occured while openning the file");
    }

    char c;
    while (fin.get(c)) {
        std::cout << c;
    }

    fin.close();
    return 0;
}
