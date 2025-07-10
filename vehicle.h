// abstract base class

#ifndef VEHICLE_H
#define VEHICLE_H
#include <string>
#include "IDiagnosable.h"

class Vehicle : public IDiagnosable {
    protected:
    std::string model;
    std::string issuetype;
    int repairCost;

    public:
    Vehicle(std::string m) :model(m){}
    virtual void diagnose() = 0;
    virtual std::string getModel() = 0;
    virtual ~Vehicle() = default; // Virtual destructor for proper cleanup of derived classes

};

#endif