﻿project(${PROJECT_PREFIX}_app)

cmake_minimum_required (VERSION 3.14)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(AUTOGEN_BUILD_DIR ${CMAKE_CURRENT_SOURCE_DIR})

if(UNIX AND NOT APPLE)
    set(TARGET_BUILD_PLATFORM "linux")
endif()
if(WIN32)
    set(TARGET_BUILD_PLATFORM "windows")
endif()
set(TARGET_BUILD_PLATFORM "${TARGET_BUILD_PLATFORM}" CACHE INTERNAL "")

if(${TARGET_BUILD_PLATFORM} STREQUAL "linux")
    set(TARGET_SCRIPT_EXT "sh")
endif()
if(${TARGET_BUILD_PLATFORM} STREQUAL "windows")
    set(TARGET_SCRIPT_EXT "bat")
endif()
set(TARGET_SCRIPT_EXT "${TARGET_SCRIPT_EXT}" CACHE INTERNAL "")

string(TOLOWER ${CMAKE_BUILD_TYPE} TARGET_BUILD_TYPE)
message("target build type - ${TARGET_BUILD_TYPE}")

if(CMAKE_SIZEOF_VOID_P EQUAL 8)
    set(TARGET_PLATFORM_ARCHITECTURE "x64")
else()
    set(TARGET_PLATFORM_ARCHITECTURE "x86")
endif()
set(TARGET_PLATFORM_ARCHITECTURE "${TARGET_PLATFORM_ARCHITECTURE}" CACHE INTERNAL "")




set(TARGET_SCRIPT_EXT "${TARGET_SCRIPT_EXT}" CACHE INTERNAL "")
set(LIB_DIR "${CMAKE_CURRENT_SOURCE_DIR}/lib" CACHE INTERNAL "")
set(CPP_LIB_DIR "${LIB_DIR}/cpp/${TARGET_BUILD_PLATFORM}/${TARGET_PLATFORM_ARCHITECTURE}/${TARGET_BUILD_TYPE}" CACHE INTERNAL "")
set(SCRIPT_DIR "${CMAKE_CURRENT_SOURCE_DIR}/script/${TARGET_BUILD_PLATFORM}" CACHE INTERNAL "")

#add all cpp library to CMAKE_PREFIX_PATH
file(GLOB children RELATIVE ${CPP_LIB_DIR} ${CPP_LIB_DIR}/*)
set(LIBRARY_LIST "" CACHE INTERNAL "")
foreach(child ${children})
    if(IS_DIRECTORY ${CPP_LIB_DIR}/${child})
        list(APPEND LIBRARY_LIST ${child})
    endif()
endforeach()

foreach(library ${LIBRARY_LIST})
    list(APPEND CMAKE_PREFIX_PATH ${CPP_LIB_DIR}/${library})
endforeach()
set(CMAKE_PREFIX_PATH "${CMAKE_PREFIX_PATH}" CACHE INTERNAL "")


find_package(Qt5 COMPONENTS Widgets REQUIRED)

set(SOURCES  
	source/almaT.h
	source/almaT.cpp
	source/almaT.ui
	source/tableviewmodel.h
	source/tableviewmodel.cpp
	source/main.cpp
	)


add_executable (${PROJECT_NAME} ${SOURCES})

target_link_libraries(${PROJECT_NAME} Qt5::Widgets)

add_custom_command(TARGET ${PROJECT_NAME}
    POST_BUILD
    COMMAND	${SCRIPT_DIR}/copy.${TARGET_SCRIPT_EXT} ${CPP_LIB_DIR}/vc_runtime/*.dll ${CMAKE_CURRENT_BINARY_DIR}
    COMMAND	${SCRIPT_DIR}/copy.${TARGET_SCRIPT_EXT} ${CPP_LIB_DIR}/qt/bin/*.dll ${CMAKE_CURRENT_BINARY_DIR}

    COMMAND	${CMAKE_COMMAND} -E make_directory ${CMAKE_CURRENT_BINARY_DIR}/plugins
    COMMAND	${SCRIPT_DIR}/copy.${TARGET_SCRIPT_EXT} ${CPP_LIB_DIR}/qt/plugins/* ${CMAKE_CURRENT_BINARY_DIR}/plugins

    COMMAND	${CMAKE_COMMAND} -E make_directory ${CMAKE_CURRENT_BINARY_DIR}/settings
)

# TODO: Добавьте тесты и целевые объекты, если это необходимо.