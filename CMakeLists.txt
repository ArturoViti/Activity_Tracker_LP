cmake_minimum_required(VERSION 3.28)
project(Activity_Tracker_LP)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

add_subdirectory(test)

find_package(Qt6 COMPONENTS
        Core
        Gui
        Widgets
        REQUIRED)
add_library(core ${SOURCE_FILES})
add_executable(Activity_Tracker_LP main.cpp
        model/ActivityVote.h
        model/SportActivityType.h
        model/Tag.cpp
        model/Tag.h
        model/Place.cpp
        model/Place.h
        model/Activity.cpp
        model/Activity.h
        model/DayActivities.cpp
        model/DayActivities.h
        exception/WrongIntervalException.cpp
        exception/WrongIntervalException.h
        exception/IntervalAlreadyOccupied.cpp
        exception/IntervalAlreadyOccupied.h
        config.h
        view/DayActivitiesView.cpp
        view/DayActivitiesView.h
)
target_link_libraries(Activity_Tracker_LP
        Qt::Core
        Qt::Gui
        Qt::Widgets
)


