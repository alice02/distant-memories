#include <stdio.h>
#include <string.h>

#define BRACK '*'
#define WHITE 'o'
#define SPACE ' '

#define UPPERLEFT 0
#define UP 1
#define UPPERRIGHT 2
#define LEFT 3
#define RIGHT 4
#define LOWERLEFT 5
#define LOW 6
#define LOWERRIGHT 7

char osero[8][8];

void init(void)
{
  int i, j;

  for(i = 0; i < 8; i++)
    {
      for (j = 0; j < 8; j++)
	{
	  osero[i][j] = SPACE;
	}
    }

  osero[3][3] = osero[4][4] = WHITE;
  osero[3][4] = osero[4][3] = BRACK;
}

void print_osero(void)
{
  int i, j;

  printf(" |A|B|C|D|E|F|G|H|\n");
  printf("-+-+-+-+-+-+-+-+-+\n");

  for (i = 0; i < 8; i++)
    {
      printf("%c|", ('a' + i));
      for(j = 0; j < 8; j++)
	{
	  printf("%c|", osero[i][j]);
	}
      printf("\n");
      printf("-+-+-+-+-+-+-+-+-+\n");
    }
}

int check_input(char input[3], char color)
{
  int i, j, x, y;
  char checker;

  if ((input[0] < 'a') || ('h' < input[0])) return -1;
  if ((input[1] < 'A') || ('H' < input[1])) return -1;

  if(osero[input[0] - 'a'][input[1] - 'A'] != SPACE) return 1;

  y = input[0] - 'a';
  x = input[1] - 'A';
  if(color == BRACK) checker = WHITE;
  else if(color == WHITE) checker = BRACK;

  for (i = 0; i < 8; i++)
    {
      switch(i)
	{
	case UPPERLEFT:
	  j = 0;
	  if ((osero[y - 1][x - 1] == color) || (osero[y - 1][x - 1] == SPACE)) break;
	  while(osero[y - 1 - j][x - 1 - j] == checker) j++;
	  if(osero[y - 1 - j][x - 1 - j] == color) return 0;
	  else break;
	  
	case UP:
	  j = 0;
	  if ((osero[y - 1][x] == color) || (osero[y - 1][x] == SPACE)) break;
	  while(osero[y - 1 - j][x] == checker) j++;
	  if(osero[y - 1 - j][x] == color) return 0;
	  else break;	
	  
	case UPPERRIGHT:
	  j = 0;
	  if ((osero[y - 1][x + 1] == color) || (osero[y - 1][x + 1] == SPACE)) break;
	  while(osero[y - 1 - j][x + 1 + j] == checker) j++;
	  if(osero[y - 1 - j][x + 1 + j] == color) return 0;
	  else break;

	case LEFT:
	  j = 0;
	  if ((osero[y][x - 1] == color) || (osero[y][x - 1] == SPACE)) break;
	  while(osero[y][x - 1 - j] == checker) j++;
	  if(osero[y][x - 1 - j] == color) return 0;
	  else break;
	  
	case RIGHT:
	  j = 0;
	  if ((osero[y][x + 1] == color) || (osero[y][x + 1] == SPACE)) break;
	  while(osero[y][x + 1 + j] == checker) j++;
	  if(osero[y][x + 1 + j] == color) return 0;
	  else break;

	case LOWERLEFT:
	  j = 0;
	  if ((osero[y + 1][x - 1] == color) || (osero[y + 1][x - 1] == SPACE)) break;
	  while(osero[y + 1 + j][x - 1 - j] == checker) j++;
	  if(osero[y + 1 + j][x - 1 - j] == color) return 0;
	  else break;

	case LOW:
	  j = 0;
	  if ((osero[y + 1][x] == color) || (osero[y + 1][x] == SPACE)) break;
	  while(osero[y + 1 + j][x] == checker) j++;
	  if(osero[y + 1 + j][x] == color) return 0;
	  else break;

	case LOWERRIGHT:
	  j = 0;
	  if ((osero[y + 1][x + 1] == color) || (osero[y + 1][x + 1] == SPACE)) break;
	  while(osero[y + 1 + j][x + 1 + j] == checker) j++;
	  if(osero[y + 1 + j][x + 1 + j] == color) return 0;
	  else break;
	}
    }
  
  return 2;
}
	
