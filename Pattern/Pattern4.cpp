#include<iostream>
using namespace std;
class Pattern4
{
	private:
	   int i, j;
	public:
	   Pattern4()//Here We are printing pattern using Constructor!
	   {
		for(i=1;i<=5;i++)
		{
		   for(j=1;j<=9;j++)
		   {
			if(j>=6-i&&j<=4+i){cout<<"*";}
			else{cout<<" ";}
		   }
		cout<<"\n";
		}
	   }
};
int main()
{
	Pattern4 c1;
//	c1.pattern4();
	return 0;
}
