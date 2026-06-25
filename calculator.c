#include <stdio.h>

int main(void){

  int x = 0;
  int y = 0;

  printf("What is x\n");
  scanf("%i", &x);
  getchar();

  printf("What is y\n");
  scanf("%i", &y);
  getchar();

  int sum = x + y;
  printf("%i\n", sum);

  return 0;

}