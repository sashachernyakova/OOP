#include "FileOutput.h"

FileOutput::FileOutput() {
    fout.open("g.txt", std::ofstream::app);
}

void FileOutput::print(Message& message) {
        if (!fout.is_open()){
            std::cout << "File can not be open\n";
        } else {
            fout << message << "\n";
            fout.flush();
        }
}

FileOutput::~FileOutput() {
    fout.close();
}
