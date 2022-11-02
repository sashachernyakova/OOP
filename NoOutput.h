#ifndef UNTITLED57_NOOUTPUT_H
#define UNTITLED57_NOOUTPUT_H

#include "ILog.h"

class NoOutput: public ILog{
public:
    void print(Message& message) override;
};

#endif
