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

  
}

int main() {

}