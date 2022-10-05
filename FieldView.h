#ifndef UNTITLED57_FIELDVIEW_H
#define UNTITLED57_FIELDVIEW_H

#include "Field.h"
#include "CellView.h"

class FieldView {
    std::vector<std::vector<char>> fieldView;
    int h;
    int w;
    CellView cellView;
public:
    FieldView(Field* field);

    void changeFieldView(Field *newField);

    void printField();

};


#endif
