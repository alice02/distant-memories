#include <stdio.h>

int main(void)
{
  char plaintext[] = "oretachihadekiru";
  int i, j, key;

  printf("key = ");
  scanf("%d", &key);

  for (i=0; plaintext[i]!='\0'; i++) {
    if(key>0){
      for (j=1; j<=key; j++) {
      if(plaintext[i] == 'z') {
        plaintext[i] -= 'z'-'a'+1;
      }
      plaintext[i] += 1;
      }
    }else if(key<0){
      for (j=-1; j>=key; j--) {
        if(plaintext[i] == 'a') {
          plaintext[i] -= 'a'-'z'-1;
        }
        plaintext[i] -= 1;
      }
    }else{
      break;
    }
  }
  
  printf("%s\n", plaintext);
  
  return 0;
}

