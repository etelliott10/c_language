#include <stdio.h>
#include <stdbool.h>

int main(void){

  long dollars = 1;
  while (true) {
    char choice;
    printf(" Would you like to have $%ld or double it and give to the next person? (y/n)\n", dollars);
    scanf(" %c", &choice);
    getchar();
    if (choice == 'y' || choice == 'y') {
      dollars = dollars * 2;
    } else {
      break;    
    }
  }
   // Print the final amount the user decided to keep
  printf("You walked away with: $%ld\n", dollars);
  return 0;
}