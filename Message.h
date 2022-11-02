#ifndef UNTITLED57_MESSAGE_H
#define UNTITLED57_MESSAGE_H

#include <iostream>

class Message {
public:
    enum LEVEL {
        GAME = 0, STATUS = 1, ERROR = 2
    };

    Message(LEVEL type = GAME, std::string message = "");

    LEVEL getType();

    std::string get_message();

    std::string get_pref();

    friend std::ostream &operator<<(std::ostream &os, Message &message);
private:
    LEVEL type;
    std::string message;
    std::string pref;
};

#endif
