#include <iostream>
#include <vector>
#include <sstream>
#include "polish.h"
using namespace std;


void polish::start() {
    while(true) {
        cout << "Command: ";
        string command;
        if (getline(cin, command)){                                                                                                                                                                                                                                        
            istringstream iss(command);                                                                                                                                                                                                        
            while( iss >> command) {
                int n;
                if(command == "n") {
                    iss >> n;
                    polish::push(n);
                } else if (command == "d") {
                    polish::pop();
                } else if (command == "+" || command =="-" || command == "*" || command == "/" || command == "min") {
                    polish::do_operation(command);
                } else if (command == "q") {
                    return;
                } else {
                    cout << endl << "Command not valid. Aborting..." << endl;
                }
            }
            polish::print_stack();                                                                                                                                                                                                         
        }                                                                                                                                                                                                                                        
    }
}

void polish::do_operation(string op) {
    int a = polish::pop();
    int b = polish::pop();    

    if(op == "+") {
        polish::push(b+a);
    } else if (op == "-") {
        polish::push(b-a);       
    } else if (op == "*") {
        polish::push(b*a);
    } else if (op == "/") {
        if(a == 0) {
            cout << "Cannot divide by zero! Aborting..." << endl;
            return;
        }
        polish::push(b/a);
    } else if (op == "min") {
        polish::push(min(a,b));
    }
}

void polish::print_stack() {
    vector<int>::iterator fst = stack.begin(),
                                cur = fst,
                                lst = stack.end();
    while(cur != lst) {
        cout << *cur << endl;
        cur++;
    }

}

int polish::pop(){
    vector<int>::iterator fst = stack.begin(), lst = stack.end();
    if (fst == lst) {
        cout << "Cannot pop, stack empty!" << endl;
        return 0;
    }
    int n = *(lst-1);
    stack.erase(lst-1);
    return n;
}

void polish::push(int n){
    stack.push_back(n);
}


