cmake_minimum_required(VERSION 3.15.0)

project(basic
        VERSION 1.0.0
        DESCRIPTION "Exploring VST3"
        )

set(SMTG_RUN_VST_VALIDATOR OFF)
#smtg_add_vst3plugin(basic
#        include/ids.h
#        include/version.h
#        source/factory.cpp
#        source/plugin_controller.cpp
#        source/plugin_controller.h
#        source/plugin_processor.cpp
#        source/plugin_processor.h
#        source/plugin_view.cpp
#        source/plugin_view.h
#        )
add_library(basic
        MODULE
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
smtg_target_set_vst_win_architecture_name(basic)
smtg_target_make_plugin_package(basic "basic" vst3)
#smtg_target_dump_plugin_package_variables(basic)
#TODO these two are crashing
#smtg_target_create_module_info_file(basic)
#smtg_target_run_vst_validator(basic)
smtg_get_vst3_path()
smtg_target_create_link_to_plugin(basic ${SMTG_PLUGIN_TARGET_PATH})

# configure_file(${SDK_ROOT}/cmake/templates/projectversion.h.in projectversion.h)

target_include_directories(basic PUBLIC
        "${PROJECT_BINARY_DIR}"
        )

target_link_libraries(basic
        AudioPlugin
        )