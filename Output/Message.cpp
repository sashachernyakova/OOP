#include "Message.h"

Message::Message(LEVEL type, std::string message) {
    switch (type) {
        case GAME:
            this->pref = "[GAME]";
            break;
        case ERROR:
            this->pref = "[ERROR]";
            break;
        case STATUS:
            this->pref = "[STATUS]";
            break;
    }

    this->message = message;
    this->type = type;
}

std::string Message::get_message() {
    return this->message;
}

std::string Message::get_pref() {
    return this->pref;
}

Message::LEVEL Message::getType() {
    return this->type;
}

std::ostream &operator<<(std::ostream &os, Message &message) {
    os << message.get_pref() + " " + message.get_message()   ;
    return os;
}
