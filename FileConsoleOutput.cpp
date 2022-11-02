#include "FIleConsoleOutput.h"
#include <fstream>

void FileConsoleOutput::print(Message& message) {
    std::cout << message << "\n";
    std::ofstream fout;
    fout.open("text.txt", std::ofstream::app);

    if (!fout.is_open()){
        std::cout << "File can not be open\n";
    } else {
        fout <<  message << "\n";
    }
    fout.close();
}
