#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

int caesar(int key, char plaintext[]);
int subsitution(char plaintext[]);


int main(int argc, char *argv[]){
  if (argc != 2){
    printf("Usage: ./caesar key\n");
    return 1;
  }

  for (int i = 0, n = strlen(argv[1]); i < n; i++){
    if (!isdigit(argv[1][i])){
      printf("Usage: ./caesar key\n");
      return 1;
    }
  }
  
  int key = atoi(argv[1]);

  char plaintext[30];
  printf("plaintext: ");
  fgets(plaintext, sizeof(plaintext), stdin);
  char ciphertext = caesar(key, plaintext);

  return 0;
}

// c = (p + k) % 26
int caesar(int key, char plaintext[]) {

  for (int i = 0; plaintext[i] != '\0'; i++){
    char c = plaintext[i];
    if (isalpha(c)){
      if (islower(c)){
        c = (c - 'a' + key) % 26 + 'a';
      } else {
        c = (c - 'A' + key) % 26 + 'A';
      }
      plaintext[i] = c;
    }
  }
  printf("%s\n", plaintext);
  return 0;
}

int subsitution(char plaintext[])
{
  return 0;
}
