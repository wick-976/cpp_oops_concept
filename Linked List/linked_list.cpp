#include <bits/stdc++.h>
using namespace std;

class Car {
public:
    string name;
};

int main() {

 
    Car c1;

    c1.name = "Ford";
    Car* pointer = &c1;
    cout << c1.name << endl;

    // Access name using the pointer
    cout << pointer->name << endl;

    return 0;
}