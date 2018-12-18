//Minmax search for mancala

#include "mancala.h"

int Search(struct mancala* m,int depth){
  int best=-60;
  int favorite=0;
  int current=-60;
  for(int i=1;i<7;i++){
    struct mancala* temp=newcopy(m);
    int again=hiddenturn(temp,i,2);
    if(again==1){
      current=MinMax(temp,2,depth);
    }else if(again==0){
      current=MinMax(temp,1,depth-1);
    } 
    if(again!=-1){
      freeman(temp);
      if(best==-60){
	best=current;
	favorite=i;
      }else if(current<best){
	best=current;
	favorite=i;
      }
    }
  }
  return favorite;
}

int MinMax(struct mancala* m,int player, int depth){
  int over=gameover(m);
  if(over==0 && depth>0){
    int best=-60;
    int current=-60;
    for(int i=1;i<7;i++){
      struct mancala* temp=newcopy(m);
      int again=hiddenturn(temp,i+1,player);
      if(again==1){
	current=MinMax(temp,player,depth);
      }else if(again==0){
	if(player==1){
	  current=MinMax(temp,2,depth-1);
	}else{
	  current=MinMax(temp,1,depth-1);
	}
      }
      freeman(temp);
      if(again==-1){
	continue;
      }
      if(best==-60){
	best=current;
      }else if(player==1 && current>best){
	best=current;
      }else if(player==2 && current<best){
	best=current;
      }
    }
    return best;
  }else if(over==1){
    return 50;
  }else if(over==-1){
    return -50;
  }else{
    return(m->home1->stones-m->home2->stones);
  }
}
