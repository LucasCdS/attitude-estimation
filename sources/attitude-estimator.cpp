/**
 * @file attitude-estimator.cpp
 * @author Lucas Camargo da Silva (lucas.camargodasilva@hotmail.com)
 * @brief Class that represents a set of attitude estimations
 * @date 2022-09-27
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include "attitude-estimator.h"

/**
 * @brief Construct a new Attitude Estimator:: Attitude Estimator object
 * 
 * @param accelerometerReading A vector of accelerometer data readings
 */
AttitudeEstimator::AttitudeEstimator(std::vector<AccelerometerReading> accelerometerReading)
{
    estimation = estimateAttitude(accelerometerReading);
}

/**
 * @brief Get the resulting attitude estimation vector
 * 
 * @return std::vector<AttitudeEstimation> A vector containing all the estimated attitude data
 */
std::vector<AttitudeEstimation> AttitudeEstimator::getAttitudeEstimation()
{
    return estimation;
}

/**
 * @brief Estimate the attitude corresponding to accelerometer data readings by following
 * the aerospace rotation sequence, that is, the sequence yaw -> pitch -> roll.
 * 
 * @param accelerometerData A set of accelerometer data readings
 * @return std::vector<AttitudeEstimation> A vector containing all the estimated attitude data
 */
std::vector<AttitudeEstimation> AttitudeEstimator::estimateAttitude(std::vector<AccelerometerReading> accelerometerData)
{   
    std::vector<AttitudeEstimation> calculatedEstimation;

    for (int i = 0; i < accelerometerData.size(); i++) {
        calculatedEstimation.push_back(AttitudeEstimation(accelerometerData[i].time_stamp_ms,calculateRoll(accelerometerData[i]),calculatePitch(accelerometerData[i])));
    }

    return calculatedEstimation;
}

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
double AttitudeEstimator::calculateRoll(AccelerometerReading reading, double mu)
{
    return std::atan2(reading.accel_y_axis,(sign(reading.accel_z_axis)*std::sqrt(reading.accel_z_axis*reading.accel_z_axis + mu*reading.accel_x_axis*reading.accel_x_axis)));
}

/**
 * @brief Calculate the pitch angle corresponding to a single accelerometer reading by
 * following the aerospace rotation sequence, that is, the sequence yaw -> pitch -> roll.
 * It uses the std::atan function to keep the estimated angle between -pi/2 rad and
 * pi/2 rad.
 * 
 * @param reading A single accelerometer reading
 * @return double The estimated pitch angle between -pi/2 rad and pi/2 rad
 */
double AttitudeEstimator::calculatePitch(AccelerometerReading reading)
{
    return std::atan(-reading.accel_x_axis/std::sqrt(reading.accel_y_axis*reading.accel_y_axis + reading.accel_z_axis*reading.accel_z_axis));
}

/**
 * @brief Determine the mathematical sign of a number. It returns +1 if the number is
 * non-negative and -1 if the number is negative.
 * 
 * @param number Number whose sign is to be determined
 * @return int The determined sign of the number
 */
int AttitudeEstimator::sign(double number)
{
    if (number>=0) {
        return 1;
    }
    else {
        return -1;
    }
}