#include "car.h"
#include <algorithm>
#include <iostream>
#include <map>
#include <limits>
#include <thread>
#include <chrono>
 
Car::Car(std::string m) : Vehicle(m) {
    std::transform(model.begin(), model.end(), model.begin(), ::tolower);
    displayModel = model;

}

std::string Car::getModel() {
    return displayModel;
}

std::string Car::getIssueType() {
    return issuetype;
}


int Car::RepairCost() {
    return repairCost;
}


void Car::diagnose() {
    std::cout << "\n Mechanic: What Issue are u having with your car?\n";
    std::cout <<"Options : engine, brakes, transmission, battery, carbody\n";
    std::cout << "Driver : ";
    std::cin >> std::ws;
    std::getline(std::cin , issuetype);

        std::transform(issuetype.begin(), issuetype.end(), issuetype.begin(), [](unsigned char c) {
        return std::tolower(c);
    });




    std::map<std::string, int> issueCost = {
        {"engine", 50000 }, 
        {"brakes", 20000},
        {"transmission", 40000},
        {"battery", 20000},
        {"carbody", 15000}
    };

    std::cout << "Diagnosing;...";
    for (int i = 0; i < 3; ++i) {
        std::this_thread::sleep_for(std::chrono::milliseconds(700)); // Simulate a delay for diagnosis
        std::cout << ".";
        std::cout.flush();
    }
    std::cout << "\n";

    int baseCost = issueCost.count(issuetype) ? issueCost[issuetype] : 10000;

    if (model == "lexus") baseCost *= 0.9;
    else if (model == "toyata") baseCost *= 1.5;
    else if (model == "mercedes") baseCost *= 2;
    else if (model == "bmw") baseCost *= 2.5;
    else if (model == "ferrari") baseCost *= 3;
    else if (model == "bugatti") baseCost *= 1.5;
    else if (model == "porche") baseCost *= 1.2;
    else if (model == "camry") baseCost  *= 0.4;
    else if (model == "honda") baseCost *= 0.9;

    repairCost = static_cast<int>(baseCost);
    
    
    if (issueCost.find(issuetype ) != issueCost.end()){
        repairCost = issueCost[issuetype];
        std::cout << "Diagnosed: " <<issuetype << " issue.\n";
    }else{
        repairCost = 10000;
        std::cout << "Processing.... Charging base cost of 10000.\n";


        
    
    }

}

