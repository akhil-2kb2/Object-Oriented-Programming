#include<iostream>
using namespace std;

void f1()
{
    //int *p = new int(10);
    unique_ptr<int> p1(new int(10));
    //unique_ptr<int> p2 = move(p1);
    unique_ptr<int> p2 ;

    cout<<*p1<<endl; 
    p2 = std::move(p1); 

    if(p1 == nullptr)
        cout<<"p1 is nullptr || not an Owner"<<endl; 
    else
        cout<<*p1<<endl;
    cout<<*p2;
    //delete p;
}
int main()
{
    f1();
    cout<<endl;
    return 0;
}