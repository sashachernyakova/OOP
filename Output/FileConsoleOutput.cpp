#include "FIleConsoleOutput.h"

FileConsoleOutput::FileConsoleOutput() {
    fout.open("g.txt", std::ofstream::app);
}

void FileConsoleOutput::print(Message& message) {
    std::cout << message << "\n";
    if (!fout.is_open()){
        std::cout << "File can not be open\n";
    } else {
        fout <<  message << "\n";
        fout.flush();
    }
}

FileConsoleOutput::~FileConsoleOutput() {
    fout.close();
}

