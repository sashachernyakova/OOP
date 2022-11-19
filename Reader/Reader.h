#ifndef UNTITLED57_READER_H
#define UNTITLED57_READER_H

class Reader{
public:
    virtual std::string read() = 0;
    virtual bool canRead() = 0;
};

#endif
