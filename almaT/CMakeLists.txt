cmake_minimum_required (VERSION 3.14)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

set(CMAKE_PREFIX_PATH "almaT/lib/cpp/windows/x64/debug/qt/lib/cmake/Qt5")

set(SOURCES  
	source/almaT.cpp 
	source/almaT.h)

find_package(Qt5 COMPONENTS Widgets REQUIRED)

add_executable (${PROJECT_NAME} ${SOURCES})

target_link_libraries(${PROJECT_NAME} Qt5::Widgets)



# TODO: Добавьте тесты и целевые объекты, если это необходимо.