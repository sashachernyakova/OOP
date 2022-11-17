#include "CellView.h"

CellView::CellView(): cellView('*') {};
char CellView::getCellView(Cell cell){
    switch (cell.getCondition()) {
        case (Cell::Condition::available): {
            cellView = '+';
            break;
        }
        case (Cell::Condition::unavailable): {
            cellView = 'x';
            break;
        }
        case (Cell::Condition::personStand): {
            cellView = 'P';
            break;
        }
        case (Cell::Condition::eventP): {
            cellView = 'E';
            break;
        }
        case (Cell::Condition::eventF): {
            cellView = 'E';
            break;
        }
    }
    return cellView;
}

