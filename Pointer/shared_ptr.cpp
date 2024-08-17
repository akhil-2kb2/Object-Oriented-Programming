#include<iostream>
using namespace std;

class Tyre
{
    public:
        void doRepair(){}
};
class Car
{
    private:
        shared_ptr<Tyre> Wheel1;
    public:
        Car()
        {
            Wheel1 = make_shared<Tyre>();
           // Wheel1 = make_shared(new Tyre())
        }
        
    
        shared_ptr<Tyre>getWheel1()
        {
            cout<<"Wheel1 is repaired"<<endl;
            return Wheel1;
        }
};
int main()
{
    Car car1;
    shared_ptr<Tyre>Wheel1(car1.getWheel1());
    
    
    
    /*shared_ptr<int> p1(new int(10));// shared_ptr<int> p1 = make_shared<int>(10);
    shared_ptr<int> p2;// shared_ptr<int> p2 = p1;
    p2 = p1;// shared_ptr<int> p2(p1);
    cout<<*p1<<endl;
    cout<<*p2<<endl;
    cout<<p1.use_count()<<endl;
    cout<<p2.use_count()<<endl;
    cout<<p1.get()<<endl;// get() returns the address of the memory location
    cout<<p2.get()<<endl; // both p1 and p2 are pointing to the same memory location
    p1.reset();// p1 is now nullptr
    cout<<p1.use_count()<<endl;// 0
    cout<<p2.use_count()<<endl;// 1
    cout<<p1.get()<<endl;// nullptr
    cout<<p2.get()<<endl;// address of the memory location */
    cout<<endl;
    return 0;
}