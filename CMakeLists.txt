cmake_minimum_required(VERSION 3.15)
project(bbl-opencolorio VERSION 0.1 LANGUAGES C CXX)

find_package(babble 0.5 CONFIG REQUIRED)
find_package(OpenColorIO 2.2 REQUIRED)

include(GNUInstallDirs)

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

# This is just here to trigger generation of compile commands for the bind file so we get LSP functionality in the bind file
add_library(bind-dummy ${bindfiles})
target_link_libraries(bind-dummy babble::bind OpenColorIO::OpenColorIO)

install(
  TARGETS 
    opencolorio-c
  LIBRARY 
    DESTINATION ${CMAKE_INSTALL_LIBDIR}
  ARCHIVE 
    DESTINATION ${CMAKE_INSTALL_LIBDIR}
  RUNTIME 
    DESTINATION ${CMAKE_INSTALL_BINDIR}
  INCLUDES 
    DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
)