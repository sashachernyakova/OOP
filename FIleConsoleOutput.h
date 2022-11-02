#ifndef UNTITLED57_FILECONSOLEOUTPUT_H
#define UNTITLED57_FILECONSOLEOUTPUT_H

#include "ILog.h"

class FileConsoleOutput: public ILog{
public:
    void print(std::string str) override;
};

#endif
