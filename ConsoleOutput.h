#ifndef UNTITLED57_CONSOLEOUTPUT_H
#define UNTITLED57_CONSOLEOUTPUT_H

#include "ILog.h"

class ConsoleOutput: public ILog{
public:
    void print(std::string str) override;
};

#endif
