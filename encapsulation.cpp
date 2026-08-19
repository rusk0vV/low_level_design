#include <iostream>
#include <string>

using namespace std;

// real life car

class SportsCar {
    
private:
    string brand;
    string model;
    bool isEngineOn;
    int currSpeed;
    int currGear;
    string tyre;

public:
    SportsCar(string b, string m) {
        this->brand = b;
        this->model = m;
        isEngineOn = false;
        currSpeed = 0;
        currGear = 0;
        tyre = "MRF";
    }

    void startEngine() {
        isEngineOn = true;
        cout << brand << " " << model << " : Engine starts with a roar" << endl;
    }

    // getters and setters

    int getCurrSpeed() {
        return this->currSpeed;
    }

    string getTyre() {
        return this->tyre;
    }

    void setTyre(string tyre) {
        // validations
        this->tyre = tyre;
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
    SportsCar* c1 = new SportsCar("Ford", "Mustang");
    c1->startEngine();
    c1->shiftGear(1);
    c1->accelerate();
    c1->shiftGear(2);
    // c1->currSpeed(200) this line will now give an error
    c1->accelerate();
    c1->shiftGear(1);
    c1->brake();
    c1->stopEngine();
}