typedef struct Matrix {
  int A[10];
  int n;
} matrix_t;

// Lower

// Row Major
void lower_set_rowmajor(matrix_t *m, int i, int j, int val) {
  if (i >= j) {
    m->A[i * (i - 1) / 2 + j - 1] = val;
  }
}
int lower_get_rowmajor(matrix_t *m, int i, int j) {
  if (i >= j) {
    return m->A[i * (i - 1) / 2 + j - 1];
  }
  return 0;
}

// Column Major
void lower_set_colmajor(matrix_t *m, int i, int j, int val) {
  if (i >= j) {
    m->A[m->n * (j - 1) + ((j - 2) * (j - 1) / 2) + i - j] = val;
  }
}
int lower_get_colmajor(matrix_t *m, int i, int j) {
  if (i >= j) {
    return m->A[m->n * (j - 1) + ((j - 2) * (j - 1) / 2) + i - j];
  }
  return 0;
}

// Upper
//
// Row Major
void upper_set_rowmajor(matrix_t *m, int i, int j, int val) {
  if (i <= j) {
    m->A[i * (i - 1) / 2 + j - 1] = val;
  }
}
int upper_get_rowmajor(matrix_t *m, int i, int j) {
  if (i <= j) {
    return m->A[i * (i - 1) / 2 + j - 1];
  }
  return 0;
}

// Column Major
void upper_set_colmajor(matrix_t *m, int i, int j, int val) {
  if (i <= j) {
    m->A[m->n * (j - 1) + ((j - 2) * (j - 1) / 2) + i - j] = val;
  }
}
int upper_get_colmajor(matrix_t *m, int i, int j) {
  if (i <= j) {
    return m->A[m->n * (j - 1) + ((j - 2) * (j - 1) / 2) + i - j];
  }
  return 0;
}
