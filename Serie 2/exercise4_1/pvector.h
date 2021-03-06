#include <iostream>
#include <vector>
#include <fstream>

#include "persistence_traits.h"

using namespace std;


template<typename T, typename P=persistence_traits<T>>
class pvector {

    string filename;
    vector<T> v;

    public:
        pvector(string fname) : filename(fname) { 
            readvector(); 
        }

        ~pvector() { 
            writevector(); 
        }

        void push_back(const T &el) { 
            v.push_back(el); 
        }

        void pop_back() { 
            v.pop_back(); 
        }

        int size() {
            return v.size();
        }

        const T& operator [](int idx) const {
            return v[idx];
        }

        void writevector() {
            ofstream ofs(filename);
            typename vector<T>::iterator fst=v.begin(), lst=v.end();
            while(fst!=lst) P::write(ofs,*fst++);
        } 

        void readvector() {
            ifstream ifs(filename);
            for(;;) {
                T x; //ifs >> x;
                P::read(ifs, x);
                if(!ifs.good()) break;
                v.push_back(x);
            }
        }

        void print() {
            typename vector<T>::iterator fst=v.begin(), lst=v.end();
            for (fst; fst!=lst; ++fst) {
                cout << " |" << *fst << "| ";
            }  
            cout << endl;
        }


};