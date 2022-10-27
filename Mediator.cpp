#include "Mediator.h"

Mediator::Mediator(): reader(CommandReader()), output(Output()){
    output.startGame();
    txt1 = reader.read();
    if (txt1 == "1"){
        controller = new Controller();
    } else if (txt1 == "2"){
        output.getHeight();
        txt1 = reader.read();
        if(txt1[0] == '-'){
            output.errorHeight();
            txt1 = "10";
        }
        output.getWidth();
        txt2 = reader.read();
        if(txt2[0] == '-'){
            output.errorWidth();
            txt2 = "10";
        }
        controller = new Controller(std::stoi(txt1), std::stoi(txt2));
    } else {
        output.errorStartNumber();
        controller = new Controller();
    }
    output.gameRules();
    while(5 == 5){
        txt1 = reader.read();
        if (txt1 == "steps"){
            controller->steps();
        }else if (txt1 == "stop"){
            output.stopGame();
            break;
        }else{
            txt2 = reader.read();
            if (controller->isDirection(txt2 )){
                if(controller->movement(std::stoi(txt1), controller->getAction(txt2)) == 1 ){
                    return;
                }
            } else {
                output.errorDirection();
            }
        }
    }
}

Mediator::~Mediator(){
    delete controller;
}



