#ifndef UNTITLED57_FILECONSOLEOUTPUT_H
#define UNTITLED57_FILECONSOLEOUTPUT_H

#include "ILog.h"

class FileConsoleOutput: public ILog{
public:
    void print(Message& message) override;
};

#endif
