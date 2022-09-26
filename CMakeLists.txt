cmake_minimum_required(VERSION 3.0.0)
project(attitude-estimation)

add_executable(attitude-estimation
  ${CMAKE_SOURCE_DIR}/main.cpp
)

target_include_directories(attitude-estimation PRIVATE
  ${CMAKE_SOURCE_DIR}/sources
  ${CMAKE_SOURCE_DIR}/headers
 )