#include "FIleConsoleOutput.h"
#include <fstream>

void FileConsoleOutput::print(std::string str) {
    std::cout << str << "\n";
    std::ofstream fout;
    fout.open("text.txt", std::ofstream::app);

    if (!fout.is_open()){
        std::cout << "File can not be open\n";
    } else {
        fout <<  str << "\n";
    }
    fout.close();
}
