#ifndef CAR_H
#define CAR_H

#include "Vehicle.h"
#include <string>
#include <iostream>

class Car : public Vehicle {
    public:
    Car(std::string m);
    std::string getModel() override;
    std::string getIssueType();
    void diagnose() override;
    int RepairCost() override;
    
private:
    std::string issuetype;
    int repairCost = 0;
    std::string displayModel;


};

#endif
