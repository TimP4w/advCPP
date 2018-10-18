#include <iostream>

using namespace std;

void swap(int &a, int &b) {
  int c = a;
  a = b;
  b = c;
}

int main(int argc, char const *argv[]) {
  int a = 1;
  int b = 2;
  swap(a, b);

  return 0;
}