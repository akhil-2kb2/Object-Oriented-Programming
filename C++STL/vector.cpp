#include<iostream>
#include<vector>
using namespace std;

class MyVector {
private:
    vector<int> v;

public:
    void addElement(int element) {
        v.push_back(element);
    }

    void printElements() {
        for(int i = 0; i < v.size(); i++) {
            cout << v[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    MyVector myVector;
    myVector.addElement(10);
    myVector.addElement(5);
    myVector.addElement(20);
    myVector.printElements();

    return 0;
}