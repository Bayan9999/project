#include "mechanic.h"
#include <iostream>
#include <fstream>
#include <map>
#include <iomanip>

Mechanic::Mechanic(std::string mechanicName) {
    name = mechanicName;
}

std::string Mechanic::getName() const{
    return name;
}

void Mechanic::inspect(Car* car){
    car->diagnose();

    std::map<std::string, int> repairTime = {
        {"engine",5}, {"brakes",2}, {"transmission",4},{"battery",1}, {"carbody",3}
    };

    std::string issue = car ->getIssueType();
    int time = repairTime.count(issue) ? repairTime[issue]: 2;
    int cost = car ->RepairCost();

    std::cout << "Estimated Repair Time:" << time << "hours\n";
    std::cout << "Estimated Repair Cost: " << std::fixed << std::setprecision(0) << cost << "\n";
    

    std::ofstream log("repair_log.txt", std::ios::app);
    log << "Mechanic: " << name << ", Model: " << car->getModel()
        << ", Issue: " << issue << ", Cost: ₦" << cost << "\n";
    log.close();
}