#include <iostream>

using namespace std;

void c_swap(int *a, int *b) {
  int c = *a;
  *a = *b;
  *b = c;
}

int main(int argc, char const *argv[]) {
  int a = 1;
  int b = 2;
  c_swap(&a, &b);
  return 0;
}