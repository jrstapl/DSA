#include <stdio.h>
void toUpper(char *s) {
  int i = 0;
  while (s[i] != '\n') {
    if (s[i] >= 'a' && s[i] <= 'z') {
      s[i] -= 32;
    }
    i++;
  }
}

void toLower(char *s) {
  int i = 0;
  while (s[i] != '\n') {
    if (s[i] >= 'A' && s[i] <= 'Z') {
      s[i] += 32;
    }
    i++;
  }
}

void findDuplicates(char *s) {
  long int H = 0;
  for (int i = 0; s[i] != '\0'; i++) {
    int x = 1;
    x = x << (s[i] - 97);
    if ((x & H) > 0) {
      printf("%c duplicated\n", s[i]);
    }
    H = H | x;
  }
}

_Bool isAnagram(char *s1, char *s2) {
  int H[26] = {0};

  for (int i = 0; s1[i] != '\0'; i++) {
    H[s1[i] - 97] += 1;
  }
  for (int i = 0; s2[i] != '\0'; i++) {
    H[s2[i] - 97] -= 1;
    if (H[s2[i] - 97] < 0) {
      return 0;
    }
  }

  for (int i = 0; i < 26; i++) {
    if (H[i] != 0) {
      return 0;
    }
  }

  return 1;
}

void permutations(char *s, int k) {
  static int A[256] = {0};
  static char res[256] = {'\0'};
  if (s[k] == '\0') {
    res[k] = '\0';
    printf("%s\n", res);
    return;
  }
  for (int i = 0; A[i] != '\0'; i++) {
    if (A[i] == 0) {
      res[k] = s[i];
      A[i] = 1;
      permutations(s, k + 1);
      A[i] = 0;
    }
  }
}

int main(int argc, char *argv[]) {

  char *s1 = "hello";
  char *s2 = "world!";

  findDuplicates(s1);
  findDuplicates(s2);

  char *s3 = "decimal";
  char *s4 = "medical";

  printf("is anagram: %b\n", isAnagram(s3, s4));

  return 0;
}
