#include <iostream>
#include "fraction.h"


template <class T>
T gcf(T a, T b) {
    if (a<b) {
        swap(a, b); 
    }
    while (b!=0) {
        a=a-b;
        if (a<b) {
            swap(a, b);
        }
    }
    return a;
}


int fraction::get_numerator(void) const {
    return num;
}
void fraction::set_numerator(int n) {
    num=n;
}
int fraction::get_denominator(void) const {
    return den;
}
void fraction::set_denominator(int d) {
    den=d;
}
    

fraction fraction::operator+(fraction b) {
    int n = num*b.get_denominator() + den*b.get_numerator();
    int d = den*b.get_denominator();

    return fraction(n/gcf(n,d), d/gcf(n,d));
}    

fraction fraction::operator-(fraction b) {
    int n = num*b.get_denominator() - den*b.get_numerator();
    int d = den*b.get_denominator();

    return fraction(n/gcf(n,d), d/gcf(n,d));
}

fraction fraction::operator*(fraction b) {
    int f1 = gcf(num, b.get_denominator());
    int f2 = gcf(den, b.get_numerator());
    return fraction((num/f1) * (b.get_numerator()/f2),(den/f2) * (b.get_denominator()/f1));
}    

fraction fraction::operator/(fraction b) { 
    return *this * fraction(b.get_denominator(), b.get_numerator());
}

bool fraction::operator==(const fraction& b) const
{
    return num == b.get_numerator() && den == b.get_denominator();
}

ostream &operator<<(ostream &os, fraction f) {
    os << '(' << f.num << '/' << f.den << ')';
    return os;
}

inline void check_char(istream &is, char ch) {
    char c; 
    is >> c; 
    if(c!=ch) { 
        is.putback(c); 
        is.setstate(ios::badbit); 
    }
}

istream &operator>>(istream &is, fraction &f) {
    fraction g;
    check_char(is, '(');
    is >> g.num;
    check_char(is, '/');
    is >> g.den;
    check_char(is, ')');
    if(is) f=g;
    return is;
}
