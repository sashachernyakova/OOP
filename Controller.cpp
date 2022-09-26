#include "Controller.h"

Controller::Controller(){
}

Controller::Controller(int y, int x){
    field = Field(&alex, y, x);
    fieldView = FieldView(&field);
}

void Controller::movement(int steps, std::string action) {
    field.changePlayerPosition(action, steps);
    fieldView.changeFieldView(&field);
    fieldView.printField();
}

void Controller::printStartField(){
    fieldView.printField();
}

void Controller::level(){
    std::cout << alex.getTotalSteps() << "\n";
};

