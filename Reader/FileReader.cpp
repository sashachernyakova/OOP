#include "FileReader.h"

FileReader::FileReader(std::ifstream *in):in(in) {}

std::string FileReader::read() {
    std::string str;
    if (std::getline(*in,str)){
        if (str[str.length()-1] == '\n'){
            str[str.length()-1] = '\0';
        }
        return str;
    }
    return "e";
}

FileReader::~FileReader() {
    in->close();
    delete in;
}

bool FileReader::canRead() {
    if (in->is_open()){
        return true;
    } else{
        in->close();
        return false;
    }
}
