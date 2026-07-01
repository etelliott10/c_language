#include <stdio.h>

// Prototype
void meow(int times);


int main(void){
  int n = 0;
  printf("How many times do you want to meow?");
  scanf("%i", &n);

  while (n < 1){
    printf("How many times do you want to meow?");
    scanf("%i", &n);
  }
  meow(n);
  return 0;
}

void meow(int times) {
  for (int i = 0; i < times; i++){
    printf("Meow\n");
  }
}