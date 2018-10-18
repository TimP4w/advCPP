#include <iostream>
using namespace std;

template <typename T>
class dumb_pointer {
    T* obj;

    public:
    dumb_pointer(T *o) :
        obj(o)
    { /*void*/ }

    // Overload -> operator. 
    T* operator->() {
        return obj;
    }
    //Overload * operator.
    T& operator*() {
        return *obj;
    }

    friend ostream &operator<<(ostream &os, dumb_pointer &ptr) {
        os << ptr.obj;
        return os;
    }

};