int check_finish(char color)
{
  int x, y, i, j, checker;

  if (color == BRACK) checker = WHITE;
  else if (color == WHITE) checker = BRACK;

  for (y = 0; y < 8; y++)
    {
      for (x = 0; x < 8; x++)
	{
	  if(osero[y][x] == SPACE)
	    {
	      
	      for (i = 0; i < 8; i++)
		{
		  switch(i)
		    {
		    case UPPERLEFT:
		      j = 0;
		      if ((osero[y - 1][x - 1] == color) || (osero[y - 1][x - 1] == SPACE)) break;
		      while(osero[y - 1 - j][x - 1 - j] == checker) j++;
		      if(osero[y - 1 - j][x - 1 - j] == color) return -1;
		      else break;
		      
		    case UP:
		      j = 0;
		      if ((osero[y - 1][x] == color) || (osero[y - 1][x] == SPACE)) break;
		      while(osero[y - 1 - j][x] == checker) j++;
		      if(osero[y - 1 - j][x] == color) return -1;
		      else break;	
		      
		    case UPPERRIGHT:
		      j = 0;
		      if ((osero[y - 1][x + 1] == color) || (osero[y - 1][x + 1] == SPACE)) break;
		      while(osero[y - 1 - j][x + 1 + j] == checker) j++;
		      if(osero[y - 1 - j][x + 1 + j] == color) return -1;
		      else break;
		      
		    case LEFT:
		      j = 0;
		      if ((osero[y][x - 1] == color) || (osero[y][x - 1] == SPACE)) break;
		      while(osero[y][x - 1 - j] == checker) j++;
		      if(osero[y][x - 1 - j] == color) return -1;
		      else break;
		      
		    case RIGHT:
		      j = 0;
		      if ((osero[y][x + 1] == color) || (osero[y][x + 1] == SPACE)) break;
		      while(osero[y][x + 1 + j] == checker) j++;
		      if(osero[y][x + 1 + j] == color) return -1;
		      else break;
		      
		    case LOWERLEFT:
		      j = 0;
		      if ((osero[y + 1][x - 1] == color) || (osero[y + 1][x - 1] == SPACE)) break;
		      while(osero[y + 1 + j][x - 1 - j] == checker) j++;
		      if(osero[y + 1 + j][x - 1 - j] == color) return -1;
		      else break;
		      
		    case LOW:
		      j = 0;
		      if ((osero[y + 1][x] == color) || (osero[y + 1][x] == SPACE)) break;
		      while(osero[y + 1 + j][x] == checker) j++;
		      if(osero[y + 1 + j][x] == color) return -1;
		      else break;
		      
		    case LOWERRIGHT:
		      j = 0;
		      if ((osero[y + 1][x + 1] == color) || (osero[y + 1][x + 1] == SPACE)) break;
		      while(osero[y + 1 + j][x + 1 + j] == checker) j++;
		      if(osero[y + 1 + j][x + 1 + j] == color) return -1;
		      else break;
		    }
		}
	      
	    }
	}
    }
  
  return 0;
}

void send_translation(char *str)
{
  int x, y, i;

  i = 0;
  for (y = 0; y < 8; y++)
    {
      for (x = 0; x < 8; x++)
	{
	  str[i] = osero[y][x];
	  i++;
	}
    }
  str[i] = '\0';

}

void receive_translation(char *str)
{
  int x, y, i;

  x = y = 0;
  for (i = 0; i != '\0'; i++)
    {
      osero[y][x] = str[i];
      x++;
      if (x == 8)
	{
	  y++;
	  x = 0;
	}
    }
}

void check_winner(int *brack, int *white, char winner[6])
{
  int i, j, b, w;

  b = w = 0;

  for (i = 0; i < 8; i++)
    {
      for (j = 0; j < 8; j++)
	{
	  if (osero[i][j] == BRACK) b++;
	  else if (osero[i][j] == WHITE) w++;
	}
    }

  if (b > w) strcpy(winner, "BRACK");
  else if (b < w) strcpy(winner, "WHITE");
  *brack = b;
  *white = w;
}

