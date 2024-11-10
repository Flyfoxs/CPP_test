cmake_minimum_required(VERSION 3.18)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -stdlib=libc++")
set(CMAKE_OSX_ARCHITECTURES "arm64")



project(CPP)

add_executable(main main.cpp)
target_link_libraries(main c++)
target_compile_features(main PRIVATE cxx_std_17)
