cmake_minimum_required(VERSION 3.5)
project(Activity_Tracker_LP)

set(CMAKE_AUTOMOC ON)                   #crea i file _moc ogni volta che incontra la macro Q_OBJECT
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOUIC ON)                   #aggiunge il file ui per la creazione della finestra interattiva

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fsanitize=address -g")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra")

find_package( Qt6 COMPONENTS Core Gui Widgets REQUIRED )
include_directories(${Qt6Widgets_INCLUDE_DIRS})
add_definitions(${Qt6Widgets_DEFINITIONS})
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${Qt6Widgets_EXECUTABLE_COMPILE_FLAGS}")

add_subdirectory(test)

set( SOURCE_FILES
    model/ActivityVote.h
        model/Tag.h
    model/Tag.cpp
    model/Place.cpp
    model/Place.h
    model/Activity.cpp
    model/Activity.h
    model/DayActivities.cpp
    model/DayActivities.h
    exception/WrongIntervalException.cpp
    exception/WrongIntervalException.h
        exception/IntervalAlreadyOccupiedException.cpp
        exception/IntervalAlreadyOccupiedException.h
    config.h
    view/DayActivitiesView.cpp
    view/DayActivitiesView.h
    view/MainWindowView.cpp
    view/MainWindowView.h
    view/AddUpdateActivitiesView.cpp
    view/AddUpdateActivitiesView.h
    view/AddUpdateActivitiesView.h
        model/Observer.h
        model/Observer.h
        model/Subject.h
        controller/DayActivitiesController.cpp
        controller/DayActivitiesController.h
        view/DayActivitiesList.cpp
        view/DayActivitiesList.h
        view/DayActivityRow.cpp
        view/DayActivityRow.h
        exception/EmptyPlaceNameException.cpp
        exception/EmptyPlaceNameException.h
        exception/EmptyTagNameException.cpp
        exception/EmptyTagNameException.h
        exception/EmptyActivityNameException.cpp
        exception/EmptyActivityNameException.h
)

add_executable(Activity_Tracker_LP main.cpp)
add_library(core ${SOURCE_FILES})

set_target_properties(${PROJECT_NAME} PROPERTIES AUTOMOC TRUE)
target_link_libraries(Activity_Tracker_LP core)
target_link_libraries(Activity_Tracker_LP Qt::Core Qt::Gui Qt::Widgets )


