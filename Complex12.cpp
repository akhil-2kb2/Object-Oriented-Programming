#include<iostream>
using namespace std;
class Complex12
{
	private:
	  int a,b;
	  const int k;
	public:
	  Complex12():a(0), b(0), k(1)
		{}
	  Complex12(int x):a(x), b(0), k(2)
		{}
	  Complex12(int a, int b, int k):a(a), b(b), k(k)
		{}
	  Complex12(Complex12 &C):k(2)  //Copy Constructor
	  {
	    a=C.a;
		b=C.b;
	  }
	  ~Complex12(){}  //Destructor
	  void setData(int, int);
	  void showData();
	  Complex12 add(Complex12);
};
	  void Complex12::setData(int x, int y)
{
	  a=x;
	  b=y;
	  //k=z;
}
	  void Complex12::showData()
{
	  cout<<"\na="<<a<<" b="<<b<<" k="<<k;
}
	  Complex12 Complex12::add(Complex12 C)
{
	  Complex12 temp(0, 0, 0);
	  temp.a=a+C.a;
	  temp.b=b+C.b;
	  return temp;
}
   int main()
{
	  Complex12 C1(1, 2, 10),C2(3),C3;
	  Complex12 C4 = C1;
	 // C1.setData(3, 4);
	 // C2.setData(5, 6);
	 // C3=C1.add(C2);
	  C1.showData();
	  C2.showData();
	  C3.showData();
	  cout<<endl;
	  return 0;
}
