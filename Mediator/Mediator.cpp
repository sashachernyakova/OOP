#include "Mediator.h"

Mediator::Mediator(): reader(ConsoleReader()), output(Output()){
    std::ifstream in("navigation.txt");
    moveReader = new FileReader(&in);
    if (!moveReader->canRead()){
        delete moveReader;
        moveReader = new ConsoleReader();
    }
    output.logger();
    log = reader.read();
    output.howPrint();
    print = std::stoi(reader.read());
    output.createField();
    txt1 = reader.read();
    if (txt1 == "1"){
        controller = new Controller(log, print);
        controller->printField();
    } else if (txt1 == "2"){
        controller = new Controller(log, print);
        output.getHeight();
        txt1 = reader.read();
        if(txt1[0] == '-'){
            controller->errorH();
            txt1 = "10";
        }
        output.getWidth();
        txt2 = reader.read();
        if(txt2[0] == '-'){
            controller->errorW();
            txt2 = "10";
        }
        delete controller;
        controller = new Controller(log, print, std::stoi(txt1), std::stoi(txt2));
        controller->printField();
    } else {
        controller = new Controller(log, print);
        controller->errorNumber();
        controller->printField();
    }
    controller->start();
    output.gameRules();
    txt1 = moveReader->read();
    while(txt1 != "e") {
        if (txt1 == "stop") {
            controller->stop();
            break;
        } else {
            std::vector <std::string> out;
            size_t start;
            size_t end = 0;
            const char delim = ' ';
            while ((start = txt1.find_first_not_of(delim, end)) != std::string::npos) {
                end = txt1.find(delim, start);
                out.push_back(txt1.substr(start, end - start));
            }
            if (controller->isDirection(out[1])) {
                if (controller->movement(std::stoi(out[0]), controller->getAction(out[1])) == 1) {
                    return;
                }
            } else {
                controller->errorD();
            }
        }
        txt1 = moveReader->read();
    }
    return;
}

Mediator::~Mediator(){
    delete controller;
    delete moveReader;
}



