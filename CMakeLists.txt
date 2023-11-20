cmake_minimum_required(VERSION 3.15)
project(bbl-opencolorio VERSION 0.1 LANGUAGES C CXX)

find_package(babble CONFIG REQUIRED)
find_package(OpenColorIO 2.2 REQUIRED)

# The bindfile contains all our binding definitions
set(bindfiles 
    bind/opencolorio.cpp 
    bind/opencolortransforms.cpp 
)

bbl_translate_binding(
    opencolorio
    BINDFILES 
        ${bindfiles}
    COMPILE_ARGS 
        -Wno-deprecated-builtins 
        -DNOMINMAX 
        -D_MT 
        -DBOOST_ALL_NO_LIB 
        -D__TBB_show_deprecation_message_task_H 
)

target_link_libraries(opencolorio-c PUBLIC OpenColorIO::OpenColorIO)
target_compile_definitions(opencolorio-c PRIVATE NOMINMAX BOOST_ALL_NO_LIB __TBB_show_deprecation_message_task_H)

# Compile a simple test program to exercise the generated library
# add_executable(opencolorio-c-test01 opencolorio-c-test01.c)
# target_link_libraries(opencolorio-c-test01 PUBLIC opencolorio-c)
# target_include_directories(opencolorio-c-test01 PRIVATE ${CMAKE_CURRENT_BINARY_DIR})
# set_property(TARGET opencolorio-c-test01 PROPERTY C_STANDARD 99)

# This is just here to trigger generation of compile commands for the bind file so we get LSP functionality in the bind file
add_library(bind-dummy ${bindfiles})
target_link_libraries(bind-dummy babble::bind OpenColorIO::OpenColorIO)
# target_include_directories(bind-dummy PRIVATE $<TARGET_PROPERTY:OpenEXR::OpenEXR,INCLUDE_DIRECTORIES>)
