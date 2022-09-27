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
#include "attitude-estimation.h"

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
         * @param dataFilePath The path to the file containing the accelerometer data
         */
        AccelerometerData(std::string dataFilePath);

        /**
         * @brief Get the accelerometer data
         * 
         * @return std::vector<AccelerometerReading> A vector of accelerometer data readings
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
         * @param dataFilePath The path to the file containing the accelerometer data
         * @return std::vector<AccelerometerReading> A vector of accelerometer data readings
         */
        std::vector<AccelerometerReading> readDataFromFile(std::string dataFilePath);
};