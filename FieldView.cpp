#include "FieldView.h"

FieldView::FieldView(Field *field){
    cellView = CellView();
    h = (*field).getHeight();
    w = (*field).getWidth();

    fieldView.resize(h);
    for (int i = 0; i < h; i++){
        fieldView[i].resize(w);
    }

    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            fieldView[i][j] = cellView.getCellView(field->getField()[i][j]);
        }
    }
}

void FieldView::changeFieldView(Field *newField) {
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            fieldView[i][j] = cellView.getCellView(newField->getField()[i][j]);
        }
    }
}

void FieldView:: printField() {
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (j == w - 1) {
                std::cout << fieldView[i][j] << "\n";
            } else {
                std::cout << fieldView[i][j];
            }
        }
    }
}




