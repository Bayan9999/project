#include "Vehicle.h"

//Vehicle::Vehicle(std::string m) : model(m), repairCost(0), issuetype("unknown") {}

void Vehicle::diagnose() {
    // Optionally empty; will be overridden in Car
}

std::string Vehicle::getModel() {
    return model;
}
