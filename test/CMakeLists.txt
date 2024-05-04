cmake_minimum_required(VERSION 3.5)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

find_package( Qt6 COMPONENTS Core Gui Widgets REQUIRED )
include_directories(${Qt6Widgets_INCLUDE_DIRS})
add_definitions(${Qt6Widgets_DEFINITIONS})
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${Qt6Widgets_EXECUTABLE_COMPILE_FLAGS}")

add_subdirectory(./lib/googletest)
set(gtest_SOURCE_DIR, ./lib/googletest/)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

set(TEST_SOURCE_FILES runAllTests.cpp
        ActivityTestFixture.cpp
        ActivityTest.cpp)

add_executable( runTest ${TEST_SOURCE_FILES} )
target_link_libraries( runTest Qt::Core Qt::Gui Qt::Widgets gtest gtest_main core )