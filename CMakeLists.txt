### Project: Attitude Estimation
###
### Description: A program that reads a log file containing data from 
### an accelerometer and generates an output file with the corresponding
### attitude estimation.
###
### Author: Lucas Camargo da Silva (lucas.camargodasilva@hotmail.com)
###
### Date: 2022-09-27

# Set minimum CMake version
cmake_minimum_required(VERSION 3.0.0)

# Set project name
project(attitude-estimation)

# Main code
add_executable(attitude-estimation
  ${CMAKE_SOURCE_DIR}/main.cpp
  ${CMAKE_SOURCE_DIR}/sources/attitude-estimation.cpp
  ${CMAKE_SOURCE_DIR}/sources/accelerometer-data.cpp
  ${CMAKE_SOURCE_DIR}/sources/attitude-estimator.cpp
)

# Test code for AccelerometerData class
add_executable(test-accelerometer-data
  ${CMAKE_SOURCE_DIR}/tests/test-accelerometer-data.cpp
  ${CMAKE_SOURCE_DIR}/sources/attitude-estimation.cpp
  ${CMAKE_SOURCE_DIR}/sources/accelerometer-data.cpp
)

# Test code for AttitudeEstimator class
add_executable(test-attitude-estimator
  ${CMAKE_SOURCE_DIR}/tests/test-attitude-estimator.cpp
  ${CMAKE_SOURCE_DIR}/sources/attitude-estimation.cpp
  ${CMAKE_SOURCE_DIR}/sources/attitude-estimator.cpp
)

# Test code for writeAttitudeEstimationFile function
add_executable(test-write-attitude-estimation-file
  ${CMAKE_SOURCE_DIR}/tests/test-write-attitude-estimation-file.cpp
  ${CMAKE_SOURCE_DIR}/sources/attitude-estimation.cpp
)

# Enable testing functionality
enable_testing()

# Define tests
add_test(NAME test-attitude-data COMMAND $<TARGET_FILE:test-accelerometer-data>)
add_test(NAME test-attitude-estimator COMMAND $<TARGET_FILE:test-attitude-estimator>)
add_test(NAME test-write-attitude-estimation-file COMMAND $<TARGET_FILE:test-write-attitude-estimation-file>)

# Include necessary directories for main code and tests
target_include_directories(attitude-estimation PRIVATE
  ${CMAKE_SOURCE_DIR}/headers
 )

target_include_directories(test-accelerometer-data PRIVATE
  ${CMAKE_SOURCE_DIR}/headers
)

target_include_directories(test-attitude-estimator PRIVATE
  ${CMAKE_SOURCE_DIR}/headers
)

target_include_directories(test-write-attitude-estimation-file PRIVATE
  ${CMAKE_SOURCE_DIR}/headers
)