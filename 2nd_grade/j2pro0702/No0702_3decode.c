#include <stdio.h>
#include <string.h>

#define NUMBER 256

int main(void)
{
  char plaintext[NUMBER+1] = {0};
  char ciphertext[NUMBER];
  char key_table[] = "qwertyuiopasdfghjklzxcvbnm";
  char alpha[] = "abcdefghijklmnopqrstuvwxyz";
  int i, j, dummy;
  
  printf("ciphertext = ");
  scanf("%s%c", ciphertext, &dummy);
  
  for (i=0; i<strlen(ciphertext); i++) {
    for (j=0; plaintext[i]==0; j++) {
      if (ciphertext[i]==key_table[j]) {
	plaintext[i] = alpha[j];
      }
    }
  }

  plaintext[i] = '\0';

  printf("%s\n", plaintext);

  return 0;
}
