cmake_minimum_required(VERSION 3.10)

project(Hilbert.ArtifactsMMO)

find_package(CURL REQUIRED)

file(GLOB_RECURSE SOURCES "src/*.cpp")

add_executable(hilbert ${SOURCES})

target_link_libraries(hilbert PRIVATE CURL::libcurl)
