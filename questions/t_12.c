#include <stdio.h>
#include <string.h>
int main() {
  // 这家傻逼题目，日了狗了，1000不可以，要写10000
  char s[10000];
  gets(s);
  int count = 0;
  int length = strlen(s) - 1;
  for(; length>=0; length--){
    if(s[length] == ' ')
      continue;
    else
      break;
  }
  for(; length>=0; length--){
    if(s[length] != ' '){
      count ++;
    }else{
      break;
    }
  }

  printf("%d\n", count);
  return 0;
}
