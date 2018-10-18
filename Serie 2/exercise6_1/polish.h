#include <iostream>
#include <vector>
#include <sstream>
#include "pvector.h"

using namespace std;

template<typename T>
class polish {
    vector<T> stack;

    void do_operation(string op) {
        T a = polish::pop();
        T b = polish::pop();    

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

    void print_stack() {
        typename vector<T>::iterator fst = stack.begin(),
                                    cur = fst,
                                    lst = stack.end();
        while(cur != lst) {
            cout << *cur << endl;
            cur++;
        }

    }

    T pop() {
        typename vector<T>::iterator fst = stack.begin(), lst = stack.end();
        if (fst == lst) {
            cout << "Cannot pop, stack empty!" << endl;
            return 0;
        }
        T n = *(lst-1);
        stack.erase(lst-1);
        return n;
    }
    
    void push(T n) {
        stack.push_back(n);
    }



    public:
    void start() {
        pvector<T> pv("pstack.txt");
        stack = pv.get_vector();
        bool running = true;
        while(running) {
            cout << "Command: ";
            string command;
            if (getline(cin, command)){                                                                                                                                                                                                                                        
                istringstream iss(command);                                                                                                                                                                                                        
                while( iss >> command) {
                    T n;
                    if(command == "n") {
                        iss >> n;
                        polish::push(n);
                    } else if (command == "d") {
                        polish::pop();
                    } else if (command == "+" || command =="-" || command == "*" || command == "/" || command == "min") {
                        polish::do_operation(command);
                    } else if (command == "q") {
                        running = false;
                    } else {
                        cout << endl << "Command not valid. Aborting..." << endl;
                        running = false;
                    }
                }
                polish::print_stack();                                                                                                                                                                                                         
            }                                                                                                                                                                                                                                        
        }
        pv.set_vector(stack);
    }



};