#include <iostream>
#include "polish.h"
#include "fraction.h"

using namespace std;

int main(int argc, char *argv[])  
{
    polish<fraction> calculator;

    calculator.start();
    return 0;
}