#include <stdio.h>

int input_temp(void);
void temperature_check(int temp);

int main(void)
{
  int temp;
  
  temp = input_temp();

  temperature_check(temp);

  return 0;
}

int input_temp(void)
{
  int temp;

  printf("temp = ");
  scanf("%d", &temp);
  while (temp<40 || 100<temp) {
    printf("temp = ", temp);
    scanf("%d", &temp);  
  }

  return temp;
}

void temperature_check(int temp)
{

  if(temp>=80){
    printf("yakedo\n");
  }
  else if(temp>=60){
    printf("choudoi-\n");
  }
  else{
    printf("nurui\n");
  }

}
