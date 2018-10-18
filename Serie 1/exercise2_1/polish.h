#include <iostream>
#include <vector>
using namespace std;


class polish {
    vector<int> stack;

    void do_operation(string op);
    void sum();
    void subtract();
    void divide();
    void multiply();
    void mymin();
    void print_stack();

    int pop();
    void push(int n);

    public:
    void start();



};