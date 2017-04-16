#include<stdio.h>
main(void)
{
  int a[9][9];
  int b,x,y;

  x=0;
  while(x<9){
    y=0;
    while(y<9){
      a[x][y]=2;
      y++;
    }
    x++;
  }

  b=0;
  while(b<9*9){
    printf("   0 1 2 3 4 5 6 7 8\n"); 
   x=0;
    while(x<9){
      y=0;
      printf("%2d",x);
      while(y<9){
	if(a[x][y]==2){
	  printf("・");
	}else if(a[x][y]==1){
	  printf("○");
	}else if(a[x][y]==0){
	  printf("●");
	}
	y++;
      }
      x++;
      printf("\n");
    }
    if(b%2==0){
      printf("黒:");
    }else{
      printf("白:");
    }

    scanf("%d",&y);
    scanf("%d",&x);

    if(a[x][y]==0){
      printf("そこには置けません!\n");
    }else if(a[x][y]==1){
      printf("そこには置けません!\n");
    }else if(x>9){
      printf("そこには置けません!\n");
    }else if(y>9){
      printf("そこには置けません!\n");
    }else{
      if(b%2==0){
	a[x][y]=0;
      }else{
	a[x][y]=1;
      }
      b++;
    }
  }
}

