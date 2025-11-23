#include <iostream>
#include <cstddef>

void mul(int * c, const int * a, size_t n1, size_t m1, const int * b, size_t m2) {
  for (size_t i = 0; i < n1; ++i) {
    for (size_t j = 0; j < m2; ++j) {

      int res = 0;
      const int * rowa = a + i * m1;
      const int * colb = b + j;

      for (size_t l = 0; l < m1; ++l) {
        int rowa_l = *(rowa + l);
        int colb_l = colb[l * m2];
        res += rowa_l * colb_l;
      }
      int * rowc = c + i * m2;
      
      rowc[j] = res;
    }

  }

}

int * mul(const int * a, size_t n1, size_t m1, const int * b, size_t m2) {
  int * r = new int[n1 * m2];
  mul(r, a, n1, m1, b, m2);
  return r;
}

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


void sum_of_mul(size_t n, int * c, const int * a, const int * const * b, size_t s) {
  if (s == 1) {
    mul(c, a, n, n, b[0], n);
  }
  const int * res = b[0];
  for (size_t i = 1; i < s; ++i) {
    res = sum(n, n, a, b[i]);
  }
  mul(c, a, n, n, res, n);
}

int * sum_of_mul(size_t n, const int * a, const int * const * b, size_t s) {
  int * r = new int[n * n];
  sum_of_mul(n, r, a, b, s);
  return r;
}

void mul_of_mul(size_t n, int * c, const int * a, const int * const * b, size_t s) {
  if (s == 1) {
    mul(c, a, n, n, b[0], n);
  }
  int * res = mul(a, n, n, b[0], n);
  for (size_t i = 1; i < s; ++i) {
    int * d = mul(a, n, n, b[i], n);
    res = mul(d, n, n, res, n);
  }

  c = res;
  
}

int * mul_of_mul(size_t n, const int * a, const int * const * b, size_t s) {
  int * r = new int[n * n];
  mul_of_mul(n, r, a, b, s);
  return r;
}


int main() {

}