//A main function for 2-player mancala

#include "mancala.h"

int main(){
  struct mancala* m=newman();
  int player=1;
  display(m);
  int c;
  int depth=4;
  while(gameover(m)==0){
    if(player==1){
      printf("P1's turn. Which space would you like to move from?\n");
      c=getchar();
      c=c-'0';
      char c2=getchar();
    }else{
      printf("AI's turn!\n");
      c=Search(m,depth);
      printf("%d\n",c);
    }
    int result=turn(m,c,player);
    display(m);
    if(result==1){ 
      printf("Dropped your final stone in your home space, go again!\n");
    }else if(result==-1){
      printf("Make a valid move by entering a number 1-6.\n");
    }else{
      if(player==1){
	player=2;
      }else{
	player=1;
      }
    }
  }
  if(m->home1->stones>m->home2->stones){
    printf("P1 wins!\n");
  }else if(m->home2->stones>m->home1->stones){
    printf("P2 wins!\n");
  }else{
    printf("It's a tie!\n");
  }
  display(m);
  freeman(m);
  exit(0);
}

      
