#include <math.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

// where adt = abstract data type
typedef struct array_adt {
  int *A;
  int size;
  int length;

} array_adt_t;

void Display(array_adt_t *A) {
  printf("[ ");
  for (int i = 0; i < A->length; i++) {
    printf("%d, ", A->A[i]);
  }
  printf(" ]\n");
  return;
}

void _Resize(array_adt_t *A, int new_size) {
  if (new_size < 1) {
    return;
  }

  int old_size = A->size;
  A->size = new_size;

  int *new_arr = (int *)malloc(A->size * sizeof(int));
  int *old_arr = A->A;

  for (int i = 0; i < A->length; i++) {
    new_arr[i] = old_arr[i];
  }
  A->A = new_arr;

  free(old_arr);
}

void Append(array_adt_t *A, int x) {
  if (A->length == A->size) {
    _Resize(A, A->size * 2);
  }

  A->A[A->length] = x;
  A->length++;
}

void Insert(array_adt_t *A, int x, int pos) {
  if (pos < 0) {
    return;
  }
  if (A->length == A->size) {
    _Resize(A, A->size * 2);
  }

  for (int i = A->length; i > pos; i--) {
    A->A[i] = A->A[i - 1];
  }
  A->A[pos] = x;
  A->length++;
}

void Delete(array_adt_t *A, int pos) {
  if (pos < 0) {
    return;
  }

  for (int i = pos; i < A->length; i++) {
    A->A[i] = A->A[i + 1];
  }

  A->length--;
}

int Search(array_adt_t *A, int x) {
  for (int i = 0; i < A->length; i++) {
    if (A->A[i] == x) {
      return i;
    }
  }
  return -1;
}

int SearchWithTransposition(array_adt_t *A, int x) {
  for (int i = 0; i < A->length; i++) {
    if (A->A[i] == x) {
      int tmp = A->A[i - 1];
      A->A[i - 1] = A->A[i];
      A->A[i] = tmp;
      return i;
    }
  }
  return -1;
}

int SearchWithFrontMove(array_adt_t *A, int x) {
  for (int i = 0; i < A->length; i++) {
    if (A->A[i] == x) {
      int tmp = A->A[0];
      A->A[0] = A->A[i];
      A->A[i] = tmp;
      return i;
    }
  }
  return -1;
}

int Get(array_adt_t *A, int pos) {
  if (pos >= 0 && pos < A->length - 1) {
    return A->A[pos];
  }
  return NULL;
}

void Set(array_adt_t *A, int x, int pos) {
  if (pos >= 0 && pos < A->length - 1) {
    A->A[pos] = x;
  }
}

int Sum(array_adt_t *A) {
  if (A->length <= 0) {
    return 0;
  }
  int sum = 0;
  for (int i = 0; i < A->length; i++) {
    sum += A->A[i];
  }
  return sum;
}

float Avg(array_adt_t *A) { return (float)Sum(A) / A->length; }

int Max(array_adt_t *A) {
  int curr_max = -INFINITY;
  for (int i = 0; i < A->length; i++) {
    if (A->A[i] > curr_max) {
      curr_max = A->A[i];
    }
  }
  return curr_max;
}
int Min(array_adt_t *A) {
  int curr_min = INFINITY;
  for (int i = 0; i < A->length; i++) {
    if (A->A[i] < curr_min) {
      curr_min = A->A[i];
    }
  }
  return curr_min;
}

void Reverse(array_adt_t *A) {

  for (int rev_i = A->length - 1, fwd_i = 0; rev_i > fwd_i; rev_i--, fwd_i++) {
    int tmp = A->A[rev_i];
    A->A[rev_i] = A->A[fwd_i];
    A->A[fwd_i] = tmp;
  }
}

void Clear(array_adt_t *A) {
  for (int i = 0; i < A->length; i++) {
    A->A[i] = 0;
  }
}

void LeftShift(array_adt_t *A, int shift) {
  if (shift < 0) {
    return;
  }
  if (shift > A->length) {
    return Clear(A);
  }
  int shift_count = 0;

  for (int i = 0; i < A->length - 1; i++) {
    A->A[i] = A->A[i + shift];
  }
  for (int i = A->length - 1; i > A->length - 1 - shift; i--) {
    A->A[i] = 0;
  }
}
void RightShift(array_adt_t *A, int shift) {
  if (shift < 0) {
    return;
  }
  if (shift > A->length) {
    return Clear(A);
  }

  for (int i = A->length - 1; i > 1; i--) {
    A->A[i] = A->A[i - shift];
  }
  for (int i = 0; i < shift + 1; i++) {
    A->A[i] = 0;
  }
}

void Shift(array_adt_t *A, int i) {
  if (i < 0) {
    return LeftShift(A, i * -1);
  } else {
    return RightShift(A, i);
  }
}

void LeftRotate(array_adt_t *A, int shift) {
  if (shift < 0) {
    return;
  }
  int shift_count = 0;
  int dangling_val = 0;
  while (shift_count <= shift) {
    dangling_val = A->A[0];
    for (int i = 0; i < A->length; i++) {
      A->A[i] = A->A[i + 1];
    }
    A->A[A->length - 1] = dangling_val;

    shift_count++;
  }
}

void RightRotate(array_adt_t *A, int shift) {
  if (shift < 0) {
    return;
  }
  int shift_count = 0;
  int dangling_val = 0;
  while (shift_count <= shift) {
    dangling_val = A->A[A->length - 1];
    for (int i = A->length - 1; i > 1; i--) {
      A->A[i] = A->A[i - 1];
    }
    A->A[0] = dangling_val;

    shift_count++;
  }
}

void Rotate(array_adt_t *A, int i) {
  if (i < 0) {
    return LeftRotate(A, i * -1);
  } else {
    return RightRotate(A, i);
  }
}

int main(int argc, char *argv[]) {
  array_adt_t arr = {0};
  arr.size = 10;

  arr.A = (int *)malloc(arr.size * sizeof(int));
  arr.length = 0;

  return 0;
}
