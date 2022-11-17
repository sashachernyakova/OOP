#ifndef UNTITLED57_FILECONSOLEOUTPUT_H
#define UNTITLED57_FILECONSOLEOUTPUT_H

#include "ILog.h"
#include <fstream>

class FileConsoleOutput: public ILog{
    std::ofstream fout;
public:
    FileConsoleOutput();
    void print(Message& message) override;
    ~FileConsoleOutput();
};

#endif
