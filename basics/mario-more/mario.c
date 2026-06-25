#include <stdio.h>
#include <stdbool.h>

void pyramid(int tall);

int main(void){
  int n = 0;
  char buffer[30];
  
  while (true) {
  printf("How tall do you want your pyramid to be from 1 - 10?\n");
  fgets(buffer, sizeof(buffer), stdin);
  sscanf(buffer,"%i", &n); 

  if (n > 0 && n < 11){
    break;
  }
  }
  
  pyramid(n);
  
}

void pyramid(int tall){
  int number_of_hashes = 1;
  // For each row
  for (int row = 0; row < tall + 1; row++){
    // For each column
    for (int column = 0; column < tall * 2 + 1; column++){
      if (column == tall) {
        printf(" ");
      } else if (column > tall - number_of_hashes && column < tall + number_of_hashes){
      printf("#");
      }
      else {
        printf(" ");
      
      }
    }
    printf("\n");
    number_of_hashes += 1;
  }
}

