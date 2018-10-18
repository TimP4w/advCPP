#include <iostream>
#include <fstream>
#include <set>
//#include "persistence_traits.h"

using namespace std;

template<typename T, typename P=persistence_traits<T>>
class pset {

    string filename;
    set<T> s;

    public:
        pset(string fname) : filename(fname) { 
            readset(); 
        }

        ~pset() { 
            writeset(); 
        }

        void insert(const T &el) { 
            s.insert(el); 
        }


        int size() {
            return s.size();
        }

        void erase(T el) {
            s.erase(el);
        }

        void print() {
            typename set<T>::iterator fst=s.begin(), lst=s.end();
            for (fst; fst!=lst; ++fst) {
                cout << " |" << *fst << "| ";
            }  
            cout << endl;
        }

        const T& operator [](int idx) const {
            return s[idx];
        }

        void writeset() {
            ofstream ofs(filename);
            typename set<T>::iterator fst=s.begin(), lst=s.end();
            while(fst!=lst) P::write(ofs,*fst++);
        } 

        void readset() {
            ifstream ifs(filename);
            for(;;) {
                T x; 
                P::read(ifs, x);
                if(!ifs.good()) break;
                s.insert(x);
            }
        }
};