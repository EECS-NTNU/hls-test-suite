#include "test_memory_17.h"
#include <stdlib.h>
#include <stdio.h>

void kernel(inout_int_t a[N], in_int_t b[N]) {

  for (int i = 0; i < N; i++) {
    int x = a[i];
    if (b[i] > 5) {
      x = 0;
      b[i] = 0;
    } else {
      x = 1;
    }
    a[i] = x;
  }
}

int main(void) {
  inout_int_t a[N];
  in_int_t b[N];

  srand(13);
  for (int j = 0; j < N; ++j) {
    a[j] = (rand() % 100) - 50;
    b[j] = (rand() % 100) - 50;
  }

  kernel(a, b);

  for (unsigned i = 0; i < N; ++i) {
    printf("%i, %i ", a[i], b[i]);
  }

  return 0;
}
