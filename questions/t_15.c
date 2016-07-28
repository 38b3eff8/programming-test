#include <stdio.h>

void print(int* array, int length){
  for(int i = 0; i < length; i++){
    printf("%d ", array[i]);
  }
  printf("\n");
}

void sort(int* array, int start, int end){
  if(start >= end)
    return;

  int right = start + 1;

  for(int i = start + 1; i < end; i++){
    if(array[start] > array[i]){
      if(i > right){
        int tmp = array[i];
        array[i] = array[right];
        array[right] = tmp;
      }
      right ++;
    }
  }

  int tmp = array[right - 1];
  array[right - 1] = array[start];
  array[start] = tmp;

  sort(array, start, right - 1);
  sort(array, right, end);
}

int main() {
  int n;
  int nums[10000];
  scanf("%d", &n);

  for(int i=0; i<n; i++){
    scanf("%d", nums+i);
  }
  sort(nums, 0, n);

  int result = 0;
  int index = 0;
  while (index < n) {
    if(nums[index] == nums[index + 1]){
      index += 3;
      result = index;
    }else{
      result = index;
      break;
    }
  }
  printf("%d", nums[result]);
  return 0;
}
