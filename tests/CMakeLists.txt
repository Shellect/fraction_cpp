add_executable(tests test.cpp)

# Связываем тесты с нашей библиотекой и с Catch2 (с готовым main)
target_link_libraries(tests PRIVATE fraction_lib Catch2::Catch2WithMain)

# Автоматически регистрируем тесты в CTest
list(APPEND CMAKE_MODULE_PATH ${catch2_SOURCE_DIR}/extras)
include(CTest)
include(Catch)
catch_discover_tests(tests)