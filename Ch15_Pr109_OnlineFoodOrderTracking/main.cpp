#include <iostream>
#include <string>
using namespace std;

class OrderStatus{
    public:
        virtual void showStatus(){
            cout << "Order is undecided\n";
        }
    
};

class Preparing : public OrderStatus{
    public:
        void showStatus(){
            cout << "Order is being prepared\n";
        }
};

class OutForDelivery : public OrderStatus{
    public:
        void showStatus(){
            cout << "Order is out for delivery\n";
        }
};

class Delivered : public OrderStatus{
    public:
        void showStatus(){
            cout << "Order has been delivered\n";
        }
};

int main(int argc, const char * argv[]) {
    
    OrderStatus *stat_pntr;
    
    Preparing prep;
    OutForDelivery ofd;
    Delivered dlvrd;
    
    stat_pntr = &prep;
    stat_pntr->showStatus();
    
    stat_pntr = &ofd;
    stat_pntr->showStatus();
    
    stat_pntr = &dlvrd;
    stat_pntr->showStatus();
    
    return 0;
}
