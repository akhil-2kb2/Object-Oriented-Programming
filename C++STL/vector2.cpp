#include <iostream>
#include <vector>
using namespace std;

int main() {
	vector<int> v {10, 5, 20};
	
	for (int x : v) 
    {
      //  x = 5;
		cout << x << " ";
	}
	cout << endl;
	return 0;
}