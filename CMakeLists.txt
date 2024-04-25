cmake_minimum_required(VERSION 3.28)
project(Activity_Tracker_LP)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)


find_package(Qt6 COMPONENTS
        Core
        Gui
        Widgets
        REQUIRED)

add_executable(Activity_Tracker_LP main.cpp)
target_link_libraries(Activity_Tracker_LP
        Qt::Core
        Qt::Gui
        Qt::Widgets
)

