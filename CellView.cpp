#include "CellView.h"

CellView::CellView(): cellView('*') {};
char CellView::getCellView(Cell cell){
    switch (cell.getCondition()) {
        case (Condition::available): {
            cellView = '*';
            break;
        }
        case (Condition::unavailable): {
            cellView = ' ';
            break;
        }
        case (Condition::personStand): {
            cellView = 'P';
            break;
        }
        case (Condition::event): {
            cellView = 'E';
            break;
        }
    }
    return cellView;
}

