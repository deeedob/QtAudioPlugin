cmake_minimum_required(VERSION 3.15.0)

project(basic
        VERSION 1.0.0
        DESCRIPTION "Exploring VST3"
        )

smtg_add_vst3plugin(basic
        include/plugids.h
        include/version.h
        source/plugfactory.cpp
        source/plugcontroller.cpp
        source/plugcontroller.h
        source/plugprocessor.cpp
        source/plugprocessor.h
        )


configure_file(${SDK_ROOT}/cmake/templates/projectversion.h.in projectversion.h)

target_include_directories(basic PUBLIC
        "${PROJECT_BINARY_DIR}"
        )

target_link_libraries(basic
        PRIVATE
        sdk
        )