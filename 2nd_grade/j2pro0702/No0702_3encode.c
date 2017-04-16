#include <stdio.h>
#include <string.h>

#define NUMBER 256

int main(void)
{
  char plaintext[NUMBER];
  char ciphertext[NUMBER] = {0};
  char key_table[] = "qwertyuiopasdfghjklzxcvbnm";
  char alpha[] =     "abcdefghijklmnopqrstuvwxyz";
  int i, j, dummy;
  
  printf("plaintext = ");
  scanf("%s%c", plaintext, &dummy);
  
  for (i=0; plaintext[i]!='\0'; i++) {
    for (j=0; ciphertext[i]==0; j++) {
      if (plaintext[i]==alpha[j]) {
	ciphertext[i] = key_table[j];
      }
    }
  }

  ciphertext[i] = '\0';

  printf("%s\n", ciphertext);

  return 0;
}
