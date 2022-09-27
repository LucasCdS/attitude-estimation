/**
 * @file attitude-estimation.cpp
 * @author Lucas Camargo da Silva (lucas.camargodasilva@hotmail.com)
 * @brief Tools for attitude estimation
 * @date 2022-09-27
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include "attitude-estimation.h"

/**
 * @brief Construct a new AccelerometerReading struct object
 * 
 * @param time_stamp_ms_ The timestamp corresponding to the measurements in [ms]
 * @param accel_x_axis_ The x axis measurement in [mg], where g is the Earth's gravity acceleration
 * @param accel_y_axis_ The y axis measurement in [mg], where g is the Earth's gravity acceleration
 * @param accel_z_axis_ The z axis measurement in [mg], where g is the Earth's gravity acceleration
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
 * @param other The object to which it is compared
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
 * @brief Construct a new AttitudeEstimation::AttitudeEstimation object
 * 
 * @param time_stamp_ms_ The timestamp corresponding to the measurements in [ms]
 * @param roll_ The estimated roll angle in [rad]
 * @param pitch_ The estimated pitch angle in [rad]
 */
AttitudeEstimation::AttitudeEstimation(int time_stamp_ms_, double roll_, double pitch_)
{
    time_stamp_ms = time_stamp_ms_;
    roll = roll_;
    pitch = pitch_;
}