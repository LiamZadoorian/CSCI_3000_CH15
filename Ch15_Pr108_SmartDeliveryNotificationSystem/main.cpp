#include <iostream>
#include <string>
using namespace std;

class Notification{
    public:
        virtual void sendMessage(){
            cout << "Sending General Notification\n";
        }
};

class Email : public Notification {
    public:
        void sendMessage(){
            cout << "Sending Email Notification\n";
        }
};

class SMS : public Notification {
    public:
        void sendMessage(){
            cout << "Sending SMS Notification\n";
        }
};

int main(int argc, const char * argv[]) {
    
    Notification *notif_pntr;
    
    Email email;
    SMS sms;
    
    notif_pntr = &email;
    notif_pntr -> sendMessage();
    
    notif_pntr = &sms;
    notif_pntr -> sendMessage();
    
    return 0;
}
