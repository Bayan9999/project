#ifndef Mechanic_H
#define Mechanic_H

#include "car.h"
#include "IDiagnosable.h"
#include <string>

class Mechanic {
private:
    std::string name;

public:
    Mechanic(std::string mechanicName);

    // to get the niggas name(mechanic)
    std::string getName() const;
    
    void inspect(Car* car);

};
#endif