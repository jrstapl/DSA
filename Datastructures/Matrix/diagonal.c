#include "stdio.h"
// diagonal matrix stored as flat array

typedef struct Matrix {
  int A[10];
  int n;
} matrix_t;

void set(matrix_t *m, int i, int j, int val) {
  if (i == j) {
    m->A[i] = val;
  }
}

int get(matrix_t *m, int i, int j) {
  if (i == j) {
    return m->A[i];
  }
  return 0;
}

void display(matrix_t m) {
  for (int i = 0; i < m.n; i++) {
    for (int j = 0; j < m.n; j++) {
      if (i == j) {
        printf("%d ", m.A[i]);
      } else {
        printf("0 ");
      }
    }
    printf("\n");
  }
}

int main() {
  struct Matrix m;
  m.n = 4;
  set(&m, 0, 0, 5);
  set(&m, 1, 1, 7);
  set(&m, 2, 2, 9);
  set(&m, 3, 3, 11);
  set(&m, 4, 4, 13);
  display(m);

  return 0;
}
