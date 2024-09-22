#include <iostream>
#include <string>

// Abstract class
class Appliance {
protected:
    std::string brand;
    int powerUsage; // Wattage

public:
    // Constructor
    Appliance(const std::string& b, int p) : brand(b), powerUsage(p) {
        std::cout << "Appliance constructor called\n";
    }

    // Destructor
    virtual ~Appliance() {
        std::cout << "Appliance destructor called\n";
    }

    // Function for subclasses
    virtual void displayInfo() const = 0;
};

// Subclass: Washing machine
class WashingMachine : public Appliance {
private:
    int drumSize; // Drum size in liters

public:
    // Constructor for WashingMachine's attributes along with the Appliance's attributes
    WashingMachine(const std::string& b, int p, int d) : Appliance(b, p), drumSize(d) {
        std::cout << "WashingMachine constructor called\n";
    }

    // Overriding function
    void displayInfo() const override {
        std::cout << "WashingMachine Info:\n";
        std::cout << "Brand: " << brand << "\n";
        std::cout << "Power Usage: " << powerUsage << " watts\n";
        std::cout << "Drum Size: " << drumSize << " liters\n";
    }

    // Destructor
    ~WashingMachine() {
        std::cout << "WashingMachine destructor called\n";
    }
};

// Subclass: Refrigerator
class Refrigerator : public Appliance {
private:
    int capacity; // Capacity in liters

public:
    // Constructor for Refrigerator attributes along with Appliance's attributes
    Refrigerator(const std::string& b, int p, int c) : Appliance(b, p), capacity(c) {
        std::cout << "Refrigerator constructor called\n";
    }

    // Overriding function
    void displayInfo() const override {
        std::cout << "Refrigerator Info:\n";
        std::cout << "Brand: " << brand << "\n";
        std::cout << "Power Usage: " << powerUsage << " watts\n";
        std::cout << "Capacity: " << capacity << " liters\n";
    }

    // Destructor
    ~Refrigerator() {
        std::cout << "Refrigerator destructor called\n";
    }
};

int main() {
    // Polymorphism
    Appliance* appliances[2];

    // Creating objects of derived classes
    appliances[0] = new WashingMachine("LG", 500, 50);
    appliances[1] = new Refrigerator("Samsung", 300, 200);

    // Calling the overridden methods through base class pointer
    appliances[0]->displayInfo();
    appliances[1]->displayInfo();

    // Deleting objects, which will call destructors in proper order
    delete appliances[0];
    delete appliances[1];

    return 0;
}