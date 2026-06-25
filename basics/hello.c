// Best practice is to use fgets instead of scanf. 
// fgets will allow mutiple words while scanf will only only one word.

#include <stdio.h> // allows printf to work

int main (void){
  printf("Hello, World!\n What is your name?\n");
  char string_name[30];
  char planet_name[30];
  scanf("%s", string_name);
  getchar();
  printf("Hello, %s\n", string_name);

  printf("What is the name of your planet?\n");
  fgets(planet_name, sizeof(planet_name), stdin);
  printf("Hello, %s\n", planet_name);

  return 0; 
}
