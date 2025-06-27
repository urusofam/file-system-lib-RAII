#include "FileHandler.h"

FileHandler::FileHandler(const std::string& filepath_, std::ios_base::openmode mode) {
    filepath = filepath_;
    file.open(filepath, mode);
    if (!file.is_open()) {
        throw FileException("File could not be opened");
    }
}

FileHandler::~FileHandler() {
    if (file.is_open()) {
        file.close();
    }
}

bool FileHandler::writeLine(const std::string& line) {
    if (file.is_open()) {
        file << line << std::endl;
        if (file.fail()) {
            throw FileException("Failed to write line to file");
        }
        return true;
    }
    throw FileException("File is not open");
}

bool FileHandler::readLine(std::string& line) {
    if (file.is_open()) {
        if (std::getline(file, line)) {
            return true;
        } else {
            return false;
        }
    }
    throw FileException("File is not open");
}

