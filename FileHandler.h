#ifndef FILEHANDLER_H
#define FILEHANDLER_H

#include <string>
#include <fstream>
#include <stdexcept>


class FileException : public std::runtime_error {
public:
    FileException(const std::string& msg) : std::runtime_error(msg) {}
};


class FileHandler {
    std::string filepath;
    std::fstream file;
public:
    FileHandler(const std::string& filepath, std::ios_base::openmode mode);
    ~FileHandler();
    FileHandler(const FileHandler&) = delete;
    FileHandler& operator=(const FileHandler&) = delete;
    bool writeLine(const std::string& line);
    bool readLine(std::string& line);
};



#endif //FILEHANDLER_H
