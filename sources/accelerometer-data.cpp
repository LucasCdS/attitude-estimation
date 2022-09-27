/**
 * @file accelerometer-data.cpp
 * @author Lucas Camargo da Silva (lucas.camargodasilva@hotmail.com)
 * @brief Class that represents a set of accelerometer data readings
 * @date 2022-09-26
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include "accelerometer-data.h"

/**
 * @brief Construct a new AccelerometerData::AccelerometerData object
 * 
 * @param dataFilePath The path to the file containing the accelerometer data
 */
AccelerometerData::AccelerometerData(std::string dataFilePath)
{
    data = readDataFromFile(dataFilePath);
}

/**
 * @brief Get the accelerometer data
 * 
 * @return std::vector<AccelerometerReading> A vector of accelerometer data readings
 */
std::vector<AccelerometerReading> AccelerometerData::getAccelerometerData()
{
    return data;
}

/**
 * @brief Read accelerometer data from a given file
 * 
 * @param dataFilePath The path to the file containing the accelerometer data
 * @return std::vector<AccelerometerReading> A vector of accelerometer data readings
 */
std::vector<AccelerometerReading> AccelerometerData::readDataFromFile(std::string dataFilePath)
{
    // Create a stream to read from the file containing the accelerometer data
    std::ifstream accelerometerDataFile(dataFilePath);
    if (!accelerometerDataFile) {
        throw std::runtime_error("Error: could not open " + dataFilePath);
    }

    // Read, parse and store the accelerometer data
    std::string line;
    std::string time_stamp_ms, accel_x_axis, accel_y_axis, accel_z_axis;
    std::vector<AccelerometerReading> readData;
    while(std::getline(accelerometerDataFile,line)){
        std::istringstream accelerometerDataStream(line);

        std::getline(accelerometerDataStream,time_stamp_ms,';');
        std::getline(accelerometerDataStream,accel_x_axis,';');
        std::getline(accelerometerDataStream,accel_y_axis,';');
        std::getline(accelerometerDataStream,accel_z_axis,';');

        readData.push_back(AccelerometerReading(stoi(time_stamp_ms),stoi(accel_x_axis),stoi(accel_y_axis),stoi(accel_z_axis)));
    }

    return readData;
}