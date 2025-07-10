#include <iostream>
#include <string>
#include <limits>
#include <vector>
#include <cstdlib>
#include <ctime>
#include<thread>
#include <chrono>
#include "car.h"
#include "mechanic.h"

int main() {
    std::srand(std::time(nullptr));

    std::vector<std::string> carModels = {"lexus","toyota","mercedes","bmw","ferrari","bugatti","porche","camry","honda"};
    std::string mechanicNames[]= {"John", "Siju", "Emmanuel"};
  
    
    std::cout << " Car Breakdown Simulation\n";

    char more;
    do {
        std::cout <<"\nAvailable car models: \n";
        for (const auto& model : carModels) {
            std::cout << "- " << model << "\n";
        }




    std::cout << "Enter your car model: ";
    std::string model;
    std::cin >> model;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    Car myCar(model);                  
    Mechanic repairGuy(mechanicNames[std::rand() % 3]);

    std::cout << "Assigned mechanic: " << repairGuy.getName() << "\n";


    repairGuy.inspect(&myCar);

    
    std::cout << "\n" << myCar.getModel() << " is ready to hit the road again!\n"; 

    std::cout<< "\nRepair completed! Do you want to repair another car? (y/n): ";
    std::cin >> more;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    }while (more == 'y' || more == 'Y');

    std::cout << "Thank you for using the Car Breakdown Simulation!\n";

    // Simulate a delay to keep the console open for a while
    std::cout << "Exiting in 10 seconds...\n";
    
    

    std::this_thread::sleep_for(std::chrono::seconds(10));

    return 0;
}