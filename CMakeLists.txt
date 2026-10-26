# CMakeLists.txt

cmake_minimum_required(VERSION 3.20)
project(FractionProject LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)

# Ваша библиотека с классом Fraction
add_library(fraction_lib Fraction.cpp)
target_include_directories(fraction_lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

# Включаем тестирование
enable_testing()

# Подключаем Catch2 через FetchContent
include(FetchContent)
FetchContent_Declare(
  Catch2
  GIT_REPOSITORY https://github.com/catchorg/Catch2.git
  GIT_TAG        v3.16.1 # or a later release
)
FetchContent_MakeAvailable(Catch2)

# Добавляем поддиректорию с тестами
add_subdirectory(tests)