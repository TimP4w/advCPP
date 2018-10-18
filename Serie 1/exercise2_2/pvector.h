#include <iostream>
#include <vector>
#include <fstream>

using namespace std;


template<typename T>
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

        void readvector() {
            ifstream ifs(filename);
            for(;;) {
                T x; ifs >> x; 
                if(!ifs.good()) break;
                v.push_back(x);
            }
        }

        void writevector() {
            ofstream ofs(filename);
            typename vector<T>::iterator fst=v.begin(), lst=v.end();
            while(fst!=lst) {
                ofs << *fst++ << endl;
            }
        }

        int size() {
            return v.size();
        }

        const T& operator [](int idx) const {
            return v[idx];
        }
};