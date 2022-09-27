/**
 * @file test-write-attitude-estimation-file.cpp
 * @author Lucas Camargo da Silva (lucas.camargodasilva@hotmail.com)
 * @brief Program to test the writeAttitudeEstimationFile function
 * @date 2022-09-27
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <iostream>
#include <sstream>
#include "attitude-estimation.h"

int main(int argc, char *argv[]) {
    // Create three dummy attitude estimations
    std::vector<AttitudeEstimation> expectedEstimationData;
    expectedEstimationData.push_back(AttitudeEstimation(54741, 3.0495318, -0.4775673));
    expectedEstimationData.push_back(AttitudeEstimation(54751, -3.1194413,-0.0231523));
    expectedEstimationData.push_back(AttitudeEstimation(54761, -3.1215151,-0.0251658));
    
    // Write output file
    std::string attitudeEstimationFilePath = "dummy_attitude_estimation_data.log";
    writeAttitudeEstimationFile(expectedEstimationData, attitudeEstimationFilePath);

    // Create a stream to read from the file containing the attitude estimation data
    std::ifstream attitudeEstimationDataFile(attitudeEstimationFilePath);
    if (!attitudeEstimationDataFile) {
        std::cout << "Could not open " << attitudeEstimationFilePath << std::endl;
        return 0;
    }

    // Read, parse and store the attitude estimation data
    std::string line;
    std::string time_stamp_ms, roll, pitch;
    std::vector<AttitudeEstimation> actualEstimationData;
    while(std::getline(attitudeEstimationDataFile,line)){
        std::istringstream attitudeEstimationDataStream(line);

        std::getline(attitudeEstimationDataStream,time_stamp_ms,';');
        std::getline(attitudeEstimationDataStream,roll,';');
        std::getline(attitudeEstimationDataStream,pitch,';');

        actualEstimationData.push_back(AttitudeEstimation(stoi(time_stamp_ms),stod(roll),stod(pitch)));
    }

    // Check if the expected attitude estimation data is equal to the actual attitude estimation data written by writeAttitudeEstimationFile
    bool failed = false;
    if (actualEstimationData != expectedEstimationData) {
        failed = true;
    }

    std::cout << "Function writeAttitudeEstimationFile " << ((failed==false)?"PASSED":"FAILED") << " its test\n";
}