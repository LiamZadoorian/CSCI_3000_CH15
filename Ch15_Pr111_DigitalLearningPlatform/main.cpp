#include <iostream>
#include <string>
using namespace std;

class Course {
    public:
        virtual void startClass() = 0;
};

class Programming : public Course{
    public:
        void startClass(){
            cout << "Programming class has started\n";
        }
};

class Math : public Course{
    public:
        void startClass(){
            cout << "Math class has started\n";
        }
};

int main(int argc, const char * argv[]) {
    
    Course *crs_pntr;
    
    Programming prgm;
    Math math;
    
    crs_pntr = &prgm;
    crs_pntr->startClass();
    
    crs_pntr = &math;
    crs_pntr->startClass();
    
    return 0;
}
