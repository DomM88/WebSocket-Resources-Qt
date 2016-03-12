cmake_minimum_required(VERSION 2.8)

project(WebSocket-Resources-Qt CXX)
ENABLE_LANGUAGE(C)

add_definitions(-std=gnu++0x)

set(CMAKE_AUTOMOC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

include_directories(
   ${CMAKE_CURRENT_LIST_DIR}/library/src
   ${CMAKE_CURRENT_BINARY_DIR}/library # For ProtoBuf generated
)

option(WITH_TESTS "Enable unittests" OFF)
if(WITH_TESTS)
  enable_testing()
  add_subdirectory(library/tests)
endif()

add_subdirectory(library)
