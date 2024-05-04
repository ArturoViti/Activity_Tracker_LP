cmake_minimum_required(VERSION 3.5)
project(Activity_Tracker_LP)

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
    model/SportActivityType.h
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
    exception/IntervalAlreadyOccupied.cpp
    exception/IntervalAlreadyOccupied.h
    config.h
    view/DayActivitiesView.cpp
    view/DayActivitiesView.h
    view/MainWindowView.cpp
    view/MainWindowView.h
    view/AddUpdateActivitiesView.cpp
    view/AddUpdateActivitiesView.h
    view/AddUpdateActivitiesView.h
)

add_executable(Activity_Tracker_LP main.cpp)
add_library(core ${SOURCE_FILES})

target_link_libraries(Activity_Tracker_LP core)
target_link_libraries(Activity_Tracker_LP Qt::Core Qt::Gui Qt::Widgets )


