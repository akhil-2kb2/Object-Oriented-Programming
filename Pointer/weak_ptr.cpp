#include<iostream>
using namespace std;
class B;
class A
{
    public:
        weak_ptr<B> p1;
       // shared_ptr<B> p1;// du to shared_ptr, it will not be destroyed until the last reference is destroyed
        void set_ptr(shared_ptr<B> &ptr1)
        {
            p1 = ptr1;
        }
    ~A()
    {
        cout<<"A is destroyed"<<endl;
    }    
};  
class B
{
    public:
        weak_ptr<A> p2;
       // shared_ptr<A> p2;
        void set_ptr(shared_ptr<A> &ptr2)
        {
            p2 = ptr2;
        }
    ~B()
    {
        cout<<"B is destroyed"<<endl;
    }
};
void f1()
{
    shared_ptr<A> objAptr(new A());
    shared_ptr<B> objBptr(new B());
    objAptr->set_ptr(objBptr);
    objBptr->set_ptr(objAptr);  
    cout<<objAptr.use_count()<<endl;
    cout<<objBptr.use_count()<<endl;
}
int main()
{
   f1();
   
  /*shared_ptr<int> p1(new int(10));
   weak_ptr<int> p2= p1;
    cout<<*p1<<" "<<*(p2.lock())<<endl;
    //cout<<p2.use_count()<<endl;
    p2.reset();
    cout<<p1.use_count()<<endl;
    cout<<p2.use_count()<<endl;*/
    cout<<endl;
    return 0;
}