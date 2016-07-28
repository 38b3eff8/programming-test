#include <stdio.h>

int fib(int index){
    int start = 1;
    int tmp = 0;
    for(int i = 1; i <= index; i++){
      int t = start;
      start = start + tmp;
      tmp = t;
    }

    return start;
}

int main() {
  int n;
  scanf("%d", &n);

  printf("%d", fib(n));
  return 0;
}
