#include "FieldView.h"

FieldView::FieldView(Field *field){
    cellView = CellView();
    vert = (*field).getVert();
    hor = (*field).getGor();

    fieldView.resize(vert);
    for (int i = 0; i < vert; i++){
        fieldView[i].resize(hor);
    }

    for (int i = 0; i < vert; i++) {
        for (int j = 0; j < hor; j++) {
            fieldView[i][j] = cellView.getCellView(field->getField()[i][j]);
        }
    }
}

void FieldView::changeFieldView(Field *newField) {
    for (int i = 0; i < vert; i++) {
        for (int j = 0; j < hor; j++) {
            fieldView[i][j] = cellView.getCellView(newField->getField()[i][j]);
        }
    }
}

void FieldView:: printField() {
    for (int i = 0; i < vert; i++) {
        for (int j = 0; j < hor; j++) {
            if (j == hor - 1) {
                std::cout << fieldView[i][j] << "\n";
            } else {
                std::cout << fieldView[i][j];
            }
        }
    }
}

