cmake_minimum_required(VERSION 3.15)

project(qt-widgets-minimal)

find_package(Qt6 COMPONENTS Core Gui Widgets REQUIRED)
set(CMAKE_AUTOMOC ON)

qt6_add_executable(qt-widgets-minimal
        main.cpp
        main_window.cpp main_window.h)

target_link_libraries(qt-widgets-minimal
        PRIVATE
        Qt6::Gui
        Qt6::Core
        Qt6::Widgets
        )