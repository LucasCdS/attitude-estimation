/**
 * @file test-attitude-estimator.cpp
 * @author Lucas Camargo da Silva (lucas.camargodasilva@hotmail.com)
 * @brief Program to test the AttitudeEstimator class
 * @date 2022-09-27
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <iostream>
#include "attitude-estimator.h"

int main(int argc, char *argv[]) {
    // Create three dummy accelerometer data readings
    std::vector<AccelerometerReading> accelerometerData;
    accelerometerData.push_back(AccelerometerReading(54741, 461, 82, -887));
    accelerometerData.push_back(AccelerometerReading(54751, 23, -22, -993));
    accelerometerData.push_back(AccelerometerReading(54761, 25, -20, -996));

    // Create the three expected attitude estimations calculated manually corresponding to each one of the dummy accelerometer data readings 
    std::vector<AttitudeEstimation> expectedEstimation;
    expectedEstimation.push_back(AttitudeEstimation(54741, 3.0495318, -0.4775673));
    expectedEstimation.push_back(AttitudeEstimation(54751, -3.1194413,-0.0231523));
    expectedEstimation.push_back(AttitudeEstimation(54761, -3.1215151,-0.0251658));

    // Create an object of the AttitudeEstimator class and initialize it with the dummy accelerometer data
    AttitudeEstimator attitudeEstimatorTester = AttitudeEstimator(accelerometerData);
    std::vector<AttitudeEstimation> actualEstimation = attitudeEstimatorTester.getAttitudeEstimation();

    // Check if the expected attitude estimations are equal to the actual attitude estimations calculated by AttitudeEstimator
    bool failed = false;
    float tolerance = 0.0001;
    for (int i = 0; i < expectedEstimation.size(); i++) {
        if (std::abs(expectedEstimation[i].roll - actualEstimation[i].roll) > tolerance) {
            failed = true;
            std::cout << "In estimation " << i << " expected roll " << expectedEstimation[i].roll << " but actual roll is " << actualEstimation[i].roll << " for a tolerance of " << tolerance << '\n';
        }
        if (std::abs(expectedEstimation[i].pitch - actualEstimation[i].pitch) > tolerance) {
            failed = true;
            std::cout << "In estimation " << i << " expected pitch " << expectedEstimation[i].pitch << " but actual is pitch " << actualEstimation[i].pitch << " for a tolerance of " << tolerance << '\n';
        }
    }

    std::cout << "Class AttitudeEstimator " << ((failed==false)?"PASSED":"FAILED") << " its test\n";
}
