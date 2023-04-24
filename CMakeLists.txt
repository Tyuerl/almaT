# CMakeList.txt: файл проекта CMake верхнего уровня; проведите глобальную конфигурацию
# и включите сюда подпроекты.
#
cmake_minimum_required (VERSION 3.8)

project ("almathea_desktop_viewer")

set(PROJECT_PREFIX "almathea_desktop_viewer")

# Включите подпроекты.
add_subdirectory ("almaT/lib")
add_subdirectory ("almaT")
