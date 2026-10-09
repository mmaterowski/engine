cmake_minimum_required(VERSION 3.20)

project(engine LANGUAGES CXX)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_library(engine
    src/test.cpp
)
add_executable(engine_app src/main.cpp)

target_compile_features(engine PUBLIC cxx_std_20)

target_include_directories(engine PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

target_link_libraries(engine_app PRIVATE engine)

enable_testing()
add_subdirectory(tests)
