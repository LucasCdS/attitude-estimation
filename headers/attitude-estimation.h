/**
 * @file attitude-estimation.h
 * @author Lucas Camargo da Silva (lucas.camargodasilva@hotmail.com)
 * @brief Tools for attitude estimation
 * @date 2022-09-27
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <iostream>
#include <vector>
#include <fstream>
#include <string>

/**
 * @brief Accelerometer reading data represented by a struct containing the timestamp
 * of the reading and its corresponding x, y and z axis measurements.
 * 
 */
struct AccelerometerReading {
    public:
        int time_stamp_ms; // the timestamp of the measurements in [ms]
        int accel_x_axis; // the x axis measurement in [mg], where g is the Earth's gravity acceleration
        int accel_y_axis; // the y axis measurement in [mg], where g is the Earth's gravity acceleration
        int accel_z_axis; // the z axus measurement in [mg], where g is the Earth's gravity acceleration

        /**
         * @brief Construct a new AccelerometerReading struct object
         * 
         * @param time_stamp_ms_ The timestamp corresponding to the measurements in [ms]
         * @param accel_x_axis_ The x axis measurement in [mg], where g is the Earth's gravity acceleration
         * @param accel_y_axis_ The y axis measurement in [mg], where g is the Earth's gravity acceleration
         * @param accel_z_axis_ The z axus measurement in [mg], where g is the Earth's gravity acceleration
         */
        AccelerometerReading(int time_stamp_ms_, int accel_x_axis_, int accel_y_axis_, int accel_z_axis_);

        /**
         * @brief Defines an equal-to operator for testing purposes
         * 
         * @param other The object to which it is compared
         * @return true 
         * @return false 
         */
        bool operator ==(const AccelerometerReading& other) const;
};

/**
 * @brief Attitude estimation represented by a struct containing the timestamp
 * of the corresponding measurements and the estimated roll and pitch angles.
 * 
 */
struct AttitudeEstimation {
    public:
        int time_stamp_ms; // the timestamp corresponding to the measurements in [ms]
        double roll; // the estimated roll angle in [rad]
        double pitch; // the estimated pitch angle in [rad]

        /**
         * @brief Construct a new AttitudeEstimation object
         * 
         * @param time_stamp_ms_ The timestamp corresponding to the measurements in [ms]
         * @param roll_ The estimated roll angle in [rad]
         * @param pitch_ The estimated pitch angle in [rad]
         */
        AttitudeEstimation(int time_stamp_ms_, double roll_, double pitch_);

        /**
         * @brief Defines an equal-to operator for testing purposes
         * 
         * @param other The struct to which it is compared
         * @return true 
         * @return false 
         */
        bool operator ==(const AttitudeEstimation& other) const;
};

/**
 * @brief Function that writes a file containing attitude estimation data
 * 
 * @param attitudeEstimation A vector containing the estimated attitude data
 * @param attitudeEstimationFilePath The path to the attitude estimation data file to be created
 */
void writeAttitudeEstimationFile(std::vector<AttitudeEstimation> attitudeEstimation, std::string attitudeEstimationFilePath);