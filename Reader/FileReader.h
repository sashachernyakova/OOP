#ifndef UNTITLED57_FILEREADER_H
#define UNTITLED57_FILEREADER_H

#include <iostream>
#include "Reader.h"
#include <fstream>

class FileReader: public Reader{
    std::ifstream* in;
public:
    FileReader(std::ifstream *in);
    std::string read() override;
    bool canRead() override;
    ~FileReader();
};

#endif
