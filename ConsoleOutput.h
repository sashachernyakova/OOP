#ifndef UNTITLED57_CONSOLEOUTPUT_H
#define UNTITLED57_CONSOLEOUTPUT_H

#include "ILog.h"

class ConsoleOutput: public ILog{
public:
    void print(Message& message) override;
};

#endif
