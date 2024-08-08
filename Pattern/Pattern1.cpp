#include<iostream>
using namespace std;
class Pattern1
{
	private:
		int i,j;
	public:
		void Patt1()
	{
		  for(i=1;i<=5;i++){
		     for(j=1;j<=5;j++){
			if(i>=j){cout<<"*";}
				else{cout<<" ";}	
			}
 		cout<<"\n";
		}
	}	

};
int main()
{
   Pattern1 p1;
   p1.Patt1();
}
