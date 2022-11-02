#ifndef UNTITLED57_FILEOUTPUT_H
#define UNTITLED57_FILEOUTPUT_H

#include "ILog.h"

class FileOutput: public ILog{
public:
    void print(Message& message) override;
};

#endif
