#include "Mediator.h"

Mediator::Mediator(): reader(ConsoleReader()), output(Output()){
    moveReader = new ConsoleReader();

    output.logger();
    log = reader.read();
    output.howPrint();
    print = std::stoi(reader.read());
    output.createField();

    str = reader.read();
    int hError = 0;
    int wError = 0;

    if (str == "1"){
        controller = new Controller(log, print);
    } else if (str == "2"){
        output.getSize();
        std::vector <int> fieldSize;

        str = reader.read();
        if(std::stoi(str) < 0){
            hError = 1;
            fieldSize.push_back(10);
        }else{
            fieldSize.push_back(std::stoi(str));
        }

        str = reader.read();
        if(std::stoi(str) < 0){
            wError = 1;
            fieldSize.push_back(10);
        }
        fieldSize.push_back(std::stoi(str));

        controller = new Controller(log, print, fieldSize[0], fieldSize[1]);
        if (hError == 1){
            controller->errorH();
        }
        if (wError == 1){
            controller->errorW();
        }

    } else {
        controller = new Controller(log, print);
        controller->errorNumber();
    }
    controller->printField();

    output.rules();
    str = reader.read();

    if(std::stoi(str) == 2){
        navigationReader = new FileNavigation();
        std::ifstream in("navigation.txt");
        navigationReader->madeVecDirection(&in);
    }
    controller->start();
    output.gameRules();
}

void Mediator::start() {
    str = moveReader->read();
    while(str != navigationReader->returnVec()[4]) {
        std::vector <std::string> out;
        makeVector(out, str);
        int go = controller->isDirection( navigationReader->returnVec(), out[1]);
        if (go != 0) {
            if (controller->movement(std::stoi(out[0]), controller->getAction(go)) == 1) {
                return;
            }
        } else {
            controller->errorD();
        }
        str = moveReader->read();
    }
    controller->stop();
}

void Mediator::makeVector(std::vector<std::string> &vec, std::string str) {
    size_t start;
    size_t end = 0;
    const char delim = ' ';
    while ((start = str.find_first_not_of(delim, end)) != std::string::npos) {
        end = str.find(delim, start);
        vec.push_back(str.substr(start, end - start));
    }
}

Mediator::~Mediator(){
    delete controller;
    delete moveReader;
    delete navigationReader;
}



