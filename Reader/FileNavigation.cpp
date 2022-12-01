#include "FileNavigation.h"

void FileNavigation::madeVecDirection(void *s) {
    std::ifstream* in = (std::ifstream*)s;
    std::string str;
    int i = 1;
    if (in->is_open()){
        while(i<6){
            std::getline(*in,str);
            if (str[str.length()-1] == '\n'){
                str[str.length()-1] = '\0';
            }
            navigation.push_back(str);
            i++;
        }
    } else {
        navigation.emplace_back("up");
        navigation.emplace_back("left");
        navigation.emplace_back("down");
        navigation.emplace_back("right");
        navigation.emplace_back("exit");
    }

}

std::vector<std::string> FileNavigation::returnVec() {
    return navigation;
}
