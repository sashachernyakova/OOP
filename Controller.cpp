#include "Controller.h"

Controller::Controller(int y, int x){
    output = Output();
    alex = new Player();
    field = new Field(y, x);
    fieldView = new FieldView(field);
    fieldView->printField();
}

int Controller::changePlayerPosition (Field::Action direction, int step) {
    int counter = 0;
    int flag = 0;
    while (counter < step) {
        if (field->canMove(direction)) {
            counter += 1;
            alex->makeStep();
            if(field->getPrevCondition() == Cell::eventP){
                if(field->getPersonCell()->getEvent()->makeEvent(alex)){
                    field->changePrevCondition(Cell::Condition::unavailable);
                    output.personInfo(alex->getHP(), alex->getXP(), alex->getTreasure());
                    if (alex->getTreasure() == 5){
                        output.win();
                        return 1;
                    }
                } else {
                    output.gameOver();
                    return 1;
                }
            }
            else if (field->getPrevCondition() == Cell::eventF){
                field->getPersonCell()->getEvent()->makeEvent(field);
                field->changePrevCondition(Cell::Condition::unavailable);
            }

        } else {
            flag = 1;
            output.someSteps(counter);
            break;
        }
        fieldView->changeFieldView(field);
    }
    if (flag != 1) {
        output.allSteps(step);
    }
    return 0;
}

int Controller::movement(int steps, Field::Action action){
    if(changePlayerPosition(action, steps) == 1){
        return 1;
    }else{
        fieldView->changeFieldView(field);
        fieldView->printField();
        return 0;
    }
}

void Controller::steps(){
    std::cout << alex->getTotalSteps() << "\n";
}

Field::Action Controller::getAction(std::string direction){
    if (direction == "right"){
        return Field::right;
    } else if(direction == "left"){
        return Field::left;
    } else if(direction == "up"){
        return Field::up;
    } else if(direction == "down"){
        return Field::down;
    }
}

bool Controller::isDirection(std::string direction){
    return (direction == "right" || direction == "left" || direction == "up" || direction == "down");
}

Controller::~Controller() {
    delete alex;
    delete field;
    delete fieldView;
}
