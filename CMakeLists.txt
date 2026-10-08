cmake_minimum_required(VERSION 3.20)

project(engine LANGUAGES CXX)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_executable(engine src/main.cpp)

target_compile_features(engine PRIVATE cxx_std_20)

target_compile_options(engine PRIVATE
  "-isystem/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/c++/v1"
)
