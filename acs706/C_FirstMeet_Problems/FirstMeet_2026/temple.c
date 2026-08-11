#include <stdio.h>

int main() {
  int blocks, height, width;
  scanf("%d %d %d", &blocks, &height, &width);
  for (int b = 1; b <= blocks; b++) {
    for (int r = 1; r <= height; r++) {
      for (int c = 1; c <= width; c++) {
        printf("*");
      }
      printf("\n");
    }
    for (int i = 1; i <= width; i++) {
      printf("-");
    }
    printf("\n");
  }
  return 0;
}