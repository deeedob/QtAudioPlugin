cmake_minimum_required(VERSION 3.15.0)

project(basic
        VERSION 1.0.0
        DESCRIPTION "Exploring VST3"
        )

smtg_add_vst3plugin(basic
        include/ids.h
        include/version.h
        source/factory.cpp
        source/plugin_controller.cpp
        source/plugin_controller.h
        source/plugin_processor.cpp
        source/plugin_processor.h
        source/plugin_view.cpp
        source/plugin_view.h
        )


configure_file(${SDK_ROOT}/cmake/templates/projectversion.h.in projectversion.h)

target_include_directories(basic PUBLIC
        "${PROJECT_BINARY_DIR}"
        )

target_link_libraries(basic
        PRIVATE
        AudioPlugin
        )