#include <stdio.h>
#include <stdbool.h>

void get_change(int money);

int main(void){ 
  char choice[10];
  
  while (true) {
  printf("Whould you like me to change out your dollar bills for cents? (y/n)\n");
  fgets(choice, sizeof(choice), stdin);
  if (choice[0] == 'y' || choice[0] == 'Y'){
    printf("How much money do you have?\n");
    char dollar_buffer[16];
    int dollars = 0;
    fgets(dollar_buffer, sizeof(dollar_buffer), stdin);
    sscanf(dollar_buffer, "%d", &dollars);
    dollars *= 100;
    get_change(dollars);
    break;
  } else {
    break;
  }

  }
 
}

void get_change(int money) {
  int num_quarters = 10;
  int num_dimes = 20;
  int num_nickels = 50;
  int num_pennies = 10;
  int total_quarters_used = 0;
  int total_dimes_used = 0;
  int total_nickels_used = 0;
  int total_pennies_used = 0;
  printf("%i\n",money);
 
  while (money > 0) {
    if (money >= 25 && num_quarters > 0){
      money -= 25;
      num_quarters -= 1;
      total_quarters_used += 1;
    } else if (money >= 10 && num_dimes > 0){
   money -= 10;
      num_dimes -= 1;
      total_dimes_used += 1;
    } 
    else if (money >= 5 && num_nickels > 0){
   money -= 5;
      num_nickels -= 1;
      total_nickels_used += 1;
    } else if (money >= 1 && num_pennies > 0) {
      money -= 1;
      num_pennies -= 1;
      total_pennies_used += 1;
    } else {
     

      break;
  }
}
 printf("Quarters: %d\n", total_quarters_used);
  printf("Dimes: %d\n", total_dimes_used); 
  printf("Nickels:%d\n", total_nickels_used);
  printf("Pennies: %d\n", total_pennies_used);
   printf("Money still owed $%i\n", money / 100);
}