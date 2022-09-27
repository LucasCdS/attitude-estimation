/**
 * @file accelerometer-data.h
 * @author Lucas Camargo da Silva (lucas.camargodasilva@hotmail.com)
 * @brief Class that represents a set of accelerometer data readings
 * @date 2022-09-26
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <iostream>

/**
 * @brief Accelerometer reading data represented by a struct containing the timestamp
 * of the reading and its corresponding x, y and z axis measurements.
 * 
 */
struct AccelerometerReading {
    public:
        int time_stamp_ms; // the timestamp of the measurements
        int accel_x_axis; // the x axis measurement
        int accel_y_axis; // the y axis measurement
        int accel_z_axis; // the z axus measurement

        /**
         * @brief Construct a new AccelerometerReading struct object
         * 
         * @param time_stamp_ms_ 
         * @param accel_x_axis_ 
         * @param accel_y_axis_ 
         * @param accel_z_axis_ 
         */
        AccelerometerReading(int time_stamp_ms_, int accel_x_axis_, int accel_y_axis_, int accel_z_axis_);

        /**
         * @brief Defines an equal-to operator for testing purposes
         * 
         * @param other the object to which it is compared
         * @return true 
         * @return false 
         */
        bool operator ==(const AccelerometerReading& other) const;
};

/**
 * @brief Class that represents a set of accelerometer data readings through a vector in
 * which each element is an AccelerometerReading struct.
 * 
 */
class AccelerometerData {
    public:
        /**
         * @brief Construct a new Accelerometer Data object
         * 
         * @param dataFilePath the path to the file containing the accelerometer data
         */
        AccelerometerData(std::string dataFilePath);

        /**
         * @brief Get the accelerometer data
         * 
         * @return std::vector<AccelerometerReading> 
         */
        std::vector<AccelerometerReading> getAccelerometerData();

    private:
        /**
         * @brief Stores the accelerometer data
         * 
         */
        std::vector<AccelerometerReading> data;

        /**
         * @brief Read accelerometer data from a given file
         * 
         * @param dataFilePath the path to the file containing the accelerometer data
         * @return std::vector<AccelerometerReading> 
         */
        std::vector<AccelerometerReading> readDataFromFile(std::string dataFilePath);
};