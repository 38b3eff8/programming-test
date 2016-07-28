#include<stdio.h>
int main(){
  int A[1000];
  int n;
  int count = 1;
  int tmp = 0;
  scanf("%d", &n);

  for(int i=0; i<n; i++){
    scanf("%d", A+i);
    if(i != 0){
      if(tmp != A[i]){
        count ++;
        tmp = A[i];
      }
    }else{
      tmp = A[i];
    }
  }

  printf("%d\n", count);
  return 0;
}
