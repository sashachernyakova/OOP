#include "Controller.h"

Controller::Controller(std::string log, int print, int y, int x): log(log), pr(print){
    alex = new Player();
    field = new Field(y, x);
    fieldView = new FieldView(field);
    if(pr == 1){
        l = (NoOutput*)(new NoOutput());
    } else if(pr == 2){
        l = (ConsoleOutput*)(new ConsoleOutput());
    } else if(pr == 3){
        l = (FileOutput*)(new FileOutput());;
    } else{
        l = (FileConsoleOutput*)(new FileConsoleOutput());
    }

    std::vector<std::string> out;
    size_t start;
    size_t end = 0;
    const char delim = ' ';

    while ((start = log.find_first_not_of(delim, end)) != std::string::npos)
    {
        end = log.find(delim, start);
        out.push_back(log.substr(start, end - start));
    }

    for(int i = 0; i < out.size(); i++){
        switch(out[i][0]){
            case '1':
                o = (PlayerFieldObserver*)(new PlayerFieldObserver(field, l));
                break;
            case '2':
                o = (GameObserver*)(new GameObserver(field, l));
                break;
            case '3':
                o = (ErrorObserver*)(new ErrorObserver(field, l));
                break;
        }
    };
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
                    (field->getMap())[IObserver::health] = alex->getHP();
                    (field->getMap())[IObserver::experience] = alex->getXP();
                    (field->getMap())[IObserver::treasure] = alex->getTreasure();
                    field->notify((field->getMap())[IObserver::health], IObserver::health);
                    field->notify((field->getMap())[IObserver::experience], IObserver::experience);
                    field->notify((field->getMap())[IObserver::treasure], IObserver::treasure);
                    if (alex->getTreasure() == 5){
                        field->notify((field->getMap())[IObserver::win], IObserver::win);
                        return 1;
                    }
                } else {
                    field->notify((field->getMap())[IObserver::lose],IObserver::lose);
                    return 1;
                }
            }
            else if (field->getPrevCondition() == Cell::eventF){
                field->getPersonCell()->getEvent()->makeEvent(field);
                field->changePrevCondition(Cell::Condition::unavailable);
            }

        } else {
            flag = 1;
            (field->getMap())[IObserver::someSteps] = counter;
            field->notify((field->getMap())[IObserver::someSteps], IObserver::someSteps);
            break;
        }
        fieldView->changeFieldView(field);
    }
    if (flag != 1) {
        (field->getMap())[IObserver::allSteps] = counter;
        field->notify((field->getMap())[IObserver::allSteps], IObserver::allSteps);
    }
    return 0;
}

int Controller::movement(int steps, Field::Action action){
    if(changePlayerPosition(action, steps) == 1){
        return 1;
    }else{
        fieldView->changeFieldView(field);
        fieldView->printField();
        std::cout << "\n";
        return 0;
    }
}

void Controller::steps(){
    std::cout << alex->getTotalSteps() << "\n";
}

Field::Action Controller::getAction(std::string direction){
    if (direction == "d"){
        return Field::right;
    } else if(direction == "a"){
        return Field::left;
    } else if(direction == "w"){
        return Field::up;
    } else if(direction == "s"){
        return Field::down;
    }
}

bool Controller::isDirection(std::string direction){
    return (direction == "a" || direction == "d" || direction == "w" || direction == "s");
}

Controller::~Controller() {
    delete alex;
    delete field;
    delete fieldView;
}

void Controller::stop() {
    field->stopGame();
}

void Controller::start() {
    field->gameStart();
}

void Controller::errorH() {
    field->errorHeight();
}

void Controller::errorW() {
    field->errorWidth();
}

void Controller::errorD() {
    field->errorDirection();
}

void Controller::errorNumber() {
    field->errorStartNumber();
}

void Controller::printField() {
    fieldView->printField();
}

