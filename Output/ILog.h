#ifndef UNTITLED57_ILOG_H
#define UNTITLED57_ILOG_H

#include "iostream"
#include "Message.h"

class ILog{
public:
    virtual void print(Message& message) = 0;
};

#endif
