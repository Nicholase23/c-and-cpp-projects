#include <iostream>
#include <string>

using namespace std;

// Base Class
class ElectronicDevice {
protected:
    string brand;
    string model;
    bool powerOn;

public:
    // Constructor
    ElectronicDevice(const string& brand, const string& model) : brand(brand), model(model), powerOn(false) {}

    // Method to turn on the device
    void turnOn() {
        powerOn = true;
    }

    // Method to turn off the device
    void turnOff() {
        powerOn = false;
    }
};

// Derived Class
class Television : public ElectronicDevice {
protected:
    double screenSize;
    string resolution;

public:
    // Constructor
    Television(const string& brand, const string& model, double screenSize, const string& resolution)
            : ElectronicDevice(brand, model), screenSize(screenSize), resolution(resolution) {}

    // Method to display television information
    void displayInfo() {
        cout << "Television Information:" << endl;
        cout << "Brand: " << brand << endl;
        cout << "Model: " << model << endl;
        cout << "Power State: " << (powerOn ? "On" : "Off") << endl;
        cout << "Screen Size: " << screenSize << " inches" << endl;
        cout << "Resolution: " << resolution << endl;
    }
};

int main() {
    // Create an instance of the Television class
    Television tv("Samsung", "Smart TV", 55.0, "4K");

    // Turn on the television
    tv.turnOn();

    // Display television information
    tv.displayInfo();

    cout << endl;

    // Turn off the television
    tv.turnOff();

    // Display television information after turning off
    tv.displayInfo();

    return 0;
}
