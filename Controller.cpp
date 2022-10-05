#include "Controller.h"

Controller::Controller(int y, int x){
    alex = new Player();
    field = new Field(y, x);
    fieldView = new FieldView(field);
    fieldView->printField();
}

void Controller::changePlayerPosition (Field::Action direction, int step) {
    int counter;
    int flag = 0;
    counter = 0;
    while (counter < step) {
        if (field->canMove(direction)) {
            counter += 1;
            alex->makeStep();
        } else {
            flag = 1;
            std::cout << "The player have gone only " << counter << " steps. Next cell is unavailable.\n";
            break;
        }
    }
    if (flag != 1) {
        std::cout << "The player have gone all " << step << " steps\n";
    }
}

void Controller::movement(int steps, Field::Action action){
    changePlayerPosition(action, steps);
    fieldView->changeFieldView(field);
    fieldView->printField();
}

void Controller::steps(){
    std::cout << alex->getTotalSteps() << "\n";
}

Controller::~Controller() {
    delete alex;
    delete field;
    delete fieldView;
}

