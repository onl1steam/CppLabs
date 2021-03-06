cmake_minimum_required(VERSION 3.1)

project(Weather_app LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt5Widgets REQUIRED)
find_package(Qt5Qml REQUIRED)
find_package(Qt5Core REQUIRED)
set(Weather_src
appmodel.cpp
appmodel.h
main.cpp
mainwindow.cpp
mainwindow.h
mainwindow.ui
resources.qrc
)

add_executable(Weather_app ${Weather_src})
target_compile_definitions(${PROJECT_NAME} PRIVATE $<$<OR:$<CONFIG:Debug>,$<CONFIG:RelWithDebInfo>>:QT_QML_DEBUG>)
target_link_libraries(Weather_app Qt5::Widgets)
target_link_libraries(Weather_app Qt5::Network)
target_link_libraries(Weather_app Qt5::Core)
