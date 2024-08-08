#include<iostream>
#include<string.h>
#include<stdio.h>
using namespace std;

class Book
{
	private:
		int bookid;
		char title[20];
		float price;

	public:
		void displayBook()
	{
		cout << bookid << " " << title << " " << price << endl;
	}

		void inputBook()
	{
		cout << "Enter Bookid, Title and Price : ";
		cin >> bookid;
		cin.ignore();
		cin.getline(title,20);
		cin >> price;
	}	


};

	int main()
{
		Book b1;
		b1.displayBook();
		b1.inputBook();
		b1.displayBook();
}

