cmake_minimum_required(VERSION 3.10)
project(FunnyJsonExplorer)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED True)

include_directories(third-party)
include_directories(include)

aux_source_directory(src SRC_FILES)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/bin)

add_executable(fje ${SRC_FILES})