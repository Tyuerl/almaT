cmake_minimum_required (VERSION 3.14)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

set(CMAKE_PREFIX_PATH "lib/cpp/windows/x64/debug/qt/lib/cmake/Qt5") # добавить выбор платформ систему и релиз

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



# TODO: Добавьте тесты и целевые объекты, если это необходимо.