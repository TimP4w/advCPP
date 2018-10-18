#include <iostream>
#include "ptrcounter.h"

using namespace std;

template <typename T>
class smart_pointer {

    T* obj;
    ptrcounter* count;

    public:

    // Constructor. Create counter and increase.
    smart_pointer(T *o) :
        obj(o), count(new ptrcounter)
    { 
        count->increase();
    }

    // Destructor. Decrease counter, if count is 0 then deallocate (both counter and object)
    ~smart_pointer() {
        count->decrease();
        if (count->counter() == 0) {
            delete obj;
            delete count;
        }
    }

    // Copy and increase counter.
    smart_pointer(const smart_pointer &p2) {
        obj = p2.obj;
        count = p2.count;

        count->increase();
    } 

    // Overload = operator. Decrease previous counter and if reaches 0, deallocate counter (but leave object?)
    smart_pointer<T>& operator=(const smart_pointer<T>& p2) {

        obj = p2.obj;
        count->decrease();
        if(count->counter() == 0) {
            delete obj;
            delete count;
        }
        count = p2.count;

        count->increase();

        return *this;  // return to allow chaining
    }

    // Overload ->
    T* operator->() {
        return obj;
    }

    // Overload *
    T& operator*() {
        return *obj;
    }

    // Get counter value
    int counter(void) {
        return count->counter();
    }
};
