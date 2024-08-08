#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;
 struct Book
{                          
	unsigned int Bookid;
	char title[20];
	float price;
	void displayBook()
	{
		cout << Bookid << " " << title << " " << price << endl;
	}	
	void inputBook()
	{
	cout << "Enter Bookid, title and price:";
	cin >> Bookid;
	cin.ignore();
	cin.getline(title, 20);
	cin >> price;
}
};	
	int main()
{
	Book b1={1, "Drilling C",345.0}, b2 = {2, "Leaning C++", 123.0};
	Book b3;
/*	b2.Bookid = 2;
	strcpy(b2.title, "Hello World!");
	b2.price = 275.0;	*/
	b3.inputBook();
//	b1.displayBook();
	b3.displayBook();
//	b2.displayBook();
/*	cout << "Maximum value of type double is " << numeric_limits<double>::max() << endl;
	 cout << "The range for type short is from "
         << numeric_limits<short>::min() << " to "
         << numeric_limits<short>::max() << endl;
    cout << "The range for type int is from "
         << numeric_limits<int>::min() << " to "
         << numeric_limits<int>::max() << endl;
    cout << "The range for type long is from "
         << numeric_limits<long>::min() << " to "
         << numeric_limits<long>::max() << endl;
    cout << "The range for type float is from "
         << numeric_limits<float>::min() << " to "
         << numeric_limits<float>::max() << endl;
    cout << "The positive range for type double is from "
         << numeric_limits<double>::min() << " to "
         << numeric_limits<double>::max() << endl;
    cout << "The positive range for type long double is from "
         << numeric_limits<long double>::min() << " to "
         << numeric_limits<long double>::max() << endl;

	return 0;*/
   }