void stone_reverse(char color, int x, int y)
{
  int i, j, checker;

  if (color == BRACK) checker = WHITE;
  else if (color == WHITE) checker = BRACK;

  for (i = 0; i < 8; i++)
    {
      switch(i)
      {
      case UPPERLEFT:
	//printf("UPPERLEFT\n");   
	j = 0;
	while(osero[y - 1 - j][x - 1 - j] == checker) j++;
	if(osero[y - 1 - j][x - 1 - j] == color)
	  {
	    j--;
	    while(0 <= j)
	      {
		osero[y - 1 - j][x - 1 - j] = color;
		j--;
	      }
	  }
	break;
	
      case UP:   
	//printf("UP\n");
	j = 0;
	while(osero[y - 1 - j][x] == checker) j++;
	if(osero[y - 1 - j][x] == color)
	  {
	    j--;
	    while(0 <= j)
	      {
		osero[y - 1 - j][x] = color;
		j--;
	      }
	  }
	break;	
	
      case UPPERRIGHT:
	//printf("UPPERRIGHT\n");    
	j = 0;
	while(osero[y - 1 - j][x + 1 + j] == checker) j++;
	if(osero[y - 1 - j][x + 1 + j] == color)
	  {
	    j--;
	    while(0 <= j)
	      {
		osero[y - 1 - j][x + 1 + j] = color;
		j--;
	      }
	  }
	break;
	
      case LEFT:
	//printf("LEFT\n");	
	j = 0;
	while(osero[y][x - 1 - j] == checker) j++;
	if(osero[y][x - 1 - j] == color)
	  {
	    j--;
	    while(0 <= j)
	      {
		osero[y][x - 1 - j] = color;
		j--;
	      }
	  }
	break;
	
      case RIGHT:
	//printf("RIGHT\n");      
	j = 0;
	while(osero[y][x + 1 + j] == checker) j++;
	if(osero[y][x + 1 + j] == color)
	  {
	    j--;
	    while(0 <= j)
	      {
		osero[y][x + 1 + j] = color;
		j--;
	      }
	    }
	break;
	
      case LOWERLEFT:
	//printf("LOWERLEFT\n");   
	j = 0;
	while(osero[y + 1 + j][x - 1 - j] == checker) j++;
	if(osero[y + 1 + j][x - 1 - j] == color)
	  {
	    j--;
	    while(0 <= j)
	      {
		osero[y + 1 + j][x - 1 - j] = color;
		j--;
	      }
	  }
	break;
	
      case LOW:
	//printf("LOW\n");   
	j = 0;
	while(osero[y + 1 + j][x] == checker) j++;
	if(osero[y + 1 + j][x] == color)
	  {
	    j--;
	    while(0 <= j)
	      {
		osero[y + 1 + j][x] = color;
		j--;
	      }
	  }
	break;
	
      case LOWERRIGHT:
	//printf("LOWERRIGHT\n");      
	j = 0;
	while(osero[y + 1 + j][x + 1 + j] == checker) j++;
	if(osero[y + 1 + j][x + 1 + j] == color)
	  {
	    j--;
	    while(0 <= j)
	      {
		osero[y + 1 + j][x + 1 + j] = color;
		j--;
	      }
	  }
	break;
	
      }
  
    }

}

void game(void)
{
  char buffer[1000], input[3], winner[6];
  int brack, white;

  printf("NOTES ~ How to Choice the spot ~\n");
  printf("ex: PLAYER's turn. Choice the spot. : gH\n");
  print_osero();

  while(1)
    {
      printf("BRACK's turn. Choice the spot. : ");
      scanf("%s", buffer);

      input[0] = buffer[0];
      input[1] = buffer[1];
      input[2] = '\0';

      if(check_input(input, BRACK) != 0)
	{
	  while(check_input(input, BRACK) != 0)
	    {
	      //printf("errorcode = %d\n", check_input(input, BRACK));
	      printf("Input is the error. Please retry the input. : ");
	      scanf("%s", buffer);

	      input[0] = buffer[0];
	      input[1] = buffer[1];
	      input[2] = '\0';
	    }
	}

      osero[input[0] - 'a'][input[1] - 'A'] = BRACK;
      stone_reverse(BRACK, (input[1] - 'A'), (input[0] - 'a'));
      print_osero();

      if(check_finish(BRACK) == 0) break;


      printf("WHITE's turn. Choice the spot. : ");
      scanf("%s", buffer);

      input[0] = buffer[0];
      input[1] = buffer[1];
      input[2] = '\0';

      if(check_input(input, WHITE) != 0)
	{
	  while(check_input(input, WHITE) != 0)
	    {
	      //printf("errorcode = %d\n", check_input(input, WHITE));
	      printf("Input is the error. Please retry the input. : ");
	      scanf("%s", buffer);

	      input[0] = buffer[0];
	      input[1] = buffer[1];
	      input[2] = '\0';
	    }
	}

      osero[input[0] - 'a'][input[1] - 'A'] = WHITE;
      stone_reverse(WHITE, (input[1] - 'A'), (input[0] - 'a'));
      print_osero();

      if(check_finish(WHITE) == 0) break;
    }

  check_winner(&brack, &white, winner);
  printf("Finish!! BRACK:%d, WHITE:%d. Winner is %s!!\n", brack, white, winner);
}

int main(void)
{
  init();
  game();

  return 0;
}
