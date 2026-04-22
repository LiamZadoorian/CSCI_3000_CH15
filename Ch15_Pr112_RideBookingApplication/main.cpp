#include <iostream>
#include <string>
using namespace std;

class Ride {
    public:
        virtual void bookRide() = 0;
};

class Bike : public Ride {
    public:
        void bookRide(){
            cout << "Bike ride booked successfully\n";
        }
};

class Car : public Ride {
    public:
        void bookRide(){
            cout << "Car ride booked successfully\n";
        }
};

int main(int argc, const char * argv[]) {
    
    Ride *rd_pntr;
    
    Bike bike;
    Car car;
    
    rd_pntr = &bike;
    rd_pntr->bookRide();
    
    rd_pntr = &car;
    rd_pntr->bookRide();
    
    return 0;
}
