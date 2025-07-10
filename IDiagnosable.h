#ifndef IDIAGNOSABLE_H
#define IDIAGNOSABLE_H

class IDiagnosable {
public:
    virtual void diagnose() = 0; // Pure virtual function for diagnosing issues
    virtual int RepairCost() = 0; // Pure virtual function to get the cost of repairs
    virtual ~IDiagnosable() = default; // Virtual destructor for proper cleanup of derived classes
};
#endif 