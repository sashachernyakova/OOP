#include "FileOutput.h"
#include <fstream>

void FileOutput::print(std::string str) {
        std::ofstream fout;
        fout.open("game.txt", std::ofstream::app);

        if (!fout.is_open()){
            std::cout << "File can not be open\n";
        } else {
            fout <<  str << "\n";
        }
        fout.close();
}
