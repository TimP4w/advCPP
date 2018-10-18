#include <iostream>
#include <fstream>
#include "fraction.h"

using namespace std;

int main(int argc, char *argv[])  
{   
    if (argc == 2) {
        if (string(argv[1]) == "--test" || string(argv[1]) == "-t") {
            ifstream infile("testFractions.txt");
            fraction a, b, c, d;
            string op;
            int total = 0;
            int pass = 0;
            int fail = 0;
            while (infile >> a >> op >> b >> d)
            {
                if(op == "+") {
                    c = a+b;
                } else if(op == "-") {
                    c = a-b;
                } else if(op == "*") {
                    c = a*b;
                } else if(op == "/") {
                    c = a/b;
                } else {
                    cout << "unknown operator, aborting..." << endl;
                    return 1;
                }
                
                if (c == d) {
                    cout << a << op << b << "=" << d << " \033[1;32m (OK)\033[0m\n" << endl;
                    pass++;
                } else {
                    cout << a << op << b << "!=" << d << " \033[1;31m (FAIL)\033[0m\n" << endl;
                    fail++;
                }
                total++;
            }
            
            cout << "Evaluated " << total << " fractions " << endl;
            cout << "Passed: " << pass << " Failed: " << fail << endl;
            
        } else if(string(argv[1]) == "--help" || string(argv[1]) == "-h") {
            cout << "Usage: ./main [-t]" << endl;
            cout << "Optional arguments: " << endl;
            cout << "-h, --help : show this message and exit" << endl;
            cout << "-t, --test : test program with included dataset" << endl;
            cout << "simply don't use any arguments in order to use it normally" << endl;
        } else {
            cout << "Wrong flag. Use --help or -h for help." << endl;
        }
    } else if (argc > 2) {
        cout << "Too many arguments! Use --help for list of commands." << endl;
        return 0;
    } else {
        cout << "Sum, subtract, multiply or divide two fractions " << endl;

        fraction a, b, c;
        string op;
        
        cout << "Provide fraction a \"(numerator/denominator)\" "; cin >> a;
        cout << "Provide operation (+,-,*,/): "; cin >> op;
        cout << "provide fraction b \"(numerator/denominator)\": "; cin >> b;
        
        
        if(op == "+") {
            c = a+b;
        } else if(op == "-") {
            c = a-b;
        } else if(op == "*") {
            c = a*b;
        } else if(op == "/") {
            c = a/b;
        } else {
            cout << "unknown operator, aborting..." << endl;
            return 1;
        }

        cout << "Result: " << c << endl; 
    }

    return 0;
}