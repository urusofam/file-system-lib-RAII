#include "FileHandler.h"
#include <iostream>

int main() {
    try {
        FileHandler fileWriter("test.txt", std::ios::out);
        fileWriter.writeLine("123123123");
        fileWriter.writeLine("123123123");
        FileHandler fileReader("test.txt", std::ios::in);
        std::string line;
        while (fileReader.readLine(line)) {
            std::cout << line << std::endl;
        }
    } catch (const FileException& e) {
        std::cerr << e.what() << std::endl;
    }
    try {
        FileHandler file("exist.txt", std::ios::in);
    } catch (const FileException& e) {
        std::cerr << e.what() << std::endl;
    }
    try {
        FileHandler fileWriterInMode("test.txt", std::ios::in);
        fileWriterInMode.writeLine("123123123");
    } catch (const FileException& e) {
        std::cerr << e.what() << std::endl;
    }
    return 0;
}