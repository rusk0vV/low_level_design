#include <iostream>
#include <string>

using namespace std;

// real life car

class Car {
public:
    virtual void startEngine() = 0;
    virtual void shiftGear(int gear) = 0;
    virtual void accelerate() = 0;
    virtual void brake() = 0;
    virtual void stopEngine() = 0;
    virtual ~Car() {} // <- this is a destructor line command
};

class SportsCar : public Car {
    
public:
    string brand;
    string model;
    bool isEngineOn;
    int currSpeed;
    int currGear;

    SportsCar(string b, string m) {
        this->brand = b;
        this->model = m;
        isEngineOn = false;
        currSpeed = 0;
        currGear = 0;
    }

    void startEngine() {
        isEngineOn = true;
        cout << brand << " " << model << " : Engine starts with a roar" << endl;
    }

    void shiftGear(int gear) {
        if(!isEngineOn) {
            cout << brand << " " << model << " : Engine is off. Cannot shift gear!" << endl;
            return; 
        }
        currGear = gear;
        cout << brand << " " << model << " : Shift to gear " << currGear << endl;
    }

    void accelerate() {
        if(!isEngineOn) {
            cout << brand << " " << model << " : Engine is off. Cannot accelerate!" << endl;
            return; 
        }
        currSpeed += 20;
        cout << brand << " " << model << " : Speed changed to " << currSpeed << endl;
    }

    void brake() {
        if(!isEngineOn) {
            cout << brand << " " << model << " : Engine is off. Cannot brake!" << endl;
            return; 
        }
        currSpeed -= 20;
        cout << brand << " " << model << " : Speed changed to " << currSpeed << endl;
    }

    void stopEngine() {
        if(!isEngineOn) {
            cout << brand << " " << model << " : Engine already shut down" << endl;
            return;
        }
        isEngineOn = false;
        cout << brand << " " << model << " : Engine shut down" << endl;
    }
}; 

int main() {
    Car* c1 = new SportsCar("Ford", "Mustang");
    c1->startEngine();
    c1->shiftGear(1);
    c1->accelerate();
    c1->shiftGear(2);
    c1->accelerate();
    c1->shiftGear(1);
    c1->brake();
    c1->stopEngine();
}