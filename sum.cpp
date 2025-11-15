#include <iostream>
#include <cstddef>

void sum(size_t n, size_t m, int * c, const int * a, const int * b) {
  for (size_t i = 0; i < m * n; ++i) {
    c[i] = a[i] + b[i];
  }
}

int * sum(size_t n, size_t m, const int * a, const int * b) {
  int * r = new int[n * m];
  sum(n, m, r, a, b);
  return r;
}

void add(size_t n, size_t m, int * a, const int * b) {
  sum(n, m, a, a, b);
}


int main() {

}