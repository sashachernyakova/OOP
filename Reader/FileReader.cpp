#include "FileReader.h"

FileReader::FileReader(std::ifstream *in):in(in) {
    if (!in->is_open()){
        in->close();
        in = nullptr;
    }
}

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
}
