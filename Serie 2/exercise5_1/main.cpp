#include <iostream>
#include "dumb_pointer.h"
#include "smart_pointer.h"
#include "object.h"
#include <vector>

using namespace std;

void print(smart_pointer<Object> p) { cout << p.counter() << ": " << *p << endl; }

void foo() {
    Object *o1=new Object(1); // let's create our 1st object
    Object *o2=new Object(2); // let's create our 2nd object

    smart_pointer<Object> p(o1); // ref counter is 1 for 1st object
    cout << p.counter() << endl; // displays 1
    smart_pointer<Object> q(p); // another smart pointer that points to o1 (overload copy constructor)
    cout << p.counter() << endl; // displays 2 (two smart pointers refer to o1)
    cout << q.counter() << endl; // displays 2 (two smart pointers refer to o1)


    smart_pointer<Object> r(o2); // ref counter is 1 for 2nd object
    cout  << r.counter() << endl; // displays 1

    q=r; // decrease counter for 1st object and
    // increase counter for 2nd object (overload assignment operator)

    cout  <<  p.counter() << endl; // displays 1
    cout  <<  q.counter() << endl; // displays 2
    cout  <<  r.counter() << endl; // displays 2

    print(p); // displays 2, and the 1st object, don't delete the object pointed to by p
    print(q); // displays 3, and the 2nd object, don't delete the object pointed to by q
    print(r); // displays 3, and the 2nd object, don't delete the object pointed to by r


    cout << *q << *r << endl; // << *r << endl; // display 1st and 2nd object (overload operator*)
    cout << p->method1() << q->method2() << r->method3() << endl;
    // invoke method1 on 1st object and
    // invoke method2 on 2nd object and
    // invoke method3 on 2nd object (overload operator->)


} // now the destructors of p, q, and r are called, make sure that 1st
// and 2nd object is each deleted once (i.e., when the counter reaches 0)


int main(int argc, char *argv[]) {

    int n = 20;
    int *i;
    i = &n;
    dumb_pointer<int> dp(&n);
    
    cout << "========== DUMB POINTER TEST ============" << endl;

    cout << "==== N ====" << endl;
    cout << &n << endl;
    cout << n << endl;

    cout << "==== Dumb Pointer ====" << endl;
    cout << &dp << endl;
    cout << dp << endl;

    cout << "==== Normal Pointer ====" << endl;
    cout << &i << endl;
    cout << i << endl;



    cout << "============= Change Value ==============" << endl;
    
    *dp = 23;

    cout << "==== N ====" << endl;
    cout << &n << endl;
    cout << n << endl;

    cout << "==== Dumb Pointer ====" << endl;
    cout << &dp << endl;
    cout << dp << endl;

    cout << "==== Normal Pointer ====" << endl;
    cout << &i << endl;
    cout << i << endl;

    cout << "==== N ====" << endl;
    cout << &n << endl;
    cout << n << endl;

    cout << "============= Test with Object ==============" << endl;

    Object *do1 = new Object(1);
    dumb_pointer<Object> dpo(do1);
    cout << dpo->method1() << endl;

    cout << "========== END DUMB POINTER TEST ============" << endl;


    cout << "========== SMART POINTER TEST ============" << endl;

    foo();

    cout << "========== END SMART POINTER TEST ============" << endl;


}

