#include<iostream>
using namespace std;
class Complex
{
	private: 
	    int a,b; // instance member variables [obj member var]
	public:
	    void setData(int x, int y);
	    void showData();	
	    Complex add(Complex C);

	
	Complex(int x, int y)
 	{
	   a=x;
	   b=y;
	}
};
	    void Complex::setData(int x, int y)
	{
		a=x;
		b=y;
	}
	    void Complex::showData()
	{
		cout << "a = "<< a << " AND" << " b = " << b << endl;
	}
	    Complex Complex::add(Complex C)
	{
		Complex temp(0,0);
		temp.a=a+C.a;
		temp.b=b+C.b;
		return temp;
	}
int main()
{
	Complex c1(1,2),c2(11,10),c3(14,15);
	c1.setData(100, 102);
	c2.setData(200, 202);
	c3=c1.add(c2);
	c3.showData();
	cout<<endl;
	return 0;
}
