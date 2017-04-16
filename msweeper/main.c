#include "msweeper.h"

int main(void)
{
  PARAMETER data;

  do {
    init(&data);
    opening_message();
    msweeper(&data);
  } while(retry());

  see_you();

  return 0;
}
