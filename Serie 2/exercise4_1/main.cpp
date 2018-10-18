#include <iostream>
#include "pvector.h"
#include "pset.h"

using namespace std;


void foo(pvector<int> pv) {
    if(pv.size()>0) cout << pv[0] << endl;
    pv.push_back(17);
}

int main(int argc, char *argv[]) {
    pvector<int> pvi("pvector-int.txt");
    //foo(pv);
    pvi.push_back(10);
    pvi.push_back(20);
    pvi.print();
    pvi.pop_back();
    pvi.print();

    pvector<string> pvs("pvector-str.txt");
    pvs.push_back("Hello World");
    pvs.push_back("Another String");
    pvs.print();


    pset<int> psi("pset-int.txt");
    psi.insert(10);
    psi.insert(20);
    psi.print();
    psi.erase(10);
    psi.print();


    pset<string> pss("pset-str.txt");
    pss.insert("Hello World");
    pss.insert("Another String");
    pss.print();

}