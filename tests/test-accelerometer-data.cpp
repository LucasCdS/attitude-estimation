/**
 * @file test-accelerometer-data.cpp
 * @author Lucas Camargo da Silva (lucas.camargodasilva@hotmail.com)
 * @brief Program to test the class AccelerometerData
 * @date 2022-09-26
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <iostream>
#include <fstream>
#include "accelerometer-data.h"

int main(int argc, char *argv[]) {

    // Create dummy file to store attitude data to be read
    std::string testDataFilePath = "dummy_accelerometer_data.log";
    std::ofstream testDataFile;
    testDataFile.open(testDataFilePath);

    // Create three dummy attitude data readings
    std::vector<AccelerometerReading> expectedDataReadings;
    expectedDataReadings.push_back(AccelerometerReading(54741, 27, -22, -982));
    expectedDataReadings.push_back(AccelerometerReading(54751, 23, -22, -993));
    expectedDataReadings.push_back(AccelerometerReading(54761, 25, -20, -996));

    // Write the dummy data to the file
    if(testDataFile.is_open())
    {
        for(int i=0;i<expectedDataReadings.size();i++){
            testDataFile << expectedDataReadings[i].time_stamp_ms << "; " << expectedDataReadings[i].accel_x_axis << "; " << expectedDataReadings[i].accel_y_axis << "; " << expectedDataReadings[i].accel_z_axis << '\n';
        }
        testDataFile.close();
    }

    // Create an object of the AccelerometerData class and initialize it with the same file
    AccelerometerData accelerometerDataTester = AccelerometerData(testDataFilePath);
    std::vector<AccelerometerReading> actualDataReadings = accelerometerDataTester.getAccelerometerData();

    // Check if the expected dummy data is equal to the actual dummy data extracted by AccelerometerData
    bool failed = false;
    if (actualDataReadings != expectedDataReadings) {
        failed = true;
    }

    std::cout << "Class AccelerometerData " << ((failed==false)?"PASSED":"FAILED") << " its test\n";
}