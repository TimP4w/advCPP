#include <iostream>
#include "object.h"

using namespace std;


string Object::method1() {
    return "This is method 1";
}
string Object::method2() {
    return "This is method 2";
}
string Object::method3() {
    return "This is method 3";
}
// Overload << in order to "print" the object
ostream &operator<<(ostream &os, Object o) {
    os << o.val;
    return os;
}
