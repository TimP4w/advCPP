#include <iostream>
using namespace std;

class Object {
    int val;

    friend ostream &operator<<(ostream &os, Object o);

    public:
    Object(int n) : val(n)
    { /* */ }

    string method1();
    string method2();
    string method3();

    


};