#ifndef UNTITLED57_FILEOUTPUT_H
#define UNTITLED57_FILEOUTPUT_H

#include "ILog.h"
#include <fstream>

class FileOutput: public ILog{
    std::ofstream fout;
public:
    FileOutput();
    void print(Message& message) override;
    ~FileOutput();
};

#endif
