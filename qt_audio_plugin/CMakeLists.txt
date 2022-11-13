cmake_minimum_required(VERSION 3.2)

set(CMAKE_AUTOMOC ON)

project(QtAudioPlugin)

find_package(Qt6 COMPONENTS Core Widgets REQUIRED)

#DEVELOPMENT, RELEASE, _DEBUG, or NDEBUG  must be defined! fdebug.h
#add_definitions(-DDEVELOPMENT )

set(SOURCES
        qvstlibentry.cpp
        #qvstconsole.cpp
        qvstapplication.cpp
        qvstcontroller.cpp
        qvsteditorview.cpp
        qvstaudioeffect.cpp
        qvstparametercontainer.cpp
        qvsthostedwidget.cpp
        )
set(HEADERS
        #qvstconsole.h
        qvstapplication.h
        qvstcontroller.h
        qvsteditorview.h
        qvstaudioeffect.h
        qvstparametercontainer.h
        qvsthostedwidget.h
        )

add_library(AudioPlugin
        SHARED
        ${SOURCES}
        ${HEADERS}
        )

target_link_libraries(AudioPlugin
        base
        sdk
        Qt6::Core
        Qt6::Widgets
        )

add_executable(test tests/test_entrypoint.cpp)
target_link_libraries(test PRIVATE AudioPlugin)