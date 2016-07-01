#include <stdio.h>

int main() {
  char ch;
  int a[] = {1, 0, 0, 0, 0, 0, 1, 0, 2, 1};
  int count = 0;
  while ((ch = getchar()) != '\n') {
    count += a[(ch - '0')];
  }
  printf("%d", count);

  return 0;
}
