#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// 给定一个整数num，( 1<=num<=3999)，将整数转换成罗马数字。

char s[] = "VLD";
char s1[] = "IXCM";

char* convert(int number, int index){
  char left = s1[index];
  char center = s[index];

  // char result[10];
  char* result = malloc(sizeof(char) * 10);
  int sub_index = 0;

  if(number <= 3){
    for(int i=0; i<number; i++){
      result[sub_index++] = left;
    }
  }else if(number <= 4){
    result[sub_index++]=left;
    result[sub_index++]=center;
  }else if(number <= 8){
    result[sub_index++] = center;
    for(int i=0; i<number-5;i++){
      result[sub_index++] = left;
    }
  }else if(number >= 9){
    result[sub_index++] = left;
    result[sub_index++]=s1[index + 1];
  }
  result[sub_index] = '\0';

  // printf("%d %s\n", number, result);
  return result;
}

void strRev(char *s){
  char temp, *end = s + strlen(s) - 1;
  while( end > s){
    temp = *s;
    *s = *end;
    *end = temp;
    --end;
    ++s;
  }
}

int main() {
  int number;
  char* result = malloc(sizeof(char) * 100);
  scanf("%d", &number);
  int index = 0;
  while(number != 0){
    char* r = convert(number % 10, index++);
    strRev(r);
    strcat(result, r);
    free(r);
    number /= 10;
  }

  strRev(result);
  printf("%s\n", result);
  return 0;
}
