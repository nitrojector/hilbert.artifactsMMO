cmake_minimum_required(VERSION 3.10)

set(CMAKE_CXX_STANDARD 20)

project(Hilbert.ArtifactsMMO)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)

find_package(CURL REQUIRED)

file(GLOB_RECURSE SOURCES "src/*.cpp")

add_executable(hilbert ${SOURCES})

target_link_libraries(hilbert PRIVATE CURL::libcurl)
