 #include<iostream>
using namespace std;
class Item
{
    private:
        int a,b; // Instance Variables
        static int k; // static member variable | class Variable
    public:
        void set_a(int x) { a=x;} //Instance Method
        void set_b(int y) { b=y;} //Instance Method 
        int get_a() { return a; } //Instance Method
        int get_b() { return b; } //Instance Method
        static void set_k(int m) { k=m;} //static Method
        static int get_k() { return k; } //static Method
};
        int Item::k; //defining static member variable
    int main()
{
    Item i1,i2;
    i1.set_a(5);
    i2.set_a(102);
    cout<<i2.get_a()<<endl;
    cout<<i1.get_a()<<endl;
    Item::set_k(10);
    cout<<"k="<<Item::get_k();
    cout<<endl;
    return 0;
}
