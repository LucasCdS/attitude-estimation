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
 * @brief Construct a new AccelerometerReading struct object
 * 
 * @param time_stamp_ms_ 
 * @param accel_x_axis_ 
 * @param accel_y_axis_ 
 * @param accel_z_axis_ 
 */
AccelerometerReading::AccelerometerReading(int time_stamp_ms_, int accel_x_axis_, int accel_y_axis_, int accel_z_axis_)
{
    time_stamp_ms = time_stamp_ms_;
    accel_x_axis = accel_x_axis_;
    accel_y_axis = accel_y_axis_;
    accel_z_axis = accel_z_axis_;
}

/**
 * @brief Defines an equal-to operator for AccelerometerReading for test purposes
 * 
 * @param other the object to which it is compared
 * @return true 
 * @return false 
 */
bool AccelerometerReading::operator ==(const AccelerometerReading& other) const
{
    if((time_stamp_ms == other.time_stamp_ms) && 
        (accel_x_axis == other.accel_x_axis) &&
        (accel_y_axis == other.accel_y_axis) &&
        (accel_z_axis == other.accel_z_axis)) {
        return true;
    }
    else{
        return false;
    }
}

/**
 * @brief Construct a new AccelerometerData::AccelerometerData object
 * 
 * @param dataFilePath the path to the file containing the accelerometer data
 */
AccelerometerData::AccelerometerData(std::string dataFilePath)
{
    data = readDataFromFile(dataFilePath);
}

/**
 * @brief Get the accelerometer data
 * 
 * @return std::vector<AccelerometerReading> 
 */
std::vector<AccelerometerReading> AccelerometerData::getAccelerometerData()
{
    return data;
}

/**
 * @brief Read accelerometer data from a given file
 * 
 * @param dataFilePath 
 * @return std::vector<AccelerometerReading> 
 */
std::vector<AccelerometerReading> AccelerometerData::readDataFromFile(std::string dataFilePath)
{
    // Create a stream to read from the file containing the accelerometer data
    std::ifstream accelerometerDataFile(dataFilePath);
    if (!accelerometerDataFile) {
        std::cout << "Could not open " << dataFilePath << std::endl;
        return std::vector<AccelerometerReading>();
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