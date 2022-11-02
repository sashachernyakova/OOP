cmake_minimum_required(VERSION 3.20)
project(untitled57)

set(CMAKE_CXX_STANDARD 14)

add_executable(untitled57 main.cpp Cell.h Cell.cpp CellView.h CellView.cpp Field.h Field.cpp FieldView.h FieldView.cpp Player.h PLayer.cpp Mediator.h Mediator.cpp CommandReader.h CommandReader.cpp Controller.h Controller.cpp IEvent.h PersonEvent.h Enemy.h Enemy.cpp Trap.h Trap.cpp Treasure.h Treasure.cpp FieldEvent.h UnavailableFrame.h UnavailableFrame.cpp FromStart.h FromStart.cpp Output.h Output.cpp IObserver.h IObservable.h ErrorObserver.h ErrorObserver.cpp GameObserver.h GameObserver.cpp PlayerFieldObserver.h PlayerFieldObserver.cpp)
