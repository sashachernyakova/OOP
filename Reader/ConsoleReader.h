#ifndef UNTITLED57_CONSOLEREADER_H
#define UNTITLED57_CONSOLEREADER_H

#pragma once

#include <string>
#include <iostream>
#include "Reader.h"

class ConsoleReader: public Reader{
    std::string str;
public:
    std::string read() override;
    bool canRead() override;
};

#endif
