#include <iostream>
using namespace std;

class fraction {
    
    int num;
    int den;
    
    friend ostream &operator<<(ostream &os, fraction f);
    friend istream &operator>>(istream &is, fraction &f);

    public:
    fraction(int n=2, int d=1) :
        num(n), den(d)
    { /*void*/ }

    int get_numerator(void) const;
    void set_numerator(int n);
    int get_denominator(void) const;
    void set_denominator(int d);
    fraction operator+(fraction b);
    fraction operator-(fraction b);
    fraction operator*(fraction b);
    fraction operator/(fraction b);
    bool operator==(const fraction& b) const;


};
