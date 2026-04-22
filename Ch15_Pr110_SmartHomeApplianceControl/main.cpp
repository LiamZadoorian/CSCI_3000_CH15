#include <iostream>
#include <string>
using namespace std;

class Appliance {
    public:
        virtual void turnOn() = 0;
};

class Fan : public Appliance{
    public:
        void turnOn(){
            cout << "Fan starts rotating.\n";
        }
};

class AC : public Appliance{
    public:
        void turnOn(){
            cout << "Air Conditioner starts cooling.\n";
        }
};

int main(int argc, const char * argv[]) {
    
    Fan fan;
    AC ac;
    
    fan.turnOn();
    ac.turnOn();
    
    return 0;
}
