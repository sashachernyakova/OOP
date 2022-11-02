#include "Mediator.h"

Mediator::Mediator(): reader(CommandReader()), output(Output()){
    output.logger();
    log = std::stoi(reader.read());
    output.howPrint();
    print = std::stoi(reader.read());
    output.createField();
    txt1 = reader.read();
    if (txt1 == "1"){
        controller = new Controller(log, print);
    } else if (txt1 == "2"){
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
        controller = new Controller(log, print, std::stoi(txt1), std::stoi(txt2));
    } else {
        controller->errorNumber();
        controller = new Controller(log, print);
    }
    controller->start();
    output.gameRules();
    while(5 == 5){
        txt1 = reader.read();
        if (txt1 == "steps"){
            controller->steps();
        }else if (txt1 == "stop"){
            controller->stop();
            break;
        }else{
            txt2 = reader.read();
            if (controller->isDirection(txt2 )){
                if(controller->movement(std::stoi(txt1), controller->getAction(txt2)) == 1 ){
                    return;
                }
            } else {
                controller->errorD();
            }
        }
    }
}

Mediator::~Mediator(){
    delete controller;
}



