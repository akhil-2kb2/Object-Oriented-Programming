#include<iostream>
#include<list>
#include<string>

using namespace std;


class RamSita {
	public:
	string name;
	string OwnerName;
	int SubscribersCount;
	list<int>PublishedVideoNo;

};

	int main() {
	
	RamSita RS; 
	RS.name ="ramsita";
	RS.OwnerName = "RAM";
	RS.SubscribersCount = 1800;
	//RS.PublishedVideoNo ={"101", "102", "103", "104", "105"};
        RS.PublishedVideoNo ={101, 102, 103, 104, 105};

	cout << "Name: " << RS.name << endl; 
	cout << "OwnerName: "<<RS.OwnerName << endl;
	cout << "SubscribersCount:" << RS.SubscribersCount << endl;
	cout << "Video:" << endl;
	for(int videoNo : RS.PublishedVideoNo) {
	
	cout << videoNo << endl;
	}
}
