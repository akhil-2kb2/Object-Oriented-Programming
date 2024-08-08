#include<iostream>
using namespace std;
class Pattern3
{
	private:
	  int i,j;
	public:
	  void Patt3()
	{
		for(i=1;i<=5;i++)
	  {
		for(j=1;j<=5;j++)
	     {
	     	if(j>=i){cout<<"*";}
                else{cout<<" ";}
	     }
	     cout<<"\n";
	  }
	}
};
int main()
{
	Pattern3 c1;
	c1.Patt3();
	return 0;
}
