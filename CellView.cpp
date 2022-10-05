#include "CellView.h"

CellView::CellView(): cellView('*') {};
char CellView::getCellView(Cell cell){
    switch (cell.getCondition()) {
        case (Cell::Condition::available): {
            cellView = '*';
            break;
        }
        case (Cell::Condition::unavailable): {
            cellView = ' ';
            break;
        }
        case (Cell::Condition::personStand): {
            cellView = 'P';
            break;
        }
        case (Cell::Condition::event): {
            cellView = 'E';
            break;
        }
    }
    return cellView;
}

