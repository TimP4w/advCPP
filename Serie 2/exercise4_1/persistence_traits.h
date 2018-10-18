#include <iostream>
#include <fstream>
#include <string>


using namespace std;

template<typename T>
struct persistence_traits {

    static void read(ifstream &i, T &elem) {
        i >> elem; 
    }

    static void write(ofstream &o, const T &elem) {
        o << elem << endl;
    }

};

template<>
struct persistence_traits<string> {

    static void read(ifstream &i, string &elem) {
        getline(i, elem);
    }

    static void write(ofstream &o, const string &elem) {
        o << elem << endl;
    }

};