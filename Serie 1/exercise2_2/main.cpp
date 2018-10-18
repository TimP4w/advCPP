#include <iostream>
#include "pvector.h"


using namespace std;


void foo(pvector<int> pv) {
    if(pv.size()>0) cout << pv[0] << endl;
    pv.push_back(17);
}

int main(int argc, char *argv[]) {
    pvector<int> pv("pvector-int.txt");
    foo(pv);
    pv.push_back(20);
    pv.push_back(21);
}