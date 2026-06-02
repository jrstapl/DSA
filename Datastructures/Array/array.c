#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  int A[5];
  int B[] = {1, 2, 3, 4, 5};

  printf("Uninitialized array");
  for (size_t i = 0; i < 5; i++) {
    printf("%p\n", &A[i]);
  }

  int *p = (int *)malloc(5 * sizeof(int));
  p[0] = 1;
  p[1] = 2;
  p[2] = 3;
  p[3] = 4;
  p[4] = 5;

  printf("Heap array");
  for (size_t i = 0; i < 5; i++) {
    printf("%d ", p[i]);
    printf("%p\n", &p[i]);
  }

  // resize array
  int *new_array = (int *)malloc(10 * sizeof(int));
  for (size_t i; i < 10; i++) {
    new_array[i] = 0;
  }
  for (size_t i; i < 5; i++) {
    new_array[i] = p[i];
  }

  free(p);
  p = new_array;
  new_array = NULL;
  printf("Resized array");
  for (size_t i = 0; i < 5; i++) {
    printf("%d ", p[i]);
    printf("%p\n", &p[i]);
  }

  int A2D[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
  int *B2D[3];
  B2D[0] = (int *)malloc(3 * sizeof(int));
  B2D[1] = (int *)malloc(3 * sizeof(int));
  B2D[2] = (int *)malloc(3 * sizeof(int));

  int **C2D;
  C2D = (int **)malloc(3 * sizeof(int *));
  C2D[0] = (int *)malloc(3 * sizeof(int));
  C2D[1] = (int *)malloc(3 * sizeof(int));
  C2D[2] = (int *)malloc(3 * sizeof(int));

  return EXIT_SUCCESS;
}
