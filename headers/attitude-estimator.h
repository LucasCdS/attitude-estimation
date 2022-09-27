/**
 * @file attitude-estimator.h
 * @author Lucas Camargo da Silva (lucas.camargodasilva@hotmail.com)
 * @brief Class that represents a set of attitude estimations
 * @date 2022-09-27
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <vector>
#include <cmath>
#include "accelerometer-data.h"

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

        AttitudeEstimation(int time_stamp_ms_, double roll_, double pitch_);
};

/**
 * @brief Class that represents a set of attitude estimations through a vector in
 * which each element is an AttitudeEstimation struct. It calculates the attiude 
 * estimation by using data from a vector of accelerometer readings.
 * 
 */
class AttitudeEstimator {
    public:
        /**
         * @brief Construct a new AttitudeEstimator object
         * 
         * @param accelerometerReading A vector of accelerometer data readings
         */
        AttitudeEstimator(std::vector<AccelerometerReading> accelerometerReading);

        /**
         * @brief Get the resulting attitude estimation vector
         * 
         * @return std::vector<AttitudeEstimation> A vector containing all the estimated attitude data
         */
        std::vector<AttitudeEstimation> getAttitudeEstimation();
        
    private:
        /**
         * @brief Stores the attitude estimation data
         * 
         */
        std::vector<AttitudeEstimation> estimation;

        /**
         * @brief Estimate the attitude corresponding to accelerometer data readings by following
         * the aerospace rotation sequence, that is, the sequence yaw -> pitch -> roll.
         * 
         * @param accelerometerReading A set of accelerometer data readings
         * @return std::vector<AttitudeEstimation> A vector containing all the estimated attitude data
         */
        std::vector<AttitudeEstimation> estimateAttitude(std::vector<AccelerometerReading> accelerometerReading);

        /**
         * @brief Calculate the roll angle corresponding to a single accelerometer reading by
         * following the aerospace rotation sequence, that is, the sequence yaw -> pitch -> roll.
         * It uses the std::atan2 function to keep the estimated angle between -pi rad and pi rad.
         * It includes a fraction mu of the square of the x axis reading in order to prevent the 
         * denominator of the equation from being zero in case the z axis reading is zero.
         * 
         * @param reading A single accelerometer reading
         * @param mu Parameter used to prevent the denominator of the equation from ever being zero
         * @return double The estimated roll angle between -pi rad and pi rad
         */
        double calculateRoll(AccelerometerReading reading, double mu = 0.01);

        /**
         * @brief Calculate the pitch angle corresponding to a single accelerometer reading by
         * following the aerospace rotation sequence, that is, the sequence yaw -> pitch -> roll.
         * It uses the std::atan function to keep the estimated angle between -pi/2 rad and
         * pi/2 rad.
         * 
         * @param reading A single accelerometer reading
         * @return double The estimated pitch angle between -pi/2 rad and pi/2 rad
         */
        double calculatePitch(AccelerometerReading reading);

        /**
         * @brief Determine the mathematical sign of a number. It returns +1 if the number is
         * non-negative and -1 if the number is negative.
         * 
         * @param number Number whose sign is to be determined
         * @return int The determined sign of the number
         */
        int sign(double number);
};