
cmake_minimum_required(VERSION 3.17)
project(ReCppCommon)
if(NOT REMAKE_ROOT_PATH)
    set(ReMakeDir ${CMAKE_CURRENT_SOURCE_DIR}/Intermedia/ReMake)
    include(${ReMakeDir}/re-cmake/Init.cmake)
    ReMake_InitProject()

    ReMake_AddSubDirsRec("Intermedia/ReMake")
    ReMake_AddSubDirsRec("Intermedia/Git")
    ReMake_AddSubDirsRec("Test")
endif()

ReMake_AddSubDirsRec("Src")
        